#pragma once

#pragma pack(push, 1)

class CIOCriticalSection
{
public:
	CIOCriticalSection() {};
	~CIOCriticalSection() {};

	void Lock(const wchar_t* file, unsigned int line) 
	{
		typedef void (__thiscall *t)(CIOCriticalSection*, const wchar_t*, unsigned int);
		t f = (t)0x00692248;
		f(this, file, line);
	};
	void UnLock(const wchar_t* file, unsigned int line) 
	{
		typedef void (__thiscall *t)(CIOCriticalSection*, const wchar_t*, unsigned int);
		t f = (t)0x006922AC;
		f(this, file, line);
	};

	/* 0000 */ CRITICAL_SECTION io_cs;
	/* 0028 */ bool bFlag;
	/* 0029 */ unsigned char _padding0029[7];
	/* 0030 */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(CIOCriticalSection, 0x0030);
