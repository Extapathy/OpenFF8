// OpenFF8.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "OpenFF8.h"
#include "structures.h"
#include "memory.h"
#include "battle.h"
#include <unordered_map>

#define SIZE 6
#define VERSION 0
std::unordered_map<DWORD, BYTE*> original_function_bytes;

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
	BeginRedirect(ff8funcs.BdLinkTask, BdLinkTask);
	BeginRedirect(ff8funcs.GetFreeLinkTask, GetFreeLinkTask);
	BeginRedirect(ff8funcs.DoLinkTask, DoLinkTask);
	BeginRedirect(ff8funcs.Archive_GetFile, Archive_GetFile);
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