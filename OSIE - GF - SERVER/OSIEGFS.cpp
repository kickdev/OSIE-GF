#include "stdafx.h"
//патч http://rghost.ru/private/49610156/5b36d9ffd339959934aadd40bf9c4ba1
//Размеры переменных http://msdn.microsoft.com/ru-ru/library/s3f49ktz.aspx
extern HANDLE g_Server;
CLog* g_Log = (CLog*)0x0913EDD0;
CTradeManager* g_TradeManager = (CTradeManager*)0x11F3C9C0;
CFileLog g_AdminCmdLog = {0};
GFS g_GFS;
CVars* g_Vars = new CVars();

#ifdef L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM
DWORD g_MinPacketDelay[256] = {0};
DWORD g_MinPacketDelayEx[256] = {0};
#endif // L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM

void ShowLog(void* pVoid, int nParam, const char* _str, ...)
{
	Guard(__WFUNCSIG__);
	va_list va;
	va_start(va, _str);
	g_Log->Add(CLog::blue, "[OSIE] L2Server Start and Patched by OSI Extender");
	g_Log->Add((CLog::LogType)nParam, _str, va);
	va_end(va);
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

	WriteMemoryDWORD(0x629E58, (uMaxIndex - 1)); // -> L2GFExt, L2GFExtL2M
	WriteMemoryDWORD(0x643F3F, (uMaxIndex - 1)); // -> L2GFExt, L2GFExtL2M
	WriteMemoryDWORD(0x6AE331, (uMaxIndex - 1)); // -> L2GFExt, L2GFExtL2M
	WriteMemoryDWORD(0x7A76D9, (uMaxIndex - 1)); // -> L2GFExt, L2GFExtL2M
	WriteMemoryDWORD(0x7A9AA3, (uMaxIndex - 1)); // -> L2GFExt, L2GFExtL2M
	WriteMemoryDWORD(0xA268B3, (uMaxIndex - 1)); // -> L2GFExt, L2GFExtL2M

	//WriteMemoryDWORD(0x4065D3, uMaxIndex); //
	//WriteMemoryDWORD(0x41797B, uMaxIndex); //
	//WriteMemoryDWORD(0x421640, uMaxIndex); //
	WriteMemoryDWORD(0x443D6B, uMaxIndex); // -> L2GFExt, L2GFExtL2M
	//WriteMemoryDWORD(0x44CFB5, uMaxIndex); //
	//WriteMemoryDWORD(0x4C5FD1, uMaxIndex); //
	//WriteMemoryDWORD(0x4C60F1, uMaxIndex); //
	//WriteMemoryDWORD(0x4C622D, uMaxIndex); //
	//WriteMemoryDWORD(0x4CFE6F, uMaxIndex); //
	//WriteMemoryDWORD(0x4F4E13, uMaxIndex); //
	WriteMemoryDWORD(0x5354A6, uMaxIndex); // -> L2GFExt, L2GFExtL2M
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
	WriteMemoryDWORD(0x6AE4BD, uMaxIndex); // -> L2GFExt, L2GFExtL2M
	//WriteMemoryDWORD(0x6B2180, uMaxIndex); //
	//WriteMemoryDWORD(0x6B42A4, uMaxIndex); //
	//WriteMemoryDWORD(0x6B53EE, uMaxIndex); //
	//WriteMemoryDWORD(0x6B5D8E, uMaxIndex); //
	//WriteMemoryDWORD(0x6B6A98, uMaxIndex); //
	//WriteMemoryDWORD(0x6B6BE9, uMaxIndex); //
	//WriteMemoryDWORD(0x6B7A27, uMaxIndex); //
	//WriteMemoryDWORD(0x6EAD59, uMaxIndex); //
	WriteMemoryDWORD(0x71E052, uMaxIndex); // -> L2GFExt, L2GFExtL2M
	WriteMemoryDWORD(0x763124, uMaxIndex); // -> L2GFExt, L2GFExtL2M
	WriteMemoryDWORD(0x77C2B7, uMaxIndex); // -> L2GFExt, L2GFExtL2M
	WriteMemoryDWORD(0x77CD45, uMaxIndex); // -> L2GFExt, L2GFExtL2M
	//WriteMemoryDWORD(0x77CFFB, uMaxIndex); //
	WriteMemoryDWORD(0x77DC42, uMaxIndex); // -> L2GFExt, L2GFExtL2M
	WriteMemoryDWORD(0x77DD45, uMaxIndex); // -> L2GFExt, L2GFExtL2M
	//WriteMemoryDWORD(0x7A2FBC, uMaxIndex); //
	//WriteMemoryDWORD(0x7AEBE5, uMaxIndex); //
	//WriteMemoryDWORD(0x7B690F, uMaxIndex); //
	//WriteMemoryDWORD(0x7B9A39, uMaxIndex); //
	//WriteMemoryDWORD(0x7C0693, uMaxIndex); //
	WriteMemoryDWORD(0x7C7EF9, uMaxIndex); // -> L2GFExt, L2GFExtL2M
	WriteMemoryDWORD(0x7C95D5, uMaxIndex); // -> L2GFExt, L2GFExtL2M
	//WriteMemoryDWORD(0x825511, uMaxIndex); //
	WriteMemoryDWORD(0x860E49, uMaxIndex); // -> L2GFExt, L2GFExtL2M
	WriteMemoryDWORD(0x8619F1, uMaxIndex); // -> L2GFExt, L2GFExtL2M
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

	//WriteMemoryDWORD(0xE5BB60, uMaxIndex); //L2World_StaticObject
	//WriteMemoryDWORD(0xE5BBB0, uMaxIndex); //L2World_Pledge
	//WriteMemoryDWORD(0xE5BC00, uMaxIndex); //L2World_Party
}

