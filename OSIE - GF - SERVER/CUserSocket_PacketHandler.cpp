#include "stdafx.h"

typedef bool (__cdecl *tUserSocketPacketHandler)(CUserSocket*, const BYTE*, BYTE);

WORD OutGameMinDelay[256] = 
{
	//       ?0   ?1   ?2   ?3   ?4   ?5   ?6   ?7   ?8   ?9   ?A   ?B   ?C   ?D   ?E   ?F         //
	/* 0? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 0? */ 
	/* 1? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 1? */ 
	/* 2? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 2? */ 
	/* 3? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 3? */ 
	/* 4? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 4? */ 
	/* 5? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 5? */ 
	/* 6? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 6? */ 
	/* 7? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 7? */ 
	/* 8? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 8? */ 
	/* 9? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 9? */ 
	/* A? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* A? */ 
	/* B? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* B? */ 
	/* C? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* C? */ 
	/* D? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* D? */ 
	/* E? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* E? */ 
	/* F? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* F? */ 
	//       ?0   ?1   ?2   ?3   ?4   ?5   ?6   ?7   ?8   ?9   ?A   ?B   ?C   ?D   ?E   ?F         //
};

WORD OutGameMinDelayEx[256] = 
{
	//       ?0   ?1   ?2   ?3   ?4   ?5   ?6   ?7   ?8   ?9   ?A   ?B   ?C   ?D   ?E   ?F         //
	/* 0? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 0? */ 
	/* 1? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 1? */ 
	/* 2? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 2? */ 
	/* 3? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 3? */ 
	/* 4? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 4? */ 
	/* 5? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 5? */ 
	/* 6? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 6? */ 
	/* 7? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 7? */ 
	/* 8? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 8? */ 
	/* 9? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* 9? */ 
	/* A? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* A? */ 
	/* B? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* B? */ 
	/* C? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* C? */ 
	/* D? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* D? */ 
	/* E? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* E? */ 
	/* F? */ 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, /* F? */ 
	//       ?0   ?1   ?2   ?3   ?4   ?5   ?6   ?7   ?8   ?9   ?A   ?B   ?C   ?D   ?E   ?F         //
};

WORD InGameMinDelay[256] = //0x22 >200, 0xA6 > 78
{
	//       ?0   ?1   ?2   ?3   ?4   ?5   ?6   ?7   ?8   ?9   ?A   ?B   ?C   ?D   ?E   ?F         //
	/* 0? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 128, /* 0? */ 
	/* 1? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 1? */ 
	/* 2? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 2? */ 
	/* 3? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 24 , 192, 192, 192, 192, 192, 192, /* 3? */ 
	/* 4? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 4? */ 
	/* 5? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 16 , 192, 24 , 192, 192, 192, 192, /* 5? */ 
	/* 6? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 6? */ 
	/* 7? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 7? */ 
	/* 8? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 8? */ 
	/* 9? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 9? */ 
	/* A? */ 192, 192, 192, 192, 192, 192, 0  , 192, 192, 192, 192, 192, 192, 192, 192, 192, /* A? */ 
	/* B? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* B? */ 
	/* C? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* C? */ 
	/* D? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* D? */ 
	/* E? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* E? */ 
	/* F? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* F? */ 
	//       ?0   ?1   ?2   ?3   ?4   ?5   ?6   ?7   ?8   ?9   ?A   ?B   ?C   ?D   ?E   ?F         //
};

WORD InGameMinDelayEx[256] = 
{
	//       ?0   ?1   ?2   ?3   ?4   ?5   ?6   ?7   ?8   ?9   ?A   ?B   ?C   ?D   ?E   ?F         //
	/* 0? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 0? */ 
	/* 1? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 1? */ 
	/* 2? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 2? */ 
	/* 3? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 3? */ 
	/* 4? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 4? */ 
	/* 5? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 5? */ 
	/* 6? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 6? */ 
	/* 7? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 7? */ 
	/* 8? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 8? */ 
	/* 9? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* 9? */ 
	/* A? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* A? */ 
	/* B? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* B? */ 
	/* C? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* C? */ 
	/* D? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* D? */ 
	/* E? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* E? */ 
	/* F? */ 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, /* F? */ 
	//       ?0   ?1   ?2   ?3   ?4   ?5   ?6   ?7   ?8   ?9   ?A   ?B   ?C   ?D   ?E   ?F         //
};

