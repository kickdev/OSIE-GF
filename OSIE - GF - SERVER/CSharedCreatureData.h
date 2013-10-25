#pragma once

#pragma pack(push, 1)

class CSharedCreatureData
{
public:
	CSharedCreatureData();
	~CSharedCreatureData();

	/* 0000 */ //unsigned int _uUnkVal0000[41];

	/* 0000 */ unsigned int _uUnkVal0000[2];
	/* 0008 */ double	x;
	/* 0010 */ double	y;
	/* 0018 */ double	z;

	/* 0020 */ unsigned int _uUnkVal0020[17];
	/* 0064 */ int	nIsPlayer;
	/* 0068 */ int	nIsAlive;
	/* 006C */ int	nAge;

	/* 0070 */ unsigned int _uUnkVal0070[3];
	/* 007C */ int  NoblesseType;
	/* 0080 */ int	HeroType;
	/* 0084 */ unsigned int _uUnkVal0084;
	/* 0088 */ int	SubJob0;
	/* 008C */ int	SubJob1;
	/* 0090 */ int	SubJob2;		   
	/* 0094 */ int	SubJob3;
	/* 0098 */ int	nRace;
	/* 009C */ int	nClass;
	/* 00A0 */ int	nSex;
	/* 00A4 */ WCHAR wszName[25];
	/* 00D6 */ bool	bUndying;
	/* 00D7 */ bool	bCanBeAttacked;
	/* 00D8 */ bool	bHide;
	/* 00D9 */ //unsigned int _uUnkVal00D8[508];
	/* 00D9 */ wchar_t _padding00D9;
	/* 00DB */ bool	_b00DB;
	/* 00DC */ unsigned int _uUnkVal00DC[5];
	/* 00F0 */ int	nHairShape;
	/* 00F4 */ int	nHairColor;
	/* 00F8 */ int	nFaceIndex;
	/* 00FC */ unsigned int _uUnkVal00FC;
	/* 0100 */ __int64 nExp;
	/* 0108 */ int nSp;
	/* 010C */ unsigned int _uUnkVal00D8[495];

	/* 08C8 */ UINT32 uBuilderLVL;
	/* 08CC */ unsigned int _uUnkVal08CC[331];
	/* 0DF8 */
};

#pragma pack(pop)

CompileTimeSizeCheck(CSharedCreatureData, 0x0DF8);
