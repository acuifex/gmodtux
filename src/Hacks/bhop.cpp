
#include "bhop.h"

void BHop::CreateMove(CUserCmd* cmd)
{
    if (!cvar->FindVar( "skele_bhop" )->GetInt())
        return;

    static bool bLastJumped = false;
    static bool bShouldFake = false;

    C_BasePlayer* localplayer = (C_BasePlayer*) entityList->GetClientEntity(engine->GetLocalPlayer());

    if (!localplayer /*|| localplayer->GetAlive*/)
        return;
//    cvar->ConsoleDPrintf("localplayer %p\n", localplayer);
//    cvar->ConsoleDPrintf("engine %p\n", engine);
//    cvar->ConsoleDPrintf("velocity lenght %f\n", localplayer->GetVelocity().Length());
//    cvar->ConsoleDPrintf("m_vecVelocity %x\n", offsets.DT_BasePlayer.m_vecVelocity);
//    cvar->ConsoleDPrintf("m_iHealth %x\n", offsets.DT_BasePlayer.m_iHealth);
//    cvar->ConsoleDPrintf("m_lifeState %x\n", offsets.DT_BasePlayer.m_lifeState);
//    cvar->ConsoleDPrintf("m_fFlags %x\n", offsets.DT_BasePlayer.m_fFlags);
//    cvar->ConsoleDPrintf("entityList %p\n", entityList);
//    cvar->ConsoleDPrintf("health %d\n", localplayer->GetHealth());
//    cvar->ConsoleDPrintf("flags %d\n", localplayer->GetFlags());
//    cvar->ConsoleDPrintf("movetype %d\n", localplayer->GetMoveType());
    if (localplayer->GetMoveType() == MOVETYPE_LADDER || localplayer->GetMoveType() == MOVETYPE_NOCLIP)
        return;

    if (!bLastJumped && bShouldFake)
    {
        bShouldFake = false;
        cmd->buttons |= IN_JUMP;
    }
    else if (cmd->buttons & IN_JUMP)
    {
        if (localplayer->GetFlags() & FL_ONGROUND)
        {
            bLastJumped = true;
            bShouldFake = true;
        }
        else
        {
            cmd->buttons &= ~IN_JUMP;
            bLastJumped = false;
        }
    }
    else
    {
        bLastJumped = false;
        bShouldFake = false;
    }
}