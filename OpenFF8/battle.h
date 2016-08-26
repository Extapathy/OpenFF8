#pragma once

#include "stdafx.h"
#include "structures.h"

int LoadAttack(DWORD caster_id, DWORD kernel_id, DWORD id, DWORD unk1, DWORD unk2, DWORD target_mask, DWORD unk3);
LinkTask* BdLinkTask(TaskList& task_list, int(*task)(LinkTask& task_data));
LinkTask* GetFreeLinkTask(const TaskList& task_list);
int DoLinkTask(TaskList& task_list);
int PlayMagic(LinkTask& task_data);
DWORD Archive_GetFile(BYTE* filename);