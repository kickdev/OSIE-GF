#pragma once

#pragma pack(push, 1)

class CUserSocket;

#define MAX_GAME_EX_PROTOCOL 0x68

class CUserSocketExt
{
public:
	CUserSocketExt();
	~CUserSocketExt();

	CUserSocket* GetUserSocket(); //compiler optimized this

	/* 0000 */ DWORD uLastPacketTickCount[256];
	/* 0400 */ DWORD uLastPacketExTickCount[(MAX_GAME_EX_PROTOCOL + 1)];
	/* 0800 */ long nLoginStage;
	/* 0804 */ UINT32 uBuilderLVL;
	/* 0808 */ unsigned int _uUnkVal0404[2];
	/* 0810 */ 
};

struct RpgClubUserSocketExt
{
	/* 0000 */ CUserSocket* pUserSocket;		//pUserSocket
	/* 0008 */ bool bUnkVal0008;				//0
	/* 0009 */ bool bUnkVal0009;				//0
	/* 000A */ bool _padding000A[2];
	/* 000C */ DWORD uLastPacketTickCount[256];	//memset 0x00
	/* 040C */ UINT32 uBuilderLVL;				//0
	/* 0410 */ 
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
	/* 0530 */ unsigned int _uUnkVal0530[668];
	/* 0FA0 */ CUserSocketExt UserSocketExt;
	/* 13A0 */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(RpgClubUserSocketExt, 0x0410);
CompileTimeOffsetCheck(CUserSocket, UserSocketExt, 0x0FA0);
