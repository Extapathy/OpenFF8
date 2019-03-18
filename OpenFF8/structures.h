#pragma once

#include "stdafx.h"
#include <bitset>

//loaded from 0x48BBD0
//0x1D27B10
#pragma pack(1)
struct Item {
	BYTE id;
	BYTE amount;
};

struct Action {
	BYTE type; //??? 0x02 = generic magic
	BYTE animscript; //???
	WORD id;
};

struct MonsterInfo {
	char name[24]; //FF8 encoded - length might be less than this

	BYTE HP[4]; //HP = (HP[0]*x*x)/20 + (HP[0] + 100*HP[2])*x + 10*HP[1] + 1000*HP[3], where x = monster lvl
	BYTE str[4];
	BYTE vit[4];
	BYTE mag[4];
	BYTE spr[4];
	BYTE spd[4];
	BYTE eva[4];

	Action Roster[48];
	//Action RosterM[16];
	//Action RosterH[16];

	BYTE Unk1[4];

	BYTE Card[3]; //1st Byte = Card Drop, 2nd Byte = Carded into, 3rd Byte = Rarely Carded into, 0xFF = no drop/can't card
	BYTE Devour[3]; //Low, Med and High lvl Devour effect id's

	BYTE unk2[6];

	USHORT LowLvlDraw[4];
	USHORT MedLvlDraw[4];
	USHORT HighLvlDraw[4];

	Item LowLvlMug[2];
	Item LowLvlRMug[2];
	Item MedLvlMug[2];
	Item MedLvlRMug[2];
	Item HighLvlMug[2];
	Item HighLvlRMug[2];

	Item LowLvlDrop[2];
	Item LowLvlRDrop[2];
	Item MedLvlDrop[2];
	Item MedLvlRDrop[2];
	Item HighLvlDrop[2];
	Item HighLvlRDrop[2];

	BYTE unk3[20];

	BYTE ElemRes[8]; //These are how resistant the monster is to each element 0 = very weak
				//0 - Fire
				//1 - Ice
				//2 - Thunder
				//3 - Earth
				//4 - Poison
				//5 - Wind
				//6 - Water
				//7 - Holy
	BYTE StatusRes[20]; //Status resistances 0xFF = immune
				//0 - Death
				//1 - Poison
				//2 - Petrify
				//3 - Darkness
				//4 - Silence
				//5 - Beserk
				//6 - Zombie
				//7 - Sleep
				//8 - Haste
				//9 - Slow
				//10 - Stop
				//11 - Regen
				//12 - Reflect
				//13 - Doom (red timer) - command/doomtrain
				//14 - Slow Petrify? (white timer) - cast using doomtrain
				//15 - Float
				//16 - Confuse
				//17 - Drain
				//18 - ???
				//19 - ???
};

struct Character {
	MonsterInfo *infoSection; //0x1D27B10 - points to section 7 of a loaded dat file - NULL for SeeDs
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
	BYTE unkbyte03; //1D280C4
	BYTE attack_type; //1D280C5
	BYTE unkbyte05; //1D280C6
	BYTE unkbyte06; //1D280C7
	WORD unkword07; //1D280C8
	WORD magic_id; //1D280CA
	DWORD* unk0B; //1D280CC
	char* attack_name; //1D280D0
	BYTE padding[4]; //1D280D4
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
	WORD offsets[56]; //0x1CF3E4C
	KernelBattleCommand battle_commands[39]; //0x1CF3F2C
	KernelMagicData magic[57]; //0x1CF4064
	KernelGFData GFs[16]; //0x1CF4DC0
	KernelEnemyAttack enemy_attacks[384]; //0x1CF5600
	KernelWeapon weapons[33]; //0x1CF7400
	KernelRenzokukenFinisher renzokuken_finishers[4]; //0x1CF758C
	KernelCharacter characters[11]; //0x1CF75EC
	KernelBattleItem battle_items[33]; //0x1CF7778
};

struct MagicData2 {
	BYTE magic_id;
	BYTE magic_amount;
	BYTE padding[3];
};

struct CharacterData {
	BYTE padding[30]; //0x000
	BYTE command_data[16]; //0x01E
	BYTE limit_data[4]; //0x02E
	BYTE padding2[80]; //0x032
	MagicData2 magic[32]; //0x082
	BYTE padding1[80]; //0x122
	WORD currentHp; //0x172
	WORD maxHp; //0x174
	BYTE padding176[66]; //0x176
	BYTE lvl; //0x1B8
	BYTE unk1B9[2]; //0x1B9
	BYTE str; //0x1BB
	BYTE vit; //0x1BC
	BYTE mag; //0x1BD
	BYTE spr; //0x1BE
	BYTE spd; //0x1BF
	BYTE luck; //0x1C0
	BYTE eva; //0x1C1
	BYTE hit; //0x1C2
	BYTE unkbyte1C3; //0x1C3
	BYTE padding1[12]; //0x1C4
};

