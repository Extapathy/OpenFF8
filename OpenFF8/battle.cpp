#include "stdafx.h"
#include "battle.h"
#include "memory.h"
#include "OpenFF8.h"
#include <algorithm>

/*int LoadAttack(DWORD caster_id, DWORD kernel_id, DWORD id, DWORD unk1, DWORD unk2, DWORD target_mask, DWORD unk3) {
	*ff8vars.unkbyte1D28E00 = 0;
	DWORD local1 = 0xFF;
	DWORD local2 = 1;
	MagicData& local3 = ff8vars.attack_queue_data[*ff8vars.attack_queue_count];
	if (caster_id < 3) {
		unk3 = 0;
		if (kernel_id == 0x04 || kernel_id == 0x0D) {
			if (ff8vars.kernel->battle_items[id].attack_type == 0x0E) {
				kernel_id = 0xF4;
				unk1 = id;
				if (id == 0x1E) {
					WORD ebx;
					BYTE eax;
					*ff8vars.unkbyte1D28E21 = 1;
					//Check that Boko is enabled
					if ((*ff8vars.chocobo_world_flags & 0x01) != 0) {
						//Check that Boko isn't in the world
						if ((*ff8vars.chocobo_world_flags & 0x02) == 0) {
							ebx = *ff8vars.boko_attack + 2;
							eax = 2;
						}
						eax = 1;
					}
					else {
						eax = 0;
					}

				}
			}
		}
	}
	//TODO untangle twisted logic above

	switch (kernel_id) {
		case 0x1D:
		case 0x06:
		case 0xF6:
		case 0xF7:
		case 0x02:
			ff8funcs.GetMagicName(id);
			if (caster_id < 3) {
				for (int i = 0; ) {
					if (ff8vars.char_data.magic->magic_id == id) break;
				}
			}



		case 0x03:
		case 0xFE:
		case 0xF4:
		case 0xF0: case 0xF5:
		case 0x04: case 0x0D:
		case 0xFA:
		case 0x10:
		case 0x0E:
		case 0xED:
		case 0xEE:
		case 0x13:
		case 0x11: case 0x12: case 0x14: case 0x15: case 0x16:
		case 0x0F:
		case 0x05:
		case 0x0B:
		case 0xF1:
		case 0xEF:
		case 0x08: case 0xEC:
		case 0x26:
		case 0x07:
		case 0x17: case 0x18: case 0x19: case 0x1A: case 0x1B: case 0x1E: case 0x1F: case 0x20: case 0x21: case 0x22:
		case 0xFC:
		case 0x1C:
		case 0xFFFC:
	}
}*/

LinkTask* BdLinkTask(TaskList& task_list, int(*task)(LinkTask& task_data)) {
	LinkTask *new_item = GetFreeLinkTask(task_list);

	if (new_item != NULL) {
		new_item->flags |= 1;
		new_item->function = task;
		new_item->unk = 0;
		new_item->next_item = NULL;
		if (task_list.last_item != NULL) {
			task_list.last_item->next_item = new_item;
			task_list.last_item = new_item;
			return new_item;
		}
		else {
			task_list.first_item = new_item;
			task_list.last_item = new_item;
			return new_item;
		}
	}

	OutputDebugStringA("BdLinkTask: FAILED !!!!\n");
	return NULL;
}

LinkTask* GetFreeLinkTask(const TaskList& task_list) {
	if (task_list.max_items > 0) {
		BYTE *ptr = (BYTE*)task_list.data_start;
		for (int i = 0; i < task_list.max_items; i++) {
			if ((*ptr & 1) == 0) {
				return (LinkTask*)ptr;
			}

			ptr += task_list.item_size;
		}
	}
	return NULL;
}

int DoLinkTask(TaskList& task_list) {
	int task_count = 0;
	LinkTask* prev_task = NULL;
	//Does all tasks in the task list once and counts the remaining tasks
	for (LinkTask* task = task_list.first_item; task != NULL; task = task->next_item) {
		//Does a task in the task list and if flag 0x02 is set, it is deleted from the task list
		if ((task->function(*task) & 0x02) != 0) {
			task->flags = 0;
			if (prev_task != NULL) {
				prev_task->next_item = task->next_item;
			}
			else {
				task_list.first_item = task->next_item;
			}
		}
		else {
			prev_task = task;
			task_count++;
		}
	}
	task_list.last_item = prev_task;
	return task_count;
}

