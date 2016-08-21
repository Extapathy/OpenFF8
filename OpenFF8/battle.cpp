#include "stdafx.h"
#include "battle.h"
#include "memory.h"
#include <algorithm>

LinkTask* BdLinkTask(TaskList& task_list, int(*task)(LinkTask* task_data)) {
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
		if ((task->function(task) & 0x02) != 0) {
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