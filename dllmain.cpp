// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "mem.h"
#include "proc.h"
#include "cons.h"
#include "hack.h"
#include "offset.h"
#include "debug.h"

#define ESC "\x1b"
#define CSI "\x1b["

using namespace Hack;
using namespace offset;

DWORD WINAPI HackThread(HMODULE hModule)
{


     // Get moduleBase
    // uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");
    moduleBase = get_moduleBase();

    bool bHealth = false, bAmmo = false, bArmor = false, bRecoil = false;


    const typedef char* (__fastcall* _ACPrintF)(const char* stringFormat, ...);
    _ACPrintF acprintf;

    acprintf = (_ACPrintF)(chatMessage);

    

    //std::cout << cblue.color << " value: " << chatHook(cblue) << "\n";
    //std::cout << cgold.color << " value: " << chatHook(cgold) <<  "\n\n";
    
    

    // chatCall :D
    acprintf(chatCall(blue).c_str(), "", "I AM GOD!");
    acprintf(chatCall(gold).c_str(), "", "BOW DOWN TO ME");
    acprintf(chatCall(pink).c_str(), "", "PEASANT FUCKS");


    // Hack loop
    while (true)
    {

        // Key input

        if (GetAsyncKeyState(VK_DELETE) & 1)
        {
            Sleep(250);
            break;
        }

        if (GetAsyncKeyState(VK_F1) & 1)
        {
            bHealth = !bHealth;
        }

        if (GetAsyncKeyState(VK_F2) & 1)
        {
            bAmmo = !bAmmo;
        }

        if (GetAsyncKeyState(VK_F3) & 1)
        {
            bArmor = !bArmor;
        }

        if (GetAsyncKeyState(VK_F4) & 1)
        {
            bRecoil = !bRecoil;

            if (bRecoil)
            {
                // ret 8; returns call immediately at first line of function
                mem::Patch((BYTE*)(recoil), (BYTE*)"\xC2\x08\x00", 3);
            }
            else
            {
                // write back original instructions
                mem::Patch((BYTE*)(recoil), (BYTE*)"\x83\xEC\x28", 3);
            }
        }


        // Continuous write
        uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + 0x17E0A8);

        if (localPlayerPtr)
        {
            if (bHealth)
            {
                *(int*)(health) = 777;
            }
            if (bAmmo)
            {
                *(int*)(heldWeaponAmmo) = 100;

            }
            if (bArmor)
            {

            }
        }
        Sleep(5);

    }


    // Cleanup & eject
    acprintf(chatCall(red).c_str(), "", "unloading hack, bye bye!");
    Sleep(50);
    debug(true);
    Sleep(200);
    FreeLibraryAndExitThread(hModule, 0);
    return 0;

}



BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
