#include "stdafx.h"

HANDLE g_Server = NULL;
CLog* g_Log = (CLog*)0x01962620;
CUserDb* g_UserDb = (CUserDb*)0x0273A1D0;

void DllInitializer(HMODULE hDllModule, DWORD ul_reason_for_call)
{
	if(ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		if(((UINT64)hDllModule) < 0x7C000000)
		{
			if(*((UINT64*)0x401000) == 0x48001E9D09058D48)
			{
				if((g_Server = OpenProcess(PROCESS_ALL_ACCESS | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, GetCurrentProcessId())))
				{
					//AdminPacket - MoveItem2Packet fix: cached crash if item not finded by dbid
					WriteMemoryQWORD(0x6A3320, (UINT64)MoveItem2Packet);

					CloseHandle(g_Server);
					g_Server = NULL;
				}
				else
					ExitProcess(1); //write access not given
			}
			else
				ExitProcess(1); //is not valid cache gf app
		}
		else
			ExitProcess(1); //dll loaded on bad allocation address (win7 fix)
	}
	else if(ul_reason_for_call == DLL_THREAD_ATTACH)
	{
		//
	}
	else if(ul_reason_for_call == DLL_THREAD_DETACH)
	{
		//
	}
	else if(ul_reason_for_call == DLL_PROCESS_DETACH)
	{
		//
	}
}

__declspec(dllexport) BOOL APIENTRY DllMain(HMODULE hDllModule, DWORD ul_reason_for_call, LPVOID pReserved)
{
	switch(ul_reason_for_call)
	{
	case DLL_PROCESS_DETACH:
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		{
			DllInitializer(hDllModule, ul_reason_for_call);
			break;
		}
	}
	return TRUE;
}

void WriteMemoryBYTES(UINT32 uAddress, LPVOID bytes, UINT32 len)
{
	DWORD flOldProtect;
	SIZE_T uNumberOfBytesWritten;
	HANDLE hServer;
	
	if((hServer = g_Server))
	{
		VirtualProtectEx(hServer, (LPVOID)uAddress, len, PAGE_WRITECOPY, &flOldProtect);
		WriteProcessMemory(hServer, (LPVOID)uAddress, bytes, len, &uNumberOfBytesWritten);
		FlushInstructionCache(hServer, (LPVOID)uAddress, len);
		VirtualProtectEx(hServer, (LPVOID)uAddress, len, flOldProtect, &flOldProtect);
	}
}

void WriteMemoryQWORD(UINT32 uAddress, QWORD value)	{ WriteMemoryBYTES(uAddress, &value, 8); }
void WriteMemoryDWORD(UINT32 uAddress, DWORD value)	{ WriteMemoryBYTES(uAddress, &value, 4); }
void WriteMemoryWORD(UINT32 uAddress, WORD value)	{ WriteMemoryBYTES(uAddress, &value, 2); }
void WriteMemoryBYTE(UINT32 uAddress, BYTE value)	{ WriteMemoryBYTES(uAddress, &value, 1); }

unsigned char* Disassemble(unsigned char* buf, const char* format, ...)
{
	Guard(__WFUNCTION__);
	va_list va;
	va_start(va, format);
	typedef unsigned char* (__stdcall *t)(unsigned char*, const char*, va_list);
	t f = (t)0x004737A4;
	unsigned char* pReturn = f(buf, format, va);
	va_end(va);
	UnGuard();
	return pReturn;
}
