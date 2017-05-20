#pragma once

#define CALL_ORIGINAL(function, args) \
			ENDREDIRECT(function); \
			ff8funcs.function args; \
			REDIRECT(function);

#define CALL_ORIGINAL_RET(function, args) \
			[=](){ \
				ENDREDIRECT(function); \
				auto returnValue = ff8funcs.function args; \
				REDIRECT(function); \
				return returnValue; \
			}()

#define FF8_STUB(functionName, argDef, argList) \
			void functionName argDef { \
				CALL_ORIGINAL(functionName, argList) \
			}

#define FF8_STUB_RET(function, argDef, argList) \
			auto function argDef { \
				return CALL_ORIGINAL(function, argList, return_value); \
			}

#define REDIRECT(function) \
			BeginRedirect(ff8funcs.function, function);

#define ENDREDIRECT(function) \
			EndRedirect(ff8funcs.function);

void PatchAddresses();
void PatchFunctions();
void UnpatchFunctions();
void BeginRedirect(LPVOID oldFunction, LPVOID newFunction);
void EndRedirect(LPVOID function);
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
DWORD DrawPrimitives(DWORD arg1, DWORD arg2, DWORD arg3, DWORD arg4, DWORD arg5, DWORD arg6, DWORD arg7, DWORD arg8);