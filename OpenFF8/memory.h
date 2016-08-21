#pragma once

#include "stdafx.h"
#include "structures.h"

#pragma pack(push, 1)
struct FF8Vars {
	//0x1CFDC48
	DWORD* timer = (DWORD*)0x1CFE92C;
	BYTE* ptr1CFE97A = (BYTE*)0x1CFE97A; //odin byte
	WORD* ptr1CFF6E2 = (WORD*)0x1CFF6E2;
	BYTE* ptr1D27ADC = (BYTE*)0x1D27ADC;
	Character* character_info = (Character*)0x1D27B10; //208 byte structure
	DWORD* ptr1D287E0 = (DWORD*)0x1D287E0; //used in func 0x48BA10
	BYTE* ptr1D28814 = (BYTE*)0x1D28814; //used in func 0x48BA10, array of 8?
	BYTE* ptr1D28854 = (BYTE*)0x1D28854; //used in func 0x48BA10, array of 8?
	BYTE* ptr1D2885C = (BYTE*)0x1D2885C; //used in func 0x48BA10, array of 8?
	DWORD* battle_vars = (DWORD*)0x1D28D98; //- 60 to 67 - base address used is 0x1D28C18 - array of size 8
	BYTE* ptr1D28DFA = (BYTE*)0x1D28DFA;
	BYTE* ptr1D28DFB = (BYTE*)0x1D28DFB; //used in opcode 0x04 case 0xD1
	BYTE* ptr1D28E06 = (BYTE*)0x1D28E06;
	bool* init_done = (bool*)0x1D28E09;
	BYTE* ptr1D28E2D = (BYTE*)0x1D28E2D;
	unk1D28E83* monster_info = (unk1D28E83*)0x1D28E83; //71 byte structure
	BYTE* ptr1D2A228 = (BYTE*)0x1D2A228;
	DWORD* ptr1D2A230 = (DWORD*)0x1D2A230;
	TaskList** unktasklist1D96A8C = (TaskList**)0x1D96A8C;
	TaskList** unktasklist1D96A94 = (TaskList**)0x1D96A94;
	TaskList** unktasklist1D96AA0 = (TaskList**)0x1D96AA0;
	TaskList** unktasklist1D96AA4 = (TaskList**)0x1D96AA4;
	TaskList** unktasklist1D96AA8 = (TaskList**)0x1D96AA8;
	TaskList** current_magic_task_list = (TaskList**)0x1D96AAC;
};

struct FF8Funcs {
	void(*Sub47E3F0)(DWORD, DWORD, void(*)()) = (void(*)(DWORD, DWORD, void(*)()))0x47E3F0;
	void(*Sub482C90)(void(*)()) = (void(*)(void(*)()))0x482C90; //Used in opcode 0x1C and 0x20
	void(*SetMaxATB)(DWORD id) = (void(*)(DWORD))0x484490;
	void(*SetStartATB)(DWORD id) = (void(*)(DWORD))0x4844D0;
	int(*CountValidTargets)() = (int(*)())0x4860A0; //0xFF if no valid targets - counts SeeDs in battle
	void(*DoMonsterTurn)(int id, int unk) = (void(*)(int, int))0x4877F0;
	void(*Sub48ACD0)() = (void(*)())0x48ACD0;
	void(*ParseMonsterStats)(DWORD id, DWORD unk1, DWORD unk2) = (void(*)(DWORD, DWORD, DWORD))0x48BBD0;
	void(*GetStats)(DWORD id) = (void(*)(DWORD))0x48C1C0;
	int(*GetStat)(int level, BYTE *datfile, int stat) = (int(*)(int, BYTE*, int))0x48C3F0;
	//void(*sub48C5C0)(DWORD) = (void(*))0x48C5C0;
	BYTE(*Rand)() = (BYTE(*)())0x48F020;
	int(*DoMagicDamage)(int caster_id, int target_id, int attack_power, int magic_attack_type) = (int(*)(int, int, int, int))0x491AD0;
	int(*DoDamage)(int attack_type, int caster_id, int target_id, int attack_power) = (int(*)(int, int, int, int))0x4922B0;
	void(*Sub4AD170)(DWORD) = (void(*)(DWORD))0x4AD170;
	void(*BS_Memset)(TaskList* task_list, LinkTask* data_start, int item_size, int item_count) = (void(*)(TaskList*, LinkTask*, int, int))0x508300;
	LinkTask*(*BdLinkTask)(TaskList* task_list, int(*task)(LinkTask* task_data)) = (LinkTask*(*)(TaskList*, int(*)(LinkTask*)))0x508360;
	LinkTask*(*GetFreeLinkTask)(TaskList* task_list) = (LinkTask*(*)(TaskList*))0x5083C0;
	int(*DoLinkTask)(TaskList* task_list) = (int(*)(TaskList*))0x508420;
	TaskList*(*Mag002_Fire_Init)(MagicIDInitData* init_data) = (TaskList*(*)(MagicIDInitData*))0x6298A0;
	int(*Mag002_Fire_B)(LinkTask* task_data) = (int(*)(LinkTask*))0x629990;
	int(*Mag002_Fire_C)(LinkTask* task_data) = (int(*)(LinkTask*))0x62A380;
	int(*Mag002_Fire_A)(LinkTask* task_data) = (int(*)(LinkTask*))0x62A610;
};

extern FF8Vars ff8vars;
extern FF8Funcs ff8funcs;
#pragma pack(pop)