static_assert(sizeof(CharacterData) == 464, "CharacterData is wrong size.");

//TODO Finish struct
struct FieldEntity {
	DWORD stack[80]; //actual size unknown
	DWORD templist[8]; //+0x140
	BYTE padding[22];
	std::bitset<32> flags; //+0x160 - FOOTSTEPSON, BGANIMESYNC, LBL, RET
	BYTE unkbyte174; // +0x174 - BGSHADE, RET
	std::bitset<8> unkflags175; // +0x175 - BGSHADE
	WORD instruction_pointer; //+0x176
	char stack_count; // +0x184
	WORD unkword188; // +0x188 - BGDRAW
	WORD unkword18C; // +0x18C - BGDRAW
	WORD unkword18E; // +0x18E - BGDRAW
	WORD unkword190; // +0x190 - BGDRAW
	WORD unkword192; // +0x192 - BGDRAW
	DWORD x_pos; //+0x190
	DWORD y_pos; //+0x194
	DWORD z_pos; //+0x198
	DWORD unkdword19E; // +0x19E - BGSHADE
	DWORD unkdword1B4; // +0x1B4
	DWORD unkdword1B8; // +0x1B8
	DWORD unkdword1BC; // +0x1BC
	DWORD unkdword1C0; // +0x1C0
	DWORD unkdword1C4; // +0x1C4
	DWORD unkdword1C8; // +0x1C8
	WORD push_radius; //+0x1F6
	WORD talk_radius; //+0x1F8
	WORD triangle_id; //+0x1FA
	WORD unkword1FE; // +0x1FE MSPEED
	//WORD move_speed; //+0x200 MSPEED
	WORD unkword202; // +0x202
	WORD unkword206; //+0x206
	WORD anime_speed; //+0x208
	WORD unkword20A; //+0x20A
	WORD unkword20C; //+0x20C
	WORD model; //+0x218
	WORD unkword21A; // +0x21A
	WORD unkword21C; // +0x21C
	WORD unkword21E; // +0x21E
	BYTE unkbyte23C; // +0x23C
	BYTE angle; //+0x241
	BYTE talk_disabled; //+0x24B
	BYTE push_disabled; //+0x249	
	BYTE through_enabled; //+0x24C
	BYTE unkbyte24E; //+24E
	BYTE base_anim_id; //+24F
	BYTE base_anim_first; //+250
	BYTE base_anim_last; //+251
	BYTE ladder_anim_id; //+252
	BYTE ladder_anim_first; //+253
	BYTE ladder_anim_last; //+254
	BYTE unkbyte256; //+256
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

struct SaveGameItem {
	BYTE id;
	BYTE quantity;
};

static_assert(sizeof(SaveGameItem) == 2, "SaveGameItem is wrong size.");

struct SaveGameGF {
	char name[12]; // 0x00
	DWORD exp; // 0x0C
	BYTE unk; // 0x10
	bool exists; // 0x11
	WORD hp; // 0x12
	std::bitset<128> complete_abilities; // 0x14
	BYTE abilities[24]; // 0x24
	WORD kills; // 0x3C
	WORD kos; // 0x3E
	BYTE learning_ability; // 0x40
	BYTE forgotten_abilities[3]; // 0x41
};

static_assert(sizeof(SaveGameGF) == 68, "SaveGameGF is wrong size.");

struct SaveGameCharacter {
	BYTE padding[152];
};

static_assert(sizeof(SaveGameCharacter) == 152, "SaveGameCharacter is wrong size.");

struct FieldVars {
	BYTE padding[1280];
};

struct SaveGame {
	WORD checksum; //0x1CFDC58
	WORD unkword0002; //0x1CFDC5A
	WORD preview_location_id; //0x1CFDC5C
	WORD preview_first_character_current_hp; //0x1CFDC5E
	WORD preview_first_character_max_hp; //0x1CFDC60
	WORD preview_save_count; //0x1CFDC62
	DWORD preview_gil_amount; //0x1CFDC64
	DWORD preview_seconds_played; //0x1CFDC68
	BYTE preview_first_character_level; //0x1CFDC6C
	BYTE preview_first_character_portrait; //0x1CFDC6D
	BYTE preview_second_character_portrait; //0x1CFDC6E
	BYTE preview_third_character_portrait; //0x1CFDC6F
	char squall_name[12]; //0x1CFDC70
	char rinoa_name[12]; //0x1CFDC7C
	char angelo_name[12]; //0x1CFDC88
	char boko_name[12]; //0x1CFDC94
	DWORD current_disk; //0x1CFDCA0
	DWORD current_save; //0x1CFDCA4
	SaveGameGF gfs[16]; //0x1CFDCA8
	SaveGameCharacter characters[8]; //0x1CFE0E8
	BYTE shops[400]; //0x1CFE5A8
	BYTE configuration[20]; //0x1CFE738
	BYTE party1[4]; //0x1CFE74C
	BYTE known_weapons[4]; //0x1CFE750
	char griever_name[12]; //0x1CFE754
	WORD unk1; //0x1CFE760
	WORD unk2; //0x1CFE762
	int gil_amount; //0x1CFE764
	int gil_amount_laguna; //0x1CFE768
	WORD limit_break_quistis; //0x1CFE76C
	WORD limit_break_zell; //0x1CFE76E
	BYTE limit_break_irvine; //0x1CFE770
	BYTE limit_break_selphie; //0x1CFE771
	BYTE limit_break_angelo_completed; //0x1CFE772
	BYTE limit_break_angelo_known; //0x1CFE773
	BYTE angelo_points[8]; //0x1CFE774
	BYTE item_battle_order[32]; //0x1CFE77C
	SaveGameItem items[198]; //0x1CFE79C
	DWORD game_time; //0x1CFE928
	DWORD countdown; //0x1CFE92C
	DWORD unk3; //0x1CFE930
	DWORD victory_count; //0x1CFE934
	WORD unk4; //0x1CFE938
	WORD battles_escaped; //0x1CFE93A
	DWORD battle_vars[8]; //0x1CFE93C
	BYTE magic_drawn_once[8]; //0x1CFE95C
	BYTE enemies_scanned_once[20]; //0x1CFE964
	BYTE renzokuken_auto; //0x1CFE978
	BYTE renzokuken_indicator; //0x1CFE979
	BYTE dream_odin_flags; //0x1CFE97A
	BYTE tutorial_info[16]; //0x1CFE97B
	BYTE seed_test_level; //0x1CFE98B
	DWORD unk5; //0x1CFE98C
	BYTE party2[4]; //0x1CFE990
	DWORD unk6; //0x1CFE994
	WORD current_module; //0x1CFE998
	WORD current_field; //0x1CFE99A
	WORD previous_field; //0x1CFE99C
	BYTE pos[12]; //0x1CFE99E
	WORD triangle_id[3]; //0x1CFE9AA
	BYTE direction[3]; //0x1CFE9B0
	BYTE unk7; //0x1CFE9B3
	DWORD unk8; //0x1CFE9B4
	FieldVars field_vars; //0x1CFE9B8
	BYTE world_map[128]; //0x1CFEEB8
	BYTE triple_triad[128]; //0x1CFEF38
	BYTE chocobo_world[64]; //0x1CFEFB8
};

static_assert(sizeof(SaveGame) == 5024, "SaveGame is wrong size.");

struct BattleAnim {
	BYTE unkbyte00;
	BYTE unkbyte01;
	WORD unkword02;
	BYTE unkbyte06;
	BYTE unkbyte07;
};

struct BattleAnimReader {
	BYTE* animptr;
	DWORD currentBit;
};

struct UnkBattleAnimRelated {
	VOID* unkptr04;
};

struct colorBGRA
{
	float B;
	float G;
	float R;
	float A;
};

struct FFModuleInterface
{
	uint32_t initSystems;
	uint32_t exitSystems;
	uint32_t field08;
	uint32_t field0C;
	uint32_t mainLoop;
	uint32_t mouseInputHandler;
	uint32_t keyboardInputHandler;
};

struct FFScene
{
	uint32_t isEnabled;                 // 0x0
	uint32_t field4;
	uint32_t field8;
	uint32_t fieldC;
	uint32_t field10;
	uint32_t nNumMeshes;                // 0x14
	uint32_t fieldRest[28];
};

struct BufApp0xC10
{
	uint32_t field000;
	uint32_t screenWidth;
	uint32_t screenHeight;
	uint32_t field00C; // colour depth?
	uint32_t fieldRest0[202];
	void* pFFScene0;                 // 0x338
	void* pFFScene1;                 // 0x33C
	uint32_t fieldRest1[367];
	void*    pBackBufferSurfaceDesc;    // 0x8FC
	uint32_t fieldRest2[89];
	uint32_t isRequestedModuleChange;   // 0xA64
	uint32_t nCurrentSceneIndex;        // 0xA68
	uint32_t fieldRest3[49];
	FFModuleInterface currentModule;    // 0xB30
	FFModuleInterface nextModule;       // 0xB4C
	uint32_t fieldRest4[42];            // 0xB68
};