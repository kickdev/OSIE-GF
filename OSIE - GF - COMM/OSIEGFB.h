#pragma once

unsigned char* Disassemble(const unsigned char* buf, const char* format, ...);

__forceinline void Guard(const wchar_t* pFuncName)
{
	UINT32 thr_index = *((UINT32*)(*((UINT64*)__readfsdword(0x2C)) + 0x08));
	((const wchar_t**)0x14D0168)[((thr_index * 1000) + ((UINT32*)0x14F33E8)[thr_index]++)] = pFuncName;
};

__forceinline void UnGuard()
{
	UINT32 thr_index = *((UINT32*)(*((UINT64*)__readfsdword(0x2C)) + 0x08));
	((UINT32*)0x14F33E8)[thr_index]--;
};

#define UnGuardRet(x) { UnGuard(); return x; } // without ; ending