//int PlayMagic(LinkTask& task_data) {
//	MagicData& magic_data = **ff8vars.magic_data_ptr;
//	BYTE* task = (BYTE*)&task_data;
//	BYTE& state = *(task + 0x0D);
//	BYTE* link_task = NULL;
//	switch (state) {
//		case 0:
//			*ff8vars.unkbyte1D99A85 = ff8funcs.CameraRelated(magic_data, *ff8vars.unkword1D99A5C);
//			state++;
//		case 1:
//			if (*ff8vars.unkbyte1D99A85 != 0) {
//				if (ff8funcs.Sub508580(0x1A, 0x40) != 0) return 0;
//			}
//			else {
//				if (ff8funcs.Sub50ADE0() != 0) return 0;
//			}
//			state++;
//		case 2:
//			*ff8vars.unkdword1D96A9C |= 0x10;
//			ff8funcs.Sub50AFC0();
//			if ((magic_data.attack_type == 0x0B && magic_data.unkword04 == 0xFFFB) || magic_data.attack_type == 0x0E) {
//				*ff8vars.unkbyte1D99A80 = 0;
//			}
//			(*ff8vars.unkstruct1D99A40)->unkdword08 &= 0xFF7FFFFF;
//			ff8funcs.Sub505C00(**ff8vars.unkstruct1D99A40, magic_data.attack_type);
//			ff8funcs.Sub506190(magic_data, *ff8vars.unkbyte1D99A85);
//			ff8funcs.LoadMagicID(magic_data.magic_id, ff8vars.current_magic_init_function);
//			state++;
//			return 0;
//		case 3: //Cast animation
//			if (*ff8vars.unkbyte1D96A90 > 0 && (*ff8vars.unkdword1D96A9C & 0x20000000) == 0) return 0;
//			if (*ff8vars.unkdword1D999C8 <= 0) return 0;
//			if (*ff8vars.unkbyte1D97718 != 0) return 0;
//			if ((*ff8vars.unkstruct1D99A40)->unkdword8C == 0) {
//				*((*ff8vars.unkstruct1D99A40)->unkbyteptr74 + 0x2C) |= 0x10;
//				state++;
//				return 0;
//			}
//			link_task = (BYTE*)ff8funcs.Sub506C10(ff8funcs.Sub50B080);
//			*(WORD*)(link_task + 0x10) = 0x10;
//			*(DWORD*)(link_task + 0x0C) = (*ff8vars.unkstruct1D99A40)->unkdword00;
//			state++;
//			return 0;
//		case 4:
//			if (*ff8vars.unkbyte1D96A90 > 0 && (*ff8vars.unkdword1D96A9C & 0x20000000) == 0) return 0;
//			if ((*((*ff8vars.unkstruct1D99A40)->unkbyteptr74 + 0x2C) & 0x20) != 0) {
//				state++;
//				if (*ff8vars.unkword1D99A90 != 0) {
//					//WORD temp = *(WORD*)(ff8vars.unkbyte1D99A84)
//				}
//			}
//			//TODO finish case 4
//		case 5: //Init magic
//			*(WORD*)((*ff8vars.unkstruct1D99A40)->unkbyteptr74 + 0x2C) &= 0xFFDF;
//			if ((*ff8vars.unkdword1D96A9C & 0x20000000) != 0) {
//				//TODO missing line
//				*ff8vars.unkdword1D96A9C &= 0xDFFFFFFF;
//
//			}
//			if ((magic_data.attack_type == 0x02 || magic_data.attack_type == 0x06) && (*ff8vars.unkstruct1D99A40)->unkbyte04 >= 0x10) {
//				*ff8vars.unkdword1D96A9C |= 0x20;
//			}
//			*ff8vars.current_magic_task_list = (*ff8vars.current_magic_init_function)(*ff8vars.current_magic_init_data);
//			if (magic_data.attack_type == 0xFE) {
//				ff8funcs.Sub56DCE0(*ff8vars.unkbyte1D28DF7, magic_data.unkword04);
//			}
//			*ff8vars.unkword1D99A8E = 0;
//			state++;
//			return 0;
//		case 6: //Magic animation
//			if (magic_data.unkword04 == 0xFFFE) {
//				if (*ff8vars.current_magic_task_list == NULL) {
//					state++;
//				}
//				return 0;
//			}
//			if (magic_data.attack_type != 0x0B && magic_data.attack_type != 0x0E) {
//				if (ff8funcs.Sub50AE80() != 0) {
//					if (*ff8vars.current_magic_task_list == NULL) return 0;
//					if (++(*ff8vars.unkword1D99A8E) < 0x384) return 0;
//					ff8funcs.InitializeSound_CAL();
//					return 0;
//				}
//				ff8funcs.Sub50AED0();
//				if ((*ff8vars.unkbyte1D99A79 & 0x02) == 0) {
//					*ff8vars.unkdword1D96A9C &= 0xEF;
//				}
//				if (*ff8vars.unkword1D99A90 == 0) {
//					state++;
//					return 0;
//				}
//
//			}
//			//TODO finish rest
//			break;
//		case 7:
//			break;
//		default:
//			return 0;
//	}
//}

