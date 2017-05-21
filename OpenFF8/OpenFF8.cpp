// OpenFF8.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "OpenFF8.h"
#include "structures.h"
#include "memory.h"
#include "battle.h"
#include <unordered_map>
#include "myIDirect3DDevice9.h"

#define SIZE 6
#define VERSION 0

std::unordered_map<DWORD, BYTE*> original_function_bytes;
DWORD(*address)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD);

//TODO add version detection code from Steam module and improve code layout
void PatchAddresses() {
	if (VERSION == 1) {
		DWORD* address = (DWORD*)&ff8funcs;
		for (int i = 0; i < sizeof(ff8funcs) / 4; i++) {
			if (*address >= 0x45B580 && *address <= 0x4974E0) *address -= 0x10;
			else if (*address >= 0x4A1960 && *address <= 0xB5F410) *address -= 0x1B0;
			address++;
		}
		address = (DWORD*)&ff8vars;
		for (int i = 0; i < sizeof(ff8vars) / 4; i++) {
			if (*address >= 0x45B580 && *address <= 0x4974E0) *address -= 0x10;
			else if (*address >= 0x4A1960 && *address <= 0xB5F410) *address -= 0x1B0;
			address++;
		}
	}
}

void PatchFunctions() {
	//This section is for redirecting DirectX
	//DWORD base_address = (DWORD)GetModuleHandle("af3dn.p");
	//ff8vars.direct3d_device_9 = (IDirect3DDevice9**)(base_address + 0x3DC04);
	//ff8vars.direct3d_device_9 = new myIDirect3DDevice9(*ff8vars.direct3d_device_9);

	//address = (DWORD(*)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD))(base_address + 0xF390);

	//REDIRECT(address, DrawPrimitives);
	//REDIRECT(WindowProc);


	REDIRECT(BdLinkTask);
	REDIRECT(GetFreeLinkTask);
	REDIRECT(DoLinkTask);
	REDIRECT(Archive_GetFile);
}

void UnpatchFunctions() {
	//ENDREDIRECT(WindowProc);


	ENDREDIRECT(BdLinkTask);
	ENDREDIRECT(GetFreeLinkTask);
	ENDREDIRECT(DoLinkTask);
	ENDREDIRECT(Archive_GetFile);
}

//TODO tidy code and add unpatch code
void BeginRedirect(LPVOID oldFunction, LPVOID newFunction)
{
	DWORD oldProtect = PAGE_EXECUTE_READWRITE;
	BYTE JMP[SIZE] = { 0xE9, 0x90, 0x90, 0x90, 0x90, 0xC3 };         // 0xE9 = JMP 0x90 = NOP oxC3 = RET
	DWORD JMPSize = ((DWORD)newFunction - (DWORD)oldFunction - 5);  // calculate jump distance
	VirtualProtect(oldFunction, SIZE, PAGE_EXECUTE_READWRITE, &oldProtect);
	original_function_bytes[(DWORD)oldFunction] = new BYTE[SIZE];
	memcpy(original_function_bytes[(DWORD)oldFunction], oldFunction, SIZE);
	memcpy(&JMP[1], &JMPSize, 4);                              // fill the nop's with the jump distance (JMP,distance(4bytes),RET)
	memcpy(oldFunction, JMP, SIZE);                                 // set jump instruction at the beginning of the original function
	VirtualProtect(oldFunction, SIZE, oldProtect, NULL);    // reset protection
}

void EndRedirect(LPVOID function)
{
	DWORD oldProtect = PAGE_EXECUTE_READWRITE;
	VirtualProtect(function, SIZE, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy(function, original_function_bytes[(DWORD)function], SIZE);
	VirtualProtect(function, SIZE, oldProtect, NULL);
	delete(original_function_bytes[(DWORD)function]);
	original_function_bytes.erase((DWORD)function);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_KEYUP:
		//printf("key pressed: %d\n", wParam);
		if (wParam == VK_TAB) {
			((myIDirect3DDevice9*)*ff8vars.direct3d_device_9)->CaptureFrame();
		}
		if (wParam == VK_CONTROL) {
			((myIDirect3DDevice9*)*ff8vars.direct3d_device_9)->wireframe = (((myIDirect3DDevice9*)*ff8vars.direct3d_device_9)->wireframe) ? false : true;
		}
		break;
	}
	LRESULT return_value = CALL_ORIGINAL_RET(WindowProc, (hwnd, uMsg, wParam, lParam));
	return return_value;
}

DWORD DrawPrimitives(DWORD arg1, DWORD arg2, DWORD vertex_data, DWORD arg4, DWORD index_data, DWORD arg6, DWORD arg7, DWORD arg8) {
	/*if (((myIDirect3DDevice9*)*ff8vars.direct3d_device_9)->IsCapturing()) {
		printf("DrawPrimitives(%d, %d, 0x%08X, %d, 0x%08X, %d, 0x%08X, %d)\n", arg1, arg2, vertex_data, arg4, index_data, arg6, arg7, arg8);
	}*/

	EndRedirect(address);
	DWORD return_value = address(arg1, arg2, vertex_data, arg4, index_data, arg6, arg7, arg8);
	BeginRedirect(address, DrawPrimitives);
	return return_value;
}