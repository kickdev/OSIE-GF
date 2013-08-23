#pragma once

#pragma pack(push, 1)

class CPledge : public CObject
{
public:
	CPledge() {};
	~CPledge() {};

	/* 478 */ 

	/* 0040 */ CSharedPledgeData* SD;
	/* 0048 */ unsigned int _uUnkVal0048[148];
	/* 0298 */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(CPledge, 0x0298);
