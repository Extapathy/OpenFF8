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
	FF8_VAR(0x0B87798, DWORD, unkdword0B87798);
	FF8_VAR(0x1CE476A, short, unkword1CE476A);
	FF8_VAR(0x1CE48A0, DWORD, keyspressed2);
	FF8_VAR(0x1CE48A8, DWORD, enabledkeys2);
	FF8_VAR(0x1CE48B0, DWORD, keyspressed1);
	FF8_VAR(0x1CE48B8, DWORD, enabledkeys1);
	FF8_VAR(0x1CF3E48, Kernel, kernel);
	//0x1CFDC58 - save game start - TODO: use save game struct here
	FF8_VAR(0x1CFDC58, SaveGame, saveGame);
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
	FF8_VAR(0x1D27B0E, BYTE, unkbyte1D27B0E);
	FF8_VAR(0x1D27B10, Character*, character_info); //208 byte structure
	FF8_VAR(0x1D280C0, BYTE, attack_queue_count);
	FF8_VAR(0x1D280C4, MagicData*, attack_queue_data);
	FF8_VAR(0x1D280C2, BYTE, unkbyte1D280C2);
	FF8_VAR(0x1D287E0, DWORD, ptr1D287E0); //used in func 0x48BA10
	FF8_VAR(0x1D28814, BYTE, unkbyte1D28814); //used in func 0x48BA10, array of 8?
	FF8_VAR(0x1D28854, BYTE, unkbyte1D28854); //used in func 0x48BA10, array of 8?
	FF8_VAR(0x1D2885C, BYTE, unkbyte1D2885C); //used in func 0x48BA10, array of 8?
	//0x1D28864 - 3 * struct of size 44 bytes
	FF8_VAR(0x1D28D98, DWORD*, battle_vars); //- 60 to 67 - base address used is 0x1D28C18 - array of size 8
	FF8_VAR(0x1D28DCD, BYTE, unkbyte1D28DCD);
	FF8_VAR(0x1D28DDC, BYTE*, current_battle_message);
	FF8_VAR(0x1D28DE4, WORD, dead_timer);
	FF8_VAR(0x1D28DF6, BYTE, unkbyte1D28DF6);
	FF8_VAR(0x1D28DF7, BYTE, unkbyte1D28DF7);
	FF8_VAR(0x1D28DF9, BYTE, unkbyte1D28DF9);
	FF8_VAR(0x1D28DFA, BYTE, unkbyte1D28DFA);
	FF8_VAR(0x1D28DFB, BYTE, unkbyte1D28DFB); //used in opcode 0x04 case 0xD1
	FF8_VAR(0x1D28DFC, BYTE, unkbyte1D28DFC);
	FF8_VAR(0x1D28DFD, BYTE, unkbyte1D28DFD);
	FF8_VAR(0x1D28E00, BYTE, unkbyte1D28E00);
	FF8_VAR(0x1D28E06, BYTE, unkbyte1D28E06);
	FF8_VAR(0x1D28E09, bool, init_done);
	FF8_VAR(0x1D28E0B, BYTE, unkbyte1D28E0B);
	FF8_VAR(0x1D28E11, BYTE, unkbyte1D28E11);
	FF8_VAR(0x1D28E12, BYTE, unkbyte1D28E12);
	FF8_VAR(0x1D28E13, BYTE, unkbyte1D28E13);
	//BYTE* current_attack_flags = (BYTE*)0x1D28E0E;
	FF8_VAR(0x1D28E21, BYTE, unkbyte1D28E21);
	FF8_VAR(0x1D28E2D, BYTE, ptr1D28E2D);
	FF8_VAR(0x1D28E83, unk1D28E83*, monster_info); //71 byte structure
	FF8_VAR(0x1D2A228, BYTE, ptr1D2A228);
	FF8_VAR(0x1D2A230, DWORD, ptr1D2A230);
	FF8_VAR(0x1D2A234, DWORD, current_attack_status_dword);
	FF8_VAR(0x1D2A238, BYTE, current_attack_param);
	FF8_VAR(0x1D2A239, BYTE, current_status_attack);
	FF8_VAR(0x1D2A23E, WORD, current_attack_status_word);
	FF8_VAR(0x1D2A241, BYTE, current_attack_element_percent);
	FF8_VAR(0x1D2A244, BYTE, current_attack_element);
	FF8_VAR(0x1D2A284, void*, unkptr1D2A284);
	FF8_VAR(0x1D2A288, void*, unkptr1D2A288);
	FF8_VAR(0x1D2B813, BYTE, countdown_enabled);
	FF8_VAR(0x1D2BB88, double, unkdouble1D2BB80);
	FF8_VAR(0x1D2BB88, uint64_t, unkqword1D2BB88);
	FF8_VAR(0x1D2BB90, uint64_t, unkqword1D2BB90);
	FF8_VAR(0x1D2BB98, DWORD, unkdword1D2BB98);
	FF8_VAR(0x1D2BB9C, DWORD, unkdword1D2BB9C);
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
	FF8_VAR(0x209AB50, DWORD, unkdword209AB50);
	FF8_VAR(0x209AB54, DWORD, unkdword209AB54);
	FF8_VAR(0x209AB58, DWORD, unkdword209AB58);
	FF8_FUNC_PTR(0x21DFEC4, current_magic_init_function, (MagicIDInitData& init_data), TaskList*);
	IDirect3D9** direct3d_9;// = (IDirect3D9**)0x6C2DC00;
	IDirect3DDevice9** direct3d_device_9;// = (IDirect3DDevice9**)0x6C2DC04;
};

