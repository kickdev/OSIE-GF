#pragma once

#pragma pack(push, 1)

class CSharedPledgeData
{
public:
	CSharedPledgeData() {};
	~CSharedPledgeData() {};

	/* 0000 */ unsigned int _uUnkVal0000[25];
	/* 0064 */ UINT32 uPledgeSID;
	/* 0068 */ WCHAR wszClanName[24];
	/* 0098 */ UINT32 uClanLeaderSID;
	/* 009C */ WCHAR wszClanLeaderName[26];
	/* 00D0 */ unsigned int _uUnkVal00D0[448];
	/* 07D0 */
};

#pragma pack(pop)

CompileTimeSizeCheck(CSharedPledgeData, 0x07D0);
