#pragma once

#include "../SDK/SDK.h"
#include "../interfaces.h"
#include "../hooker.h"
#include "../Hacks/NoFog.h"


typedef void (*FrameStageNotifyFn) (void*, ClientFrameStage_t);
typedef void (*SetKeyCodeStateFn) (void*, ButtonCode_t, bool);
typedef void (*BeginFrameFn) (void*, float);
typedef void (*CreateMoveFn) (void*, float, CUserCmd*);
typedef void (*PaintFn) (void*, PaintMode_t);
typedef void (*LockCursorFn) (void*);


namespace Hooks
{
	void FrameStageNotify(void* thisptr, ClientFrameStage_t stage);
	void SetKeyCodeState(void* thisptr, ButtonCode_t code, bool bPressed);
	void BeginFrame(void* thisptr, float frameTime);
	bool ShouldDrawFog(void* thisptr);
    bool CreateMove(void* thisptr, float flInputSampleTime, CUserCmd* cmd);

	void LockCursor(void* thisptr);

	void Paint(void* thisptr, PaintMode_t mode);
}

namespace CreateMove
{
	inline bool sendPacket;
	inline QAngle lastTickViewAngles;
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
