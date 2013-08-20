#pragma once

#pragma pack(push, 1)

class CSharedCreatureData
{
public:
	CSharedCreatureData() {};
	~CSharedCreatureData() {};

	/* 0000 */ unsigned int _uUnkVal0000[41];
	/* 00A4 */ wchar_t pName[25];
	/* 00D6 */ wchar_t _padding00D6;
	/* 00D8 */ unsigned int _uUnkVal00D8[508];
	/* 08C8 */ UINT32 uBuilderLVL;
	/* 08CC */ unsigned int _uUnkVal08CC[331];
	/* 0DF8 */
};

#pragma pack(pop)

CompileTimeSizeCheck(CSharedCreatureData, 0x0DF8);
