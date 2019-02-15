#pragma once

#include "stdafx.h"

//loaded from 0x48BBD0
//0x1D27B10
#pragma pack(1)
struct Character {
	BYTE **infoSection; //0x1D27B10 - points to section 7 of a loaded dat file - NULL for SeeDs
	BYTE **aiSection; //0x1D27B14 -  NULL for SeeDs
	DWORD status1D27B18; //0x1D27B18 0x27
	BYTE status; //0x1D27B1C - MSB - reflect / shell / protect / regen / stop / slow / haste / sleep - LSB
	BYTE unk1[3]; //0x1D27B1D
	DWORD ATBmax; //0x1D27B20
	DWORD ATBcur; //0x1D27B24
	DWORD currentHP; //0x1D27B28
	DWORD maxHP; //0x1D27B2C
	BYTE unk2_0[4]; //0x1D27B30
	DWORD localVars[8]; //0x1D27B34 - DC to E3 - base address used is 0x1D277C4
	WORD elemRes[8]; //0x1D27B54 - 500 = very weak, 800 = normal, 1000 = fully absorb - 0. Fire, 1. Ice, 2. Thunder, 3. Earth, 4. Poison, 5. Wind, 6. Water, 7. Holy
	WORD timers[16]; //0x1D27B64 - status timers
	DWORD unkdword1D27B84; //0x1D27B84
	DWORD unkdword1D27B88; //0x1D27B88
	DWORD status1D27B8C; //0x1D27B8C - edited by function 0x48C5C0 - set to 0x11 initially
	WORD status1; //0x1D27B90 MSB - ? / zombie / berserk / silence / blind / petrify / poison / death - LSB
	WORD unkword1D27B92; //0x1D27B92
	WORD unkword1D27B94; //0x1D27B94 ????? 0x2E, 0x29, 0x06, 
	WORD unkword1D27B96; //0x1D27B96 ?????
	BYTE lastAttacker; //0x1D27B98 - used in opcode 0x0E case 0xCB
	BYTE unkbyte1D27B99; //0x1D27B99 - set to parts of current attack flags
	BYTE unk5_0[6]; //0x1D27B9A
	BYTE mentalRes[40]; //0x1D27BA0 - Mental resistances - 0. Death, 1. Poison, 2. Petrify, 3. Darkness, 4. Silence, 5. Berserk, 6. Zombie, 8. Sleep, 9. Haste, A. Slow, B. Stop, C. Regen, F. Reflect, 12. Doom, 14. Petrifying, 15. Float, 16. Confuse, 17. Drain, 18. Expulsion, rest are always 100 for monsters
	BYTE unkbyte1D27BC8; //0x1D27BC8 used in case 0x2A  - edited by function 0x48C5C0
	BYTE unkbyte1D27BC9; //0x1D27BC9 - edited by function 0x48C5C0
	BYTE unkbyte1D27BCA; //0x1D27BCA
	BYTE unkbyte1D27BCB; //0x1D27BCB - edited by function 0x48C5C0
	BYTE lvl; //0x1D27BCC
	BYTE str; //0x1D27BCD
	BYTE vit; //0x1D27BCE
	BYTE mag; //0x1D27BCF
	BYTE spr; //0x1D27BD0
	BYTE spd; //0x1D27BD1
	BYTE luck; //0x1D27BD2
	BYTE eva; //0x1D27BD3
	BYTE hit; //0x1D27BD4
	BYTE unk7[5]; //0x1D27BD5
	BYTE crisisLevel; //0x1D27BDA
	BYTE unkbyte1D27BDB; //0x1D27BDB
	WORD unkword1D27BDC; //0x1D27BDC
	BYTE unk8[2]; //0x1D27BDE
};

static_assert(sizeof(Character) == 208, "Character structure is wrong size.");

//0x1D28E83
struct unk1D28E83 {
	BYTE strMul; //0x1D28E83
	BYTE vitMul; //0x1D28E84
	BYTE magMul; //0x1D28E85
	BYTE sprMul; //0x1D28E86
	BYTE spdMul; //0x1D28E87
	BYTE evaMul; //0x1D28E88
	BYTE difficulty; //0x1D28E89
	BYTE unk[64]; //1D28E8A
};

