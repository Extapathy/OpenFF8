#pragma once

#include "stdafx.h"
#include "structures.h"

LinkTask* BdLinkTask(TaskList& task_list, int(*task)(LinkTask& task_data));
LinkTask* GetFreeLinkTask(const TaskList& task_list);
int DoLinkTask(TaskList& task_list);
int PlayMagic(LinkTask& task_data);