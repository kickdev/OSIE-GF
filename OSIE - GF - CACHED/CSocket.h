#pragma once

#pragma pack(push, 1)

class CSocket : public CIOSocket
{
public:
	CSocket() {};
	~CSocket() {};

	/* 090 */ virtual __int64 _vfunc090() { return NULL; };
	/* 098 */ 

	/* 00B0 */ unsigned int _uUnkVal00B0[60];
	/* 01A0 */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(CSocket, 0x01A0);