UINT64 __cdecl CUserSocket::OutGamePacketHandler(CUserSocket* pUserSocket, const BYTE* packet, BYTE uOpcode)
{
	Guard(__WFUNCSIG__);

	bool bPacketResult;
	UINT64 uPacketOffset;
	long _nLoginStage =  pUserSocket->UserSocketExt.nLoginStage;
	WORD uPacketLen = *((WORD*)(packet - 3));
	DWORD uDelayTickCount, uCurrentTickCount;

	if(((UINT32)_nLoginStage) < 5)
	{
		switch(uOpcode)
		{
		case 0x0E: //ProtocolVersion
			{
				if((_nLoginStage = InterlockedCompareExchange(&pUserSocket->UserSocketExt.nLoginStage, 2, 1)) == 1)
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
						g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by len, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
						bPacketResult = true;
					}
				}
				else
				{
#ifdef L2SERVER_DEBUG
					g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by stage, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
					bPacketResult = true;
				}
				break;
			}
		case 0xB1: //NetPing
			{
				uCurrentTickCount = GetTickCount();
				if((uDelayTickCount = (uCurrentTickCount - ((DWORD)InterlockedExchange((volatile LONG*)&pUserSocket->UserSocketExt.uLastPacketTickCount[uOpcode], (LONG)uCurrentTickCount)))) > OutGameMinDelay[uOpcode])
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
						g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by len, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
						bPacketResult = true;
					}
				}
				else
				{
#ifdef L2SERVER_DEBUG_PACKET_DELAY
					g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by delay, len %u, login_stage %i, delay %u / %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage, uDelayTickCount, OutGameMinDelay[uOpcode]);