DWORD Archive_GetFile(BYTE* filename) {
	char message[100] = "";
	
	snprintf(message, 100, "Loading file: %s\n", filename);
	OutputDebugStringA(message);

	EndRedirect(ff8funcs.Archive_GetFile);
	DWORD return_value = ff8funcs.Archive_GetFile(filename);
	BeginRedirect(ff8funcs.Archive_GetFile, Archive_GetFile);

	return return_value;
}

//TODO finish sorting fire code
/*DWORD* unkDEE360 = (DWORD*)0xDEE360;
LinkTask* fire_task_dataA = (LinkTask*)0x24CA818;
TaskList* fire_task_listA = (TaskList*)0x24CA828;
TaskList* fire_task_listB = (TaskList*)0x24CA838;
LinkTask* fire_task_dataB = (LinkTask*)0x24CA848;
unkInitData* fire_init_data = (unkInitData*)0x24CBD60;

TaskList* Mag002_Fire_Init(MagicIDInitData& init_data) {
	fire_init_data->init_data = &init_data;
	fire_init_data->unk = (BYTE)init_data.unk;
	std::fill_n(unkDEE360, 7, 1);
	ff8funcs.BS_Memset(fire_task_listA, fire_task_dataA, 16, 1);
	BdLinkTask(*fire_task_listA, ff8funcs.Mag002_Fire_A)->unk1 = 0;
	ff8funcs.BS_Memset(fire_task_listB, fire_task_dataB, 36, 150);
	eax = fire_init_data->init_data->unk3;
	if (? ? > 1) {
		BdLinkTask(fire_task_listB, ff8funcs.Mag002_Fire_B);
	}
	else {
		BdLinkTask(fire_task_listB, ff8funcs.Mag002_Fire_C);
	}

	return fire_task_listA;
}*/

int DatAnimationReader(UnkBattleAnimRelated* arg1, BattleAnim* arg2) {
	DWORD local4;
	DWORD local0;

	BattleAnim* ebx = arg2;
	BYTE al = arg2->unkbyte06;
	BYTE cl = arg2->unkbyte07;

	if (al >= cl)
		return 1;

	//call func here
	BattleAnimReader* retval;
	UnkBattleAnimRelated* ecx = arg1;
	BattleAnimReader* esi = retval;
	DWORD edx = 0;
	VOID* eax = arg1->unkptr04; //TODO fix
	BYTE dl = arg2->unkbyte00;
	local0 = 0;
	//TODO
	cl = ebx->unkbyte01;
	dl = cl;
	//if (cl & 1)
}

// void MonsterAI(int monsterId, BYTE* aiCode, int arg3, int arg4) {
// 	//ebx = monsterId
// 	DWORD local74 = arg4;
// 	DWORD local70 = arg3;
// 	BYTE* local6C = aiCode;
// 	DWORD local6C1;
// 	DWORD local68 = monsterId;
// 	DWORD local60;
// 	DWORD local5C;
// 	DWORD local58;
// 	DWORD local54;
// 	BYTE local52;
// 	BYTE local51;
// 	BYTE local50;
// 	DWORD local4C;
// 	BYTE local48;
// 	BYTE local44;
// 	MonsterInfo* local40;
// 	DWORD local3C;
// 	DWORD local38;
// 	DWORD local34;
// 	DWORD local30;
// 	DWORD local2C;
// 	BYTE local28;
// 	DWORD local24;
// 	DWORD local20;
// 	DWORD local1C;
// 	DWORD local18;
// 	DWORD local14;
// 	DWORD local10;
// 	BYTE local0C;
// 	DWORD local08;
// 	BYTE local04;
// 	WORD local00;