void OnLoadEnd(UINT64 uClassBase)
{
	typedef UINT32 (__thiscall *t)(UINT64);
	t f = (t)0x00470544;
	if(f(uClassBase) == 0x0F)
	{
		//HWND hWnd;
		//if((hWnd = FindWindowW(L"__L2PATCHD__", NULL))) //L2PatchD api - auto start npc server at load end
		//{
		//	wstring cmd_line = L"-show_start_dlg -wait 250 -press_start_";
		//	cmd_line += (wchar_t)('0' + 4); //where 4 = # of app in "Start Settings" dialog
		//	cmd_line += L" -wait 500 -press_ok	-wait 250 -tray_hide";

		//	COPYDATASTRUCT cds;
		//	cds.cbData = (DWORD)(cmd_line.size() * 2); 
		//	cds.lpData = (PVOID)cmd_line.c_str(); 
		//	SendMessageW(hWnd, WM_COPYDATA, NULL, (LPARAM)&cds);
		//}
	}
}

typedef bool (__cdecl *tHtmlCmd)(CUserSocket*, CUser*, const wchar_t*, const wchar_t*);

bool __cdecl _HtmlCmdObserver(CUserSocket* pUserSocket, CUser* pUser, const wchar_t* pStr1, const wchar_t* pStr2)
{
	Guard(__WFUNCSIG__);

	bool bReturn;
	if(!pUser->IsNowTrade())
	{
		tHtmlCmd fHtmlCmd = (tHtmlCmd)0x948444;
		bReturn = fHtmlCmd(pUserSocket, pUser, pStr1, pStr2);
	}
	else
	{

#ifdef L2SERVER_DEBUG
		g_Log->Add(CLog::red, L"(FIXED BY L2M.RU) user [%s] try hack observer", pUser->SD->wszName);
#endif

		bReturn = false;
	}

	UnGuardRet(bReturn)
}

