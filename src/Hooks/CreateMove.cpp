#include "hooks.h"

#include "../Hacks/bhop.h"
#include "../Hacks/autostrafe.h"

bool Hooks::CreateMove(void* thisptr, float flInputSampleTime, CUserCmd* cmd)
{
    clientModeVMT->GetOriginalMethod<CreateMoveFn>(22)(thisptr, flInputSampleTime, cmd);

    if (cmd && cmd->command_number)
    {
        BHop::CreateMove(cmd);
        AutoStrafe::CreateMove(cmd);
    }
}
