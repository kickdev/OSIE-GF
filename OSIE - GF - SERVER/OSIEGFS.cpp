#include "stdafx.h"

extern HANDLE g_Server;
CLog* g_Log = (CLog*)0x0913EDD0;
CTradeManager* g_TradeManager = (CTradeManager*)0x11F3C9C0;

void ShowLog(void* pVoid, int nParam, const char* _str, ...)
{
	Guard(__WFUNCSIG__);

	g_Log->Add(CLog::blue, "L2Server Start and Patched by OSI Extender");
	g_Log->Add(CLog::red, "Test vars = %d", g_Vars.GetTestValue());

	UnGuard();
}

void ExtendUserDataSize()
{
	WriteMemoryDWORD(0x5AEF0E, sizeof(CUser));
	WriteMemoryDWORD(0x5E1869, sizeof(CUser));
}

void ExtendUserSocketDataSize()
{
	WriteMemoryDWORD(0x91BFEE, sizeof(CUserSocket));
	WriteMemoryDWORD(0x93CEC1, sizeof(CUserSocket));
}

void RedErrorBlock()
{
	NOPMemory(0x42E44A, 5); //Airship(1) Move ...
	NOPMemory(0x6D323A, 5); //malloc >32k
}

void MaxIndexExtend() //crash may be
{
	const unsigned int uMaxIndex = 20000; //default 10000

	WriteMemoryDWORD(0x629E58, (uMaxIndex - 1)); // -> L2GFExt
	WriteMemoryDWORD(0x643F3F, (uMaxIndex - 1)); // -> L2GFExt
	WriteMemoryDWORD(0x6AE331, (uMaxIndex - 1)); // -> L2GFExt
	WriteMemoryDWORD(0x7A76D9, (uMaxIndex - 1)); // -> L2GFExt
	WriteMemoryDWORD(0x7A9AA3, (uMaxIndex - 1)); // -> L2GFExt
	WriteMemoryDWORD(0xA268B3, (uMaxIndex - 1)); // -> L2GFExt

	//WriteMemoryDWORD(0x4065D3, uMaxIndex); //
	//WriteMemoryDWORD(0x41797B, uMaxIndex); //
	//WriteMemoryDWORD(0x421640, uMaxIndex); //
	WriteMemoryDWORD(0x443D6B, uMaxIndex); // -> L2GFExt
	//WriteMemoryDWORD(0x44CFB5, uMaxIndex); //
	//WriteMemoryDWORD(0x4C5FD1, uMaxIndex); //
	//WriteMemoryDWORD(0x4C60F1, uMaxIndex); //
	//WriteMemoryDWORD(0x4C622D, uMaxIndex); //
	//WriteMemoryDWORD(0x4CFE6F, uMaxIndex); //
	//WriteMemoryDWORD(0x4F4E13, uMaxIndex); //
	WriteMemoryDWORD(0x5354A6, uMaxIndex); // -> L2GFExt
	//WriteMemoryDWORD(0x5E9D64, uMaxIndex); //
	//WriteMemoryDWORD(0x5F648F, uMaxIndex); //
	//WriteMemoryDWORD(0x5F68FB, uMaxIndex); //
	//WriteMemoryDWORD(0x604B71, uMaxIndex); //
	//WriteMemoryDWORD(0x624771, uMaxIndex); //
	//WriteMemoryDWORD(0x625CF4, uMaxIndex); //
	//WriteMemoryDWORD(0x62C000, uMaxIndex); //
	//WriteMemoryDWORD(0x63C054, uMaxIndex); //
	//WriteMemoryDWORD(0x677247, uMaxIndex); //
	//WriteMemoryDWORD(0x68F467, uMaxIndex); //
	//WriteMemoryDWORD(0x68F4DF, uMaxIndex); //
	//WriteMemoryDWORD(0x690045, uMaxIndex); //
	//WriteMemoryDWORD(0x69407F, uMaxIndex); //
	//WriteMemoryDWORD(0x69C82D, uMaxIndex); //
	//WriteMemoryDWORD(0x6AC448, uMaxIndex); //
	WriteMemoryDWORD(0x6AE4BD, uMaxIndex); // -> L2GFExt
	//WriteMemoryDWORD(0x6B2180, uMaxIndex); //
	//WriteMemoryDWORD(0x6B42A4, uMaxIndex); //
	//WriteMemoryDWORD(0x6B53EE, uMaxIndex); //
	//WriteMemoryDWORD(0x6B5D8E, uMaxIndex); //
	//WriteMemoryDWORD(0x6B6A98, uMaxIndex); //
	//WriteMemoryDWORD(0x6B6BE9, uMaxIndex); //
	//WriteMemoryDWORD(0x6B7A27, uMaxIndex); //
	//WriteMemoryDWORD(0x6EAD59, uMaxIndex); //
	WriteMemoryDWORD(0x71E052, uMaxIndex); // -> L2GFExt
	WriteMemoryDWORD(0x763124, uMaxIndex); // -> L2GFExt
	WriteMemoryDWORD(0x77C2B7, uMaxIndex); // -> L2GFExt
	WriteMemoryDWORD(0x77CD45, uMaxIndex); // -> L2GFExt
	//WriteMemoryDWORD(0x77CFFB, uMaxIndex); //
	WriteMemoryDWORD(0x77DC42, uMaxIndex); // -> L2GFExt
	WriteMemoryDWORD(0x77DD45, uMaxIndex); // -> L2GFExt
	//WriteMemoryDWORD(0x7A2FBC, uMaxIndex); //
	//WriteMemoryDWORD(0x7AEBE5, uMaxIndex); //
	//WriteMemoryDWORD(0x7B690F, uMaxIndex); //
	//WriteMemoryDWORD(0x7B9A39, uMaxIndex); //
	//WriteMemoryDWORD(0x7C0693, uMaxIndex); //
	WriteMemoryDWORD(0x7C7EF9, uMaxIndex); // -> L2GFExt
	WriteMemoryDWORD(0x7C95D5, uMaxIndex); // -> L2GFExt
	//WriteMemoryDWORD(0x825511, uMaxIndex); //
	WriteMemoryDWORD(0x860E49, uMaxIndex); // -> L2GFExt
	WriteMemoryDWORD(0x8619F1, uMaxIndex); // -> L2GFExt
	//WriteMemoryDWORD(0x86FA04, uMaxIndex); //
	//WriteMemoryDWORD(0x86FC48, uMaxIndex); //
	//WriteMemoryDWORD(0x88CD47, uMaxIndex); //
	//WriteMemoryDWORD(0x89184C, uMaxIndex); //
	//WriteMemoryDWORD(0x8AFEA0, uMaxIndex); //
	//WriteMemoryDWORD(0x8FA544, uMaxIndex); //
	//WriteMemoryDWORD(0x8FB393, uMaxIndex); //
	//WriteMemoryDWORD(0x94E406, uMaxIndex); //
	//WriteMemoryDWORD(0x959174, uMaxIndex); //
	//WriteMemoryDWORD(0x96F0AC, uMaxIndex); //
	//WriteMemoryDWORD(0x970571, uMaxIndex); //
	//WriteMemoryDWORD(0xA28DE5, uMaxIndex); //
	//WriteMemoryDWORD(0xA29175, uMaxIndex); //
	//WriteMemoryDWORD(0xA2A6B1, uMaxIndex); //

	WriteMemoryDWORD(0xE5BB60, uMaxIndex); //L2World_StaticObject
	WriteMemoryDWORD(0xE5BBB0, uMaxIndex); //L2World_Pledge
	WriteMemoryDWORD(0xE5BC00, uMaxIndex); //L2World_Party
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
				if((g_Server = OpenProcess(PROCESS_ALL_ACCESS | PROCESS_VM_READ | PROCESS_VM_WRITE, FALSE, GetCurrentProcessId())))
				{
					BYTE uRpgClubType = NULL;
					HMODULE hRpgClubModule;
					const wchar_t* pRpgClubDllName = L"L2GFExt.dll";
					if((hRpgClubModule = GetModuleHandleW(pRpgClubDllName)))
					{
						if(*((UINT64*)(((UINT64)hRpgClubModule) + 0x1000)) == 0x48000243A9058D48)
							uRpgClubType = 1;
						else
						{
							Msg(L"LoadWarning", L"[%s]\n not supported version of %s detected", __WFILE__, pRpgClubDllName);
//							ExitProcess(1);
						}
					}

					CCodeRestorator CodeRestorator;

#ifdef L2SERVER_DEBUG
					CodeRestorator.bIsShowRate = true;
#endif // L2SERVER_DEBUG

					if(uRpgClubType && CodeRestorator.OpenParentFile(g_Server, 0xC6006406C1058D48))
					{
						CodeRestorator.RestoreFunctionCode(0x93CE54); //sub_180001410 CUserSocket__Allocate [168]
						CodeRestorator.RestoreFunctionCode(0x92DE7C); //sub_180001490 CUserSocket::~CUserSocket [241]
						CodeRestorator.RestoreFunctionCode(0x92EB3C); //sub_180017EB0 CUserSocket::OnRead (in_code) [1673]
						CodeRestorator.RestoreFunctionCode(0x5E0644); //sub_180017EE2 LoadSelectedCharacterPacket [9515]
						CodeRestorator.RestoreFunctionCode(0x91CB48); //sub_180001050 ActionPacket [258]
						CodeRestorator.RestoreFunctionCode(0x91C220); //sub_180001070 AttackPacket [385]
						CodeRestorator.RestoreFunctionCode(0x93F7F0); //sub_180001090 CUserSocket::LoginPacket [2031]
						CodeRestorator.RestoreFunctionCode(0x8C5320); //sub_180001150 User::OnEnterWorldPacket [2005]
					}

					ExtendUserDataSize();
					ExtendUserSocketDataSize();
					RedErrorBlock();
					MaxIndexExtend();

					WriteInstruction(0x93CEDC, (UINT32)CUserSocket::UserSocketConstructor, 0xE8);		//sub_180001410 CUserSocket__Allocate
					WriteInstruction(0x92E068, (UINT32)CUserSocket::UserSocketDestructor, 0xE8);		//sub_180001490 CUserSocket::~CUserSocket
					WriteInstruction(0x5E1ACA, (UINT32)CUser::UserConstructor, 0xE8);					//sub_180017EE2, sub_180017EFF LoadSelectedCharacterPacket (in_code) set bulder lvl1 (maybe here epilog 152 protocol implimentation be in orig version)
					WriteInstruction(0x8D4340, (UINT32)CUser::UserDestructor, 0xE8);					//			
					WriteInstructionJmp(0x92EF0B, (UINT32)CUserSocket::OutGamePacketHandler, 0x92EF17);	//sub_180017EB0 CUserSocket::OnRead (in_code), sub_180001050 ActionPacket (simple check to exist pUserSocketExt->pUserSocket), sub_180001070 AttackPacket (simple check to exist pUserSocketExt->pUserSocket), sub_180001090 CUserSocket::LoginPacket
					WriteInstructionJmp(0x92EDFE, (UINT32)CUserSocket::InGamePacketHandler, 0x92EE0C);	//sub_180017EB0 CUserSocket::OnRead (in_code), sub_180001150 User::OnEnterWorldPacket
					WriteMemoryQWORD(0x92EAE0, 0x8B48D38B49C28B44);
					WriteMemoryQWORD(0x92EAE8, 0x98248489482024CB);
					WriteInstructionCall(0x92EAE9, (UINT32)CUserSocket::GamePacketExHandler, 0x92EB03);	//

					//Msg(L"Load", L"[%s]\n complete loaded, 0x%08X", __WFILE__, *((UINT32*)0x5E1869));
					g_Vars.Initialize(); // initialization ini file

					WriteInstruction(0x6B3423, (UINT32)ShowLog, 0xE8);			//copyrite DevExt
					//L2Server Protocol start
					WriteMemoryBYTES(0xC6BD83, (void *)g_Vars.GetServerProtocol(), strlen(g_Vars.GetServerProtocol()));
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
	t f = (t)0x0068EA18;
	unsigned char* pReturn = f(buf, format, va);
	va_end(va);
	UnGuard();
	return pReturn;
}
