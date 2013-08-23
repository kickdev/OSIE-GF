#pragma once

#pragma pack(push, 1)

class CTrade : public CMemoryObject
{
public:
	CTrade() {};
	~CTrade() {};

	/* 020 */ virtual __int64 _vfunc020() { return NULL; };
	/* 028 */ 

	/* 0018 */ UINT32 _uUnkVal0018; 
	/* 001C */ UINT32 _uUnkVal001C; 
	/* 0020 */ UINT32 _uUnkVal0020; 
	/* 0024 */ DWORD uTickCount1; 
	/* 0028 */ UINT32 uTradeStarterSID;	//who start trade (1 person)
	/* 002C */ UINT32 uTradeTargetSID;	//who accept trade (2 person)
#ifdef IS_VS2005_RELEASE
	/* 0030 */ v_int starter_trade_items; 
#else //IS_VS2005_RELEASE
	/* 0030 */ unsigned char _padding0030[VS2005_RELEASE_VECTOR_SIZE];
#endif //IS_VS2005_RELEASE
#ifdef IS_VS2005_RELEASE
	/* 0050 */ v_int target_trade_items;  
#else //IS_VS2005_RELEASE
	/* 0050 */ unsigned char _padding0050[VS2005_RELEASE_VECTOR_SIZE];
#endif //IS_VS2005_RELEASE 
	/* 0070 */ INT8 _cUnkVal0070; 
	/* 0071 */ INT8 _cUnkVal0071; 
	/* 0072 */ INT8 _cUnkVal0072; 
	/* 0073 */ INT8 _cUnkVal0073; 
	/* 0074 */ BYTE pBuff1[8192]; 
	/* 2074 */ BYTE pBuff2[8192]; 
	/* 4074 */ UINT32 _uUnkVal4074; 
	/* 4078 */ UINT32 _uUnkVal4078; 
	/* 407C */ CYieldLock trade_cs;
	/* 4088 */ DWORD nTickCount2; 
	/* 408C */ UINT32 _padding408C; 
	/* 4090 */
};

#pragma pack(pop)

CompileTimeSizeCheck(CTrade, 0x4090);
