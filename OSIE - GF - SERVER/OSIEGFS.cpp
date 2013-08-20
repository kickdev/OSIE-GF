#include "stdafx.h"

extern HANDLE g_Server;
extern CVars g_Vars; // global params

CLog* g_Log = (CLog*)0x0913EDD0;

void ShowLog(void* pVoid, int nParam, const char* _str, ...)
{
	Guard(__WFUNCSIG__);

	g_Log->Add(CLog::blue, "L2Server Start and Patched by OSI Extender");

	UnGuard();
}

void RedErrorBlock(void* pVoid, int nParam, const wchar_t* wstr, ...)
{
	Guard(__WFUNCSIG__);

	g_Log->Add(CLog::red, "Test vars = %d", g_Vars.GetTestValue());

	UnGuard();
}

void DllInitializer(HMODULE hDllModule, DWORD ul_reason_for_call)
{
//	Msg(L"Load", L"[%s]\n DbgBreak", __WFILE__);

	if(ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		if(((UINT64)hDllModule) < 0x7E000000 && ((UINT64)(&g_Server)) < 0x7F000000)
		{
			if(*((UINT64*)0x401000) == 0xC6006406C1058D48)
			{
				if(g_Server = OpenProcess(PROCESS_ALL_ACCESS | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, GetCurrentProcessId()))
				{
					g_Vars.Initialize(); // initialization ini file
//					Msg(L"Load", L"[%s]\n complete loaded", __WFILE__);
					WriteInstructionCALL(0x006B3423, 0x006B3423 + 5, (void *)ShowLog);		//copyrite DevExt
					WriteInstructionCALL(0x006D323A, 0x006D323A + 5, (void *)RedErrorBlock);	//mallok rederr block
					WriteInstructionCALL(0x0042E44A, 0x0042E44A + 5, (void *)RedErrorBlock);	//move venicle rederr block
					//L2Server Protocol start
					WriteMemoryBYTES(0x00C6BD83, (void *)g_Vars.GetServerProtocol(), strlen(g_Vars.GetServerProtocol()));
					//L2Server Protocol end
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
		{	//некоторые 7ки х64 дллку в целях безопасности грузят выше 0x80000000 оффсета, что не дает возможности применять E8/E9 7F FF FF FF прыжки
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
	t f = (t)0x0068EA18;
	unsigned char* pReturn = f(buf, format, va);
	va_end(va);
	UnGuard();
	return pReturn;
}