static_assert(sizeof(unk1D28E83) == 71, "Structure is wrong size.");

//This is only the common header, the tasks have varying sizes.
struct LinkTask {
	WORD flags;
	WORD unk;
	LinkTask *next_item;
	int(*function)(LinkTask&);
	WORD unk1;
};

struct TaskList {
	LinkTask *first_item;
	LinkTask *last_item;
	LinkTask *data_start;
	WORD item_size;
	WORD max_items;
};

static_assert(sizeof(TaskList) == 16, "TaskList is wrong size.");

struct MagicIDInitData {
	WORD unk;
	WORD unk1;
	LPVOID* unk3;
};

struct unkInitData {
	MagicIDInitData* init_data;
	BYTE unk;
};

struct UnkStruct1D99A40 {
	DWORD unkdword00;
	BYTE unkbyte04;
	BYTE padding[3];
	DWORD unkdword08;
	BYTE padding1[104];
	BYTE* unkbyteptr74;
	BYTE padding2[20];
	DWORD unkdword8C;
};

static_assert(sizeof(UnkStruct1D99A40) == 144, "UnkStruct1D99A40 is wrong size.");

struct MagicData {
	BYTE unkbyte00;
	BYTE attack_type;
	BYTE unkbyte02;
	BYTE unkbyte03;
	WORD unkword04;
	WORD magic_id;
	DWORD* unk08;
	char* attack_name;
	BYTE padding[4];
};

static_assert(sizeof(MagicData) == 20, "MagicData is wrong size.");

struct KernelBattleCommand {
	BYTE padding[8];
};

struct KernelMagicData {
	WORD name_offset;
	WORD description_offset;
	WORD magic_id;
	BYTE unkbyte06;
	BYTE attack_type;
	BYTE attack_power;
	BYTE unkbyte09;
	BYTE target_info;
	BYTE attack_flags;
	BYTE draw_resist;
	BYTE hit_count;
	BYTE element;
	BYTE unkbyte0F;
	DWORD status_dword;
	WORD status_word;
	BYTE status_attack;
	BYTE HP_junction_value;
	BYTE str_junction_value;
	BYTE vit_junction_value;
	BYTE mag_junction_value;
	BYTE spr_junction_value;
	BYTE spd_junction_value;
	BYTE eva_junction_value;
	BYTE hit_junction_value;
	BYTE luck_junction_value;
	BYTE J_elemental_attack_element;
	BYTE J_elemental_attack_value;
	BYTE J_elemental_defence_element;
	BYTE J_elemental_defence_value;
	BYTE J_status_attack_value;
	BYTE J_status_defence_value;
	WORD J_status_attack_status;
	WORD J_status_defence_status;
	BYTE GF_compatibility[16];
	WORD unkword3A;
};

static_assert(sizeof(KernelMagicData) == 60, "KernelMagicData is wrong size.");

struct KernelGFData {
	BYTE padding[132];
};

struct KernelEnemyAttack {
	BYTE padding[20];
};

struct KernelWeapon {
	BYTE padding[12];
};

struct KernelRenzokukenFinisher {
	BYTE padding[24];
};

struct KernelCharacter {
	BYTE padding[36];
};

struct KernelBattleItem {
	WORD name_offset;
	WORD description_offset;
	WORD magic_id;
	BYTE attack_type;
	BYTE attack_power;
	BYTE unkbyte08;
	BYTE target_info;
	BYTE unkbyte0A;
	BYTE attack_flags;
	BYTE unkbyte0C;
	BYTE status_attack;
	WORD status_word;
	DWORD status_dword;
	BYTE attack_param;
	BYTE unkbyte15;
	BYTE hit_count;
	BYTE element;
};

static_assert(sizeof(KernelBattleItem) == 24, "KernelBattleItem is wrong size.");

