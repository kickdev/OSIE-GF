#include "stdafx.h"

CPacketLimiterCfg::CPacketLimiterCfg()
{
	for(UINT32 i = 0; i < 256; i++)
	{
		this->PacketSetting[i][PACKET_LIMITER_CFG_MAX_COUNT] = 100;		//packet delay by id (in ms)
		this->PacketSetting[i][PACKET_LIMITER_CFG_MIN_TICK] = 0;		//packet action by id (block, block to ping, kick, ban, no action)
		this->PacketSetting[i][PACKET_LIMITER_CFG_2] = 0;				//reserved
		this->PacketSetting[i][PACKET_LIMITER_CFG_3] = 0;				//reserved
		this->PacketExSetting[i][PACKET_LIMITER_CFG_MAX_COUNT] = 100;	//packet delay by id (in ms)
		this->PacketExSetting[i][PACKET_LIMITER_CFG_MIN_TICK] = 0;		//packet action by id (block, block to ping, kick, ban, no action)
		this->PacketExSetting[i][PACKET_LIMITER_CFG_2] = 0;				//reserved
		this->PacketExSetting[i][PACKET_LIMITER_CFG_3] = 0;				//reserved
	}

	this->uReleaseTime = 1000;
	this->uMaxPacket = 1000;
	this->uUnkSetting3 = 500;
}
