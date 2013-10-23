#include "stdafx.h"

typedef bool (__cdecl *tUserSocketPacketHandler)(CUserSocket*, const BYTE*, BYTE);

extern DWORD g_MinPacketDelay[256];
extern DWORD g_MinPacketDelayEx[256];
volatile long g_packet_delay_save_trigger_counter = 0;

void SaveLogDelayPacket()
{
	FILE* pFile;
	wchar_t pBuffW[MAX_PATH];
	SYSTEMTIME log_time;
	GetLocalTime(&log_time);
	swprintf_s(pBuffW, MAX_PATH, L"FloodGuard_%02d_%02d_%04d_%02d_%02d_%02d_%03d.ini", log_time.wMonth, log_time.wDay, log_time.wYear, log_time.wHour, log_time.wMinute, log_time.wSecond, log_time.wMilliseconds);
	if(!_wfopen_s(&pFile, pBuffW, L"wb"))
	{
		UINT32 slen = 0;
		unsigned char Encoding[2] = { 0xFF, 0xFE };
		if(fwrite(Encoding, 2, 1, pFile) == 1)
		{
			for(UINT32 i = 0; i < 256; i++)
			{
				if(g_MinPacketDelay[i] > 9999)
					slen = (UINT32)swprintf_s(pBuffW, (MAX_PATH - 2), L"%02X_timespan	= %u 	; \r\n", i, 9999);
				else
					slen = (UINT32)swprintf_s(pBuffW, (MAX_PATH - 2), L"%02X_timespan	= %u 	; \r\n", i, g_MinPacketDelay[i]);
				fwrite(pBuffW, (slen * 2), 1, pFile);
				slen = (UINT32)swprintf_s(pBuffW, (MAX_PATH - 2), L"%02X_action	= 0x002	; [drop]\r\n", i);
				fwrite(pBuffW, (slen * 2), 1, pFile);
			}

			slen = (UINT32)swprintf_s(pBuffW, (MAX_PATH - 2), L"\r\n\r\n");
			fwrite(pBuffW, (slen * 2), 1, pFile);

			for(UINT32 i = 0; i < MAX_GAME_EX_PROTOCOL; i++)
			{
				if(g_MinPacketDelayEx[i] > 9999)
					slen = (UINT32)swprintf_s(pBuffW, (MAX_PATH - 2), L"D0_%02X_timespan	= %u 	; \r\n", i, 9999);
				else
					slen = (UINT32)swprintf_s(pBuffW, (MAX_PATH - 2), L"D0_%02X_timespan	= %u 	; \r\n", i, g_MinPacketDelayEx[i]);
				fwrite(pBuffW, (slen * 2), 1, pFile);
				slen = (UINT32)swprintf_s(pBuffW, (MAX_PATH - 2), L"D0_%02X_action	= 0x002	; [drop]\r\n", i);
				fwrite(pBuffW, (slen * 2), 1, pFile);
			}

			slen = (UINT32)swprintf_s(pBuffW, (MAX_PATH - 2), L"\r\n\r\n");
			fwrite(pBuffW, (slen * 2), 1, pFile);
		}
		fclose(pFile);
	}
}

