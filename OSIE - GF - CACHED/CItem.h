#pragma once

#pragma pack(push, 1)

#define ITEM_DEF_ATTR_FIRE 0
#define ITEM_DEF_ATTR_WATER 1
#define ITEM_DEF_ATTR_WIND 2
#define ITEM_DEF_ATTR_EARTH 3
#define ITEM_DEF_ATTR_HOLY 4
#define ITEM_DEF_ATTR_UNHOLY 5

class CItemAttributeData
{
public:
	CItemAttributeData() {};
	~CItemAttributeData() {};

	/* 0000 */ INT16 nAtkAttrElement; //-2 by default
	/* 0002 */ UINT16 uAtkAttrPower; union {
	/* 0004 */ UINT16 uDefAttr[6]; struct { //ITEM_DEF_ATTR_*
	/* 0004 */ UINT16 uDefAttrFire;
	/* 0006 */ UINT16 uDefAttrWater;
	/* 0008 */ UINT16 uDefAttrWind;
	/* 000A */ UINT16 uDefAttrEarth;
	/* 000C */ UINT16 uDefAttrHoly;
	/* 000E */ UINT16 uDefAttrUnholy; }; };
	/* 0010 */ UINT16 uDefEnch[3];
	/* 0016 */ 
};

class CItem : public CMemoryObject
{
public:
	CItem() {};
	~CItem() {};

	/* 020 */ virtual __int64 _vfunc020() { return NULL; };
	/* 028 */ 

	static CObjectSP* Load(CObjectSP* pObjectSP, UINT32 nItemDbId)
	{
		typedef CObjectSP* (*t)(CObjectSP*, UINT32);
		t f = (t)0x0047926C;
		return f(pObjectSP, nItemDbId);
		//
	};

	/* 0014 */ unsigned int uUnk0014; //???
	/* 0018 */ UINT32 uTransactMode;
	/* 001C */ UINT32 uItemDbId;
	/* 0020 */ UINT32 uItemOwnerID;
	/* 0024 */ UINT32 uItemType; //uItemId
	/* 0028 */ UINT64 uAmount;
	/* 0030 */ UINT32 uEnchant;
	/* 0034 */ UINT32 uDamaged;
	/* 0038 */ UINT32 uBless;
	/* 003C */ UINT32 uIdent;
	/* 0040 */ UINT32 uWished;
	/* 0044 */ UINT32 uWareHouse;
	/* 0048 */ UINT32 uUnk0048;	//check in transact delete, transact id ? transation
	/* 004C */ UINT32 uInventorySlotIndex;
	/* 0050 */ UINT32 uUnk0050;
	/* 0054 */ UINT32 _uUnk0054; //unused or reserved
	/* 0058 */ UINT64 uUnk0058;
	/* 0060 */ UINT64 uUnk0060;
	/* 0068 */ UINT32 uUnk0068;
	/* 006C */ UINT32 uUnk006C;
	/* 0070 */ UINT32 uUnk0070;
	/* 0074 */ bool bUnk0074;
	/* 0075 */ bool bUnk0075;
	/* 0076 */ bool _padding0076[2];
	/* 0078 */ UINT64 uUnk0078;
	/* 0080 */ bool bUnk0080;	//true if transact delete
	/* 0081 */ bool _padding0081;
	/* 0082 */ CItemAttributeData AttributeData;
	/* 0098 */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(CItem, 0x98);