struct FF8Funcs {
	FF8_FUNCTION(0x409A57, FFSwitchModule, (FFModuleInterface*, void*));
	FF8_FUNCTION(0x409B08, Sub409B08, (BufApp0xC10*));
	FF8_FUNCTION(0x409B25, Sub409B25, (BufApp0xC10*));
	FF8_FUNCTION(0x409B42, Sub409B42, (BufApp0xC10*));
	FF8_FUNC_RET(0x40A04A, FFGetBufferAddress, (), void*);
	FF8_FUNCTION(0x40AA12, FFGetTime, (uint64_t*));
	FF8_FUNC_RET(0x40AC5B, WindowProc, (HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam), LRESULT);
	FF8_FUNCTION(0x416B9A, Sub416B9A, (void*));
	FF8_FUNCTION(0x41DFBA, FFClearViewport, (DWORD, DWORD, DWORD, BufApp0xC10*));
	FF8_FUNCTION(0x41E168, FFSetBGMaterial, (colorBGRA*, BufApp0xC10*));
	FF8_FUNCTION(0x41E947, Sub41E947, (DWORD, BufApp0xC10*));
	FF8_FUNC_RET(0x41E972, FFBeginAndDrawScene, (DWORD, BufApp0xC10*), DWORD);
	FF8_FUNCTION(0x41E99D, Sub41E99D, (BufApp0xC10*));
	FF8_FUNCTION(0x424BF9, Sub424BF9, (void*));
	FF8_FUNCTION(0x43FBE8, Sub43FBE8, (BufApp0xC10*));
	FF8_FUNC_RET(0x45B2E0, IsWindowActive, (), bool);
	FF8_FUNCTION(0x45B450, Sub45B450, ());
	FF8_FUNCTION(0x45B580, Sub45B580, ());
	FF8_FUNCTION(0x4647A0, Sub4647A0, ());
	FF8_FUNC_RET(0x46B440, InitializeSound_CAL, (), DWORD);
	FF8_FUNCTION(0x4701B0, UpdateTimers, ());
	FF8_FUNCTION(0x477890, Sub477890, (FieldEntity*));
	FF8_FUNCTION(0x47D930, Sub47D930, (DWORD, DWORD));
	FF8_FUNCTION(0x47E080, Sub47E080, (DWORD));
	FF8_FUNCTION(0x47E200, Sub47E200, (void(*)()));
	FF8_FUNCTION(0x47E220, Sub47E220, (BYTE*, DWORD, DWORD, DWORD, DWORD));
	FF8_FUNC_RET(0x47E3F0, Sub47E3F0, (DWORD, DWORD, void(*)()), void*);
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
	FF8_FUNC_RET(0x47EAF0, GetCharacterName1, (int id), BYTE*);
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
	FF8_FUNC_RET(0x483790, Sub483790, (BYTE, BYTE), BYTE);
	FF8_FUNC_RET(0x4837E0, Sub4837E0, (BYTE, DWORD), BYTE);
	FF8_FUNC_RET(0x483860, Sub483860, (DWORD), DWORD);
	FF8_FUNCTION(0x484490, SetMaxATB, (DWORD id));
	FF8_FUNCTION(0x4844D0, SetStartATB, (DWORD id));
	FF8_FUNCTION(0x485F00, Sub485F00, (DWORD));
	FF8_FUNC_RET(0x4860A0, CountValidTargets, (), DWORD); //0xFF if no valid targets - counts SeeDs in battle
	FF8_FUNCTION(0x4877F0, DoMonsterTurn, (int id, int unk));
	FF8_FUNC_RET(0x487D80, HasBattleItem, (int id), BOOL);
	FF8_FUNC_RET(0x487DB0, UseBattleItem, (int unk1, int id), BOOL);
	FF8_FUNCTION(0x48ACD0, Sub48ACD0, ());
	FF8_FUNCTION(0x48B7A0, SetKnownMagic, (int magic_id));
	FF8_FUNCTION(0x48BBD0, InitMonster, (DWORD id, DWORD unk1, DWORD unk2));
	FF8_FUNCTION(0x48C1C0, GetMonsterStats, (DWORD id));
	FF8_FUNC_RET(0x48C3F0, GetMonsterStat, (int level, BYTE *datfile, int stat), DWORD);
	FF8_FUNCTION(0x48C5C0, Sub48C5C0, (DWORD));
	FF8_FUNC_RET(0x48CCB0, GetItemAmount, (int item_id), DWORD);
	FF8_FUNC_RET(0x48D200, LoadAttack, (DWORD caster_id, DWORD kernel_id, DWORD id, DWORD unk1, DWORD unk2, DWORD target_mask, DWORD unk3), DWORD);
	FF8_FUNCTION(0x48E830, Sub48E830, (DWORD));
	FF8_FUNCTION(0x48EF50, Sub48EF50, (WORD, DWORD*));
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
	FF8_FUNC_RET(0x495210, Sub495210, (BYTE*, BYTE, BYTE*), BYTE*);
	FF8_FUNC_RET(0x495280, Sub495280, (BYTE*), BYTE*);
	FF8_FUNC_RET(0x496310, GetCharacterHP, (int lvl, int char_id), DWORD);
	FF8_FUNC_RET(0x496440, GetCharacterStat, (int lvl, int char_id, int stat), DWORD);
	FF8_FUNC_RET(0x4967C0, GetCharacterHit, (int char_id), DWORD);
	FF8_FUNC_RET(0x4968A0, GetCharacterEva, (int char_id, int unk1), DWORD);
	FF8_FUNC_RET(0x497380, Sub497380, (DWORD menuId, DWORD subMenuId, DWORD, DWORD), DWORD);
	FF8_FUNCTION(0x4980C0, Sub4980C0, ());
	FF8_FUNCTION(0x499A40, Sub499A40, ());
	FF8_FUNCTION(0x499EA0, Sub499EA0, ());
	FF8_FUNCTION(0x49B120, Sub49B120, ());
	FF8_FUNCTION(0x4A22C0, FFMenuModule, (BufApp0xC10*));
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
	FF8_FUNCTION(0x56BA50, Sub56BA50, (DWORD, BufApp0xC10*));
	FF8_FUNCTION(0x56D9C0, Sub56D9C0, ());
	FF8_FUNCTION(0x56DCE0, Sub56DCE0, (BYTE unk1, WORD unk2));
	FF8_FUNC_RET(0x6298A0, Mag002_Fire_Init, (MagicIDInitData* init_data), TaskList*);
	FF8_FUNC_RET(0x629990, Mag002_Fire_B, (LinkTask& task_data), DWORD);
	FF8_FUNC_RET(0x62A380, Mag002_Fire_C, (LinkTask& task_data), DWORD);
	FF8_FUNC_RET(0x62A610, Mag002_Fire_A, (LinkTask& task_data), DWORD);
};

extern FF8Vars ff8vars;
extern FF8Funcs ff8funcs;
#pragma pack(pop)