UINT64 __cdecl CUserSocket::OutGamePacketHandler2(CUserSocket* pUserSocket, const BYTE* packet, BYTE uOpcode)
{
	Guard(__WFUNCSIG__);

	bool bPacketResult;
	UINT64 uPacketOffset;
	WORD uPacketLen = *((WORD*)(packet - 3));

	if(uOpcode == 0xD0) //UserPacketEx
	{
		uPacketOffset = pUserSocket->pPacketTable[uOpcode];
		tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
		bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
	}
	else
	{
#ifdef L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM
		DWORD uDelayTickCount, uCurrentTickCount = GetTickCount();
		uDelayTickCount = (uCurrentTickCount - ((DWORD)InterlockedExchange((volatile LONG*)&pUserSocket->UserSocketExt.uLastPacketTickCount[uOpcode], (LONG)uCurrentTickCount)));
		if(g_MinPacketDelay[uOpcode] > uDelayTickCount)
			InterlockedExchange((LONG*)&g_MinPacketDelay[uOpcode], (LONG)uDelayTickCount);
#ifdef L2SERVER_INCOMING_SHOW_PACKET_INFO
		g_Log->Add(CLog::black, L"[%s][%d] incoming packet 0x%02X, len %u, delay %u / min %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, uDelayTickCount, g_MinPacketDelay[uOpcode]);
#endif // L2SERVER_INCOMING_SHOW_PACKET_INFO
#else // L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM
#ifdef L2SERVER_INCOMING_SHOW_PACKET_INFO
		g_Log->Add(CLog::black, L"[%s][%d] incoming packet 0x%02X, len %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen);
#endif // L2SERVER_INCOMING_SHOW_PACKET_INFO
#endif // L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM

#ifdef L2SERVER_L2M_TEST_SOCKET
	if(!pUserSocket->UserSocketL2M.PacketDelayCheck(packet, uOpcode))
		UnGuardRet(0x92EE0C)
#endif // L2SERVER_L2M_TEST_SOCKET

		switch(uOpcode)
		{
		case 0x0E: //ProtocolVersion
			{
				if(uPacketLen > 6 && uPacketLen < 268)
				{
					uPacketOffset = pUserSocket->pPacketTable[uOpcode];
					tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
					bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
				}
				else
				{
#ifdef L2SERVER_DEBUG
					g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by len, len %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen);
#endif // L2SERVER_DEBUG
					bPacketResult = true;
				}
				break;
			}
		case 0xB1: //NetPing
			{
				if(uPacketLen == 15)
				{
					uPacketOffset = pUserSocket->pPacketTable[uOpcode];
					tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
					bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
				}
				else
				{
#ifdef L2SERVER_DEBUG
					g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by len, len %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen);
#endif // L2SERVER_DEBUG
					bPacketResult = true;
				}
				break;
			}
		case 0x2B: //AuthLogin
			{
				if(uPacketLen > 34 && uPacketLen < 62)
				{
					uPacketOffset = pUserSocket->pPacketTable[uOpcode];
					tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
					bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
				}
				else
				{
#ifdef L2SERVER_DEBUG
					g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by len, len %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen);
#endif // L2SERVER_DEBUG
					bPacketResult = true;
				}
				break;
			}
		case 0x00: //Logout				len 3
		case 0x12: //CharacterSelect	len ?
		case 0x0C: //CharacterCreate	len ?
		case 0x0D: //CharacterDelete	len ?
		case 0x13: //NewCharacter		len ?
		case 0x0F: //MoveBackwardToLocation	len ? (when char logout)
		case 0x59: //ValidatePosition	len ? (when char logout)
		case 0x7B: //CharacterRestore	len ?
			{
				uPacketOffset = pUserSocket->pPacketTable[uOpcode];
				tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
				bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
				break;
			}
		default:
			{
#ifdef L2SERVER_DEBUG
				g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by switch, len %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen);
#endif // L2SERVER_DEBUG
				bPacketResult = true;
				break;
			}
		}
	}

	if(bPacketResult)
		UnGuardRet(0x92F0BD)
	else
		UnGuardRet(0x92EF17)
}

