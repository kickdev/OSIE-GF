#include "stdafx.h"

CUserSocketExt::CUserSocketExt()
{
	this->nLoginStage = 1;
	this->uBuilderLVL = 0;
#ifdef L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM
	for(UINT32 i = 0; i < (MAX_GAME_PROTOCOL + 1); i++)
		this->uLastPacketTickCount[i] = 0xCCCCCCCC;
	for(UINT32 i = 0; i < (MAX_GAME_EX_PROTOCOL + 1); i++)
		this->uLastPacketExTickCount[i] = 0xCCCCCCCC;
#endif // L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM
}

CUserSocketExt::~CUserSocketExt()
{
#ifdef L2SERVER_DEBUG
	g_Log->Add(CLog::black, L"[%s] released", __WFUNCTION__);
#endif // L2SERVER_DEBUG
}

CUserSocket* CUserSocketExt::GetUserSocket()
{
	return (CUserSocket*)(((UINT64)this) - offsetof(CUserSocket, UserSocketExt));
}

//

CRPGClubUserSocketExtL2M::CRPGClubUserSocketExtL2M()
{
	//this->bUnkVal0004 = false;
	//memset(&this->_uUnkVal0005, 0x00, 0x40);
	//memset(&this->_uUnkVal0045, 0x00, 0x40);
	//this->_uUnkVal0088 = NULL;
	//this->_uUnkVal008C = NULL;
	//this->_uUnkVal0090 = NULL;
	this->uLastReadTickCount = GetTickCount();
	this->uReadPacketCount = NULL;
	this->uLogPacketCount = NULL;
	memset(&this->PacketLimiterData, 0x00, ((MAX_GAME_PROTOCOL + 1) * 2 * 4));
	memset(&this->PacketExLimiterData, 0x00, ((MAX_GAME_EX_PROTOCOL + 1) * 2 * 4));
}

