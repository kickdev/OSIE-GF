#pragma once

#pragma pack(push, 1)

class CTradeManager : public CMemoryObject
{
public:
	CTradeManager() {};
	~CTradeManager() {};

	//* 020 */ virtual __int64 _vfunc020() { return NULL; };
	/* 028 */ 

	CObjectSP* GetTrade(CObjectSP* pObjectSP, UINT32 uTradeSID)
	{
		typedef CObjectSP* (__thiscall *t)(CTradeManager*, CObjectSP*, UINT32);
		t f = (t)0x00872A48;
		return f(this, pObjectSP, uTradeSID);
	};

	/* 0018 */ UINT32 _uUnkVal0018; 
	/* 001C */ UINT32 _uUnkVal001C;  
	/* 0020 */
};

#pragma pack(pop)

CompileTimeSizeCheck(CTrade, 0x4090);
