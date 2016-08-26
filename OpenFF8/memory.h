#pragma once

#include "stdafx.h"
#include "structures.h"

#pragma pack(push, 1)
struct FF8Vars {
	Kernel* kernel = (Kernel*)0x1CF3E48;
	//0x1CFDC58 - save game start
	DWORD* timer = (DWORD*)0x1CFE92C;
	BYTE* ptr1CFE97A = (BYTE*)0x1CFE97A; //odin byte
	BYTE* chocobo_world_flags = (BYTE*)0x1CFEFB8;
	BYTE* boko_attack = (BYTE*)0x1CFEFE5;
	//end of save data
	//0x1CFF000 - character data start
	CharacterData char_data;
	//0x1CFF570 - character data end
	WORD* encounter_id = (WORD*)0x1CFF6E0;
	WORD* battle_flags = (WORD*)0x1CFF6E2;
	//BYTE* current_attack_flagsA = (BYTE*)0x1D27ADC;
	Character* character_info = (Character*)0x1D27B10; //208 byte structure
	BYTE* attack_queue_count = (BYTE*)0x1D280C0;
	MagicData* attack_queue_data = (MagicData*)0x1D280C4;
	DWORD* ptr1D287E0 = (DWORD*)0x1D287E0; //used in func 0x48BA10
	BYTE* ptr1D28814 = (BYTE*)0x1D28814; //used in func 0x48BA10, array of 8?
	BYTE* ptr1D28854 = (BYTE*)0x1D28854; //used in func 0x48BA10, array of 8?
	BYTE* ptr1D2885C = (BYTE*)0x1D2885C; //used in func 0x48BA10, array of 8?
	DWORD* battle_vars = (DWORD*)0x1D28D98; //- 60 to 67 - base address used is 0x1D28C18 - array of size 8
	BYTE** current_battle_message = (BYTE**)0x1D28DDC;
	WORD* dead_timer = (WORD*)0x1D28DE4;
	BYTE* unkbyte1D28DF7 = (BYTE*)0x1D28DF7;
	BYTE* ptr1D28DFA = (BYTE*)0x1D28DFA;
	BYTE* ptr1D28DFB = (BYTE*)0x1D28DFB; //used in opcode 0x04 case 0xD1
	BYTE* unkbyte1D28E00 = (BYTE*)0x1D28E00;
	BYTE* ptr1D28E06 = (BYTE*)0x1D28E06;
	bool* init_done = (bool*)0x1D28E09;
	//BYTE* current_attack_flags = (BYTE*)0x1D28E0E;
	BYTE* unkbyte1D28E21 = (BYTE*)0x1D28E21;
	BYTE* ptr1D28E2D = (BYTE*)0x1D28E2D;
	unk1D28E83* monster_info = (unk1D28E83*)0x1D28E83; //71 byte structure
	BYTE* ptr1D2A228 = (BYTE*)0x1D2A228;
	DWORD* ptr1D2A230 = (DWORD*)0x1D2A230;
	DWORD* current_attack_status_dword = (DWORD*)0x1D2A234;
	BYTE* current_attack_param = (BYTE*)0x1D2A238;
	BYTE* current_status_attack = (BYTE*)0x1D2A239;
	WORD* current_attack_status_word = (WORD*)0x1D2A23E;
	BYTE* current_attack_element_percent = (BYTE*)0x1D2A241;
	BYTE* current_attack_element = (BYTE*)0x1D2A244;
	BYTE* countdown_enabled = (BYTE*)0x1D2B813;
	BYTE** current_character_commands = (BYTE**)0x1D76834;
	BYTE** current_character_limit_break = (BYTE**)0x1D76838;
	BYTE* current_active_character_id = (BYTE*)0x1D76844;
	BYTE* new_active_character_id = (BYTE*)0x1D76845;
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
	BYTE* current_entity = (BYTE*)0x1D9CDF1;
	FieldEntity** entity_other = (FieldEntity**)0x1D9CF88;
	FieldEntity** entity_background = (FieldEntity**)0x1D9CF8C;
	FieldEntity** entity_door = (FieldEntity**)0x1D9CF90;
	BYTE* entity_count_other = (BYTE*)0x1D9D019;
	BYTE* entity_count_line = (BYTE*)0x1D9D0E0;
	BYTE* entity_count_door = (BYTE*)0x1D9D0E1;
	BYTE* entity_count_background = (BYTE*)0x1D9D0E8;
	FieldEntity** entity_line = (FieldEntity**)0x1D9D0F0;
	TaskList*(**current_magic_init_function)(MagicIDInitData& init_data) = (TaskList*(**)(MagicIDInitData&))0x21DFEC4;
};

