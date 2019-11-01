#include "offsets.h"
#include "Utils/netvarmanager.h"

COffsets offsets;

void Offsets::GetOffsets()
{
	std::vector<RecvTable *> tables = NetVarManager::GetTables();

	offsets.DT_BasePlayer.m_Local = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_Local");
	offsets.DT_BasePlayer.m_aimPunchAngle = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_aimPunchAngle");
	offsets.DT_BasePlayer.m_viewPunchAngle = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_viewPunchAngle");
	offsets.DT_BasePlayer.m_vecViewOffset = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_vecViewOffset[0]");
	offsets.DT_BasePlayer.m_nTickBase = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_nTickBase");
	offsets.DT_BasePlayer.m_vecVelocity = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_vecVelocity[0]");
	offsets.DT_BasePlayer.m_iHealth = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_iHealth");
	offsets.DT_BasePlayer.m_lifeState = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_lifeState");
	offsets.DT_BasePlayer.m_fFlags = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_fFlags");
	offsets.DT_BasePlayer.m_iObserverMode = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_iObserverMode");
	offsets.DT_BasePlayer.m_hObserverTarget = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_hObserverTarget");
	offsets.DT_BasePlayer.m_hViewModel = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_hViewModel[0]");
	offsets.DT_BasePlayer.m_szLastPlaceName = NetVarManager::GetOffset(tables, "DT_BasePlayer", "m_szLastPlaceName");
	offsets.DT_BasePlayer.deadflag = NetVarManager::GetOffset(tables, "DT_BasePlayer", "deadflag");

	offsets.DT_BaseEntity.m_flAnimTime = NetVarManager::GetOffset(tables, "DT_BaseEntity", "m_flAnimTime");
	offsets.DT_BaseEntity.m_flSimulationTime = NetVarManager::GetOffset(tables, "DT_BaseEntity", "m_flSimulationTime");
	offsets.DT_BaseEntity.m_vecOrigin = NetVarManager::GetOffset(tables, "DT_BaseEntity", "m_vecOrigin");
	offsets.DT_BaseEntity.m_nRenderMode = NetVarManager::GetOffset(tables, "DT_BaseEntity", "m_nRenderMode");
	offsets.DT_BaseEntity.m_iTeamNum = NetVarManager::GetOffset(tables, "DT_BaseEntity", "m_iTeamNum");
	offsets.DT_BaseEntity.m_iParentAttachment = NetVarManager::GetOffset(tables, "DT_BaseEntity", "m_iParentAttachment");
	offsets.DT_BaseEntity.m_MoveType = offsets.DT_BaseEntity.m_iParentAttachment - 2;
	offsets.DT_BaseEntity.m_Collision = NetVarManager::GetOffset(tables, "DT_BaseEntity", "m_Collision");
	offsets.DT_BaseEntity.m_bSpotted = NetVarManager::GetOffset(tables, "DT_BaseEntity", "m_bSpotted");

	offsets.DT_BaseCombatCharacter.m_hActiveWeapon = NetVarManager::GetOffset(tables, "DT_BaseCombatCharacter", "m_hActiveWeapon");
	offsets.DT_BaseCombatCharacter.m_hMyWeapons = NetVarManager::GetOffset(tables, "DT_BaseCombatCharacter", "m_hMyWeapons") / 2;
	offsets.DT_BaseCombatCharacter.m_hMyWearables = NetVarManager::GetOffset(tables, "DT_BaseCombatCharacter", "m_hMyWearables");

	offsets.DT_PlayerResource.m_iPing = NetVarManager::GetOffset(tables, "DT_PlayerResource", "m_iPing");
	offsets.DT_PlayerResource.m_iKills = NetVarManager::GetOffset(tables, "DT_PlayerResource", "m_iKills");
	offsets.DT_PlayerResource.m_iAssists = NetVarManager::GetOffset(tables, "DT_PlayerResource", "m_iAssists");
	offsets.DT_PlayerResource.m_iDeaths = NetVarManager::GetOffset(tables, "DT_PlayerResource", "m_iDeaths");
	offsets.DT_PlayerResource.m_bConnected = NetVarManager::GetOffset(tables, "DT_PlayerResource", "m_bConnected");
	offsets.DT_PlayerResource.m_iTeam = NetVarManager::GetOffset(tables, "DT_PlayerResource", "m_iTeam");
	offsets.DT_PlayerResource.m_iPendingTeam = NetVarManager::GetOffset(tables, "DT_PlayerResource", "m_iPendingTeam");
	offsets.DT_PlayerResource.m_bAlive = NetVarManager::GetOffset(tables, "DT_PlayerResource", "m_bAlive");
	offsets.DT_PlayerResource.m_iHealth = NetVarManager::GetOffset(tables, "DT_PlayerResource", "m_iHealth");

	offsets.DT_CSPlayer.m_iShotsFired = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_iShotsFired");
	offsets.DT_CSPlayer.m_angEyeAngles[0] = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_angEyeAngles[0]");
	offsets.DT_CSPlayer.m_angEyeAngles[1] = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_angEyeAngles[1]");
	offsets.DT_CSPlayer.m_iAccount = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_iAccount");
	offsets.DT_CSPlayer.m_totalHitsOnServer = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_totalHitsOnServer");
	offsets.DT_CSPlayer.m_ArmorValue = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_ArmorValue");
	offsets.DT_CSPlayer.m_bIsDefusing = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_bIsDefusing");
	offsets.DT_CSPlayer.m_bIsGrabbingHostage = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_bIsGrabbingHostage");
	offsets.DT_CSPlayer.m_bIsScoped = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_bIsScoped");
	offsets.DT_CSPlayer.m_bGunGameImmunity = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_bGunGameImmunity");
	offsets.DT_CSPlayer.m_bIsRescuing = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_bIsRescuing");
	offsets.DT_CSPlayer.m_bHasHelmet = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_bHasHelmet");
	offsets.DT_CSPlayer.m_bHasDefuser = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_bHasDefuser");
	offsets.DT_CSPlayer.m_flFlashDuration = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_flFlashDuration");
	offsets.DT_CSPlayer.m_flFlashMaxAlpha = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_flFlashMaxAlpha");
	offsets.DT_CSPlayer.m_flLowerBodyYawTarget = NetVarManager::GetOffset(tables, "DT_CSPlayer", "m_flLowerBodyYawTarget");

	offsets.DT_BaseAttributableItem.m_iItemDefinitionIndex = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_iItemDefinitionIndex");
	offsets.DT_BaseAttributableItem.m_iItemIDHigh = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_iItemIDHigh");
	offsets.DT_BaseAttributableItem.m_iAccountID = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_iAccountID");
	offsets.DT_BaseAttributableItem.m_iEntityQuality = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_iEntityQuality");
	offsets.DT_BaseAttributableItem.m_szCustomName = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_szCustomName");
	offsets.DT_BaseAttributableItem.m_nFallbackPaintKit = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_nFallbackPaintKit");
	offsets.DT_BaseAttributableItem.m_nFallbackSeed = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_nFallbackSeed");
	offsets.DT_BaseAttributableItem.m_flFallbackWear = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_flFallbackWear");
	offsets.DT_BaseAttributableItem.m_nFallbackStatTrak = NetVarManager::GetOffset(tables, "DT_BaseAttributableItem", "m_nFallbackStatTrak");

	offsets.DT_BaseViewModel.m_nModelIndex = NetVarManager::GetOffset(tables, "DT_BaseViewModel", "m_nModelIndex");
	offsets.DT_BaseViewModel.m_hWeapon = NetVarManager::GetOffset(tables, "DT_BaseViewModel", "m_hWeapon");
	offsets.DT_BaseViewModel.m_hOwner = NetVarManager::GetOffset(tables, "DT_BaseViewModel", "m_hOwner");

	offsets.DT_WeaponCSBase.m_bReloadVisuallyComplete = NetVarManager::GetOffset(tables, "DT_WeaponCSBase", "m_bReloadVisuallyComplete");
	offsets.DT_WeaponCSBase.m_fAccuracyPenalty = NetVarManager::GetOffset(tables, "DT_WeaponCSBase", "m_fAccuracyPenalty");

	offsets.DT_BaseCombatWeapon.m_flNextPrimaryAttack = NetVarManager::GetOffset(tables, "DT_BaseCombatWeapon", "m_flNextPrimaryAttack");
	offsets.DT_BaseCombatWeapon.m_hOwner = NetVarManager::GetOffset(tables, "DT_BaseCombatWeapon", "m_hOwner");
	offsets.DT_BaseCombatWeapon.m_iClip1 = NetVarManager::GetOffset(tables, "DT_BaseCombatWeapon", "m_iClip1");
	offsets.DT_BaseCombatWeapon.m_bInReload = offsets.DT_BaseCombatWeapon.m_flNextPrimaryAttack + 113;

	offsets.DT_BaseCSGrenade.m_bRedraw = NetVarManager::GetOffset(tables, "DT_BaseCSGrenade", "m_bRedraw");
	offsets.DT_BaseCSGrenade.m_bIsHeldByPlayer = NetVarManager::GetOffset(tables, "DT_BaseCSGrenade", "m_bIsHeldByPlayer");
	offsets.DT_BaseCSGrenade.m_bPinPulled = NetVarManager::GetOffset(tables, "DT_BaseCSGrenade", "m_bPinPulled");
	offsets.DT_BaseCSGrenade.m_fThrowTime = NetVarManager::GetOffset(tables, "DT_BaseCSGrenade", "m_fThrowTime");
	offsets.DT_BaseCSGrenade.m_bLoopingSoundPlaying = NetVarManager::GetOffset(tables, "DT_BaseCSGrenade", "m_bLoopingSoundPlaying");
	offsets.DT_BaseCSGrenade.m_flThrowStrength = NetVarManager::GetOffset(tables, "DT_BaseCSGrenade", "m_flThrowStrength");

	offsets.DT_DynamicProp.m_bShouldGlow = NetVarManager::GetOffset(tables, "DT_DynamicProp", "m_bShouldGlow");
}
