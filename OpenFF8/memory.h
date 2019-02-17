#pragma once

#include "stdafx.h"
#include "structures.h"

#define FF8_VAR(address, varType, varName) \
  varType& varName = *(varType*)address;

#define FF8_FUNC_PTR(address, functionName, argDef, retType) \
  retType(*&functionName) argDef = *(retType(**) argDef ) address;

#define FF8_FUNCTION(address, functionName, argDef) \
  void(*functionName)argDef = (void(*)argDef) address;

#define FF8_FUNC_RET(address, functionName, argDef, retType) \
  retType (*functionName)argDef = (retType (*)argDef) address;

#pragma pack(push, 1)
struct FF8Vars {
	FF8_VAR(0x1CE476A, short, unkword1CE476A);
	FF8_VAR(0x1CE48A0, DWORD, keyspressed2);
	FF8_VAR(0x1CE48A8, DWORD, enabledkeys2);
	FF8_VAR(0x1CE48B0, DWORD, keyspressed1);
	FF8_VAR(0x1CE48B8, DWORD, enabledkeys1);
	FF8_VAR(0x1CF3E48, Kernel, kernel);
	//0x1CFDC58 - save game start - TODO: use save game struct here
	SaveGame* saveGame = (SaveGame*)0x1CFDC58;
	DWORD* timer = (DWORD*)0x1CFE92C;
	BYTE* ptr1CFE97A = (BYTE*)0x1CFE97A; //odin byte
	BYTE* chocobo_world_flags = (BYTE*)0x1CFEFB8;
	BYTE* boko_attack = (BYTE*)0x1CFEFE5;
	//end of save data
	//0x1CFF000 - character data start
	//CharacterData char_data;
	//0x1CFF570 - character data end
	FF8_VAR(0x1CFF6E0, WORD, encounter_id);
	FF8_VAR(0x1CFF6E2, WORD, battle_flags);
	//BYTE* current_attack_flagsA = (BYTE*)0x1D27ADC;
	FF8_VAR(0x1D27B10, Character, character_info); //208 byte structure
	FF8_VAR(0x1D280C0, BYTE, attack_queue_count);
	FF8_VAR(0x1D280C4, MagicData, attack_queue_data);
	FF8_VAR(0x1D287E0, DWORD, ptr1D287E0); //used in func 0x48BA10
	FF8_VAR(0x1D28814, BYTE, ptr1D28814); //used in func 0x48BA10, array of 8?
	FF8_VAR(0x1D28854, BYTE, ptr1D28854); //used in func 0x48BA10, array of 8?
	FF8_VAR(0x1D2885C, BYTE, ptr1D2885C); //used in func 0x48BA10, array of 8?
	FF8_VAR(0x1D28D98, DWORD, battle_vars); //- 60 to 67 - base address used is 0x1D28C18 - array of size 8
	FF8_VAR(0x1D28DDC, BYTE*, current_battle_message);
	FF8_VAR(0x1D28DE4, WORD, dead_timer);
	FF8_VAR(0x1D28DF7, BYTE, unkbyte1D28DF7);
	FF8_VAR(0x1D28DFA, BYTE, ptr1D28DFA);
	FF8_VAR(0x1D28DFB, BYTE, ptr1D28DFB); //used in opcode 0x04 case 0xD1
	FF8_VAR(0x1D28E00, BYTE, unkbyte1D28E00);
	FF8_VAR(0x1D28E06, BYTE, ptr1D28E06);
	FF8_VAR(0x1D28E09, bool, init_done);
	//BYTE* current_attack_flags = (BYTE*)0x1D28E0E;
	FF8_VAR(0x1D28E21, BYTE, unkbyte1D28E21);
	FF8_VAR(0x1D28E2D, BYTE, ptr1D28E2D);
	FF8_VAR(0x1D28E83, unk1D28E83, monster_info); //71 byte structure
	FF8_VAR(0x1D2A228, BYTE, ptr1D2A228);
	FF8_VAR(0x1D2A230, DWORD, ptr1D2A230);
	FF8_VAR(0x1D2A234, DWORD, current_attack_status_dword);
	FF8_VAR(0x1D2A238, BYTE, current_attack_param);
	FF8_VAR(0x1D2A239, BYTE, current_status_attack);
	FF8_VAR(0x1D2A23E, WORD, current_attack_status_word);
	FF8_VAR(0x1D2A241, BYTE, current_attack_element_percent);
	FF8_VAR(0x1D2A244, BYTE, current_attack_element);
	FF8_VAR(0x1D2B813, BYTE, countdown_enabled);
	FF8_VAR(0x1D76834, BYTE*, current_character_commands);
	FF8_VAR(0x1D76838, BYTE*, current_character_limit_break);
	FF8_VAR(0x1D76844, BYTE, current_active_character_id);
	FF8_VAR(0x1D76845, BYTE, new_active_character_id);
	//0x1D76928 - battle character UI start (array of 3 items)
	FF8_VAR(0x1D76928, BattleCharacterUI, battle_character_ui);
	//0x1D76A6C - battle character UI end
	FF8_VAR(0x1D96A8C, TaskList*, unktasklist1D96A8C); //animation sequence
	FF8_VAR(0x1D96A90, BYTE, unkbyte1D96A90);
	FF8_VAR(0x1D96A94, TaskList*, unktasklist1D96A94);
	FF8_VAR(0x1D96A9C, DWORD, unkdword1D96A9C);
	FF8_VAR(0x1D96AA0, TaskList*, unktasklist1D96AA0);
	FF8_VAR(0x1D96AA4, TaskList*, unktasklist1D96AA4);
	FF8_VAR(0x1D96AA8, TaskList*, unktasklist1D96AA8);
	FF8_VAR(0x1D96AAC, TaskList*, current_magic_task_list);
	FF8_VAR(0x1D97718, BYTE, unkbyte1D97718);
	FF8_VAR(0x1D999C8, int, unkdword1D999C8);
	FF8_VAR(0x1D99A40, UnkStruct1D99A40*, unkstruct1D99A40);
	FF8_VAR(0x1D99A50, MagicData*, magic_data_ptr);
	FF8_VAR(0x1D99A5C, WORD, unkword1D99A5C); //could be dword
	FF8_VAR(0x1D99A78, MagicIDInitData, current_magic_init_data);
	FF8_VAR(0x1D99A79, BYTE, unkbyte1D99A79);
	FF8_VAR(0x1D99A80, BYTE, unkbyte1D99A80);
	FF8_VAR(0x1D99A84, BYTE, unkbyte1D99A84);
	FF8_VAR(0x1D99A85, BYTE, unkbyte1D99A85);
	FF8_VAR(0x1D99A8E, WORD, unkword1D99A8E);
	FF8_VAR(0x1D99A90, WORD, unkword1D99A90);
	FF8_VAR(0x1D99AAA, BYTE, unkbyte1D99AAA);
	FF8_VAR(0x1D9CDC0, DWORD, script_debug);
	FF8_VAR(0x1D9CDF1, BYTE, current_entity);
	FF8_VAR(0x1D9CF88, FieldEntity*, entity_other);
	FF8_VAR(0x1D9CF8C, FieldEntity*, entity_background);
	FF8_VAR(0x1D9CF90, FieldEntity*, entity_door);
	FF8_VAR(0x1D9D019, BYTE, entity_count_other);
	FF8_VAR(0x1D9D020, FieldEntity**, unkfieldentity1D9D020);
	FF8_VAR(0x1D9D0E0, BYTE, entity_count_line);
	FF8_VAR(0x1D9D0E1, BYTE, entity_count_door);
	FF8_VAR(0x1D9D0E8, BYTE, entity_count_background);
	FF8_VAR(0x1D9D0F0, FieldEntity*, entity_line);
	FF8_VAR(0x1DCB340, DWORD*, unkptrarr1DCB340);
	FF8_FUNC_PTR(0x21DFEC4, current_magic_init_function, (MagicIDInitData& init_data), TaskList*);
	IDirect3D9** direct3d_9;// = (IDirect3D9**)0x6C2DC00;
	IDirect3DDevice9** direct3d_device_9;// = (IDirect3DDevice9**)0x6C2DC04;
};