struct FF8Funcs {
	int(*InitializeSound_CAL)() = (int(*)())0x46B440;
	void(*Sub47E3F0)(DWORD, DWORD, void(*)()) = (void(*)(DWORD, DWORD, void(*)()))0x47E3F0;
	void(*SetGFExists)(int GF_id) = (void(*)(int))0x47E480;
	BYTE*(*GetDuelName)(int id) = (BYTE*(*)(int))0x47E530;
	BYTE*(*GetDuelDescription)(int id) = (BYTE*(*)(int))0x47E560;
	BYTE*(*GetShotName)(int id) = (BYTE*(*)(int))0x47E590;
	BYTE*(*GetShotDescription)(int id) = (BYTE*(*)(int))0x47E5C0;
	BYTE*(*GetRenzokukenFinisherName)(int id) = (BYTE*(*)(int))0x47E5F0;
	BYTE*(*GetRenzokukenFinisherDescription)(int id) = (BYTE*(*)(int))0x47E620;
	BYTE*(*GetBlueMagicName)(int id) = (BYTE*(*)(int))0x47E650;
	BYTE*(*GetBlueMagicDescription)(int id) = (BYTE*(*)(int))0x47E680;
	BYTE*(*GetTempCharLimitName)(int id) = (BYTE*(*)(int))0x47E6B0;
	BYTE*(*GetTempCharLimitDescription)(int id) = (BYTE*(*)(int))0x47E6E0;
	BYTE*(*GetGFAbilityName)(int id) = (BYTE*(*)(int))0x47E710;
	BYTE*(*GetGFAbilityDescription)(int id) = (BYTE*(*)(int))0x47E840;
	BYTE*(*GetMagicName)(int id) = (BYTE*(*)(int))0x47E970;
	BYTE*(*GetMagicDescription)(int id) = (BYTE*(*)(int))0x47E9C0;
	BYTE*(*GetItemName)(int id) = (BYTE*(*)(int))0x47EA30;
	BYTE*(*GetItemDescription)(int id) = (BYTE*(*)(int))0x47EA90;
	//character name functions here
	BYTE*(*GetWeaponName)(int id) = (BYTE*(*)(int))0x47EBA0;
	BYTE*(*GetCommandName)(int id) = (BYTE*(*)(int))0x47EBD0;
	BYTE*(*GetCommandDescription)(int id) = (BYTE*(*)(int))0x47EC00;
	BYTE*(*GetMiscText)(int id) = (BYTE*(*)(int))0x47EC70;
	BYTE(*CanStoreMagic)(int char_id, int magic_id) = (BYTE(*)(int, int))0x47ED90;
	bool(*IsMagicJunctioned)(int party_member_id, int magic_id) = (bool(*)(int, int))0x47EEB0;
	void(*Sub482C90)(void(*)()) = (void(*)(void(*)()))0x482C90; //Used in opcode 0x1C and 0x20
	void(*DeadTimeReset)() = (void(*)())0x482F70;
	void(*DeadTimeTick)() = (void(*)())0x482F80;
	void(*SetMaxATB)(DWORD id) = (void(*)(DWORD))0x484490;
	void(*SetStartATB)(DWORD id) = (void(*)(DWORD))0x4844D0;
	int(*CountValidTargets)() = (int(*)())0x4860A0; //0xFF if no valid targets - counts SeeDs in battle
	void(*DoMonsterTurn)(int id, int unk) = (void(*)(int, int))0x4877F0;
	bool(*HasBattleItem)(int id) = (bool(*)(int))0x487D80;
	bool(*UseBattleItem)(int unk1, int id) = (bool(*)(int, int))0x487DB0;
	void(*Sub48ACD0)() = (void(*)())0x48ACD0;
	void(*SetKnownMagic)(int magic_id) = (void(*)(int))0x48B7A0;
	void(*InitMonster)(DWORD id, DWORD unk1, DWORD unk2) = (void(*)(DWORD, DWORD, DWORD))0x48BBD0;
	void(*GetMonsterStats)(DWORD id) = (void(*)(DWORD))0x48C1C0;
	int(*GetMonsterStat)(int level, BYTE *datfile, int stat) = (int(*)(int, BYTE*, int))0x48C3F0;
	int(*GetItemAmount)(int item_id) = (int(*)(int))0x48CCB0;
	int(*LoadAttack)(DWORD caster_id, DWORD kernel_id, DWORD id, DWORD unk1, DWORD unk2, DWORD target_mask, DWORD unk3) = (int(*)(DWORD, DWORD, DWORD, DWORD, DWORD, DWORD, DWORD))0x48D200;
	BYTE(*Rand)() = (BYTE(*)())0x48F020;
	BYTE(*Rand1toX)(BYTE max) = (BYTE(*)(BYTE))0x48F120;
	int(*CureStatus)(int target_id, int spell_power, int status_word, int status_dword) = (int(*)(int, int, int, int))0x491820;
	int(*DoMagicDamage)(int caster_id, int target_id, int attack_power, int magic_attack_type) = (int(*)(int, int, int, int))0x491AD0;
	BYTE(*InflictStatuses)(int caster_id, int target_id, int damage_type) = (BYTE(*)(int, int, int))0x492090;
	int(*DoDamage)(int attack_type, int caster_id, int target_id, int attack_power) = (int(*)(int, int, int, int))0x4922B0;
	void(*SetEnemyScannedOnce)(int enemy_id) = (void(*)(int))0x493810;
	void(*UpdateCrisisLevel)(int char_id) = (void(*)(int))0x4941F0;
	BYTE*(*GetNonJGFAttackName)(int id) = (BYTE*(*)(int))0x495050;
	BYTE*(*GetGFAttackName)(int id) = (BYTE*(*)(int))0x495070;
	BYTE*(*GetEnemyAttackName)(int id) = (BYTE*(*)(int))0x4950A0;
	int(*GetCharacterHP)(int lvl, int char_id) = (int(*)(int, int))0x496310;
	int(*GetCharacterStat)(int lvl, int char_id, int stat) = (int(*)(int, int, int))0x496440;
	int(*GetCharacterHit)(int char_id) = (int(*)(int))0x4967C0;
	int(*GetCharacterEva)(int char_id, int unk1) = (int(*)(int, int))0x4968A0;
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
	void(*UpdateFieldEntities)(int unk1) = (void(*)(int))0x529FF0;
	void(*InitFieldEntities)() = (void(*)())0x52C650;
	int(*GetDrawPointStatus)(int id) = (int(*)(int))0x52D150;
	int(*GetDrawPointMagic)(int id) = (int(*)(int))0x52D1E0;
	void(*Sub56DCE0)(BYTE unk1, WORD unk2) = (void(*)(BYTE, WORD))0x56DCE0;
	TaskList*(*Mag002_Fire_Init)(MagicIDInitData* init_data) = (TaskList*(*)(MagicIDInitData*))0x6298A0;
	int(*Mag002_Fire_B)(LinkTask& task_data) = (int(*)(LinkTask&))0x629990;
	int(*Mag002_Fire_C)(LinkTask& task_data) = (int(*)(LinkTask&))0x62A380;
	int(*Mag002_Fire_A)(LinkTask& task_data) = (int(*)(LinkTask&))0x62A610;
};

extern FF8Vars ff8vars;
extern FF8Funcs ff8funcs;
#pragma pack(pop)