bool CRPGClubUserSocketExtL2M::PacketDelayCheck(const BYTE* pPacket, BYTE uOpcode)
{
	Guard(__WFUNCSIG__);

	CUser* pUser;
	UINT32 uPacketLen;
	CUserSocket* pUserSocket = this->GetUserSocket();

	if((uPacketLen = pUserSocket->uReadPacketLen) && uOpcode != 0xD0)
	{
		DWORD uCurrentTickCount = GetTickCount();
		DWORD uLastReadDelay = (uCurrentTickCount - this->uLastReadTickCount);

		if(uLastReadDelay > g_GFS.cfg.plc.uReleaseTime)
		{
			this->uLastReadTickCount = uCurrentTickCount;
			this->uReadPacketCount = NULL;
			this->uLogPacketCount = NULL;
			for(UINT32 i = 0; i < (MAX_GAME_PROTOCOL + 1); i++)
				this->PacketLimiterData[i][USER_DELAY_COUNT] = this->PacketLimiterData[i][USER_DELAY_LAST_TICK] = NULL;
		}

		if(++this->uReadPacketCount > g_GFS.cfg.plc.uMaxPacket)
		{
			if(!((this->uReadPacketCount - 1) % g_GFS.cfg.plc.uMaxPacket))
				g_Log->Add(CLog::red, L"(FIXED BY L2M.RU) Max packet count reached for all packets User Count [%u] Max Count [%u] Packet 0x%02X User [%s][%u.%u.%u.%u] Tick [%u]", this->uReadPacketCount, g_GFS.cfg.plc.uMaxPacket, uOpcode, ((pUser = pUserSocket->User()) ? pUser->SD->wszName : L"NO USER"), pUserSocket->client_ip.S_un.S_un_b.s_b1, pUserSocket->client_ip.S_un.S_un_b.s_b2, pUserSocket->client_ip.S_un.S_un_b.s_b3, pUserSocket->client_ip.S_un.S_un_b.s_b4, uLastReadDelay);
			goto ReturnErrorBlock;
		}

		DWORD* pDelayPair = this->PacketLimiterData[uOpcode];
		DWORD* pDelayPairCfg = g_GFS.cfg.plc.PacketSetting[uOpcode];

		if(pDelayPair[USER_DELAY_COUNT])
		{
			pDelayPair[USER_DELAY_COUNT]++;

			if(pDelayPairCfg[PACKET_LIMITER_CFG_MAX_COUNT] && pDelayPair[USER_DELAY_COUNT] > pDelayPairCfg[PACKET_LIMITER_CFG_MAX_COUNT]) //
			{
				if(!((pDelayPair[USER_DELAY_COUNT] - 1) % pDelayPairCfg[PACKET_LIMITER_CFG_MAX_COUNT]))
					g_Log->Add(CLog::red, L"(FIXED BY L2M.RU) Max packet count reached for packet 0x%02X User Count [%u] Max Count [%u] User [%s][%u.%u.%u.%u] Tick [%u]", uOpcode, pDelayPair[USER_DELAY_COUNT], pDelayPairCfg[PACKET_LIMITER_CFG_MAX_COUNT], ((pUser = pUserSocket->User()) ? pUser->SD->wszName : L"NO USER"), pUserSocket->client_ip.S_un.S_un_b.s_b1, pUserSocket->client_ip.S_un.S_un_b.s_b2, pUserSocket->client_ip.S_un.S_un_b.s_b3, pUserSocket->client_ip.S_un.S_un_b.s_b4, uLastReadDelay);
				goto ReturnErrorBlock;
			}

			if(pDelayPairCfg[PACKET_LIMITER_CFG_MIN_TICK] && ((uCurrentTickCount - pDelayPair[USER_DELAY_LAST_TICK]) < pDelayPairCfg[PACKET_LIMITER_CFG_MIN_TICK]))
			{
				if(this->uLogPacketCount++ < 4)
					g_Log->Add(CLog::red, L"(FIXED BY L2M.RU) Tick interval reached for packet 0x%02X User tick [%u] Set tick [%u] User [%s][%u.%u.%u.%u] Tick [%u]", uOpcode, (uCurrentTickCount - pDelayPair[USER_DELAY_LAST_TICK]), pDelayPairCfg[PACKET_LIMITER_CFG_MIN_TICK], ((pUser = pUserSocket->User()) ? pUser->SD->wszName : L"NO USER"), pUserSocket->client_ip.S_un.S_un_b.s_b1, pUserSocket->client_ip.S_un.S_un_b.s_b2, pUserSocket->client_ip.S_un.S_un_b.s_b3, pUserSocket->client_ip.S_un.S_un_b.s_b4, uLastReadDelay);
				goto ReturnErrorBlock;
			}

			pDelayPair[USER_DELAY_LAST_TICK] = uCurrentTickCount;
			UnGuardRet(true)
		}
		else
		{
			pDelayPair[USER_DELAY_COUNT]++;
			pDelayPair[USER_DELAY_LAST_TICK] = uCurrentTickCount;
			UnGuardRet(true)
		}
	}
	else
		UnGuardRet(true)

ReturnErrorBlock:
	UnGuardRet(false)
}

