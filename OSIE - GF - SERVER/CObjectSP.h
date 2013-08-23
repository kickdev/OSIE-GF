#pragma once

#pragma pack(push, 1)

class CTrade;

class CObjectSP
{
public:
	CObjectSP() {};
	~CObjectSP();

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
		CTrade* pTrade;
		CUser* pUser;
	};
	/* 0008 */ UINT32 uReleaseType;
	/* 000C */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(CObjectSP, 0x000C);
