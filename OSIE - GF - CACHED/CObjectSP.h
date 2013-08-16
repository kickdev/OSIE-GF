#pragma once

#pragma pack(push, 1)

class CObjectSP
{
public:
	CObjectSP() {};
	~CObjectSP();



#ifdef L2CACHE_DEBUG
#endif //L2CACHE_DEBUG


	__forceinline void Release()
	{
		if(this->pMemoryObject)
		{
			this->pMemoryObject->Release(__FILE__, __LINE__, this->uReleaseType, false);
			this->pMemoryObject = NULL;
		}
	};

	/* 0000 */ union
	{
		CMemoryObject* pMemoryObject;
		CUser* pUser;
		CWareHouse* pWareHouse;
		CItem* pItem;
	};
	/* 0008 */ UINT32 uReleaseType;
	/* 000C */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(CObjectSP, 0x0C);
