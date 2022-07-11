#include "include.h"

DWORD WINAPI RecoilThread(HMODULE hMod)
{
    LocalPlayer L;
    DWORD localplayer = L.Get();
    Vector3 OldPunch{ 0, 0, 0 };



    int* ShotsFired;
    Vector3* RecoilPunch;
    Vector3 PunchAngle;
    Vector3 Angle;

    while (!GetAsyncKeyState(UNINJECT_KB))
    {
        if (UserSettings.EnableRecoilControl)
        {
            if (localplayer)
            {
                
                ShotsFired = (int*)(localplayer + m_iShotsFired);
                RecoilPunch = (Vector3*)(localplayer + m_aimPunchAngle);
                PunchAngle = *RecoilPunch * (UserSettings.RecoilControlAmount * 2);

                if (*ShotsFired > 1 && GetAsyncKeyState(VK_LBUTTON))
                {
                    Angle = L.GetViewAngels() + OldPunch - PunchAngle;
                    L.SetViewAngels(Angle);
                }
               
                OldPunch = PunchAngle;
                
            }
            else
            {
                localplayer = L.Get();
            }
        }
    }
    FreeLibraryAndExitThread(hMod, 0);
}