void __cdecl CPledge_CheckByPowerGradeId_Log_Fix(CPledge* pPledge, UINT32 uPowerGradeId)
{
	Guard(__WFUNCSIG__);

#ifdef L2SERVER_DEBUG
	g_Log->Add(CLog::red, L"(FIXED BY L2M.RU) Invalid Pledge Power GradeId %d, PledgeID %d, PledgeName [%s]", uPowerGradeId, pPledge->SD->uPledgeSID, pPledge->SD->wszClanName);
#endif

	UnGuard();
}

bool __cdecl _BuilderCmd2Handler(CUserSocket* pUserSocket, const unsigned char* packet)
{
	Guard(__WFUNCSIG__);

	bool bReturn;
	CUser* pUser = pUserSocket->User();
	if(pUser)
	{
		UINT32 i;
		wchar_t pBuff[960];
		for(i = 0; i < 960; i++)
		{
			if(!(pBuff[i] = ((wchar_t*)packet)[i]))
				break;
		}
		if(i >= 960)
			pBuff[(960 - 1)] = '\0';

		CSharedCreatureData* pSD = pUser->SD;
		CCreature* pTargetCreature = pUser->GetTarget();
		if(pTargetCreature)
		{
			CSharedCreatureData* pTargetSD = pTargetCreature->SD;
			g_Log->Add(CLog::blue, L"Builder [%s][%u] to [%s] CMD //%s", pSD->wszName, pSD->uBuilderLVL, pTargetSD->wszName, pBuff);
			g_AdminCmdLog.AddToLog(L"Builder [%s][%u] to [%s] CMD //%s", pSD->wszName, pSD->uBuilderLVL, pTargetSD->wszName, pBuff);
		}
		else
		{
			g_Log->Add(CLog::blue, L"Builder [%s][%u] CMD //%s", pSD->wszName, pSD->uBuilderLVL, pBuff);
			g_AdminCmdLog.AddToLog(L"Builder [%s][%u] CMD //%s", pSD->wszName, pSD->uBuilderLVL, pBuff);
		}

		typedef bool (__cdecl *t)(CUserSocket*, const unsigned char*);
		t f = (t)0x4E2BA0;
		bReturn = f(pUserSocket, packet);
	}
	else
		bReturn = false;

	UnGuardRet(bReturn)
}

UINT64 __cdecl _LoginPacketCheckCharacterName(CUserSocket* pUserSocket, const wchar_t* pAccountName)
{
	Guard(__WFUNCSIG__);

	wchar_t wch;
	bool bCheckResult = false;
	UINT32 i, uSize = (UINT32)wcslen(pAccountName);
	if(uSize && uSize < 15)
	{
		for(i = 0; i < uSize; i++)
		{
			if(((wch = pAccountName[i]) >= '0' && wch <= '9') || 
				(wch >= 'A' && wch <= 'Z') || 
				(wch >= 'a' && wch <= 'z') || 
				wch == ' ' || wch == '_' || wch == '-' || wch == '.')
			{}
			else
				break;
		}
		if(i == uSize)
			bCheckResult = true;
	}

	if(bCheckResult)
		UnGuardRet(0x93F8E5) //ok
	else
		UnGuardRet(0x93F8EE) //err
}

