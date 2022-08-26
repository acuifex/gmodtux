#include <thread>
#include <chrono>
#include <fcntl.h>
#include <sys/stat.h>
#include <cstdio>

#include "Hooks/hooks.h"
#include "hooker.h"
#include "interfaces.h"
#include "Utils/util.h"
#include "Utils/netvarmanager.h"

void MainThread() {
	Interfaces::FindInterfaces();
	Interfaces::DumpInterfaces();
	
	// Hooker::FindSetNamedSkybox();
//	Hooker::FindViewRender();
	Hooker::HookSwapWindow();
	Hooker::HookPollEvent();
//	Hooker::FindSDLInput();
//     Hooker::FindIClientMode(); // i think this one was working
	// Hooker::FindGlobalVars();
	// Hooker::FindCInput();
//	Hooker::FindPrediction();
// 	Hooker::FindSurfaceDrawing();
// 	Hooker::FindGetLocalClient();
// 	Hooker::FindInitKeyValues();
// 	Hooker::FindLoadFromBuffer();
//     Hooker::FindVstdlibFunctions();
	Hooker::FindLuaSharedFunctions();
//	Hooker::FindOverridePostProcessingDisable();
	
	// if( !Settings::RegisterConVars() ){
	// 	cvar->ConsoleDPrintf("Error making Custom ConVars! Stopping...\n");
	// 	return;
	// }
	
	// clientVMT = new VMT(client);
	// clientVMT->HookVM( Hooks::FrameStageNotify, 35 );
	// clientVMT->ApplyVMT();
	
	// clientModeVMT = new VMT(clientMode);
	// clientModeVMT->HookVM( Hooks::ShouldDrawFog, 16 );
	// TODO: this was crashing for me, figure out what's up
	// clientModeVMT->HookVM( Hooks::CreateMove, 22 );
	// clientModeVMT->ApplyVMT();
	
	engineVGuiVMT = new VMT(engineVGui);
	engineVGuiVMT->HookVM( Hooks::Paint, 14 );
	engineVGuiVMT->ApplyVMT();
	
	// GetRenderContext changes between calls.......
	matRenderContextVMT = new VMT(material->GetRenderContext());
	matRenderContextVMT->HookVM( Hooks::ReadPixels, 11 );
	matRenderContextVMT->ApplyVMT();
	
//	materialVMT = new VMT(material); // good?
//	materialVMT->HookVM( Hooks::BeginFrame, 42 );
//	materialVMT->ApplyVMT();
//
//	surfaceVMT = new VMT(surface); // good?
//	surfaceVMT->HookVM( Hooks::LockCursor, 67 );
//	surfaceVMT->ApplyVMT();
	
	NetVarManager::DumpNetvars();
	Offsets::GetOffsets();
	
	//Settings::LoadSettings();
	
	srand(time(nullptr)); // Seed random # Generator so we can call rand() later
	
	cvar->ConsoleColorPrintf(ColorRGBA(0, 225, 0), "\ngmodtux Successfully loaded.\n");
}

/* Entrypoint to the Library. Called when loading */
int __attribute__((constructor)) Startup() {
	// std::thread mainThread(MainThread);
	// The root of all suffering is attachment
	// Therefore our little buddy must detach from this realm.
	// Farewell my thread, may we join again some day..
	// mainThread.detach();
	MainThread();
	return 0;
}

/* Called when un-injecting the library */
void __attribute__((destructor)) Shutdown() {
	cvar->FindVar("cl_mouseenable")->SetValue(1);
	SDL2::UnhookWindow();
	SDL2::UnhookPollEvent();
	
	
	// clientVMT->ReleaseVMT();
	// clientModeVMT->ReleaseVMT();
	engineVGuiVMT->ReleaseVMT();
	matRenderContextVMT->ReleaseVMT();
	
	// *s_bOverridePostProcessingDisable = false;
	
	/* Cleanup ConVars we have made */
	// for( ConVar* var : Util::createdConvars ){
	// 	cvar->UnregisterConCommand(var);
	// }
	
	cvar->ConsoleColorPrintf(ColorRGBA(255, 0, 0), "gmodtux unloaded successfully.\n");
	
}
