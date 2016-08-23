#pragma once

#include "stdafx.h"
#include "structures.h"

#pragma pack(push, 1)
struct FF8Vars {
	Kernel* kernel = (Kernel*)0x1CF3E48;
	//0x1CFDC48
	DWORD* timer = (DWORD*)0x1CFE92C; //in save game
	BYTE* ptr1CFE97A = (BYTE*)0x1CFE97A; //odin byte
	BYTE* chocobo_attacks = (BYTE*)0x1CFEFB8;
	BYTE* unkbyte1CFEFE5 = (BYTE*)0x1CFEFE5;
	WORD* ptr1CFF6E2 = (WORD*)0x1CFF6E2;
	BYTE* ptr1D27ADC = (BYTE*)0x1D27ADC;
	Character* character_info = (Character*)0x1D27B10; //208 byte structure
	BYTE* attack_queue_count = (BYTE*)0x1D280C0;
	MagicData* attack_queue_data = (MagicData*)0x1D280C4;
	DWORD* ptr1D287E0 = (DWORD*)0x1D287E0; //used in func 0x48BA10
	BYTE* ptr1D28814 = (BYTE*)0x1D28814; //used in func 0x48BA10, array of 8?
	BYTE* ptr1D28854 = (BYTE*)0x1D28854; //used in func 0x48BA10, array of 8?
	BYTE* ptr1D2885C = (BYTE*)0x1D2885C; //used in func 0x48BA10, array of 8?
	DWORD* battle_vars = (DWORD*)0x1D28D98; //- 60 to 67 - base address used is 0x1D28C18 - array of size 8
	BYTE* unkbyte1D28DF7 = (BYTE*)0x1D28DF7;
	BYTE* ptr1D28DFA = (BYTE*)0x1D28DFA;
	BYTE* ptr1D28DFB = (BYTE*)0x1D28DFB; //used in opcode 0x04 case 0xD1
	BYTE* unkbyte1D28E00 = (BYTE*)0x1D28E00;
	BYTE* ptr1D28E06 = (BYTE*)0x1D28E06;
	bool* init_done = (bool*)0x1D28E09;
	BYTE* unkbyte1D28E21 = (BYTE*)unkbyte1D28E21;
	BYTE* ptr1D28E2D = (BYTE*)0x1D28E2D;
	unk1D28E83* monster_info = (unk1D28E83*)0x1D28E83; //71 byte structure
	BYTE* ptr1D2A228 = (BYTE*)0x1D2A228;
	DWORD* ptr1D2A230 = (DWORD*)0x1D2A230;
	TaskList** unktasklist1D96A8C = (TaskList**)0x1D96A8C; //animation sequence
	BYTE* unkbyte1D96A90 = (BYTE*)0x1D96A90;
	TaskList** unktasklist1D96A94 = (TaskList**)0x1D96A94;
	DWORD* unkdword1D96A9C = (DWORD*)0x1D96A9C;
	TaskList** unktasklist1D96AA0 = (TaskList**)0x1D96AA0;
	TaskList** unktasklist1D96AA4 = (TaskList**)0x1D96AA4;
	TaskList** unktasklist1D96AA8 = (TaskList**)0x1D96AA8;
	TaskList** current_magic_task_list = (TaskList**)0x1D96AAC;
	BYTE* unkbyte1D97718 = (BYTE*)0x1D97718;
	int* unkdword1D999C8 = (int*)0x1D999C8;
	UnkStruct1D99A40** unkstruct1D99A40 = (UnkStruct1D99A40**)0x1D99A40;
	MagicData** magic_data_ptr = (MagicData**)0x1D99A50;
	WORD* unkword1D99A5C = (WORD*)0x1D99A5C; //could be dword
	MagicIDInitData* current_magic_init_data = (MagicIDInitData*)0x1D99A78;
	BYTE* unkbyte1D99A79 = (BYTE*)0x1D99A79;
	BYTE* unkbyte1D99A80 = (BYTE*)0x1D99A80;
	BYTE* unkbyte1D99A84 = (BYTE*)0x1D99A84;
	BYTE* unkbyte1D99A85 = (BYTE*)0x1D99A85;
	WORD* unkword1D99A8E = (WORD*)0x1D99A8E;
	WORD* unkword1D99A90 = (WORD*)0x1D99A90;
	BYTE* unkbyte1D99AAA = (BYTE*)0x1D99AAA;
	TaskList*(**current_magic_init_function)(MagicIDInitData& init_data) = (TaskList*(**)(MagicIDInitData&))0x21DFEC4;
};

