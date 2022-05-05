#include "autostrafe.h"
#include "../Utils/math.h"

bool enabled = true;
AutostrafeType type = AutostrafeType::AS_RAGE;
bool silent = true;

static void LegitStrafe(C_BasePlayer* localplayer, CUserCmd* cmd)
{
    if (localplayer->GetFlags() & FL_ONGROUND)
        return;

    if (cmd->buttons & IN_FORWARD || cmd->buttons & IN_BACK || cmd->buttons & IN_MOVELEFT || cmd->buttons & IN_MOVERIGHT)
        return;
    static float cl_sidespeed = cvar->FindVar("cl_sidespeed")->GetFloat();

    if (cmd->mousedx <= 1 && cmd->mousedx >= -1)
        return;

    switch (type)
    {
        case AutostrafeType::AS_FORWARDS:
            if(cmd->mousedx < 0.f){
                cmd->sidemove = -cl_sidespeed;
                cmd->buttons |= IN_MOVELEFT;
            } else {
                cmd->sidemove = cl_sidespeed;
                cmd->buttons |= IN_MOVERIGHT;
            }
            break;
        case AutostrafeType::AS_BACKWARDS:
            cmd->sidemove = cmd->mousedx < 0.f ? 450.f : -450.f;
            break;
        case AutostrafeType::AS_LEFTSIDEWAYS:
            cmd->forwardmove = cmd->mousedx < 0.f ? -450.f : 450.f;
            break;
        case AutostrafeType::AS_RIGHTSIDEWAYS:
            cmd->forwardmove = cmd->mousedx < 0.f ? 450.f : -450.f;
            break;
        default:
            break;
    }
}

static void RageStrafe(C_BasePlayer* localplayer, CUserCmd* cmd)
{
    static bool leftRight;
    bool inMove = cmd->buttons & IN_FORWARD || cmd->buttons & IN_BACK || cmd->buttons & IN_MOVELEFT || cmd->buttons & IN_MOVERIGHT;
    static float cl_sidespeed = cvar->FindVar("cl_sidespeed")->GetFloat();

    if (cmd->buttons & IN_FORWARD && localplayer->GetVelocity().Length() <= 50.0f)
        cmd->forwardmove = cl_sidespeed;

    float yaw_change = 0.0f;
    if (localplayer->GetVelocity().Length() > 50.f)
        yaw_change = 30.0f * fabsf(30.0f / localplayer->GetVelocity().Length());

//    C_BaseCombatWeapon* activeWeapon = (C_BaseCombatWeapon*) entityList->GetClientEntityFromHandle(localplayer->GetActiveWeapon());
//    if (activeWeapon && !activeWeapon->GetAmmo() == 0 && cmd->buttons & IN_ATTACK)
//        yaw_change = 0.0f;

    QAngle viewAngles;
    engine->GetViewAngles(viewAngles);

    if (!(localplayer->GetFlags() & FL_ONGROUND) && !inMove)
    {
        if (leftRight || cmd->mousedx > 1)
        {
            viewAngles.y += yaw_change;
            cmd->sidemove = cl_sidespeed;
        }
        else if (!leftRight || cmd->mousedx < 1)
        {
            viewAngles.y -= yaw_change;
            cmd->sidemove = -cl_sidespeed;
        }

        leftRight = !leftRight;
    }

    Math::NormalizeAngles(viewAngles);
    Math::ClampAngles(viewAngles);

    Math::CorrectMovement(viewAngles, cmd, cmd->forwardmove, cmd->sidemove);

    if (!silent)
        cmd->viewangles = viewAngles;
}

void AutoStrafe::CreateMove(CUserCmd* cmd)
{
    if(!(bool)cvar->FindVar( "skele_autostrafe" )->GetInt())
        return;

    C_BasePlayer* localplayer = (C_BasePlayer*) entityList->GetClientEntity(engine->GetLocalPlayer());
    if (!localplayer)
        return;

    if (localplayer->GetMoveType() == MOVETYPE_LADDER || localplayer->GetMoveType() == MOVETYPE_NOCLIP)
        return;

//    if (!localplayer->GetAlive())
//        return;

    switch (type)
    {
        case AutostrafeType::AS_FORWARDS:
        case AutostrafeType::AS_BACKWARDS:
        case AutostrafeType::AS_LEFTSIDEWAYS:
        case AutostrafeType::AS_RIGHTSIDEWAYS:
            LegitStrafe(localplayer, cmd);
            break;
        case AutostrafeType::AS_RAGE:
            RageStrafe(localplayer, cmd);
            break;
    }
}
