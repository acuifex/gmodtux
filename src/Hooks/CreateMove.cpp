#include "hooks.h"


bool Hooks::CreateMove(void* thisptr, float flInputSampleTime, CUserCmd* cmd)
{
    clientModeVMT->GetOriginalMethod<CreateMoveFn>(22)(thisptr, flInputSampleTime, cmd);

    if (cmd && cmd->command_number)
    {
        cvar->ConsoleDPrintf("test\n");
    }
}
