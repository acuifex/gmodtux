#include "esp.h"

#include "../interfaces.h"
#include "../settings.h"
#include "../Utils/draw.h"

bool Settings::ESP::enabled = false;

void DrawEntity(C_BaseEntity* entity, const char* str)
{
	Vector screenPos;
	Vector pos = entity->GetVecOrigin();
	// cvar->ConsoleDPrintf("%s\n", str);
	// cvar->ConsoleDPrintf("pos: %f, %f, %f\n", pos.x, pos.y, pos.z);
	
	if (debugOverlay->ScreenPosition( pos, screenPos ))
		return;
	
	// cvar->ConsoleDPrintf("scrpos: %f, %f, %f\n", screenPos.x, screenPos.y, screenPos.z);
	
	Draw::AddText(screenPos.x, screenPos.y, str, ImColor(0,0,255));
}

void ESP::Paint() {
	if (!Settings::ESP::enabled)
		return;
	
	if (!engine->IsInGame())
		return;
	
	C_BasePlayer* localplayer = (C_BasePlayer*) entityList->GetClientEntity(engine->GetLocalPlayer());
	if (!localplayer)
		return;
	
	// TODO: bug, this is missing some of the entities.
	for (int i = 1; i <= entityList->GetHighestEntityIndex(); i++)
	{
		C_BaseEntity* entity = dynamic_cast<C_BaseEntity*>(entityList->GetClientEntity(i));
		if (!entity)
			continue;
		
		if (entity == localplayer)
			continue;
		
		// DORMANT IS BORKED
		// if (entity->GetDormant())
		// 	continue;
		
		ClientClass* clientClass = entity->GetClientClass();
		
		std::stringstream displayText;
		displayText << "clientClass->m_ClassID " << (int)clientClass->m_ClassID << "\n";
		displayText << "clientClass->m_pNetworkName " << clientClass->m_pNetworkName;
		DrawEntity(entity, displayText.str().c_str());
	}
}