#endif // L2SERVER_DEBUG_PACKET_DELAY
					bPacketResult = true;
				}
				break;
			}
		case 0x2B: //AuthLogin
			{
				if((_nLoginStage = InterlockedCompareExchange(&pUserSocket->UserSocketExt.nLoginStage, 3, 2)) == 2)
				{
					if(uPacketLen > 34 && uPacketLen < 62)
					{
						uPacketOffset = pUserSocket->pPacketTable[uOpcode];
						tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
						if(!(bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode)))
						{
							if((_nLoginStage = InterlockedCompareExchange(&pUserSocket->UserSocketExt.nLoginStage, 4, 3)) != 3)
							{
#ifdef L2SERVER_DEBUG
								g_Log->Add(CLog::red, L"[%s][%d] invalid state login_stage %i at packet 0x%02X, len %u", __WFUNCTION__, __LINE__, _nLoginStage, uOpcode, uPacketLen);
#endif // L2SERVER_DEBUG
								bPacketResult = true;
							}
						}
					}
					else
					{
#ifdef L2SERVER_DEBUG
						g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by len, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
						bPacketResult = true;
					}
				}
				else
				{
#ifdef L2SERVER_DEBUG
					g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by stage, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
					bPacketResult = true;
				}
				break;
			}
		case 0x00: //Logout
			{
				if(pUserSocket->UserSocketExt.nLoginStage >= 4)
				{
					uPacketOffset = pUserSocket->pPacketTable[uOpcode];
					tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
					bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
				}
				else
				{
#ifdef L2SERVER_DEBUG
					g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by stage, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
					bPacketResult = true;
				}
				break;
			}
		case 0x0C: //CharacterCreate
		case 0x0D: //CharacterDelete
		case 0x13: //NewCharacter
		case 0x7B: //CharacterRestore
			{
				uCurrentTickCount = GetTickCount();
				if((uDelayTickCount = (uCurrentTickCount - ((DWORD)InterlockedExchange((volatile LONG*)&pUserSocket->UserSocketExt.uLastPacketTickCount[uOpcode], (LONG)uCurrentTickCount)))) > OutGameMinDelay[uOpcode])
				{
#ifdef L2SERVER_DEBUG
					g_Log->Add(CLog::black, L"[%s][%d] incoming packet 0x%02X, len %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen);
#endif // L2SERVER_DEBUG

					if(pUserSocket->UserSocketExt.nLoginStage == 4)
					{
						uPacketOffset = pUserSocket->pPacketTable[uOpcode];
						tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
						bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
					}
					else
					{
#ifdef L2SERVER_DEBUG
						g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by stage, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
						bPacketResult = true;
					}
				}
				else
				{
#ifdef L2SERVER_DEBUG_PACKET_DELAY
					g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by delay, len %u, login_stage %i, delay %u / %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage, uDelayTickCount, OutGameMinDelay[uOpcode]);
#endif // L2SERVER_DEBUG_PACKET_DELAY
					bPacketResult = true;
				}
				break;
			}
		case 0x12: //CharacterSelect
			{
				if(pUserSocket->UserSocketExt.nLoginStage == 4 && uPacketLen == 21)
				{
#ifdef L2SERVER_DEBUG
					g_Log->Add(CLog::black, L"[%s][%d] incoming packet 0x%02X, len %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen);
#endif // L2SERVER_DEBUG
					uPacketOffset = pUserSocket->pPacketTable[uOpcode];
					tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
					if(!(bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode)))
					{
						if((_nLoginStage = InterlockedCompareExchange(&pUserSocket->UserSocketExt.nLoginStage, 5, 4)) != 4)
						{
#ifdef L2SERVER_DEBUG
							g_Log->Add(CLog::red, L"[%s][%d] invalid state login_stage %i at packet 0x%02X, len %u", __WFUNCTION__, __LINE__, _nLoginStage, uOpcode, uPacketLen);
#endif // L2SERVER_DEBUG
							bPacketResult = true;
						}
					}
				}
				else
				{
#ifdef L2SERVER_DEBUG
					g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by stage, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
					bPacketResult = true;
				}
				break;
			}
		case 0xD0: //UserPacketEx
			{
				uPacketOffset = pUserSocket->pPacketTable[uOpcode];
				tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
				bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
				break;
			}
		default:
			{
#ifdef L2SERVER_DEBUG
				g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by switch, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
				bPacketResult = true;
				break;
			}
		}
	}
	else if(pUserSocket->UserSocketExt.nLoginStage == 5)
	{
		switch(uOpcode)
		{
		case 0x12: //CharacterSelect
			{
				if(uPacketLen == 21)
				{
#ifdef L2SERVER_DEBUG
					g_Log->Add(CLog::black, L"[%s][%d] packet 0x%02X blocked by stage, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
					bPacketResult = false;
				}
				else
				{
#ifdef L2SERVER_DEBUG
					g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by len, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
					bPacketResult = true;
				}
				break;
			}
		default:
			{
#ifdef L2SERVER_DEBUG
				g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by stage, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
				bPacketResult = true;
				break;
			}
		}
	}
	else if(pUserSocket->UserSocketExt.nLoginStage == 6)
	{
		switch(uOpcode)
		{
		default:
			{
#ifdef L2SERVER_DEBUG
				g_Log->Add(CLog::black, L"[%s][%d] packet 0x%02X blocked by stage, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
				bPacketResult = false;
				break;
			}
		}
	}
	else
	{
#ifdef L2SERVER_DEBUG
		g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by stage, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
		bPacketResult = true;
	}

	if(bPacketResult)
		UnGuardRet(0x92F0BD)
	else
		UnGuardRet(0x92EF17)
}

UINT64 __cdecl CUserSocket::InGamePacketHandler(CUserSocket* pUserSocket, const BYTE* packet, BYTE uOpcode)
{
	Guard(__WFUNCSIG__);

	bool bPacketResult;
	UINT64 uPacketOffset;
	long _nLoginStage =  pUserSocket->UserSocketExt.nLoginStage;
	WORD uPacketLen = *((WORD*)(packet - 3));
	DWORD uDelayTickCount, uCurrentTickCount;

	if(uOpcode == 0xD0) //UserPacketEx
	{
		uPacketOffset = pUserSocket->pPacketTable[uOpcode];
		tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
		bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
	}
	else
	{
		CUser* pUser = pUserSocket->User();
		if(pUser)
		{
			if(((UINT32)_nLoginStage) >= 6)
			{
#ifdef L2SERVER_USE_DELAY_SYSTEM
				uCurrentTickCount = GetTickCount();
				uDelayTickCount = (uCurrentTickCount - ((DWORD)InterlockedExchange((volatile LONG*)&pUserSocket->UserSocketExt.uLastPacketTickCount[uOpcode], (LONG)uCurrentTickCount)));
#endif // L2SERVER_USE_DELAY_SYSTEM

				switch(uOpcode)
				{
				case 0x1B: //AddTradeItem
					{
#ifdef L2SERVER_USE_DELAY_SYSTEM
						if(uDelayTickCount > InGameMinDelay[uOpcode])
#else // L2SERVER_USE_DELAY_SYSTEM
						if(true)
#endif // L2SERVER_USE_DELAY_SYSTEM
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
								g_Log->Add(CLog::red, L"[%s][%d] user [%s] try add item in trade, but trade not exist", __WFUNCTION__, __LINE__, pUser->SD->pName);
#endif // L2SERVER_DEBUG
								bPacketResult = true;
							}
						}
						else
						{
#ifdef L2SERVER_SEND_DELAY_MSG
							pUserSocket->SendSystemMessage(L"WALL", L"Stop flood to server");
#endif // L2SERVER_SEND_DELAY_MSG
#ifdef L2SERVER_DEBUG_PACKET_DELAY
							g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by delay, len %u, login_stage %i, delay %u / %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage, uDelayTickCount, InGameMinDelay[uOpcode]);
#endif // L2SERVER_DEBUG_PACKET_DELAY
#ifdef L2SERVER_USE_DELAY_KICK
							bPacketResult = true;
#else // L2SERVER_USE_DELAY_KICK
							bPacketResult = false;
#endif // L2SERVER_USE_DELAY_KICK
						}
						break;
					}
				case 0x23: //RequestBypassToServer
					{
#ifdef L2SERVER_USE_DELAY_SYSTEM
						if(uDelayTickCount > InGameMinDelay[uOpcode])
#else // L2SERVER_USE_DELAY_SYSTEM
						if(true)
#endif // L2SERVER_USE_DELAY_SYSTEM
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
						}
						else
						{
#ifdef L2SERVER_SEND_DELAY_MSG
							pUserSocket->SendSystemMessage(L"WALL", L"Stop flood to server");
#endif // L2SERVER_SEND_DELAY_MSG
#ifdef L2SERVER_DEBUG_PACKET_DELAY
							g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by delay, len %u, login_stage %i, delay %u / %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage, uDelayTickCount, InGameMinDelay[uOpcode]);
#endif // L2SERVER_DEBUG_PACKET_DELAY
#ifdef L2SERVER_USE_DELAY_KICK
							bPacketResult = true;
#else // L2SERVER_USE_DELAY_KICK
							bPacketResult = false;
#endif // L2SERVER_USE_DELAY_KICK
						}
						break;
					}
				case 0x55: //AnswerTradeRequest
					{
#ifdef L2SERVER_USE_DELAY_SYSTEM
						if(uDelayTickCount > InGameMinDelay[uOpcode])
#else // L2SERVER_USE_DELAY_SYSTEM
						if(true)
#endif // L2SERVER_USE_DELAY_SYSTEM
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
						}
						else
						{
#ifdef L2SERVER_SEND_DELAY_MSG
							pUserSocket->SendSystemMessage(L"WALL", L"Stop flood to server");
#endif // L2SERVER_SEND_DELAY_MSG
#ifdef L2SERVER_DEBUG_PACKET_DELAY
							g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by delay, len %u, login_stage %i, delay %u / %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage, uDelayTickCount, InGameMinDelay[uOpcode]);
#endif // L2SERVER_DEBUG_PACKET_DELAY
#ifdef L2SERVER_USE_DELAY_KICK
							bPacketResult = true;
#else // L2SERVER_USE_DELAY_KICK
							bPacketResult = false;
#endif // L2SERVER_USE_DELAY_KICK
						}
						break;
					}
