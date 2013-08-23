#pragma once

#pragma pack(push, 1)

class CYieldLock
{
public:
	CYieldLock() {};
	~CYieldLock() {};

	void Lock(const wchar_t* file, unsigned int line) 
	{
		typedef void (__thiscall *t)(CYieldLock*, const wchar_t*, unsigned int);
		t f = (t)0x0097E9D4;
		f(this, file, line);
	};
	void UnLock(const wchar_t* file, unsigned int line) 
	{
		typedef void (__thiscall *t)(CYieldLock*, const wchar_t*, unsigned int);
		t f = (t)0x0097EA74;
		f(this, file, line);
	};

	/* 0000 */ UINT32 _uUnkVal0000[3];
	/* 000C */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(CYieldLock, 0x000C);
