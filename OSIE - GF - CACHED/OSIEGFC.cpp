#include "stdafx.h"

extern HANDLE g_Server;
CLog* g_Log = (CLog*)0x01962620;
CUserDb* g_UserDb = (CUserDb*)0x0273A1D0;

void DllInitializer(HMODULE hDllModule, DWORD ul_reason_for_call)
{
//	Msg(L"Load", L"[%s]\n DbgBreak", __WFILE__);

	if(ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		if(((UINT64)hDllModule) < 0x7E000000 && ((UINT64)(&g_Server)) < 0x7F000000)
		{
			if(*((UINT64*)0x401000) == 0x48001E9D09058D48)
			{
				if((g_Server = OpenProcess(PROCESS_ALL_ACCESS | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, GetCurrentProcessId())))
				{
					//AdminPacket - MoveItem2Packet fix: cached crash if item not finded by dbid
					WriteMemoryQWORD(0x6A3320, (UINT64)MoveItem2Packet);

//					Msg(L"Load", L"[%s]\n complete loaded", __WFILE__);

					CloseHandle(g_Server);
					g_Server = NULL;
				}
				else
				{
					Msg(L"LoadError", L"[%s]\n write access not given", __WFILE__);
					ExitProcess(1);
				}
			}
			else
			{
				Msg(L"LoadError", L"[%s]\n is not valid application\nOr dll incompatible this app", __WFILE__);
				ExitProcess(1);
			}
		}
		else
		{	//в некоторых случаях дллка грузится выше 0x80000000 оффсета, что не дает возможности применять E8/E9 7F FF FF FF прыжки
			Msg(L"LoadError", L"[%s]\n dll loaded on bad allocation address (win7 fix)", __WFILE__);
			ExitProcess(1);
		}
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
//	case DLL_PROCESS_DETACH:
	case DLL_PROCESS_ATTACH:
//	case DLL_THREAD_ATTACH:
//	case DLL_THREAD_DETACH:
		{
			DllInitializer(hDllModule, ul_reason_for_call);
			break;
		}
	}
	return TRUE;
}

unsigned char* Disassemble(unsigned char* buf, const char* format, ...)
{
	Guard(__WFUNCSIG__);
	va_list va;
	va_start(va, format);
	typedef unsigned char* (__cdecl *t)(unsigned char*, const char*, va_list);
	t f = (t)0x004737A4;
	unsigned char* pReturn = f(buf, format, va);
	va_end(va);
	UnGuard();
	return pReturn;
}
