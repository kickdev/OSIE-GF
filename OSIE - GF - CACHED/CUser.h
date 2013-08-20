#pragma once

#pragma pack(push, 1)

class CUser : public CMemoryObject
{
public:
	CUser() {};
	~CUser() {};

	UINT32 GetItemWare(UINT32 uItemDbId) //item_id to item_obj_id ? to_type ?
	{
		typedef UINT32 (__thiscall *t)(CUser*, UINT32);
		t f = (t)0x0053BE58;
		return f(this, uItemDbId);
	};
	CObjectSP* GetWareHouse(CObjectSP* pObjectSP, UINT32 uWareHouseType, bool bLoadIfNotExist) //item_id to item_obj_id ? to_type ?
	{
		typedef CObjectSP* (__thiscall *t)(CUser*, CObjectSP*, UINT32, bool);
		t f = (t)0x00543524;
		return f(this, pObjectSP, uWareHouseType, bLoadIfNotExist);
	};
	bool SetSeizedItemOwner(UINT32 uItemDbId, UINT32 uReceiverCharDbId, CWareHouse* pSenderWareHouse)
	{
		typedef bool (__thiscall *t)(CUser*, UINT32, UINT32, CWareHouse*);
		t f = (t)0x0053C0F8;
		return f(this, uItemDbId, uReceiverCharDbId, pSenderWareHouse);
	};

	UINT32 GetId() { return this->uCharDbId; };
	wchar_t* GetCharName() { return this->CharName; };

	/* 0018 */ unsigned int _uUnkVal0018[64];
	/* 0118 */ DWORD uDataCreateTickCount;
	/* 011C */ unsigned int _uUnkVal011C[3];
	/* 0128 */ RWLock user_data_cs;
	/* 0160 */ unsigned int _uUnkVal0160[16];
	/* 01A0 */ WCHAR CharName[24];
	/* 01D0 */ UINT32 uCharDbId;
	/* 01D4 */ WCHAR CharAccount[24];
	/* 0204 */ UINT32 uAccountDbId;
	/* 0208 */ UINT32 uPledgeDbId;
	/* 020C */ UINT32 uBuilderLvL;
	/* 0210 */ UINT32 uGenderId;
	/* 0214 */ UINT32 uRaceId;
	/* 0218 */ UINT32 uClassId;
	/* 021C */ UINT32 uWorldId;
	/* 0220 */ INT32 x;
	/* 0224 */ INT32 y;
	/* 0228 */ INT32 z;
	/* 022C */ UINT32 uIsInVehicle;
	/* 0230 */ DOUBLE fHP;
	/* 0238 */ DOUBLE fMP;
	/* 0240 */ DOUBLE fCP;
	/* 0248 */ DOUBLE fMaxHP;
	/* 0250 */ DOUBLE fMaxMP;
	/* 0258 */ DOUBLE fMaxCP;
	/* 0260 */ UINT32 uSp;
	/* 0264 */ unsigned int _padding0264;
	/* 0268 */ UINT64 uExp;
	/* 0270 */ UINT32 nLevel;
	/* 0274 */ unsigned int _padding0274;
	/* 0278 */ __int64 nDropExp;
	/* 0280 */ unsigned int _uUnkVal0280[4]; union {
	/* 0290 */ UINT32 UserSlotItemDbId[26]; struct {
	/* 0290 */ UINT32 ST_underware;
	/* 0294 */ UINT32 ST_right_ear;
	/* 0298 */ UINT32 ST_left_ear;
	/* 029C */ UINT32 ST_neck;
	/* 02A0 */ UINT32 ST_right_finger;
	/* 02A4 */ UINT32 ST_left_finger;
	/* 02A8 */ UINT32 ST_head;
	/* 02AC */ UINT32 ST_right_hand;
	/* 02B0 */ UINT32 ST_left_hand;
	/* 02B4 */ UINT32 ST_gloves;
	/* 02B8 */ UINT32 ST_chest;
	/* 02BC */ UINT32 ST_legs;
	/* 02C0 */ UINT32 ST_feet;
	/* 02C4 */ UINT32 ST_back;
	/* 02C8 */ UINT32 ST_both_hand;
	/* 02CC */ UINT32 ST_hair;
	/* 02D0 */ UINT32 ST_hair2;
	/* 02D4 */ UINT32 ST_rbracelet;
	/* 02D8 */ UINT32 ST_lbracelet;
	/* 02DC */ UINT32 ST_deco1;
	/* 02E0 */ UINT32 ST_deco2;
	/* 02E4 */ UINT32 ST_deco3;
	/* 02E8 */ UINT32 ST_deco4;
	/* 02EC */ UINT32 ST_deco5;
	/* 02F0 */ UINT32 ST_deco6;
	/* 02F4 */ UINT32 ST_belt; }; };
	/* 02F8 */ unsigned int _uUnkVal02F8[75];
	/* 0424 */ UINT32 uNameColor;
	/* 0428 */ UINT32 uTitleColor;
	/* 042C */ unsigned int _uUnkVal042C[11];
	/* 0458 */ UINT32 uVitalityCount;
	/* 045C */ unsigned int _uUnkVal045C;
	/* 0460 */ SYSTEMTIME logout_date;
	/* 0470 */ SYSTEMTIME login_date;
	/* 0480 */ SYSTEMTIME create_date;
	/* 0490 */ unsigned int AbnormalData[34][4];
	/* 06B0 */ unsigned int _uUnkVal06B0[7];
	/* 06CC */ WCHAR CharTitle[24];
	/* 06FC */ unsigned int _uUnkVal06FC[11];
	/* 0728 */ unsigned int QuestData[26][4];
	/* 08C8 */ bool bCharInGame;
	/* 08C9 */ bool _padding08C9[3];
	/* 08CC */ unsigned int _uUnkVal08CC[57];
	/* 09B0 */ 
};

#pragma pack(pop)

CompileTimeOffsetCheck(CUser, uDataCreateTickCount, 0x0118);
CompileTimeOffsetCheck(CUser, UserSlotItemDbId, 0x0290);
CompileTimeOffsetCheck(CUser, AbnormalData, 0x0490);
CompileTimeSizeCheck(CUser, 0x09B0);
