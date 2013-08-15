#pragma once

#pragma pack(push, 1)

class CObjectSP
{
public:
	CObjectSP() {};
	~CObjectSP() {};

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
	/* 0000 */ UINT32 uReleaseType;
	/* 0000 */ 
};

#pragma pack(pop)
