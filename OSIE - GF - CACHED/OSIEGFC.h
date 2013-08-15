#pragma once

void WriteMemoryBYTES(UINT32 uAddress, LPVOID bytes, UINT32 len);
void WriteMemoryQWORD(UINT32 uAddress, QWORD value);
void WriteMemoryDWORD(UINT32 uAddress, DWORD value);
void WriteMemoryWORD(UINT32 uAddress, WORD value);
void WriteMemoryBYTE(UINT32 uAddress, BYTE value);

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