//				case 0x3A: //Appearing (need be after enterworld)
//				case 0x7D: //RequestRestartPoint (need be after enterworld)
				case 0x56: //RequestActionUse
				case 0x2C: //RequestGetItemFromPet
				case 0x95: //RequestGiveItemToPet
				case 0x3C: //SendWareHouseWithDrawList
				case 0xA7: //RequestPackageSendableItemList
				case 0xA8: //RequestPackageSend
					{
#ifdef L2SERVER_USE_DELAY_SYSTEM
						if(uDelayTickCount > InGameMinDelay[uOpcode])
#else // L2SERVER_USE_DELAY_SYSTEM
						if(true)
#endif // L2SERVER_USE_DELAY_SYSTEM
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
						}
						else
						{
#ifdef L2SERVER_SEND_DELAY_MSG
							pUserSocket->SendSystemMessage(L"WALL", L"Stop flood to server");
#endif // L2SERVER_SEND_DELAY_MSG
#ifdef L2SERVER_DEBUG_PACKET_DELAY
							g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by delay, len %u, login_stage %i, delay %u / %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage, uDelayTickCount, InGameMinDelay[uOpcode]);
#endif // L2SERVER_DEBUG_PACKET_DELAY
#ifdef L2SERVER_USE_DELAY_KICK
							bPacketResult = true;
