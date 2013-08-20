#pragma once

unsigned char* Disassemble(unsigned char* buf, const char* format, ...);

__forceinline void Guard(const wchar_t* pFuncName)
{
	UINT32 thr_index = *((UINT32*)(*((UINT64*)__readgsqword(0x58)) + 0x10));
	((const wchar_t**)0x191D530)[((thr_index * 1000) + ((UINT32*)0x194C330)[thr_index]++)] = pFuncName;
};

__forceinline void UnGuard()
{
	UINT32 thr_index = *((UINT32*)(*((UINT64*)__readgsqword(0x58)) + 0x10));
	((UINT32*)0x194C330)[thr_index]--;
};

#define UnGuardRet(x) { UnGuard(); return x; } // without ; ending
