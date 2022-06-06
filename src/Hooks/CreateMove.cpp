#include "hooks.h"

#include "../Hacks/bhop.h"
#include "../Hacks/autostrafe.h"

bool CreateMove::sendPacket = true;

bool Hooks::CreateMove(void* thisptr, float flInputSampleTime, CUserCmd* cmd)
{
    bool ret = clientModeVMT->GetOriginalMethod<CreateMoveFn>(22)(thisptr, flInputSampleTime, cmd);

    if (cmd && cmd->command_number)
    {
        // uintptr_t rbp;
        // asm volatile("mov %%rbp, %0" : "=r" (rbp));
        // bool *sendPacket = ((*(bool **)rbp) - 0x18);
        // CreateMove::sendPacket = true;

        // BHop::CreateMove(cmd);
        // AutoStrafe::CreateMove(cmd);

//        *sendPacket = CreateMove::sendPacket;
    }
    return ret;
}
