#pragma once
#include <vector>

namespace offset {

	static uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");
	static uintptr_t* localPlayerPtr = (uintptr_t*)(moduleBase + 0x17E0A8);
	static uintptr_t chatMessage = moduleBase + 0xDAD50;
	static uintptr_t recoil = moduleBase + 0xc8ba0;
	static uintptr_t health = *localPlayerPtr + 0xec;
	static uintptr_t* heldWeapon = (uintptr_t*)(*localPlayerPtr + 0x368);
	static uintptr_t* heldWeaponArray = (uintptr_t*)(*heldWeapon + 0x14);
	static uintptr_t heldWeaponAmmo = *heldWeaponArray + 0x0;


	static uintptr_t get_moduleBase()
	{
		return moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");
	}

}