#include "settings.h"



bool Settings::RegisterConVars( ) {
	// TODO: i should nuke all of this/change this to gmod's functions
    bool convarsOK = true;
    convarsOK &= Util::RegisterConVar( "skele_autostrafe", "0" );
    convarsOK &= Util::RegisterConVar( "skele_disable_fog", "0" );
    convarsOK &= Util::RegisterConVar( "skele_bhop", "0" );
    convarsOK &= Util::RegisterConVar( "skele_desync", "0" );
    convarsOK &= Util::RegisterConVar( "skele_nospread", "1" );
    convarsOK &= Util::RegisterConVar( "skele_name", "test" );
    convarsOK &= Util::RegisterConVar( "skele_luaload_enabled", "0" );
    convarsOK &= Util::RegisterConVar( "skele_luaload_path", "/hdd/test.lua" );
//    cvar->ConsoleDPrintf("skybox: %d\n", cvar->FindVar("skele_skybox_enabled")->GetInt());

    return convarsOK;
}