#else // L2SERVER_USE_DELAY_KICK
							bPacketResult = false;
#endif // L2SERVER_USE_DELAY_KICK
						}
						break;
					}
				case 0xA6:
					{
						uPacketOffset = pUserSocket->pPacketTable[uOpcode];
						tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
						bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
						break;
					}
				default:
					{
#ifdef L2SERVER_USE_DELAY_SYSTEM
						if(uDelayTickCount > InGameMinDelay[uOpcode])
#else // L2SERVER_USE_DELAY_SYSTEM
						if(true)
#endif // L2SERVER_USE_DELAY_SYSTEM
						{
//#ifdef L2SERVER_DEBUG
//							g_Log->Add(CLog::black, L"[%s][%d] incoming packet 0x%02X, len %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen);
//#endif // L2SERVER_DEBUG
							uPacketOffset = pUserSocket->pPacketTable[uOpcode];
							tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
							bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode);
						}
						else
						{
#ifdef L2SERVER_SEND_DELAY_MSG
							pUserSocket->SendSystemMessage(L"WALL", L"Stop flood to server");
#endif // L2SERVER_SEND_DELAY_MSG
#ifdef L2SERVER_DEBUG_PACKET_DELAY
							g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by delay, len %u, login_stage %i, delay %u / %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage, uDelayTickCount, InGameMinDelay[uOpcode]);
#endif // L2SERVER_DEBUG_PACKET_DELAY
#ifdef L2SERVER_USE_DELAY_KICK
							bPacketResult = true;
#else // L2SERVER_USE_DELAY_KICK
							bPacketResult = false;
