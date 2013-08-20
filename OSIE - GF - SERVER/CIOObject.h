#pragma once

#pragma pack(push, 1)

class CIOObject : public CMemoryObject
{
public:
	CIOObject() {};
	~CIOObject() {};

	/* 020 */ virtual __int64 _vfunc020() { return NULL; };
	/* 028 */ virtual __int64 _vfunc028() { return NULL; };
	/* 030 */ virtual __int64 _vfunc030() { return NULL; };
	/* 038 */ virtual __int64 _vfunc038() { return NULL; };
	/* 040 */ virtual __int64 _vfunc040() { return NULL; };
	/* 048 */ virtual __int64 _vfunc048() { return NULL; };
	/* 050 */ 

	/* 0018 */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(CIOObject, 0x0018);
