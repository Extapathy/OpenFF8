#include "stdafx.h"
#include "battle.h"
#include "memory.h"
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

	OutputDebugString("BdLinkTask: FAILED !!!!\n");
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

int PlayMagic(LinkTask& task_data) {
	MagicData& magic_data = **ff8vars.magic_data_ptr;
	BYTE* task = (BYTE*)&task_data;
	BYTE& state = *(task + 0x0D);
	BYTE* link_task = NULL;
	switch (state) {
		case 0:
			*ff8vars.unkbyte1D99A85 = ff8funcs.CameraRelated(magic_data, *ff8vars.unkword1D99A5C);
			state++;
		case 1:
			if (*ff8vars.unkbyte1D99A85 != 0) {
				if (ff8funcs.Sub508580(0x1A, 0x40) != 0) return 0;
			}
			else {
				if (ff8funcs.Sub50ADE0() != 0) return 0;
			}
			state++;
		case 2:
			*ff8vars.unkdword1D96A9C |= 0x10;
			ff8funcs.Sub50AFC0();
			if ((magic_data.attack_type == 0x0B && magic_data.unkword04 == 0xFFFB) || magic_data.attack_type == 0x0E) {
				*ff8vars.unkbyte1D99A80 = 0;
			}
			(*ff8vars.unkstruct1D99A40)->unkdword08 &= 0xFF7FFFFF;
			ff8funcs.Sub505C00(**ff8vars.unkstruct1D99A40, magic_data.attack_type);
			ff8funcs.Sub506190(magic_data, *ff8vars.unkbyte1D99A85);
			ff8funcs.LoadMagicID(magic_data.magic_id, ff8vars.current_magic_init_function);
			state++;
			return 0;
		case 3: //Cast animation
			if (*ff8vars.unkbyte1D96A90 > 0 && (*ff8vars.unkdword1D96A9C & 0x20000000) == 0) return 0;
			if (*ff8vars.unkdword1D999C8 <= 0) return 0;
			if (*ff8vars.unkbyte1D97718 != 0) return 0;
			if ((*ff8vars.unkstruct1D99A40)->unkdword8C == 0) {
				*((*ff8vars.unkstruct1D99A40)->unkbyteptr74 + 0x2C) |= 0x10;
				state++;
				return 0;
			}
			link_task = (BYTE*)ff8funcs.Sub506C10(ff8funcs.Sub50B080);
			*(WORD*)(link_task + 0x10) = 0x10;
			*(DWORD*)(link_task + 0x0C) = (*ff8vars.unkstruct1D99A40)->unkdword00;
			state++;
			return 0;
		case 4:
			if (*ff8vars.unkbyte1D96A90 > 0 && (*ff8vars.unkdword1D96A9C & 0x20000000) == 0) return 0;
			if ((*((*ff8vars.unkstruct1D99A40)->unkbyteptr74 + 0x2C) & 0x20) != 0) {
				state++;
				if (*ff8vars.unkword1D99A90 != 0) {
					//WORD temp = *(WORD*)(ff8vars.unkbyte1D99A84)
				}
			}
			//TODO finish case 4
		case 5: //Init magic
			*(WORD*)((*ff8vars.unkstruct1D99A40)->unkbyteptr74 + 0x2C) &= 0xFFDF;
			if ((*ff8vars.unkdword1D96A9C & 0x20000000) != 0) {
				//TODO missing line
				*ff8vars.unkdword1D96A9C &= 0xDFFFFFFF;

			}
			if ((magic_data.attack_type == 0x02 || magic_data.attack_type == 0x06) && (*ff8vars.unkstruct1D99A40)->unkbyte04 >= 0x10) {
				*ff8vars.unkdword1D96A9C |= 0x20;
			}
			*ff8vars.current_magic_task_list = (*ff8vars.current_magic_init_function)(*ff8vars.current_magic_init_data);
			if (magic_data.attack_type == 0xFE) {
				ff8funcs.Sub56DCE0(*ff8vars.unkbyte1D28DF7, magic_data.unkword04);
			}
			*ff8vars.unkword1D99A8E = 0;
			state++;
			return 0;
		case 6: //Magic animation
			if (magic_data.unkword04 == 0xFFFE) {
				if (*ff8vars.current_magic_task_list == NULL) {
					state++;
				}
				return 0;
			}
			if (magic_data.attack_type != 0x0B && magic_data.attack_type != 0x0E) {
				if (ff8funcs.Sub50AE80() != 0) {
					if (*ff8vars.current_magic_task_list == NULL) return 0;
					if (++(*ff8vars.unkword1D99A8E) < 0x384) return 0;
					ff8funcs.InitializeSound_CAL();
					return 0;
				}
				ff8funcs.Sub50AED0();
				if ((*ff8vars.unkbyte1D99A79 & 0x02) == 0) {
					*ff8vars.unkdword1D96A9C &= 0xEF;
				}
				if (*ff8vars.unkword1D99A90 == 0) {
					state++;
					return 0;
				}

			}
			//TODO finish rest
			break;
		case 7:
			break;
		default:
			return 0;
	}
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