UINT64 __cdecl _VersionPacketEx(CUserSocket* pUserSocket, const unsigned char* packet, UINT32 uProtocolId, unsigned char* buff)
{
	Guard(__WFUNCSIG__);

	if(*((WORD*)(packet - 7)) == 267)
	{
		UINT32 _uClientCRC;
		const UINT32 uServerCRC = 0x601F5D11;
		Disassemble(packet, "bd", 0x100, buff, &_uClientCRC);

		UINT32 i;
		for(i = 0; i < 0x20; i++)
		{
			if(((UINT64*)buff)[i] != ((UINT64*)0x121C1360)[i])
				break;
		}
		if(i == 0x20)
		{
			if(_uClientCRC != uServerCRC)
			{
				g_Log->Add(CLog::red, L"[%s][%u] invalid crc [client 0x%08X, server 0x%08X], IP [%u.%u.%u.%u]", __WFUNCTION__, __LINE__, _uClientCRC, uServerCRC, pUserSocket->client_ip.S_un.S_un_b.s_b1, pUserSocket->client_ip.S_un.S_un_b.s_b2, pUserSocket->client_ip.S_un.S_un_b.s_b3, pUserSocket->client_ip.S_un.S_un_b.s_b4);
				UnGuardRet(0x933B2F) //close connection
			}

			UnGuardRet(0x933B5D) //continiue, send key...
		}
		else
			UnGuardRet(0x933A9C) //nck fail
	}
	else
	{
		g_Log->Add(CLog::red, L"[%s][%u] invalid len %u / %u, IP [%u.%u.%u.%u]", __WFUNCTION__, __LINE__, *((WORD*)(packet - 7)), 267, pUserSocket->client_ip.S_un.S_un_b.s_b1, pUserSocket->client_ip.S_un.S_un_b.s_b2, pUserSocket->client_ip.S_un.S_un_b.s_b3, pUserSocket->client_ip.S_un.S_un_b.s_b4);
		UnGuardRet(0x933B2F) //close connection
	}
}

void L2GFExtL2MFix()
{
	WriteMemoryQWORD(0x0E5FC78, (UINT64)_HtmlCmdObserver); //L2World_Party

	NOPMemory(0x61CABA, 5); //disable send mail to nc
	NOPMemory(0x61BB2D, 5); //disable send mail to nc

	WriteMemoryQWORD(0x7CA7DF, 0x4F0FCB8B49D28B41);
	WriteInstructionCall(0x7CA7E5, (UINT32)CPledge_CheckByPowerGradeId_Log_Fix, 0x7CA7FB);	//
	WriteInstructionCall(0x7C9DD5, (UINT32)CPledge_CheckByPowerGradeId_Log_Fix, 0x7C9DF1);	//

	WriteMemoryQWORD(0x948DC6, 0x5024448D4CCE8B4C);
	WriteInstructionCall(0x948DD5, (UINT32)CHTMLCacheManager::_IsValidHtmlLink);			//

	WriteMemoryQWORD(0x94A2BA, 0xE024848D4CCE8B4C);
	WriteInstructionCall(0x94A2CC, (UINT32)CHTMLCacheManager::_IsValidHtmlLink);			//

	WriteInstructionCall(0x91ED7C, (UINT32)_BuilderCmd2Handler);							//

	WriteMemoryQWORD(0x93F892, 0x661876393BCE8B48);
	WriteInstructionCallJmpEax(0x93F895, (UINT32)_LoginPacketCheckCharacterName, 0x93F8E5);	//

	WriteMemoryQWORD(0x933A5E, 0x8B48D08B48C18B44);
	WriteMemoryQWORD(0x933A66, 0x44FFD5B1B3DB33CF);
	WriteInstructionCallJmpEax(0x933A69, (UINT32)_VersionPacketEx, 0x933A9C);				//

	WriteMemoryQWORD(0xC543F8, (UINT64)CUser::_DeleteItemInInventoryBeforeCommit);			//
}

void OSIEFix()
{
	WriteMemoryQWORD(0xC54400, (UINT64)CUser::_UserEnterWorld); //
	WriteInstructionCall(0x5E1B30, (UINT32)CUserSocket::_BindUser); // Kill kamael race
	// Changing the Number of Initial Classes from 11 to 9.
	WriteMemoryBYTE(0x925363, 0x09); // (old 0x0B)
	// Deleting Newer Initial Classes
	WriteMemoryDWORD(0xC6BBEC, 0x00); // Male Kamael (old 0x7B)
	WriteMemoryDWORD(0xC6BBF0, 0x00); // Female Kamael (old 0x7C)

	WriteInstruction(0xA2D776, (UINT32)_CharacterCreatePacket, 0x05);
}

