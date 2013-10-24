#pragma once

#pragma pack(push, 1)

class CUser;

class CUserOSIE
{
public:
	CUserOSIE();
	CUserOSIE(wchar_t* pCharName, wchar_t* pAccName, unsigned int uCharId, unsigned int uAccountId, unsigned int uPledgeId, unsigned int uBuilder, unsigned int uGender, unsigned int uRace, unsigned int uClass, unsigned int uWorld, int nPosX, int nPosY, int nPosZ, double fHP, double fMP, unsigned int uSp, unsigned __int64 uExp, unsigned int uLevel, int nAlign, unsigned int uPK, unsigned int uPvP, unsigned int uPKPardon, unsigned int uUnk1, unsigned int uUnk2, unsigned int uUnk3, unsigned int uUnk4, unsigned int uUnk5, unsigned int uUnk6, unsigned int uUnk7, unsigned int uUnk8, unsigned int uUnk9, wchar_t* pCharTitle, unsigned char* pUnkBuff, unsigned int uUnk10, unsigned int uUnk11, unsigned int uUnk12, unsigned int uUnk13, unsigned int uUnk14, unsigned int uUnk15, unsigned int uUnk16, unsigned int uUnk17, unsigned int uUnk18, unsigned int uUnk19, unsigned int uUnk20, unsigned int uUnk21, unsigned int uUnk22, bool bUnk23);
	~CUserOSIE();

	CUser* GetUser();

	/* 0000 */ WCHAR pCharName[50];
	/* 0064 */ WCHAR pAccName[50];
	/* 00C8 */ UINT32 uCharId;
	/* 00CC */ UINT32 uAccountId;
	/* 00D0 */ UINT32 uPledgeId;
	/* 00D4 */ UINT32 uBuilder;
	/* 00D8 */ UINT32 uGender;
	/* 00DC */ UINT32 uRace;
	/* 00E0 */ UINT32 uClass;
	/* 00E4 */ UINT32 uWorld;
	/* 00E8 */ int nPosX;
	/* 00EC */ int nPosY;
	/* 00F0 */ int nPosZ;
	/* 00F4 */ double fHP;
	/* 00FC */ double fMP;
	/* 0104 */ UINT32 uSp;
	/* 0108 */ UINT64 uExp;
	/* 0110 */ UINT32 uLevel;
	/* 0114 */ int nAlign;
	/* 0118 */ UINT32 uPK;
	/* 011C */ UINT32 uPvP;
	/* 0120 */ UINT32 uPKPardon;
	/* 0124 */ WCHAR pCharTitle[50];

	/* 0188 */ CUserSocket* socket;
	/* 0190 */

	BOOL CheckRace();
	CUserSocket* GetUserSocket();
};

class CUserExt
{
public:
	CUserExt();
	~CUserExt();

	CUser* GetUser(); //compiler optimized this

	/* 0000 */ bool bIsEnterIntoWorld;		//
	/* 0001 */ bool bIsEnteredIntoWorld;	//
	/* 0002 */ bool _padding0002[2];		//
	/* 0004 */ UINT32 uBuilderLvL;			//
	/* 0008 */ 

};

struct RpgClubUserExt
{
	/* 0000 */ CUser* pUser;		//pUser
	/* 0008 */ 
};

struct HTMLCmdData
{
#ifdef IS_VS2005_RELEASE
	/* 0000 */ wstring html_data;  
#else //IS_VS2005_RELEASE
	/* 0000 */ unsigned char _padding0000[VS2005_RELEASE_STRING_SIZE];
#endif //IS_VS2005_RELEASE 
	/* 0028 */ UINT64 var0028[4];
	/* 0048 */ 
};

CompileTimeSizeCheck(HTMLCmdData, 0x48);

typedef vector<HTMLCmdData> v_html_data;

class CUser : public CCreature
{
public:
	CUser() {};
	~CUser() {};

