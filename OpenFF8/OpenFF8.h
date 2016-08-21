#pragma once

void PatchAddresses();
void PatchFunctions();
void BeginRedirect(LPVOID oldFunction, LPVOID newFunction);