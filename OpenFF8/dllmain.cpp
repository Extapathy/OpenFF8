// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "OpenFF8.h"
#include <stdio.h>

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		PatchAddresses();
		PatchFunctions();
		//Console seems to cause instability, so I've disabled it for now
		//AllocConsole();
		//freopen("CONOUT$", "w", stdout);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

