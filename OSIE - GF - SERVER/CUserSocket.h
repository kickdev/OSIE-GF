#pragma once

#pragma pack(push, 1)

class CUserSocket;

#define MAX_GAME_PROTOCOL 0xD0
#define MAX_GAME_EX_PROTOCOL 0x68

class CUserSocketExt
{
public:
	CUserSocketExt();
	~CUserSocketExt();

	CUserSocket* GetUserSocket(); //compiler optimized this

	/* 0000:1A20 */ long nLoginStage;
	/* 0004:1A24 */ UINT32 uBuilderLVL;
	/* 0008:1A28 */ unsigned int _uUnkVal0008[6];
#ifdef L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM
	/* 0000:0000 */ DWORD uLastPacketTickCount[(MAX_GAME_PROTOCOL + 1)];
	/* 0000:0000 */ DWORD uLastPacketExTickCount[(MAX_GAME_EX_PROTOCOL + 1)];
#endif // L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM
	/* 0020:1A40 */ 
};

class CRPGClubUserSocketExt
{
public:
	CRPGClubUserSocketExt() {};
	~CRPGClubUserSocketExt() {};

	/* 0000 */ CUserSocket* pUserSocket;		//pUserSocket
	/* 0008 */ bool bUnkVal0008;				//0
	/* 0009 */ bool bUnkVal0009;				//0
	/* 000A */ bool _padding000A[2];
	/* 000C */ DWORD uLastPacketTickCount[256];	//memset 0x00
	/* 040C */ UINT32 uBuilderLVL;				//0
	/* 0410 */ 
};

#define USER_DELAY_LAST_TICK 0
#define USER_DELAY_COUNT 1

class CRPGClubUserSocketExtL2M
{
public:
	CRPGClubUserSocketExtL2M();
	~CRPGClubUserSocketExtL2M() {};

	CUserSocket* GetUserSocket(); //compiler optimized this
	bool PacketDelayCheck(const BYTE* pPacket, BYTE uOpcode);
	bool PacketExDelayCheck(const BYTE* pPacket, WORD uOpcodeEx);

	/* 0000:0FA0 */ unsigned int _uUnkVal0000;
	/* 0004:0FA4 */ bool bUnkVal0004;					//0 flag (new enc system ?)
	/* 0005:0FA5 */ bool _padding0085[3];
	/* 0008:0FA8 */ unsigned int _uUnkVal0008[16];		//0 40h struct (new enc system ?)
	/* 0048:0FE8 */ unsigned int _uUnkVal0045[16];		//0 40h struct (new enc system ?)
	/* 0088:1028 */ unsigned int _uUnkVal0088;			//0
	/* 008C:102C */ unsigned int _uUnkVal008C;			//0
	/* 0090:1030 */ unsigned int _uUnkVal0090;			//0
	/* 0094:1034 */ DWORD uLastReadTickCount;			//create_tick
	/* 0098:1038 */ UINT32 uReadPacketCount;			//0
	/* 009C:103C */ UINT32 uLogPacketCount;				//0
	/* 00A0:1040 */ DWORD PacketLimiterData[(MAX_GAME_PROTOCOL + 1)][2];		//0
	/* 0728:16C8 */ unsigned int _padding0728[2];
	/* 0730:16D0 */ DWORD PacketExLimiterData[(MAX_GAME_EX_PROTOCOL + 1)][2];	//0
	/* 0A78:1A18 */ unsigned int _padding1A18[2];
	/* 0A80:1A20 */ 
};

class CUserSocket : public CSocket
{
public:
	CUserSocket() {};
	~CUserSocket() {};

	static CUserSocket* __cdecl UserSocketConstructor(CUserSocket* pUserSocket, SOCKET _s);
	static CUserSocket* __cdecl UserSocketDestructor(CUserSocket* pUserSocket, bool bIsMemoryFreeUsed);
	static UINT64 __cdecl OutGamePacketHandler(CUserSocket* pUserSocket, const BYTE* packet, BYTE uOpcode);
	static UINT64 __cdecl InGamePacketHandler(CUserSocket* pUserSocket, const BYTE* packet, BYTE uOpcode);
	static bool __cdecl GamePacketExHandler(CUserSocket* pUserSocket, const BYTE* packet, WORD uOpcode);
	static UINT64 __cdecl OutGamePacketHandler2(CUserSocket* pUserSocket, const BYTE* packet, BYTE uOpcode);
	static UINT64 __cdecl InGamePacketHandler2(CUserSocket* pUserSocket, const BYTE* packet, BYTE uOpcode);
	static bool __cdecl GamePacketExHandler2(CUserSocket* pUserSocket, const BYTE* packet, WORD uOpcode);

	void SendSystemMessage(const wchar_t* pSender, const wchar_t* pMsg)
	{
		typedef void (__thiscall *t)(CUserSocket*, const wchar_t*, const wchar_t*);
		t f = (t)0x009244F0;
		f(this, pSender, pMsg);
	};

	/* 0A0 */ virtual CUser* User() { return NULL; };
	/* 0A8 */ virtual __int64 _vfunc0A8() { return NULL; };
	/* 0B0 */ 

	/* 0100 */ unsigned int _uUnkVal0100[266];
	/* 0528 */ CUser* pUser;
	/* 0530 */ unsigned int _uUnkVal0530[647];
	/* 0F4C */ UINT32 uClientCRC;
	/* 0F50 */ unsigned int _uUnkVal0F50[20];
	/* 0FA0 */ CRPGClubUserSocketExtL2M UserSocketL2M; //modded
	/* 1A20 */ CUserSocketExt UserSocketExt;
	/* 1A40 */ 
};

#pragma pack(pop)

CompileTimeOffsetCheck(CUserSocket, uClientCRC, 0x0F4C);
CompileTimeOffsetCheck(CUserSocket, UserSocketL2M, 0x0FA0);
CompileTimeOffsetCheck(CUserSocket, UserSocketExt, 0x1A20);
//CompileTimeSizeCheck(CUserSocket, 0x1A40); //from 4000 to 6720