// 	local08 = ff8vars.monster_info[monsterId].difficulty;
// 	local0C = 0;
// 	local44 = 0;
// 	local04 = 0;
// 	local68 = 0;
// 	local40 = ff8vars.character_info[monsterId].infoSection;
// 	local28 = 0;
// 	local00 = 0;

// 	if (!ff8vars.init_done && ff8vars.character_info[monsterId].status1 & 0x20) {
// 		if (ff8funcs.CountValidTargets() == 0xFF) {
// 			local68 = 0;
// 			local50 = 0;
// 			DWORD esi = 0x1D2A21D;
			
// 		}
// 		else {
// 			BYTE target;
// 			do {
// 				int target = (ff8funcs.Rand() & 0xFF) % 3;
// 			} while (ff8vars.character_info[target].status1 & 1);

// 			local50 = 0;
// 			DWORD esi = 0x1D2A21D;
// 			local68 = 1 << target;
// 		}
// 		int ability = local50 + 16 * local08;
// 		local04 = local40->Roster[ability].type;
// 		local00 = local40->Roster[ability].id;
// 		local0C = local40->Roster[ability].animscript;

// 		if (local00) {
// 			if (local04 == 2) {
// 				local68 |= ff8funcs.Sub483860(ff8vars.kernel.magic[local00].target_info);
// 			}
// 			else if (local04 == 4) {
// 				local68 |= ff8funcs.Sub483860(ff8vars.kernel.items[local00].target_info);
// 			}
// 			else if (ff8vars.kernel.enemy_attacks[local00]. & 0x80) {
// 				local68 |= 0x4000;
// 			}
// 			ff8funcs.LoadAttack(monsterId, local04, ebp, local44, local28, local68, local0C);
// 			ff8funcs.Sub48E830(local68);

// 			if (ff8vars.unkbyte1D27B0E != 0) {
// 				return;
// 			}

// 			ff8funcs.Sub47E080(5);
// 			ff8funcs.Sub485F00(ff8vars.attack_queue_count - 1);
// 			ff8vars.attack_queue_data[ff8vars.attack_queue_count - 1].attack_type = 0;

// 			if (ff8vars.unkbyte1D28E0B) {
// 				ff8funcs.Sub483860(ff8vars.kernel.magic[ff8vars.unkbyte1D28DCD].target_info);
// 				//TODO
// 			}
// 		}
// 	}
// 	BYTE* esi = local6C; //arg2
// 	while (local48 = *esi++ != 0) {
// 		//edi = 0xFF
// 		switch (local48) {
// 			case 0x24:
// 				ff8vars.character_info[monsterId].ATBmax = ff8vars.character_info[monsterId].ATBcur;
// 				break;
// 			case 0x1C:
// 				ff8funcs.Sub482C90(ff8funcs.Sub48ACD0);
// 				//TODO
// 				break;
// 			case 0x20:
// 				//TODO similar to 0x1C
// 				break;
// 			case 0x34:
// 				local51 = *esi++;
// 				local2C = local51;
// 				ff8vars.unkbyte1D280C2 = 0;
// 				ff8vars.unkbyte1D28DF9 = 1;
// 				ff8vars.unkbyte1D28DFD = 1;

// 				int i = 3;
// 				do {
// 					if (ff8vars.character_info[i].status1D27B8C & 1 == 0) {
// 						local6C1 = i;
// 						break;
// 					}
// 					i++;
// 					if (i == 8) {
// 						local6C1 = 0xFF;
// 					}
// 				} while (i < 8);

// 				ff8funcs.Sub48C5C0(local6C1);
// 				ff8funcs.Sub47D930(local6C1, local2C);
// 				ff8vars.unkbyte1D28DFB = local6C1;
// 				ff8vars.unkbyte1D28DFC = local2C;

// 				ff8funcs.Sub47E3F0(0x71, 0x80, (void(*)())0x48AD10);
// 				ff8funcs.Sub47E200((void(*)())0x4876B0);
// 				break;
// 			case 0x3B:
// 				local51 = *esi++;
// 				local52 = *esi++;
// 				local2C = local51;
// 				ff8vars.unkbyte1D280C2 = 0;
// 				ff8vars.unkbyte1D28DF9 = 1;
// 				ff8vars.unkbyte1D28DFD = 1;