UINT64 __cdecl CUserSocket::InGamePacketHandler2(CUserSocket* pUserSocket, const BYTE* packet, BYTE uOpcode)
{
	Guard(__WFUNCSIG__);

	CUser* pUser;
	bool bPacketResult;
	UINT64 uPacketOffset;
	WORD uPacketLen = *((WORD*)(packet - 3));

	if(uOpcode == 0xD0) //UserPacketEx
	{
		uPacketOffset = pUserSocket->pPacketTable[uOpcode];
		tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
		bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
	}
	else if((pUser = pUserSocket->User()))
	{
		if(!(InterlockedIncrement(&g_packet_delay_save_trigger_counter) % 1024))
			SaveLogDelayPacket();

		DWORD uDelayTickCount, uCurrentTickCount = GetTickCount();
		uDelayTickCount = (uCurrentTickCount - ((DWORD)InterlockedExchange((volatile LONG*)&pUserSocket->UserSocketExt.uLastPacketTickCount[uOpcode], (LONG)uCurrentTickCount)));

#ifdef L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM
		if(g_MinPacketDelay[uOpcode] > uDelayTickCount)
		InterlockedExchange((LONG*)&g_MinPacketDelay[uOpcode], (LONG)uDelayTickCount);
#ifdef L2SERVER_INCOMING_SHOW_PACKET_INFO
		g_Log->Add(CLog::black, L"[%s][%d] incoming packet 0x%02X, len %u, delay %u / min %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, uDelayTickCount, g_MinPacketDelay[uOpcode]);
#endif // L2SERVER_INCOMING_SHOW_PACKET_INFO
#else // L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM
#ifdef L2SERVER_INCOMING_SHOW_PACKET_INFO
		g_Log->Add(CLog::black, L"[%s][%d] incoming packet 0x%02X, len %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen);
#endif // L2SERVER_INCOMING_SHOW_PACKET_INFO
#endif // L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM

#ifdef L2SERVER_L2M_TEST_SOCKET
	if(!pUserSocket->UserSocketL2M.PacketDelayCheck(packet, uOpcode))
		UnGuardRet(0x92EE0C)
#endif // L2SERVER_L2M_TEST_SOCKET

		switch(uOpcode)
		{
		case 0x1B: //AddTradeItem
			{
				if(pUser->IsNowTrade())
				{
					uPacketOffset = pUserSocket->pPacketTable[uOpcode];
					tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
					bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
				}
				else
				{
#ifdef L2SERVER_DEBUG
					g_Log->Add(CLog::red, L"[%s][%d] user [%s] try add item to trade, but trade not exist", __WFUNCTION__, __LINE__, pUser->SD->wszName);
#endif // L2SERVER_DEBUG
					bPacketResult = true;
				}
				break;
			}
		case 0x22: //RequestLinkHtml - все пакеты которыми флудят и это несет нагрузку (отправка одного хтмл получателю до 16 кб!)
			{
				if(uDelayTickCount > 256)
				{
					uPacketOffset = pUserSocket->pPacketTable[uOpcode];
					tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
					bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
				}
				else
				{
					pUserSocket->SendSystemMessage(L"WALL", L"Stop flood to server");
					bPacketResult = false;
				}
				break;
			}
		case 0x23: //RequestBypassToServer
			{
				if(pUser->IsNowTrade())
				{
					//package_deposit, package_withdraw and also 4+ strings
					pUserSocket->SendSystemMessage(L"WALL", L"You can`t do this while trading!");
					bPacketResult = false;
				}
				else
				{
					uPacketOffset = pUserSocket->pPacketTable[uOpcode];
					tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
					bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
				}
				break;
			}
		case 0x55: //AnswerTradeRequest
			{
				if(*((UINT32*)packet) == 1)
				{
					CObjectSP TradeSP;
					g_TradeManager->GetTrade(&TradeSP, pUser->uTradeSID);
					if(TradeSP.pTrade)
					{
						if(pUser->uSID == TradeSP.pTrade->uTradeStarterSID)
						{
							TradeSP.Release();
							pUserSocket->SendSystemMessage(L"WALL", L"You can`t accept your request!");
							bPacketResult = false;
						}
						else
						{
							TradeSP.Release();
							uPacketOffset = pUserSocket->pPacketTable[uOpcode];
							tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
							bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
						}
					}
					else
					{
						TradeSP.Release();
						uPacketOffset = pUserSocket->pPacketTable[uOpcode];
						tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
						bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
					}
				}
				else
				{
					uPacketOffset = pUserSocket->pPacketTable[uOpcode];
					tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
					bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
				}
				break;
			}
		case 0x3A: //Appearing (need be after enterworld)
		case 0x7D: //RequestRestartPoint (need be after enterworld)
			{
				if(pUser->UserExt.bIsEnteredIntoWorld)
				{
					uPacketOffset = pUserSocket->pPacketTable[uOpcode];
					tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
					bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
				}
				else
					bPacketResult = false;
				break;
			}
		case 0x56: //RequestActionUse
		case 0x2C: //RequestGetItemFromPet
		case 0x95: //RequestGiveItemToPet
		case 0x3C: //SendWareHouseWithDrawList
		case 0xA7: //RequestPackageSendableItemList
		case 0xA8: //RequestPackageSend
			{
				if(pUser->IsNowTrade())
				{
					//package_deposit, package_withdraw and also 4+ strings
					pUserSocket->SendSystemMessage(L"WALL", L"You can`t do this while trading!");
					bPacketResult = false;
				}
				else
				{
					uPacketOffset = pUserSocket->pPacketTable[uOpcode];
					tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
					bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
				}
				break;
			}
		case 0xA6: //packet with 0 delay
			{
				uPacketOffset = pUserSocket->pPacketTable[uOpcode];
				tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
				bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
				break;
			}
		case 0x12: //CharacterSelect - offline packets
		case 0xB1: //NetPing
			{
				uPacketOffset = pUserSocket->pPacketTable[uOpcode];
				tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
				bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
				break;
			}
		case 0x11: //EnterWorld
			{
				if(!pUser->UserExt.bIsEnterIntoWorld)
				{
					pUser->UserExt.bIsEnterIntoWorld = true;
					uPacketOffset = pUserSocket->pPacketTable[uOpcode];
					tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
					bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
					if(!bPacketResult)
						pUser->UserExt.bIsEnteredIntoWorld = true;
				}
				else
					bPacketResult = false;
				break;
			}
		default:
			{
				uPacketOffset = pUserSocket->pPacketTable[uOpcode];
				tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
				bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
				break;
			}
		}
	}
	else
	{
#ifdef L2SERVER_DEBUG
		g_Log->Add(CLog::red, L"[%s][%d] pUser is not exist, packet 0x%02X, len %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen);
#endif // L2SERVER_DEBUG
		bPacketResult = true;
	}

	if(bPacketResult)
		UnGuardRet(0x92F08A)
	else
		UnGuardRet(0x92EE48)
}

bool __cdecl CUserSocket::GamePacketExHandler2(CUserSocket* pUserSocket, const BYTE* packet, WORD uOpcodeEx)
{
	Guard(__WFUNCSIG__);

	CUser* pUser;
	bool bPacketResult;
	UINT64 uPacketOffset;
	WORD uPacketLen = *((WORD*)(packet - 5));

	if(uOpcodeEx > MAX_GAME_EX_PROTOCOL)
	{
#ifdef L2SERVER_DEBUG
		g_Log->Add(CLog::red, L"[%s][%d] packet 0x%04X blocked by switch, len %u", __WFUNCTION__, __LINE__, uOpcodeEx, uPacketLen);
#endif // L2SERVER_DEBUG
		bPacketResult = true;
	}
	else if((pUser = pUserSocket->User()))
	{
#ifdef L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM
		DWORD uDelayTickCount, uCurrentTickCount = GetTickCount();
		uDelayTickCount = (uCurrentTickCount - ((DWORD)InterlockedExchange((volatile LONG*)&pUserSocket->UserSocketExt.uLastPacketExTickCount[((BYTE)uOpcodeEx)], (LONG)uCurrentTickCount)));
		if(g_MinPacketDelayEx[((BYTE)uOpcodeEx)] > uDelayTickCount)
			InterlockedExchange((LONG*)&g_MinPacketDelayEx[((BYTE)uOpcodeEx)], (LONG)uDelayTickCount);
#ifdef L2SERVER_INCOMING_SHOW_PACKET_INFO
		g_Log->Add(CLog::black, L"[%s][%d][%d] incoming packet 0x%04X, len %u, delay %u / min %u", __WFUNCTION__, __LINE__, 1, uOpcodeEx, uPacketLen, uDelayTickCount, g_MinPacketDelayEx[((BYTE)uOpcodeEx)]);
#endif // L2SERVER_INCOMING_SHOW_PACKET_INFO
#else // L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM
#ifdef L2SERVER_INCOMING_SHOW_PACKET_INFO
		g_Log->Add(CLog::black, L"[%s][%d][%d] incoming packet 0x%04X, len %u", __WFUNCTION__, __LINE__, 1, uOpcodeEx, uPacketLen);
#endif // L2SERVER_INCOMING_SHOW_PACKET_INFO
#endif // L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM

#ifdef L2SERVER_L2M_TEST_SOCKET
	if(!pUserSocket->UserSocketL2M.PacketExDelayCheck(packet, uOpcodeEx))
		UnGuardRet(true)
#endif // L2SERVER_L2M_TEST_SOCKET

		//online packets
		switch(((BYTE)uOpcodeEx))
		{
		case 0x01: //RequestManorList
		case 0x21: //RequestKeyMapping
		case 0x3D: //RequestAllFortressInfo
		case 0x36: //RequestGotoLobby
			{
				uPacketOffset = ((UINT64*)0x121C0D60)[((BYTE)uOpcodeEx)];
				tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
				bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, ((BYTE)uOpcodeEx));
				break;
			}
		default:
			{
				uPacketOffset = ((UINT64*)0x121C0D60)[((BYTE)uOpcodeEx)];
				tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
				bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, ((BYTE)uOpcodeEx));
				break;
			}
		}
	}
	else
	{
#ifdef L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM
		DWORD uDelayTickCount, uCurrentTickCount = GetTickCount();
		uDelayTickCount = (uCurrentTickCount - ((DWORD)InterlockedExchange((volatile LONG*)&pUserSocket->UserSocketExt.uLastPacketExTickCount[((BYTE)uOpcodeEx)], (LONG)uCurrentTickCount)));
		if(g_MinPacketDelayEx[((BYTE)uOpcodeEx)] > uDelayTickCount)
			InterlockedExchange((LONG*)&g_MinPacketDelayEx[((BYTE)uOpcodeEx)], (LONG)uDelayTickCount);
#ifdef L2SERVER_INCOMING_SHOW_PACKET_INFO
		g_Log->Add(CLog::black, L"[%s][%d][%d] incoming packet 0x%04X, len %u, delay %u / min %u", __WFUNCTION__, __LINE__, 0, uOpcodeEx, uPacketLen, uDelayTickCount, g_MinPacketDelayEx[((BYTE)uOpcodeEx)]);
#endif // L2SERVER_INCOMING_SHOW_PACKET_INFO
#else // L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM
#ifdef L2SERVER_INCOMING_SHOW_PACKET_INFO
		g_Log->Add(CLog::black, L"[%s][%d][%d] incoming packet 0x%04X, len %u", __WFUNCTION__, __LINE__, 0, uOpcodeEx, uPacketLen);
#endif // L2SERVER_INCOMING_SHOW_PACKET_INFO
#endif // L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM

#ifdef L2SERVER_L2M_TEST_SOCKET
	if(!pUserSocket->UserSocketL2M.PacketExDelayCheck(packet, uOpcodeEx))
		UnGuardRet(true)
#endif // L2SERVER_L2M_TEST_SOCKET

		//offline packets
		switch(((BYTE)uOpcodeEx))
		{
		case 0x01: //RequestManorList
		case 0x21: //RequestKeyMapping
		case 0x3D: //RequestAllFortressInfo
		case 0x36: //RequestGotoLobby
			{
				uPacketOffset = ((UINT64*)0x121C0D60)[((BYTE)uOpcodeEx)];
				tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
				bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, ((BYTE)uOpcodeEx));
				break;
			}
		default:
			{
#ifdef L2SERVER_DEBUG
				g_Log->Add(CLog::red, L"[%s][%d] packetEx 0x%04X blocked by outgame, len %u", __WFUNCTION__, __LINE__, uOpcodeEx, uPacketLen);
#endif // L2SERVER_DEBUG
				bPacketResult = true;
				break;
			}
		}
	}

	UnGuardRet(bPacketResult)
}
