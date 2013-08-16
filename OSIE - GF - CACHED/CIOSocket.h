#pragma once

#pragma pack(push, 1)

class CIOSocket : public CIOObject
{
public:
	CIOSocket() {};
	~CIOSocket() {};

	/* 050 */ virtual __int64 _vfunc050() { return NULL; };
	/* 058 */ virtual __int64 _vfunc058() { return NULL; };
	/* 060 */ virtual __int64 _vfunc060() { return NULL; };
	/* 068 */ virtual void Send(const char* format, ...) {};
	/* 070 */ virtual __int64 _vfunc070() { return NULL; };
	/* 078 */ virtual __int64 _vfunc078() { return NULL; };
	/* 080 */ virtual __int64 _vfunc080() { return NULL; };
	/* 088 */ virtual __int64 _vfunc088() { return NULL; };
	/* 090 */ 

	/* 0018 */ unsigned int _uUnkVal0018[38];
	/* 00B0 */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(CIOSocket, 0xB0);
