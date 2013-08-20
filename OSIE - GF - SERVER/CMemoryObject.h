#pragma once

#pragma pack(push, 1)

class CMemoryObject
{
public:
	CMemoryObject() {};

	/* 000 */ virtual ~CMemoryObject() {};
	/* 008 */ virtual CMemoryObject* AddRef(const char* file, int line) { _InterlockedIncrement(&this->nRefCount); };
	/* 010 */ virtual long Release(const char* file, int line, UINT32 uReleaseType, bool bUnkVal) { return _InterlockedDecrement(&this->nRefCount); };
	/* 018 */ virtual void ReportOrt(const char* file, int line) {};
	/* 020 */ 

	/* 0008 */ long nRefCount;
	/* 000C */ long nInTimer;
	/* 0010 */ long nIdentityId;
	/* 0014 */ long _padding0014;
	/* 0018 */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(CMemoryObject, 0x0018);
