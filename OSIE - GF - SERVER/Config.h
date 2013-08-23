#pragma once

#pragma pack(push, 1)

#define PACKET_LIMITER_CFG_MAX_COUNT 0
#define PACKET_LIMITER_CFG_MIN_TICK 1
#define PACKET_LIMITER_CFG_2 2 //reserved
#define PACKET_LIMITER_CFG_3 3 //reserved

class CPacketLimiterCfg
{
public:
	CPacketLimiterCfg();
	~CPacketLimiterCfg() {};

	/* 0000 */ DWORD PacketSetting[256][4];
	/* 1000 */ DWORD PacketExSetting[256][4];
	/* 2000 */ UINT32 uReleaseTime;
	/* 2004 */ UINT32 uMaxPacket;
	/* 2008 */ UINT32 uUnkSetting3;
	/* 200C */ UINT32 _padding200C;
	/* 2010 */ 
};

class GFSConfig
{
public:
	GFSConfig() {};
	~GFSConfig() {};

	/* 0000 */ CPacketLimiterCfg plc;
	/* 0000 */ 
};

class GFS
{
public:
	GFS() {};
	~GFS() {};

	/* 0000 */ GFSConfig cfg;
	/* 0000 */ 
};

#pragma pack(pop)