struct FF8Funcs {
	int(*InitializeSound_CAL)() = (int(*)())0x46B440;
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
	int(*LoadAttack)(DWORD caster_id, DWORD kernel_id, DWORD id, DWORD unk1, DWORD unk2, DWORD target_mask, DWORD unk3) = (int(*)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD))0x48D200;
	//void(*sub48C5C0)(DWORD) = (void(*))0x48C5C0;
	BYTE(*Rand)() = (BYTE(*)())0x48F020;
	int(*DoMagicDamage)(int caster_id, int target_id, int attack_power, int magic_attack_type) = (int(*)(int, int, int, int))0x491AD0;
	int(*DoDamage)(int attack_type, int caster_id, int target_id, int attack_power) = (int(*)(int, int, int, int))0x4922B0;
	void(*Sub4AD170)(DWORD) = (void(*)(DWORD))0x4AD170;
	void(*Sub505C00)(UnkStruct1D99A40& unk1, BYTE attack_type) = (void(*)(UnkStruct1D99A40&, BYTE))0x505C00;
	BYTE(*CameraRelated)(MagicData& magic_data, WORD unk2) = (BYTE(*)(MagicData&, WORD))0x505F00;
	void(*Sub506190)(MagicData& magic_data, BYTE unk1) = (void(*)(MagicData&, BYTE))0x506190;
	LinkTask*(*Sub506C10)(int(*)(LinkTask&)) = (LinkTask*(*)(int(*)(LinkTask&)))0x506C10;
	void(*BS_Memset)(TaskList* task_list, LinkTask* data_start, int item_size, int item_count) = (void(*)(TaskList*, LinkTask*, int, int))0x508300;
	LinkTask*(*BdLinkTask)(TaskList& task_list, int(*task)(LinkTask& task_data)) = (LinkTask*(*)(TaskList&, int(*)(LinkTask&)))0x508360;
	LinkTask*(*GetFreeLinkTask)(const TaskList& task_list) = (LinkTask*(*)(const TaskList&))0x5083C0;
	int(*DoLinkTask)(TaskList& task_list) = (int(*)(TaskList&))0x508420;
	int(*Sub508580)(int unk1, int unk2) = (int(*)(int, int))0x508580;
	int(*PlayMagic)(LinkTask& task_data) = (int(*)(LinkTask&))0x50A9A0;
	int(*Sub50ADE0)() = (int(*)())0x50ADE0;
	int(*Sub50AE80)() = (int(*)())0x50AE80;
	int(*Sub50AED0)() = (int(*)())0x50AED0;
	void(*LoadMagicID)(WORD magic_id, TaskList*(**unk1)(MagicIDInitData& init_data)) = (void(*)(WORD, TaskList*(**)(MagicIDInitData&)))0x50AF20;
	void(*Sub50AFC0)() = (void(*)())0x50AFC0;
	int(*Sub50B080)(LinkTask& task_data) = (int(*)(LinkTask&))0x50B080;
	void(*Sub56DCE0)(BYTE unk1, WORD unk2) = (void(*)(BYTE, WORD))0x56DCE0;
	TaskList*(*Mag002_Fire_Init)(MagicIDInitData* init_data) = (TaskList*(*)(MagicIDInitData*))0x6298A0;
	int(*Mag002_Fire_B)(LinkTask& task_data) = (int(*)(LinkTask&))0x629990;
	int(*Mag002_Fire_C)(LinkTask& task_data) = (int(*)(LinkTask&))0x62A380;
	int(*Mag002_Fire_A)(LinkTask& task_data) = (int(*)(LinkTask&))0x62A610;
};

extern FF8Vars ff8vars;
extern FF8Funcs ff8funcs;
#pragma pack(pop)