struct FF8Funcs {
	FF8_FUNC_RET(0x40AC5B, WindowProc, (HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam), LRESULT);
	FF8_FUNC_RET(0x46B440, InitializeSound_CAL, (), DWORD);
	FF8_FUNCTION(0x477890, Sub477890, (FieldEntity*));
	FF8_FUNCTION(0x47E3F0, Sub47E3F0, (DWORD, DWORD, void(*)()));
	FF8_FUNCTION(0x47E480, SetGFExists, (int GF_id));
	FF8_FUNC_RET(0x47E530, GetDuelName, (int id), BYTE*);
	FF8_FUNC_RET(0x47E560, GetDuelDescription, (int id), BYTE*);
	FF8_FUNC_RET(0x47E590, GetShotName, (int id), BYTE*);
	FF8_FUNC_RET(0x47E5C0, GetShotDescription, (int id), BYTE*);
	FF8_FUNC_RET(0x47E5F0, GetRenzokukenFinisherName, (int id), BYTE*);
	FF8_FUNC_RET(0x47E620, GetRenzokukenFinisherDescription, (int id), BYTE*);
	FF8_FUNC_RET(0x47E650, GetBlueMagicName , (int id), BYTE*);
	FF8_FUNC_RET(0x47E680, GetBlueMagicDescription, (int id), BYTE*);
	FF8_FUNC_RET(0x47E6B0, GetTempCharLimitName, (int id), BYTE*);
	FF8_FUNC_RET(0x47E6E0, GetTempCharLimitDescription, (int id), BYTE*);
	FF8_FUNC_RET(0x47E710, GetGFAbilityName, (int id), BYTE*);
	FF8_FUNC_RET(0x47E840, GetGFAbilityDescription, (int id), BYTE*);
	FF8_FUNC_RET(0x47E970, GetMagicName, (int id), BYTE*);
	FF8_FUNC_RET(0x47E9C0, GetMagicDescription, (int id), BYTE*);
	FF8_FUNC_RET(0x47EA30, GetItemName, (int id), BYTE*);
	FF8_FUNC_RET(0x47EA90, GetItemDescription, (int id), BYTE*);
	//character name functions here
	FF8_FUNC_RET(0x47EBA0, GetWeaponName, (int id), BYTE*);
	FF8_FUNC_RET(0x47EBD0, GetCommandName, (int id), BYTE*);
	FF8_FUNC_RET(0x47EC00, GetCommandDescription, (int id), BYTE*);
	FF8_FUNC_RET(0x47EC70, GetMiscText, (int id), BYTE*);
	FF8_FUNC_RET(0x47ED90, CanStoreMagic, (int char_id, int magic_id), BYTE);
	FF8_FUNC_RET(0x47EEB0, IsMagicJunctioned, (int party_member_id, int magic_id), BOOL);
	FF8_FUNCTION(0x482C90, Sub482C90, (void(*)())); //Used in opcode 0x1C and 0x20
	FF8_FUNCTION(0x482F70, DeadTimeReset, ());
	FF8_FUNCTION(0x482F80, DeadTimeTick, ());
	FF8_FUNCTION(0x484490, SetMaxATB, (DWORD id));
	FF8_FUNCTION(0x4844D0, SetStartATB, (DWORD id));
	FF8_FUNC_RET(0x4860A0, CountValidTargets, (), DWORD); //0xFF if no valid targets - counts SeeDs in battle
	FF8_FUNCTION(0x4877F0, DoMonsterTurn, (int id, int unk));
	FF8_FUNC_RET(0x487D80, HasBattleItem, (int id), BOOL);
	FF8_FUNC_RET(0x487DB0, UseBattleItem, (int unk1, int id), BOOL);
	FF8_FUNCTION(0x48ACD0, Sub48ACD0, ());
	FF8_FUNCTION(0x48B7A0, SetKnownMagic, (int magic_id));
	FF8_FUNCTION(0x48BBD0, InitMonster, (DWORD id, DWORD unk1, DWORD unk2));
	FF8_FUNCTION(0x48C1C0, GetMonsterStats, (DWORD id));
	FF8_FUNC_RET(0x48C3F0, GetMonsterStat, (int level, BYTE *datfile, int stat), DWORD);
	FF8_FUNC_RET(0x48CCB0, GetItemAmount, (int item_id), DWORD);
	FF8_FUNC_RET(0x48D200, LoadAttack, (DWORD caster_id, DWORD kernel_id, DWORD id, DWORD unk1, DWORD unk2, DWORD target_mask, DWORD unk3), DWORD);
	FF8_FUNC_RET(0x48F020, Rand, (), BYTE);
	FF8_FUNC_RET(0x48F120, Rand1toX, (BYTE max), BYTE);
	FF8_FUNC_RET(0x491820, CureStatus, (int target_id, int spell_power, int status_word, int status_dword), DWORD);
	FF8_FUNC_RET(0x491AD0, DoMagicDamage, (int caster_id, int target_id, int attack_power, int magic_attack_type), DWORD);
	FF8_FUNC_RET(0x492090, InflictStatuses, (int caster_id, int target_id, int damage_type), BYTE);
	FF8_FUNC_RET(0x4922B0, DoDamage, (int attack_type, int caster_id, int target_id, int attack_power), DWORD);
	FF8_FUNCTION(0x493810, SetEnemyScannedOnce, (int enemy_id));
	FF8_FUNCTION(0x4941F0, UpdateCrisisLevel, (int char_id));
	FF8_FUNC_RET(0x495050, GetNonJGFAttackName, (int id), BYTE*);
	FF8_FUNC_RET(0x495070, GetGFAttackName, (int id), BYTE*);
	FF8_FUNC_RET(0x4950A0, GetEnemyAttackName, (int id), BYTE*);
	FF8_FUNC_RET(0x496310, GetCharacterHP, (int lvl, int char_id), DWORD);
	FF8_FUNC_RET(0x496440, GetCharacterStat, (int lvl, int char_id, int stat), DWORD);
	FF8_FUNC_RET(0x4967C0, GetCharacterHit, (int char_id), DWORD);
	FF8_FUNC_RET(0x4968A0, GetCharacterEva, (int char_id, int unk1), DWORD);
	FF8_FUNCTION(0x4AD170, Sub4AD170, (DWORD unk1));
	FF8_FUNCTION(0x505C00, Sub505C00, (UnkStruct1D99A40& unk1, BYTE attack_type));
	FF8_FUNC_RET(0x505F00, CameraRelated, (MagicData& magic_data, WORD unk2), BYTE);
	FF8_FUNCTION(0x506190, Sub506190, (MagicData& magic_data, BYTE unk1));
	FF8_FUNC_RET(0x506C10, Sub506C10, (int(*)(LinkTask&)), LinkTask*);
	FF8_FUNCTION(0x508300, BS_Memset, (TaskList* task_list, LinkTask* data_start, int item_size, int item_count));
	FF8_FUNC_RET(0x508360, BdLinkTask, (TaskList& task_list, int(*task)(LinkTask& task_data)), LinkTask*);
	FF8_FUNC_RET(0x5083C0, GetFreeLinkTask, (const TaskList& task_list), LinkTask*);
	FF8_FUNC_RET(0x508420, DoLinkTask, (TaskList& task_list), DWORD);
	FF8_FUNC_RET(0x508580, Sub508580, (int unk1, int unk2), DWORD);
	FF8_FUNC_RET(0x50A9A0, PlayMagic, (LinkTask& task_data), DWORD);
	FF8_FUNC_RET(0x50ADE0, Sub50ADE0, (), DWORD);
	FF8_FUNC_RET(0x50AE80, Sub50AE80, (), DWORD);
	FF8_FUNC_RET(0x50AED0, Sub50AED0, (), DWORD);
	FF8_FUNCTION(0x50AF20, LoadMagicID, (WORD magic_id, TaskList*(**unk1)(MagicIDInitData& init_data)));
	FF8_FUNCTION(0x50AFC0, Sub50AFC0, ());
	FF8_FUNC_RET(0x50B080, Sub50B080, (LinkTask& task_data), DWORD);
	FF8_FUNC_RET(0x51B4E0, Archive_GetFile, (BYTE* filename), DWORD);
	FF8_FUNCTION(0x529FF0, UpdateFieldEntities, (int unk1));
	FF8_FUNCTION(0x52C650, InitFieldEntities, ());
	FF8_FUNC_RET(0x52D150, GetDrawPointStatus, (int id), DWORD);
	FF8_FUNC_RET(0x52D1E0, GetDrawPointMagic, (int id), DWORD);
	FF8_FUNCTION(0x56DCE0, Sub56DCE0, (BYTE unk1, WORD unk2));
	FF8_FUNC_RET(0x6298A0, Mag002_Fire_Init, (MagicIDInitData* init_data), TaskList*);
	FF8_FUNC_RET(0x629990, Mag002_Fire_B, (LinkTask& task_data), DWORD);
	FF8_FUNC_RET(0x62A380, Mag002_Fire_C, (LinkTask& task_data), DWORD);
	FF8_FUNC_RET(0x62A610, Mag002_Fire_A, (LinkTask& task_data), DWORD);
};

extern FF8Vars ff8vars;
extern FF8Funcs ff8funcs;
#pragma pack(pop)