	static CUser* __cdecl UserConstructor(CUser* pUser, wchar_t* pCharName, wchar_t* pAccName, unsigned int uCharId, unsigned int uAccountId, unsigned int uPledgeId, unsigned int uBuilder, unsigned int uGender, unsigned int uRace, unsigned int uClass, unsigned int uWorld, int nPosX, int nPosY, int nPosZ, double fHP, double fMP, unsigned int uSp, unsigned __int64 uExp, unsigned int uLevel, int nAlign, unsigned int uPK, unsigned int uPvP, unsigned int uPKPardon, unsigned int uUnk1, unsigned int uUnk2, unsigned int uUnk3, unsigned int uUnk4, unsigned int uUnk5, unsigned int uUnk6, unsigned int uUnk7, unsigned int uUnk8, unsigned int uUnk9, wchar_t* pCharTitle, unsigned char* pUnkBuff, unsigned int uUnk10, unsigned int uUnk11, unsigned int uUnk12, unsigned int uUnk13, unsigned int uUnk14, unsigned int uUnk15, unsigned int uUnk16, unsigned int uUnk17, unsigned int uUnk18, unsigned int uUnk19, unsigned int uUnk20, unsigned int uUnk21, unsigned int uUnk22, bool bUnk23);
	static CUser* __cdecl UserDestructor(CUser* pUser, bool bIsMemoryFreeUsed);

	/* AA8 */ virtual __int64 _vfuncAA8() { return NULL; };
	/* AB0 */ virtual __int64 _vfuncAB0() { return NULL; };
	/* AB8 */ virtual __int64 _vfuncAB8() { return NULL; };
	/* AC0 */ virtual __int64 _vfuncAC0() { return NULL; };
	/* AC8 */ virtual __int64 _vfuncAC8() { return NULL; };
	/* AD0 */ virtual __int64 _vfuncAD0() { return NULL; };
	/* AD8 */ virtual __int64 _vfuncAD8() { return NULL; };
	/* AE0 */ virtual __int64 _vfuncAE0() { return NULL; };
	/* AE8 */ virtual __int64 _vfuncAE8() { return NULL; };
	/* AF0 */ virtual __int64 _vfuncAF0() { return NULL; };
	/* AF8 */ virtual __int64 _vfuncAF8() { return NULL; };
	/* B00 */ virtual __int64 _vfuncB00() { return NULL; };
	/* B08 */ virtual __int64 _vfuncB08() { return NULL; };
	/* B10 */ virtual __int64 _vfuncB10() { return NULL; };
	/* B18 */ virtual __int64 _vfuncB18() { return NULL; };
	/* B20 */ virtual __int64 _vfuncB20() { return NULL; };
	/* B28 */ virtual __int64 _vfuncB28() { return NULL; };
	/* B30 */ virtual __int64 _vfuncB30() { return NULL; };
	/* B38 */ virtual __int64 _vfuncB38() { return NULL; };
	/* B40 */ virtual __int64 _vfuncB40() { return NULL; };
	/* B48 */ virtual __int64 _vfuncB48() { return NULL; };
	/* B50 */ virtual __int64 _vfuncB50() { return NULL; };
	/* B58 */ virtual __int64 _vfuncB58() { return NULL; };
	/* B60 */ virtual __int64 _vfuncB60() { return NULL; };
	/* B68 */ virtual __int64 _vfuncB68() { return NULL; };
	/* B70 */ virtual __int64 _vfuncB70() { return NULL; };
	/* B78 */ virtual __int64 _vfuncB78() { return NULL; };
	/* B80 */ virtual __int64 _vfuncB80() { return NULL; };
	/* B88 */ virtual __int64 _vfuncB88() { return NULL; };
	/* B90 */ virtual __int64 _vfuncB90() { return NULL; };
	/* B98 */ virtual __int64 _vfuncB98() { return NULL; };
	/* BA0 */ virtual __int64 _vfuncBA0() { return NULL; };
	/* BA8 */ virtual __int64 _vfuncBA8() { return NULL; };
	/* BB0 */ virtual __int64 _vfuncBB0() { return NULL; };
	/* BB8 */ virtual __int64 _vfuncBB8() { return NULL; };
	/* BC0 */ virtual __int64 _vfuncBC0() { return NULL; };
	/* BC8 */ virtual __int64 _vfuncBC8() { return NULL; };
	/* BD0 */ virtual __int64 _vfuncBD0() { return NULL; };
	/* BD8 */ virtual __int64 _vfuncBD8() { return NULL; };
	/* BE0 */ virtual __int64 _vfuncBE0() { return NULL; };
	/* BE8 */ virtual __int64 _vfuncBE8() { return NULL; };
	/* BF0 */ virtual __int64 _vfuncBF0() { return NULL; };
	/* BF8 */ virtual __int64 _vfuncBF8() { return NULL; };
	/* C00 */ virtual __int64 _vfuncC00() { return NULL; };
	/* C08 */ virtual __int64 _vfuncC08() { return NULL; };
	/* C10 */ virtual __int64 _vfuncC10() { return NULL; };
	/* C18 */ virtual __int64 _vfuncC18() { return NULL; };
	/* C20 */ virtual __int64 _vfuncC20() { return NULL; };
	/* C28 */ virtual __int64 _vfuncC28() { return NULL; };
	/* C30 */ virtual __int64 _vfuncC30() { return NULL; };
	/* C38 */ virtual __int64 _vfuncC38() { return NULL; };
	/* C40 */ virtual __int64 _vfuncC40() { return NULL; };
	/* C48 */ virtual __int64 _vfuncC48() { return NULL; };
	/* C50 */ virtual __int64 _vfuncC50() { return NULL; };
	/* C58 */ virtual __int64 _vfuncC58() { return NULL; };
	/* C60 */ virtual __int64 _vfuncC60() { return NULL; };
	/* C68 */ virtual __int64 _vfuncC68() { return NULL; };
	/* C70 */ virtual __int64 _vfuncC70() { return NULL; };
	/* C78 */ virtual __int64 _vfuncC78() { return NULL; };
	/* C80 */ virtual __int64 _vfuncC80() { return NULL; };
	/* C88 */ virtual __int64 _vfuncC88() { return NULL; };
	/* C90 */