//TODO finish kernel
struct Kernel {
	DWORD section_count;
	WORD offsets[56];
	KernelBattleCommand battle_commands[39];
	KernelMagicData magic[57];
	KernelGFData GFs[16];
	KernelEnemyAttack enemy_attacks[384];
	KernelWeapon weapons[33];
	KernelRenzokukenFinisher renzokuken_finishers[4];
	KernelCharacter characters[11];
	KernelBattleItem battle_items[33];
};

struct MagicData2 {
	BYTE magic_id;
	BYTE magic_amount;
	BYTE padding[3];
};

struct CharacterData {
	BYTE padding[30];
	BYTE command_data[16];
	BYTE limit_data[4];
	BYTE padding2[80];
	MagicData2 magic[32];
	BYTE padding1[174];
};

static_assert(sizeof(CharacterData) == 464, "CharacterData is wrong size.");

//TODO Finish struct
struct FieldEntity {
	DWORD stack[80]; //actual size unknown
	DWORD templist[8]; //+0x140
	BYTE padding[22];
	DWORD flags; //+0x160 - FOOTSTEPSON, BGANIMESYNC
	BYTE unkbyte174; // +0x174 - BGSHADE
	BYTE unkbyte175; // +0x175 - BGSHADE
	WORD instruction_pointer; //+0x176
	char stack_count; //+0x184
	WORD unkword188; // +0x188 - BGDRAW
	WORD unkword18C; // +0x18C - BGDRAW
	WORD unkword18E; // +0x18E - BGDRAW
	WORD unkword190; // +0x190 - BGDRAW
	WORD unkword192; // +0x192 - BGDRAW
	DWORD x_pos; //+0x190
	DWORD y_pos; //+0x194
	DWORD z_pos; //+0x198
	DWORD unkdword19E; // +0x19E - BGSHADE
	WORD push_radius; //+0x1F6
	WORD talk_radius; //+0x1F8
	WORD triangle_id; //+0x1FA
	//WORD move_speed; //+0x1FE
	//WORD move_speed; //+0x200
	WORD anime_speed; //+0x208
	WORD model; //+0x218
	BYTE angle; //+0x241
	BYTE talk_disabled; //+0x24B
	BYTE push_disabled; //+0x249	
	BYTE through_enabled; //+0x24C
	BYTE base_anim_id; //+24F
	BYTE base_anim_first; //+250
	BYTE base_anim_last; //+251
	BYTE ladder_anim_id; //+252
	BYTE ladder_anim_first; //+253
	BYTE ladder_anim_last; //+254
};

//0x1D76928
struct BattleCharacterUI {
	BYTE* character_name; //0x00
	BYTE padding[4]; //0x04
	WORD x; //0x08
	WORD y; //0x0A
	BYTE padding7[4]; //0x0C
	DWORD unkdword10; //0x10
	BYTE padding1[10]; //0x14
	WORD character_hp; //0x1E
	BYTE padding2[28]; //0x20
	BYTE unkbyte3C; //0x3C
	BYTE unkbyte3D; //0x3D
	BYTE unkbyte3E; //0x3E
	BYTE unkbyte3F; //0x3F
	WORD unkword40; //0x40
	WORD unkword42; //0x42
	BYTE padding5[4]; //0x44
	BYTE unkbyte48; //0x48 character ID?
	BYTE unkbyte49; //0x49
	WORD name_x; //0x4A
	BYTE padding3[4]; //0x4C
	BYTE unkbyte50; //0x50
	BYTE unkbyte51; //0x51
	BYTE unkbyte52; //0x52
	BYTE unkbyte53; //0x53
	DWORD unkdword54; //0x54
	DWORD unkdword58; //0x58
	DWORD unkdword5C; //0x5C
	DWORD unkdword60; //0x60
	DWORD unkdword64; //0x64
	BYTE unkbyte68; //0x68
	BYTE padding4[3]; //0x69
};

static_assert(sizeof(BattleCharacterUI) == 108, "BattleCharacterUI is wrong size.");