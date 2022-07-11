#include "include.h"

DWORD LocalPlayer::Get()
{
	Engine E;
	return *(DWORD*)(Global_GameModule + dwLocalPlayer);
}

int LocalPlayer::GetHealth()
{
	DWORD Player = Get();
	if (Player)
		return *(int*)(Player + m_iHealth);
	return -1;

}

int LocalPlayer::GetTeam()
{
	DWORD Player = Get();
	if (Player)
		return *(int*)(Player + m_iTeamNum);
	return -1;

}

int LocalPlayer::CrosshairID()
{
	DWORD Player = Get();
	if (Player)
		return *(int*)(Player + m_iCrosshairId);
	return -1;

}

bool LocalPlayer::Exists()
{
	Engine E;
	if (*(DWORD*)(Global_GameModule + dwLocalPlayer))
		return true;
	return false;
}

void LocalPlayer::ForceJump()
{
	Engine E;
	*(DWORD*)(Global_GameModule + dwForceJump) = 6;
}

void LocalPlayer::ForceAttack()
{
	*(int*)(Global_GameModule + dwForceAttack) = 5;
}

void LocalPlayer::StopAttack()
{
	*(int*)(Global_GameModule + dwForceAttack) = 4;
}

void LocalPlayer::SetViewAngels(Vector3 Input)
{
	Input.Normalize();
	Vector3* ViewAngels = (Vector3*)(*(DWORD*)(Global_EngineModule + dwClientState) + dwClientState_ViewAngles);
	*ViewAngels = Input;
}

Vector3 LocalPlayer::GetViewAngels()
{
	Vector3* ViewAngels = (Vector3*)(*(DWORD*)(Global_EngineModule + dwClientState) + dwClientState_ViewAngles);
	return *ViewAngels;
}