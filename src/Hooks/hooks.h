#pragma once

#include "../SDK/SDK.h"
#include "../interfaces.h"
#include "../hooker.h"
#include "../Hacks/NoFog.h"
#include "../GTGUI/gtgui.h"


typedef void (*FrameStageNotifyFn) (void*, ClientFrameStage_t);
typedef void (*SetKeyCodeStateFn) (void*, ButtonCode_t, bool);
typedef void (*BeginFrameFn) (void*, float);
typedef bool (*CreateMoveFn) (void*, float, CUserCmd*);
typedef void (*PaintFn) (void*, PaintMode_t);
typedef void (*LockCursorFn) (void*);

namespace Hooks {
	void FrameStageNotify(void* thisptr, ClientFrameStage_t stage);
	void SetKeyCodeState(void* thisptr, ButtonCode_t code, bool bPressed);
	void BeginFrame(void* thisptr, float frameTime);
	bool ShouldDrawFog(void* thisptr);
	bool CreateMove(void* thisptr, float flInputSampleTime, CUserCmd* cmd);
	void LockCursor(void* thisptr);
	void Paint(void* thisptr, PaintMode_t mode);
	void PaintImGui(); // Draw with ImGui.
}

namespace CreateMove
{
    extern bool sendPacket;
//    extern QAngle lastTickViewAngles;
}

namespace Paint
{
    extern int engineWidth; // updated in paint.
    extern int engineHeight;
}

namespace OverrideView
{
	inline float currentFOV;
}

namespace SetKeyCodeState
{
	inline bool shouldListen;
	inline ButtonCode_t* keyOutput;
}
