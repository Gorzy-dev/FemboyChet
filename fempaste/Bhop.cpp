#include "include.h"

DWORD WINAPI BhopThread(HMODULE hMod)
{
	LocalPlayer LP;
	while (!GetAsyncKeyState(UNINJECT_KB))
	{

		LocalPlayer LP;
		if (LP.Exists() && UserSettings.EnableBhop)
		{
			DWORD flag = *(BYTE*)(LP.Get() + m_fFlags);
			if (GetAsyncKeyState(VK_SPACE) && flag & (1 << 0))
			{
				LP.ForceJump();
			}
		}
	}
	FreeLibraryAndExitThread(hMod, 0);
}