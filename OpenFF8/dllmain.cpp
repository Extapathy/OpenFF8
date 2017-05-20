// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "OpenFF8.h"
#include <stdio.h>

HMODULE dll;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		dll = hModule;
		PatchAddresses();
		PatchFunctions();
		//Console seems to cause instability, so I've disabled it for now
		//AllocConsole();
		freopen("CONOUT$", "w", stdout);
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		UnpatchFunctions();
		//Console seems to cause instability, so I've disabled it for now
		//FreeConsole();
		break;
	}
	return TRUE;
}

extern "C" __declspec(dllexport) void UnloadDll() {
	FreeLibraryAndExitThread(dll, 0);
}