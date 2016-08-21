#pragma once

#include "stdafx.h"

//loaded from 0x48BBD0
//0x1D27B10
#pragma pack(push, 1)
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
	BYTE unk5_0[7]; //0x1D27B99
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
#pragma pack(pop)


static_assert(sizeof(Character) == 208, "Character structure is wrong size.");

//0x1D28E83
#pragma pack(push, 1)
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
#pragma pack(pop)

static_assert(sizeof(unk1D28E83) == 71, "Structure is wrong size.");

#pragma pack(push, 1)
//This is only the common header, the tasks have varying sizes.
struct LinkTask {
	WORD flags;
	WORD unk;
	LinkTask *next_item;
	int(*function)(LinkTask*);
	WORD unk1;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct TaskList {
	LinkTask *first_item;
	LinkTask *last_item;
	LinkTask *data_start;
	WORD item_size;
	WORD max_items;
};
#pragma pack(pop)

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