void DllInitializer(HMODULE hDllModule, DWORD ul_reason_for_call)
{
//	Msg(L"Load", L"[%s]\n DbgBreak", __WFILE__);

	CreateDirectoryA("CrashLogsOSIE", NULL);
	system("move *.bak CrashLogsOSIE");

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
						else if(*((UINT64*)(((UINT64)hRpgClubModule) + 0x1000)) == 0x4C89481024548948)
							uRpgClubType = 2;
						else
						{
							Msg(L"LoadWarning", L"[%s]\n not supported version of %s detected", __WFILE__, pRpgClubDllName);
//							ExitProcess(1);
						}
					}

					CreateDirectoryW(L"ExtLog", NULL);
					CreateDirectoryW(L"ExtLog\\admin", NULL);
					g_AdminCmdLog.OpenLogFile(L"ExtLog\\admin\\builder_cmd");

					CCodeRestorator CodeRestorator;
#ifdef L2SERVER_DEBUG
					CodeRestorator.bIsShowRate = true;
#endif // L2SERVER_DEBUG

#ifdef L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM
					for(UINT32 i = 0; i < 256; i++)
						g_MinPacketDelay[i] = g_MinPacketDelayEx[i] = 0xCCCCCCCC;
#endif // L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM

					if(uRpgClubType && CodeRestorator.OpenParentFile(g_Server, 0xC6006406C1058D48))
					{
						CodeRestorator.RestoreFunctionCode(0x93CE54, 168); //sub_180001410 CUserSocket__Allocate
						CodeRestorator.RestoreFunctionCode(0x92DE7C, 241); //sub_180001490 CUserSocket::~CUserSocket
						CodeRestorator.RestoreFunctionCode(0x92EB3C, 1673); //sub_180017EB0 CUserSocket::OnRead
						CodeRestorator.RestoreFunctionCode(0x5E0644, 9515); //sub_180017EE2 LoadSelectedCharacterPacket
						CodeRestorator.RestoreFunctionCode(0x91CB48, 258); //sub_180001050 ActionPacket
						CodeRestorator.RestoreFunctionCode(0x91C220, 385); //sub_180001070 AttackPacket
						CodeRestorator.RestoreFunctionCode(0x93F7F0, 2031); //sub_180001090 CUserSocket::LoginPacket
						CodeRestorator.RestoreFunctionCode(0x8C5320, 2005); //sub_180001150 User::OnEnterWorldPacket

						if(uRpgClubType == 2)
						{
							CodeRestorator.RestoreFunctionCode(0x7CA72C, 230); //CPledge_CheckByPowerGradeId_Log_Fix
							CodeRestorator.RestoreFunctionCode(0x7C9D50, 181); //CPledge_CheckByPowerGradeId_Log_Fix
							CodeRestorator.RestoreFunctionCode(0x91C998, 167); //CUserSocket::InGamePacketHandler2 AddTradeItem
							CodeRestorator.RestoreFunctionCode(0x948BD4, 873); //HtmlCMDPacket
							CodeRestorator.RestoreFunctionCode(0x94A098, 1132); //LinkHtmlPacket
							CodeRestorator.RestoreFunctionCode(0x4E2BA0, 591); //BuilderCmd2Handler
							CodeRestorator.RestoreFunctionCode(0x93344C, 2588); //VersionPacket
							CodeRestorator.RestoreFunctionCode(0x92B9B4, 789); //GetItemFromPetPacket
							CodeRestorator.RestoreFunctionCode(0x92099C, 423); //GetItemFromPetPacket
						}
					}

					ExtendUserDataSize();
					ExtendUserSocketDataSize();
					RedErrorBlock();
					MaxIndexExtend();

					WriteMemoryDWORD(0x690053, (5 * 60000 * 1000)); //deadlock time to 5 min
					WriteInstructionJmp(0x6B27AC, 0x6B273B, 0x6B27FE); //disable exit if not connected to auth at load
					WriteInstructionCall(0x6B278A, (UINT32)OnLoadEnd);
					//WriteMemoryBYTE(0xC6BD84, '7'); //87 protocol

					WriteInstruction(0x93CEDC, (UINT32)CUserSocket::UserSocketConstructor, 0xE8);		//sub_180001410 CUserSocket__Allocate
					WriteInstruction(0x92E068, (UINT32)CUserSocket::UserSocketDestructor, 0xE8);		//sub_180001490 CUserSocket::~CUserSocket
					WriteInstruction(0x5E1ACA, (UINT32)CUser::UserConstructor, 0xE8);					//sub_180017EE2, sub_180017EFF LoadSelectedCharacterPacket (in_code) set bulder lvl1 (maybe here epilog 152 protocol implimentation be in orig version)
					WriteInstruction(0x8D4340, (UINT32)CUser::UserDestructor, 0xE8);					//			

					WriteMemoryQWORD(0x92EAE0, 0x8B48D38B49C28B44);
					WriteMemoryQWORD(0x92EAE8, 0x98248489482024CB);
					//WriteInstructionCallJmpEax(0x92EF0B, (UINT32)CUserSocket::OutGamePacketHandler, 0x92EF17);	//sub_180017EB0 CUserSocket::OnRead (in_code), sub_180001050 ActionPacket (simple check to exist pUserSocketExt->pUserSocket), sub_180001070 AttackPacket (simple check to exist pUserSocketExt->pUserSocket), sub_180001090 CUserSocket::LoginPacket
					//WriteInstructionCallJmpEax(0x92EDFE, (UINT32)CUserSocket::InGamePacketHandler, 0x92EE0C);		//sub_180017EB0 CUserSocket::OnRead (in_code), sub_180001150 User::OnEnterWorldPacket
					//WriteInstructionCall(0x92EAE9, (UINT32)CUserSocket::GamePacketExHandler, 0x92EB03);			//
					WriteInstructionCallJmpEax(0x92EF0B, (UINT32)CUserSocket::OutGamePacketHandler2, 0x92EF17);		//sub_180017EB0 CUserSocket::OnRead (in_code), sub_180001050 ActionPacket (simple check to exist pUserSocketExt->pUserSocket), sub_180001070 AttackPacket (simple check to exist pUserSocketExt->pUserSocket), sub_180001090 CUserSocket::LoginPacket
					WriteInstructionCallJmpEax(0x92EDFE, (UINT32)CUserSocket::InGamePacketHandler2, 0x92EE0C);		//sub_180017EB0 CUserSocket::OnRead (in_code), sub_180001150 User::OnEnterWorldPacket
					WriteInstructionCall(0x92EAE9, (UINT32)CUserSocket::GamePacketExHandler2, 0x92EB03);			//

					L2GFExtL2MFix(); //fixes from L2GFExt L2M.RU Project 

					//Msg(L"Load", L"[%s]\n complete loaded, 0x%08X", __WFILE__, *((UINT32*)0x5E1869));

					g_Vars->Initialize(); // initialization ini file

					WriteInstructionCall(0x6B3423, (UINT32)ShowLog);			//copyrite DevExt
					//L2Server Protocol start
					NULLMemory(0xC6BD78, 16);
					WriteMemoryBYTES(0xC6BD78, (void*)g_Vars->GetServerProtocol().c_str(), (int)g_Vars->GetServerProtocol().size());
					//L2Server Protocol end

					OSIEFix();

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
		{
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

unsigned char* Disassemble(const unsigned char* buf, const char* format, ...)
{
	Guard(__WFUNCSIG__);
	va_list va;
	va_start(va, format);
	typedef unsigned char* (__cdecl *t)(const unsigned char*, const char*, va_list);
	t f = (t)0x0068EA18;
	unsigned char* pReturn = f(buf, format, va);
	va_end(va);
	UnGuardRet(pReturn);
}