// 				if (local52 == 0) {
// 					int i = 3;
// 					do {
// 						if (ff8vars.character_info[i].status1D27B8C & 1 == 0) {
// 							local6C1 = i;
// 							break;
// 						}
// 						i++;
// 						if (i == 8) {
// 							local6C1 = 0xFF;
// 						}
// 					} while (i < 8);
// 				}
// 				else {
// 					local6C1 = local52;
// 				}

// 				ff8funcs.Sub48C5C0(local6C1);
// 				ff8funcs.Sub47D930(local6C1, local2C);
// 				ff8vars.unkbyte1D28DFB = local6C1;
// 				ff8vars.unkbyte1D28DFC = local2C;

// 				ff8funcs.Sub47E3F0(0x71, 0x80, (void(*)())0x48AD10);
// 				*((WORD*)ff8funcs.Sub47E3F0(0x71, 0x80, (void(*)())0x487670)) = local6C1;
// 				ff8funcs.Sub47E200((void(*)())0x4876B0);
// 				ff8funcs.Sub47E080(6);
// 				break;
// 			case 0x1F:
// 				local51 = *esi++;
// 				local2C = local51;
// 				ff8vars.unkbyte1D280C2 = 0;
// 				ff8vars.unkbyte1D28DF9 = 1;
// 				ff8vars.unkbyte1D28DFD = 1;

// 				int i = 3;
// 				do {
// 					if (ff8vars.character_info[i].status1D27B8C & 1 == 0) {
// 						local6C1 = i;
// 						break;
// 					}
// 					i++;
// 					if (i == 8) {
// 						local6C1 = 0xFF;
// 					}
// 				} while (i < 8);

// 				ff8funcs.Sub48C5C0(local6C1);
// 				ff8funcs.Sub47D930(local6C1, local2C);
// 				ff8vars.unkbyte1D28DFB = local6C1;
// 				ff8vars.unkbyte1D28DFC = local2C;

// 				ff8funcs.Sub47E3F0(0x71, 0x80, (void(*)())0x48AD10);
// 				*((WORD*)ff8funcs.Sub47E3F0(0x71, 0x80, (void(*)())0x487670)) = local6C1;
// 				ff8funcs.Sub47E200((void(*)())0x4876B0);
// 				ff8funcs.Sub47E080(6);
// 				break;
// 			case 0x1B:
// 				local50 = *esi++ + 3;
// 				ff8funcs.Sub47E3F0(0x70, 0x80, NULL);
// 				local28 = *esi++;

// 				ff8vars.unkbyte1D28E06 = 1;
// 				local04 = 0;
// 				local00 = 3;
// 				local1C = 0;
// 				local68 = 1 << local50;
// 				ff8funcs.LoadAttack(monsterId, 0, 3, local44, local28, local68, 0);
// 				ff8funcs.Sub48E830(local68);
// 				ff8funcs.Sub47E080(5);
// 				ff8funcs.Sub485F00(ff8vars.attack_queue_count - 1);
// 				ff8vars.attack_queue_data[ff8vars.attack_queue_count - 1].attack_type = 0;
// 				*((WORD*)ff8funcs.Sub47E3F0(0x71, 0x80, (void(*)())0x487670)) = local50;
// 				ff8funcs.Sub47E080(6);
// 				break;
// 			case 0x2E:
// 				ff8funcs.Sub48EF50(ff8vars.character_info[monsterId].unkword1D27B94, &local30);
// 				BYTE value = ff8funcs.Sub4837E0(local30, 0);
// 				ff8vars.character_info[monsterId].unkbyte1D27BC8 = value;
// 				if (value != 0xFF) {
// 					ff8vars.unkbyte1D28E11 = 2;
// 					ff8vars.unkbyte1D28E12 = value;
// 					value = local30;
// 				}
// 				local34 = value;
// 				local50 = value;

// 				if (value == 0xFF) {
// 					break;
// 				}

