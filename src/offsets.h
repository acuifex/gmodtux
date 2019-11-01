#pragma once

#include <cstdio>
#include "SDK/vector.h"

struct COffsets
{
	struct
	{
		std::ptrdiff_t m_Local;
		std::ptrdiff_t m_aimPunchAngle;
		std::ptrdiff_t m_viewPunchAngle;
		std::ptrdiff_t m_vecViewOffset;
		std::ptrdiff_t m_nTickBase;
		std::ptrdiff_t m_vecVelocity;
		std::ptrdiff_t m_iHealth;
		std::ptrdiff_t m_lifeState;
		std::ptrdiff_t m_fFlags;
		std::ptrdiff_t m_iObserverMode;
		std::ptrdiff_t m_hObserverTarget;
		std::ptrdiff_t m_hViewModel;
		std::ptrdiff_t m_szLastPlaceName;
		std::ptrdiff_t deadflag;
	} DT_BasePlayer;

	struct
	{
		std::ptrdiff_t m_flAnimTime;
		std::ptrdiff_t m_flSimulationTime;
		std::ptrdiff_t m_vecOrigin;
		std::ptrdiff_t m_nRenderMode;
		std::ptrdiff_t m_iTeamNum;
		std::ptrdiff_t m_iParentAttachment;
		std::ptrdiff_t m_MoveType;
		std::ptrdiff_t m_Collision;
		std::ptrdiff_t m_bSpotted;
	} DT_BaseEntity;

	struct
	{
		std::ptrdiff_t m_hActiveWeapon;
		std::ptrdiff_t m_hMyWeapons;
		std::ptrdiff_t m_hMyWearables;
	} DT_BaseCombatCharacter;

	struct
	{
		std::ptrdiff_t m_iPing;
		std::ptrdiff_t m_iKills;
		std::ptrdiff_t m_iAssists;
		std::ptrdiff_t m_iDeaths;
		std::ptrdiff_t m_bConnected;
		std::ptrdiff_t m_iTeam;
		std::ptrdiff_t m_iPendingTeam;
		std::ptrdiff_t m_bAlive;
		std::ptrdiff_t m_iHealth;
	} DT_PlayerResource;

	struct
	{
		std::ptrdiff_t m_iShotsFired;
		std::ptrdiff_t m_angEyeAngles[2];
		std::ptrdiff_t m_iAccount;
		std::ptrdiff_t m_totalHitsOnServer;
		std::ptrdiff_t m_ArmorValue;
		std::ptrdiff_t m_bHasDefuser;
		std::ptrdiff_t m_bIsDefusing;
		std::ptrdiff_t m_bIsGrabbingHostage;
		std::ptrdiff_t m_bIsScoped;
		std::ptrdiff_t m_bGunGameImmunity;
		std::ptrdiff_t m_bIsRescuing;
		std::ptrdiff_t m_bHasHelmet;
		std::ptrdiff_t m_flFlashDuration;
		std::ptrdiff_t m_flFlashMaxAlpha;
		std::ptrdiff_t m_flLowerBodyYawTarget;
	} DT_CSPlayer;

	struct
	{
		std::ptrdiff_t m_iItemDefinitionIndex;
		std::ptrdiff_t m_iItemIDHigh;
		std::ptrdiff_t m_iAccountID;
		std::ptrdiff_t m_iEntityQuality;
		std::ptrdiff_t m_szCustomName;
		std::ptrdiff_t m_nFallbackPaintKit;
		std::ptrdiff_t m_nFallbackSeed;
		std::ptrdiff_t m_flFallbackWear;
		std::ptrdiff_t m_nFallbackStatTrak;
	} DT_BaseAttributableItem;

	struct
	{
		std::ptrdiff_t m_nModelIndex;
		std::ptrdiff_t m_hWeapon;
		std::ptrdiff_t m_hOwner;
	} DT_BaseViewModel;

	struct
	{
		std::ptrdiff_t m_bReloadVisuallyComplete;
		std::ptrdiff_t m_fAccuracyPenalty;
	} DT_WeaponCSBase;

	struct
	{
		std::ptrdiff_t m_bRedraw;
		std::ptrdiff_t m_bIsHeldByPlayer;
		std::ptrdiff_t m_bPinPulled;
		std::ptrdiff_t m_fThrowTime;
		std::ptrdiff_t m_bLoopingSoundPlaying;
		std::ptrdiff_t m_flThrowStrength;
	} DT_BaseCSGrenade;

	struct
	{
		std::ptrdiff_t m_flNextPrimaryAttack;
		std::ptrdiff_t m_hOwner;
		std::ptrdiff_t m_iClip1;
		std::ptrdiff_t m_bInReload;
	} DT_BaseCombatWeapon;

	struct
	{
		std::ptrdiff_t m_bShouldGlow;
	} DT_DynamicProp;
};

namespace Offsets
{
	void GetOffsets();
}

extern COffsets offsets;