#endif // L2SERVER_USE_DELAY_KICK
						}
						break;
					}
				}
			}
			else if(((UINT32)_nLoginStage) == 5)
			{
#ifdef L2SERVER_USE_DELAY_SYSTEM
				uCurrentTickCount = GetTickCount();
				uDelayTickCount = (uCurrentTickCount - ((DWORD)InterlockedExchange((volatile LONG*)&pUserSocket->UserSocketExt.uLastPacketTickCount[uOpcode], (LONG)uCurrentTickCount)));
#endif // L2SERVER_USE_DELAY_SYSTEM
				
				switch(uOpcode)
				{
				case 0x11: //EnterWorld
					{
#ifdef L2SERVER_USE_DELAY_SYSTEM
						if(uDelayTickCount > InGameMinDelay[uOpcode])
#else // L2SERVER_USE_DELAY_SYSTEM
						if(true)
#endif // L2SERVER_USE_DELAY_SYSTEM
						{
							uPacketOffset = pUserSocket->pPacketTable[uOpcode];
							tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
							if(!(bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, uOpcode)))
							{
								if((_nLoginStage = InterlockedCompareExchange(&pUserSocket->UserSocketExt.nLoginStage, 6, 5)) != 5)
								{
#ifdef L2SERVER_DEBUG
									g_Log->Add(CLog::red, L"[%s][%d] invalid state login_stage %i at packet 0x%02X, len %u", __WFUNCTION__, __LINE__, _nLoginStage, uOpcode, uPacketLen);
#endif // L2SERVER_DEBUG
									bPacketResult = true;
								}
							}
						}
						else
						{
#ifdef L2SERVER_SEND_DELAY_MSG
							pUserSocket->SendSystemMessage(L"WALL", L"Stop flood to server");
#endif // L2SERVER_SEND_DELAY_MSG
#ifdef L2SERVER_DEBUG_PACKET_DELAY
							g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by delay, len %u, login_stage %i, delay %u / %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage, uDelayTickCount, InGameMinDelay[uOpcode]);
#endif // L2SERVER_DEBUG_PACKET_DELAY
#ifdef L2SERVER_USE_DELAY_KICK
							bPacketResult = true;
#else // L2SERVER_USE_DELAY_KICK
							bPacketResult = false;
#endif // L2SERVER_USE_DELAY_KICK
						}
						break;
					}
				case 0xB1: //NetPing
					{
#ifdef L2SERVER_USE_DELAY_SYSTEM
						if(uDelayTickCount > InGameMinDelay[uOpcode])
#else // L2SERVER_USE_DELAY_SYSTEM
						if(true)
#endif // L2SERVER_USE_DELAY_SYSTEM
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
								g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by len, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
								bPacketResult = true;
							}
						}
						else
						{
#ifdef L2SERVER_SEND_DELAY_MSG
							pUserSocket->SendSystemMessage(L"WALL", L"Stop flood to server");
#endif // L2SERVER_SEND_DELAY_MSG
#ifdef L2SERVER_DEBUG_PACKET_DELAY
							g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by delay, len %u, login_stage %i, delay %u / %u", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage, uDelayTickCount, InGameMinDelay[uOpcode]);
#endif // L2SERVER_DEBUG_PACKET_DELAY
#ifdef L2SERVER_USE_DELAY_KICK
							bPacketResult = true;
#else // L2SERVER_USE_DELAY_KICK
							bPacketResult = false;
#endif // L2SERVER_USE_DELAY_KICK
						}
						break;
					}
				case 0x12: //CharacterSelect
					{
						if(uPacketLen == 21)
						{
#ifdef L2SERVER_DEBUG
							g_Log->Add(CLog::black, L"[%s][%d] packet 0x%02X blocked by switch, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
							bPacketResult = false;
						}
						else
						{
#ifdef L2SERVER_DEBUG
							g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by switch, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
							bPacketResult = true;
						}
						break;
					}
				default:
					{
#ifdef L2SERVER_DEBUG
						g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by switch, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
						bPacketResult = true;
						break;
					}
				}
			}
			else
			{
#ifdef L2SERVER_DEBUG
				g_Log->Add(CLog::red, L"[%s][%d] packet 0x%02X blocked by stage, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
				bPacketResult = true;
			}
		}
		else
		{
#ifdef L2SERVER_DEBUG
			g_Log->Add(CLog::red, L"[%s][%d] pUser is not exist, packet 0x%02X, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcode, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
			bPacketResult = true;
		}
	}

	if(bPacketResult)
		UnGuardRet(0x92F08A)
	else
		UnGuardRet(0x92EE48)
}

