#include "stdafx.h"
#include "Level80System.h"

void CLevel80System::Initialize()
{
	SetMaxLevel(80);
}

void CLevel80System::SetMaxLevel(UINT32 uMaxLevel)
{
	/*
	 * .text:0000000000562C8B                 mov     ebp, 55h // main level 85
	 * .text:0000000000562C9D                 mov     ebp, 50h // sub level 80
	 * .text:0000000000562CA4                 mov     ebp, 63h // npc level 99
	 */
	WriteInstruction(0x562C8B, uMaxLevel, 0xBD); //Change main class max  level

	//.text:00000000004877BE                 cmp     rax, 54h // level 85 - 1 = 84
	WriteMemoryBYTE(0x4877C1, (BYTE)(uMaxLevel - 1));

	//.text:00000000007A620C                 cmp     eax, 54h // level 85 - 1 = 84
	WriteMemoryBYTE(0x7A620E, (BYTE)(uMaxLevel - 1));
}