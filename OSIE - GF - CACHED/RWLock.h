#pragma once

#pragma pack(push, 1)

class RWLock
{
public:
	RWLock() {};
	~RWLock() {};

	bool ReadLock(const wchar_t* file = L"ReadLockByDLL", int line = __LINE__) //if true - fail
	{
		typedef bool (__thiscall *t)(RWLock*, const wchar_t*, int);
		t f = (t)0x004B0844;
		return f(this, file, line);
	};
	void ReadUnlock()
	{
		typedef void (__thiscall *t)(RWLock*);
		t f = (t)0x004B09D4;
		f(this);
	};
	bool WriteLock(const wchar_t* file = L"WriteLockByDLL", int line = __LINE__) //if true - fail
	{
		typedef bool (__thiscall *t)(RWLock*, const wchar_t*, int);
		t f = (t)0x004B0AE4;
		return f(this, file, line);
	};
	void WriteUnlock()
	{
		typedef void (__thiscall *t)(RWLock*);
		t f = (t)0x004B0B80;
		f(this);
	};

	/* 0000 */ CRITICAL_SECTION read_cs;
	/* 0028 */ HANDLE hWaitHandle;
	/* 0030 */ UINT32 uWriteRefCount;
	/* 0034 */ unsigned int _padding0034;
	/* 0038 */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(RWLock, 0x0038);