bool __cdecl CUserSocket::GamePacketExHandler(CUserSocket* pUserSocket, const BYTE* packet, WORD uOpcodeEx)
{
	Guard(__WFUNCSIG__);

	bool bPacketResult;
	UINT64 uPacketOffset;
	long _nLoginStage = pUserSocket->UserSocketExt.nLoginStage;
	WORD uPacketLen = *((WORD*)(packet - 5));
	DWORD uDelayTickCount, uCurrentTickCount;

	if(uOpcodeEx > MAX_GAME_EX_PROTOCOL)
	{
#ifdef L2SERVER_DEBUG
		g_Log->Add(CLog::red, L"[%s][%d] packet 0x%04X blocked by switch, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcodeEx, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
		bPacketResult = true;
	}
	else
	{
		CUser* pUser = pUserSocket->User();
		if(pUser)
		{
#ifdef L2SERVER_USE_DELAY_SYSTEM
			uCurrentTickCount = GetTickCount();
			uDelayTickCount = (uCurrentTickCount - ((DWORD)InterlockedExchange((volatile LONG*)&pUserSocket->UserSocketExt.uLastPacketExTickCount[((BYTE)uOpcodeEx)], (LONG)uCurrentTickCount)));
#endif // L2SERVER_USE_DELAY_SYSTEM

			if(((UINT32)_nLoginStage) >= 6)
			{
				switch(((BYTE)uOpcodeEx))
				{
				case 0x36: //RequestGotoLobby
					{
						if(uDelayTickCount > OutGameMinDelayEx[((BYTE)uOpcodeEx)])
						{
#ifdef L2SERVER_DEBUG
							g_Log->Add(CLog::black, L"[%s][%d] incoming packetEx 0x%04X, len %u, delay %u / %u", __WFUNCTION__, __LINE__, uOpcodeEx, uPacketLen, uDelayTickCount, OutGameMinDelayEx[((BYTE)uOpcodeEx)]);
#endif // L2SERVER_DEBUG
							uPacketOffset = ((UINT64*)0x121C0D60)[((BYTE)uOpcodeEx)];
							tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
							if(!(bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, ((BYTE)uOpcodeEx))))
							{
								InterlockedExchange(&pUserSocket->UserSocketExt.nLoginStage, 4);
							}
						}
						else
						{
#ifdef L2SERVER_DEBUG_PACKET_DELAY
							g_Log->Add(CLog::red, L"[%s][%d] packetEx 0x%04X blocked by delay, len %u, login_stage %i, delay %u / %u", __WFUNCTION__, __LINE__, uOpcodeEx, uPacketLen, _nLoginStage, uDelayTickCount, OutGameMinDelayEx[((BYTE)uOpcodeEx)]);
#endif // L2SERVER_DEBUG_PACKET_DELAY
							bPacketResult = true;
						}
						break;
					}
				default:
					{
#ifdef L2SERVER_USE_DELAY_SYSTEM
						if(uDelayTickCount > InGameMinDelayEx[((BYTE)uOpcodeEx)])
#else // L2SERVER_USE_DELAY_SYSTEM
						if(true)
#endif // L2SERVER_USE_DELAY_SYSTEM
						{
//#ifdef L2SERVER_DEBUG
//							g_Log->Add(CLog::black, L"[%s][%d] incoming packetEx 0x%04X, len %u, delay %u / %u", __WFUNCTION__, __LINE__, uOpcodeEx, uPacketLen, uDelayTickCount, InGameMinDelayEx[((BYTE)uOpcodeEx)]);
//#endif // L2SERVER_DEBUG
							uPacketOffset = ((UINT64*)0x121C0D60)[((BYTE)uOpcodeEx)];
							tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
							bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, ((BYTE)uOpcodeEx));
						}
						else
						{
#ifdef L2SERVER_SEND_DELAY_MSG
							pUserSocket->SendSystemMessage(L"WALL", L"Stop flood to server");
#endif // L2SERVER_SEND_DELAY_MSG
#ifdef L2SERVER_DEBUG_PACKET_DELAY
							g_Log->Add(CLog::red, L"[%s][%d] packetEx 0x%04X blocked by delay, len %u, login_stage %i, delay %u / %u", __WFUNCTION__, __LINE__, uOpcodeEx, uPacketLen, _nLoginStage, uDelayTickCount, InGameMinDelayEx[((BYTE)uOpcodeEx)]);
#endif // L2SERVER_DEBUG_PACKET_DELAY
#ifdef L2SERVER_USE_DELAY_KICK
							bPacketResult = true;
#else // L2SERVER_USE_DELAY_KICK
							bPacketResult = false;
#endif // L2SERVER_USE_DELAY_KICK
						}
						break;
					}
				}
			}
			else if(((UINT32)_nLoginStage) == 5)
			{
				switch(((BYTE)uOpcodeEx))
				{
				case 0x01: //RequestManorList
				case 0x21: //RequestKeyMapping
				case 0x3D: //RequestAllFortressInfo
					{
						if(uDelayTickCount > InGameMinDelayEx[((BYTE)uOpcodeEx)])
						{
#ifdef L2SERVER_DEBUG
							g_Log->Add(CLog::black, L"[%s][%d] incoming packetEx 0x%04X, len %u, delay %u / %u", __WFUNCTION__, __LINE__, uOpcodeEx, uPacketLen, uDelayTickCount, InGameMinDelayEx[((BYTE)uOpcodeEx)]);
#endif // L2SERVER_DEBUG
							uPacketOffset = ((UINT64*)0x121C0D60)[((BYTE)uOpcodeEx)];
							tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
							bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, ((BYTE)uOpcodeEx));
						}
						else
						{
#ifdef L2SERVER_DEBUG_PACKET_DELAY
							g_Log->Add(CLog::red, L"[%s][%d] packetEx 0x%04X blocked by delay, len %u, login_stage %i, delay %u / %u", __WFUNCTION__, __LINE__, uOpcodeEx, uPacketLen, _nLoginStage, uDelayTickCount, InGameMinDelayEx[((BYTE)uOpcodeEx)]);
#endif // L2SERVER_DEBUG_PACKET_DELAY
#ifdef L2SERVER_USE_DELAY_KICK
							bPacketResult = true;
#else // L2SERVER_USE_DELAY_KICK
							bPacketResult = false;
#endif // L2SERVER_USE_DELAY_KICK
						}
						break;
					}
				default:
					{
#ifdef L2SERVER_DEBUG
						g_Log->Add(CLog::red, L"[%s][%d] packetEx 0x%04X blocked by stage, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcodeEx, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
						bPacketResult = true;
						break;
					}
				}
			}
			else
			{
#ifdef L2SERVER_DEBUG
				g_Log->Add(CLog::red, L"[%s][%d] packetEx 0x%04X blocked by stage, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcodeEx, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
				bPacketResult = true;
			}
		}
		else
		{
			if(_bittest(&pUserSocket->UserSocketExt.nLoginStage, 2))
			{
				switch(((BYTE)uOpcodeEx))
				{
				case 0x36: //RequestGotoLobby
					{
						uCurrentTickCount = GetTickCount();
						if((uDelayTickCount = (uCurrentTickCount - ((DWORD)InterlockedExchange((volatile LONG*)&pUserSocket->UserSocketExt.uLastPacketExTickCount[((BYTE)uOpcodeEx)], (LONG)uCurrentTickCount)))) > OutGameMinDelayEx[((BYTE)uOpcodeEx)])
						{
#ifdef L2SERVER_DEBUG
							g_Log->Add(CLog::black, L"[%s][%d] incoming packetEx 0x%04X, len %u", __WFUNCTION__, __LINE__, uOpcodeEx, uPacketLen);
#endif // L2SERVER_DEBUG
							uPacketOffset = ((UINT64*)0x121C0D60)[((BYTE)uOpcodeEx)];
							tUserSocketPacketHandler fUserSocketPacketHandler = (tUserSocketPacketHandler)uPacketOffset;
							bPacketResult = fUserSocketPacketHandler(pUserSocket, packet, ((BYTE)uOpcodeEx));
						}
						else
						{
#ifdef L2SERVER_DEBUG_PACKET_DELAY
							g_Log->Add(CLog::red, L"[%s][%d] packetEx 0x%04X blocked by delay, len %u, login_stage %i, delay %u / %u", __WFUNCTION__, __LINE__, uOpcodeEx, uPacketLen, _nLoginStage, uDelayTickCount, OutGameMinDelayEx[((BYTE)uOpcodeEx)]);
#endif // L2SERVER_DEBUG_PACKET_DELAY
							bPacketResult = true;
						}
						break;
					}
				default:
					{
#ifdef L2SERVER_DEBUG
						g_Log->Add(CLog::red, L"[%s][%d] packetEx 0x%04X blocked by switch, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcodeEx, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
						bPacketResult = true;
						break;
					}
				}
			}
			else
			{
#ifdef L2SERVER_DEBUG
				g_Log->Add(CLog::red, L"[%s][%d] packetEx 0x%04X blocked by stage, len %u, login_stage %i", __WFUNCTION__, __LINE__, uOpcodeEx, uPacketLen, _nLoginStage);
#endif // L2SERVER_DEBUG
				bPacketResult = true;
			}
		}
	}

	UnGuardRet(bPacketResult)
}
