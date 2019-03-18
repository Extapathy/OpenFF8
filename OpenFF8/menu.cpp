#include "memory.h"
#include "menu.h"

void FFMenuModule(BufApp0xC10* pBufApp0xC10) {
	ff8vars.unkqword1D2BB88 = ff8vars.unkqword1D2BB90;

	if (ff8funcs.IsWindowActive())
		return;

	colorBGRA bgColor;
	bgColor.B = 1.0f;
	bgColor.G = 0.0f;
	bgColor.R = 0.0f;
	bgColor.A = 1.0f;
	ff8funcs.FFSetBGMaterial(&bgColor, pBufApp0xC10);
	ff8funcs.FFClearViewport(1, 1, 1, pBufApp0xC10);

	if (ff8funcs.FFBeginAndDrawScene(0, pBufApp0xC10) != 0)
	{
		ff8funcs.Sub43FBE8(pBufApp0xC10);
		ff8funcs.Sub409B42(pBufApp0xC10);
		ff8funcs.Sub409B08(pBufApp0xC10);
		ff8funcs.Sub409B25(pBufApp0xC10);
		ff8funcs.Sub416B9A(ff8vars.unkptr1D2A284);
		ff8funcs.Sub424BF9(ff8vars.unkptr1D2A288);
		ff8funcs.Sub49B120();
		ff8vars.unkdword209AB54 = 1; // done in a function
		ff8funcs.UpdateTimers();

		DWORD result = ff8funcs.Sub497380(ff8vars.unkdword1D2BB98, ff8vars.unkdword0B87798, 0, 0);
		if ((result & 0x400) != 0)
		{
			ff8vars.unkdword1D2BB9C = result;
			void* buffer = ff8funcs.FFGetBufferAddress();
			FFModuleInterface newModule;
			newModule.field08 = 0x470690;
			newModule.field0C = 0x4706A0;
			newModule.mainLoop = 0x4706B0;
			newModule.mouseInputHandler = 0;
			newModule.keyboardInputHandler = 0;
			ff8funcs.FFSwitchModule(&newModule, buffer);
			ff8funcs.Sub4647A0();
			*(DWORD*)((BYTE*)buffer + 0xB88) = 1;
			ff8funcs.Sub45B580();
		}

		ff8funcs.Sub4980C0();
		ff8funcs.Sub56BA50(ff8vars.unkdword209AB50, pBufApp0xC10);
		ff8funcs.Sub41E947(1, pBufApp0xC10);
		ff8funcs.Sub56BA50(ff8vars.unkdword209AB58, pBufApp0xC10);
		ff8funcs.Sub499EA0();
		ff8funcs.Sub45B450();
		ff8funcs.Sub499A40();
		ff8funcs.Sub41E99D(pBufApp0xC10);
	}

	ff8funcs.Sub56D9C0();

	do
	{
		ff8funcs.FFGetTime(&ff8vars.unkqword1D2BB90);
	} while (ff8vars.unkqword1D2BB90 - ff8vars.unkqword1D2BB88 < ff8vars.unkdouble1D2BB80);

	ff8vars.unkqword1D2BB88 = ff8vars.unkqword1D2BB90;
}