// 				ff8vars.unkbyte1D28E13 = ff8funcs.Sub483790(local34, ff8vars.character_info[monsterId].unkbyte1D27BC8);
// 				int edx = 0; //TODO replace with message speed
// 				ff8funcs.Sub47E220(ff8funcs.Sub495280(ff8funcs.Sub495210(ff8funcs.Sub495210(ff8funcs.Sub495210(ff8funcs.GetCharacterName1(local34), 7, ff8funcs.GetMiscText(0x1B)), *ff8funcs.GetMiscText(0xB), ff8funcs.GetMagicName(ff8vars.unkbyte1D28E12)), *ff8funcs.GetMiscText(0xB) ,ff8funcs.GetMiscText(0x75))), edx, 3, 0x80, 0x56);
// 				break;
// 			case 0x29:
// 				ff8funcs.Sub48EF50(ff8vars.character_info[monsterId].unkword1D27B94, &local38);
// 				BYTE value = ff8funcs.Sub4837E0(local38, 0);
// 				ff8vars.character_info[monsterId].unkbyte1D27BC8 = value;
// 				if (value != 0xFF) {
// 					ff8vars.unkbyte1D28E11 = 2;
// 					ff8vars.unkbyte1D28E12 = value;
// 					value = local38;
// 				}
// 				local50 = value;

// 				if (value == 0xFF) {
// 					break;
// 				}

// 				ff8vars.unkbyte1D28E13 = 1;
// 				int edx = 0; //TODO replace with message speed
// 				//TODO finish
// 				break;
// 			case 0x1A:
// 				break;
// 			case 0x22:
// 				break;
// 			case 0x18:
// 				break;
// 			case 0x01:
// 				break;
// 			case 0x25:
// 				break;
// 			case 0x0E:
// 				local50 = *esi++;
// 				local51 = *esi++;
// 				if (local51 == 0xCB) {
// 					local51 = ff8vars.character_info[monsterId].lastAttacker;
// 				}
// 				ff8vars.character_info[monsterId].localVars[local50 - 0xDC] = local51;
// 				break;
// 			case 0x0F:
// 				local50 = *esi++;
// 				local51 = *esi++;
// 				ff8vars.battle_vars[local50 - 0x60] = local51;
// 				break;
// 			case 0x11:
// 				local50 = *esi++;
// 				local51 = *esi++;
// 				ff8vars.saveGame.battle_vars[local50 - 0x50] = local51;
// 				break;
// 			case 0x12:
// 				local50 = *esi++;
// 				local51 = *esi++;
// 				if (local51 == 0xCB) {
// 					local51 = ff8vars.character_info[monsterId].lastAttacker;
// 				}
// 				ff8vars.character_info[monsterId].localVars[local50 - 0xDC] += local51;
// 				break;
// 			case 0x13:
// 				local50 = *esi++;
// 				local51 = *esi++;
// 				ff8vars.battle_vars[local50 - 0x60] += local51;
// 				break;
// 			case 0x15:
// 				local50 = *esi++;
// 				local51 = *esi++;
// 				ff8vars.saveGame.battle_vars[local50 - 0x50] += local51;
// 				break;
// 			case 0x2D:
// 				local50 = *esi++;
// 				//TODO
// 				break;
// 			case 0x02:
// 				break;
// 			case 0x23:
// 				break;
// 			case 0x0C:
// 				break;
// 			case 0x06:
// 				break;
// 			case 0x0D:
// 				break;
// 			case 0x19:
// 				break;
// 			case 0x0B:
// 				break;
// 			case 0x16:
// 				break;
// 			case 0x17:
// 				break;
// 			case 0x27:
// 				break;
// 			case 0x28:
// 				break;
// 			case 0x09:
// 				break;
// 			case 0x05:
// 				break;
// 			case 0x1E:
// 				break;
// 			case 0x03:
// 				break;
// 			case 0x07:
// 				break;
// 			case 0x2A:
// 				break;
// 			case 0x26:
// 				break;
// 			case 0x2B:
// 				break;
// 			case 0x04:
// 				break;
// 			case 0x1D:
// 				break;
// 			case 0x08:
// 				break;
// 			case 0x2C:
// 				break;
// 			case 0x2F:
// 				break;
// 			case 0x30:
// 				break;
// 			case 0x31:
// 				break;
// 			case 0x32:
// 				break;
// 			case 0x33:
// 				break;
// 			case 0x35:
// 				break;
// 			case 0x36:
// 				break;
// 			case 0x37:
// 				break;
// 			case 0x38:
// 				break;
// 			case 0x39:
// 				break;
// 			case 0x3A:
// 				break;
// 			case 0x3C:
// 				break;
// 			case 0x3D:
// 				break;

// 		}
// 	}
// }