	/* 840 */ static bool __cdecl _DeleteItemInInventoryBeforeCommit(CUser* pUser, UINT32 uItemId, UINT64 uItemCount);
	/* 841 */ static void __cdecl _UserEnterWorld(CUser* pUser);
	/* 842 */ static void __cdecl _Say(CUser* pUser, wchar_t* msg);

	bool __thiscall IsNowTrade();

	CTrade* __thiscall GetTrade();

	void __thiscall EnterWorld();

	void __thiscall Say(wchar_t* msg);

	/* 1CB0 */ unsigned int _uUnkVal1CB0[1389];
	/* 3264 */ CYieldLock html_cs;
	/* 3270 */ bool bUnkVal3270;
	/* 3271 */ bool bUnkVal3271[7];
#ifdef IS_VS2005_RELEASE
	/* 3278 */ v_html_data html_data;  
#else //IS_VS2005_RELEASE
	/* 3278 */ unsigned char _padding3278[VS2005_RELEASE_VECTOR_SIZE];
#endif //IS_VS2005_RELEASE 
	/* 3298 */ unsigned int _uUnkVal3298[50]; 
	/* 3360 */ UINT32 uTradeSID;
	/* 3364 */ unsigned int _uUnkVal3364[427];
	/* 3A10 */ CUserExt UserExt;
	/* 3A18 */ CUserOSIE UserOSIE;
	/* 3BA0 */
};

#pragma pack(pop)

CompileTimeSizeCheck(RpgClubUserExt, 0x0008);
CompileTimeOffsetCheck(CUser, uTradeSID, 0x3360);
CompileTimeOffsetCheck(CUser, UserExt, 0x3A10);
CompileTimeOffsetCheck(CUser, UserOSIE, 0x3A18);