bool CRPGClubUserSocketExtL2M::PacketExDelayCheck(const BYTE* pPacket, WORD uOpcodeEx)
{
	Guard(__WFUNCSIG__);

	CUser* pUser;
	UINT32 uPacketLen;
	CUserSocket* pUserSocket = this->GetUserSocket();

	if((uPacketLen = pUserSocket->uReadPacketLen))
	{
		DWORD uCurrentTickCount = GetTickCount();
		DWORD uLastReadDelay = (uCurrentTickCount - this->uLastReadTickCount);

		if(uLastReadDelay > g_GFS.cfg.plc.uReleaseTime)
		{
			this->uLastReadTickCount = uCurrentTickCount;
			this->uReadPacketCount = NULL;
			this->uLogPacketCount = NULL;
			for(UINT32 i = 0; i < (MAX_GAME_EX_PROTOCOL + 1); i++)
				this->PacketExLimiterData[i][USER_DELAY_COUNT] = this->PacketExLimiterData[i][USER_DELAY_LAST_TICK] = NULL;
		}

		if(++this->uReadPacketCount > g_GFS.cfg.plc.uMaxPacket)
		{
			if(!((this->uReadPacketCount - 1) % g_GFS.cfg.plc.uMaxPacket))
				g_Log->Add(CLog::red, L"(FIXED BY L2M.RU) Max packet count reached for all packets User Count [%u] Max Count [%u] PacketEx 0x%04X User [%s][%u.%u.%u.%u] Tick [%u]", this->uReadPacketCount, g_GFS.cfg.plc.uMaxPacket, uOpcodeEx, ((pUser = pUserSocket->User()) ? pUser->SD->wszName : L"NO USER"), pUserSocket->client_ip.S_un.S_un_b.s_b1, pUserSocket->client_ip.S_un.S_un_b.s_b2, pUserSocket->client_ip.S_un.S_un_b.s_b3, pUserSocket->client_ip.S_un.S_un_b.s_b4, uLastReadDelay);
			goto ReturnErrorBlock;
		}

		DWORD* pDelayPair = this->PacketExLimiterData[uOpcodeEx];
		DWORD* pDelayPairCfg = g_GFS.cfg.plc.PacketExSetting[uOpcodeEx];

		if(pDelayPair[USER_DELAY_COUNT])
		{
			pDelayPair[USER_DELAY_COUNT]++;

			if(pDelayPairCfg[PACKET_LIMITER_CFG_MAX_COUNT] && pDelayPair[USER_DELAY_COUNT] > pDelayPairCfg[PACKET_LIMITER_CFG_MAX_COUNT]) //
			{
				if(!((pDelayPair[USER_DELAY_COUNT] - 1) % pDelayPairCfg[PACKET_LIMITER_CFG_MAX_COUNT]))
					g_Log->Add(CLog::red, L"(FIXED BY L2M.RU) Max packet count reached for packetEx 0x%04X User Count [%u] Max Count [%u] User [%s][%u.%u.%u.%u] Tick [%u]", uOpcodeEx, pDelayPair[USER_DELAY_COUNT], pDelayPairCfg[PACKET_LIMITER_CFG_MAX_COUNT], ((pUser = pUserSocket->User()) ? pUser->SD->wszName : L"NO USER"), pUserSocket->client_ip.S_un.S_un_b.s_b1, pUserSocket->client_ip.S_un.S_un_b.s_b2, pUserSocket->client_ip.S_un.S_un_b.s_b3, pUserSocket->client_ip.S_un.S_un_b.s_b4, uLastReadDelay);
				goto ReturnErrorBlock;
			}

			if(pDelayPairCfg[PACKET_LIMITER_CFG_MIN_TICK] && ((uCurrentTickCount - pDelayPair[USER_DELAY_LAST_TICK]) < pDelayPairCfg[PACKET_LIMITER_CFG_MIN_TICK]))
			{
				if(this->uLogPacketCount++ < 4)
					g_Log->Add(CLog::red, L"(FIXED BY L2M.RU) Tick interval reached for packetEx 0x%04X User tick [%u] Set tick [%u] User [%s][%u.%u.%u.%u] Tick [%u]", uOpcodeEx, (uCurrentTickCount - pDelayPair[USER_DELAY_LAST_TICK]), pDelayPairCfg[PACKET_LIMITER_CFG_MIN_TICK], ((pUser = pUserSocket->User()) ? pUser->SD->wszName : L"NO USER"), pUserSocket->client_ip.S_un.S_un_b.s_b1, pUserSocket->client_ip.S_un.S_un_b.s_b2, pUserSocket->client_ip.S_un.S_un_b.s_b3, pUserSocket->client_ip.S_un.S_un_b.s_b4, uLastReadDelay);
				goto ReturnErrorBlock;
			}

			pDelayPair[USER_DELAY_LAST_TICK] = uCurrentTickCount;
			UnGuardRet(true)
		}
		else
		{
			pDelayPair[USER_DELAY_COUNT]++;
			pDelayPair[USER_DELAY_LAST_TICK] = uCurrentTickCount;
			UnGuardRet(true)
		}
	}
	else
		UnGuardRet(true)

ReturnErrorBlock:
	UnGuardRet(false)
}

CUserSocket* CRPGClubUserSocketExtL2M::GetUserSocket()
{
	return (CUserSocket*)(((UINT64)this) - offsetof(CUserSocket, UserSocketL2M));
}

//
