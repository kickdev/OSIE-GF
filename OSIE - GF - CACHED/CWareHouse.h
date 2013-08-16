#pragma once

#pragma pack(push, 1)

#define WAREHOUSE_TYPE_INVENTORY 0
#define WAREHOUSE_TYPE_WAREHOUSE 1	//?
#define WAREHOUSE_TYPE_CLAN 1001	//?

class CWareHouse : public CMemoryObject
{
public:
	CWareHouse() {};
	~CWareHouse() {};

	/* 020 */ virtual CObjectSP* GetItemByType(CObjectSP* pObjectSP, UINT32 uItemType, UINT32 uIdent) { return NULL; };
	/* 028 */ virtual CObjectSP* GetItem(CObjectSP* pObjectSP, UINT32 uItemDbId) { return NULL; };
	/* 030 */ virtual CObjectSP* PopItem(CObjectSP* pObjectSP, UINT32 uItemDbId) { return NULL; };
	/* 038 */ virtual bool PushItem(CItem* pItem) { return NULL; };
	/* 040 */ 

	bool MoveItemToChar(UINT32 uItemDbId, CWareHouse* pReceiverWareHouse)
	{
		typedef bool (__thiscall *t)(CWareHouse*, UINT32, CWareHouse*);
		t f = (t)0x005688C0;
		return f(this, uItemDbId, pReceiverWareHouse);
	};

	/* 0018 */ unsigned int _uUnkVal0018[40];
	/* 00B8 */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(CWareHouse, 0xB8);
