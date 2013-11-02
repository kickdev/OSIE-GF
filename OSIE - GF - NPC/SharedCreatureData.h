#pragma once

#pragma pack(push, 1)

struct AbnormalInfo
{
	INT32 nAbnormalType;
	INT32 nLevel;
	INT32 AbSlotType;
};

enum AbnormalStatusSlotType
{
	ABSLOT_UNDERWEAR	= 0,
	ABSLOT_LEFT_EAR	= 1,
	ABSLOT_RIGHT_EAR	= 2,
	ABSLOT_NECK		= 3,
	ABSLOT_LEFT_RING	= 4,
	ABSLOT_RIGHT_RING = 5,
	ABSLOT_HEAD		= 6,
	ABSLOT_LEFT_HAND	= 7,
	ABSLOT_RIGHT_HAND = 8,
	ABSLOT_GLOVES		= 9,
	ABSLOT_CHEST		= 10,
	ABSLOT_LEGS		= 11,
	ABSLOT_FEET		= 12,
	ABSLOT_BACK		= 13,
	ABSLOT_TWO_HAND	= 14,
	ABSLOT_ONE_PIECE	= 15,
	ABSLOT_HAIR		= 16,
	ABSLOT_DRESS		= 17,
	ABSLOT_TATOO		= 18,
	ABSLOT_HAIR2		= 19,
	ABSLOT_BRACELET		= 20,
	ABSLOT_BRACELET_AGATHION		= 21,
	ABSLOT_TALISMAN		= 22,
	ABSLOT_TALISMAN1		= 23,
	ABSLOT_TALISMAN2		= 24,
	ABSLOT_TALISMAN3		= 25,
	ABSLOT_TATOO1		= 26,
	ABSLOT_TATOO2		= 27,
	ABSLOT_BELT		= 28
};

struct QuestData
{
	INT32 questId;
	INT32 questState;
	INT32 questJournal;
	INT32 unk4;
};

struct EquipmentSlot
{
	INT32 nObjIdUnder;
	INT32 nObjIdLEar;
	INT32 nObjIdREar;
	INT32 nObjIdNeck;
	INT32 nObjIdLRing;
	INT32 nObjIdRRing;
    INT32 nObjIdHead;
	INT32 nObjIdLHand;
	INT32 nObjIdRHand;
	INT32 nObjIdGloves;
	INT32 nObjIdChest;
	INT32 nObjIdLegs;
	INT32 nObjIdFeet;
	INT32 nObjIdBack;
    INT32 nObjId2Hand;
    INT32 nObjIdOnePiece;
    INT32 nObjIdHair;
    INT32 nObjIdDress;
    INT32 nObjIdTatoo;
	INT32 nObjIdHair2;
	INT32 nObjIdBracelet;
	INT32 nObjIdBraceletAgathion;
	INT32 nObjIdTalisman;
	INT32 nObjIdTalisman1;
	INT32 nObjIdTalisman2;
	INT32 nObjIdTalisman3;
	INT32 nObjIdTatoo1;
	INT32 nObjIdTatoo2;
	INT32 nObjIdBelt;
};

class CSharedCreatureData
{
public:
	CSharedCreatureData() {};
	~CSharedCreatureData() {};

	static void __cdecl ExtendCreatureSharedData();

	/* Variables */

	/* 0000 */ int _uUnkVal0000;
	/* 0004 */ int _uUnkVal0004;

	/* 0008 */ DOUBLE x;
	/* 0010 */ DOUBLE y;
	/* 0018 */ DOUBLE z;

	/* 0020 */ INT32 nHeading;
	/* 0024 */ INT32 nObjectID;
	/* 0028 */ INT32 nIndex;
	/* 002C */ INT32 nNPCIndex;

	/* 0030 */ int _uUnkVal0030;

	/* 0034 */ INT32 nVehicleIndex;
	/* 0038 */ UINT64 userServerId;

	/* 0040 */ unsigned __int64 _uUnkVal0040;
	/* 0048 */ unsigned __int64 _uUnkVal0048;

	/* 0050 */ UINT8 bIsActive;
	/* 0051 */ unsigned char _uUnkVal0051;
	/* 0052 */ unsigned char _uUnkVal0052;
	/* 0053 */ unsigned char _uUnkVal0053;
	/* 0054 */ int _uUnkVal0054;
	/* 0058 */ int _uUnkVal0058;
	/* 005C */ int _uUnkVal005C;
	/* 0060 */ int _uUnkVal0060;

	/* 0064 */ INT32 nIsPlayer;
	/* 0068 */ INT32 nIsAlive;
	/* 006C */ INT32 nAge;

	/* 0070 */ int _uUnkVal0070;
	/* 0074 */ int _uUnkVal0074;

	/* 0078 */ UINT32 SubClassID;
	/* 007C */ UINT32 NoblesseType;
	/* 0080 */ UINT32 HeroType;

	/* 0084 */ int _uUnkVal0084;

	/* 0088 */ INT32 SubJob0;
	/* 008C */ INT32 SubJob1;
	/* 0090 */ INT32 SubJob2;
	/* 0094 */ INT32 SubJob3;
	/* 0098 */ INT32 nRace;
	/* 009C */ INT32 nClass;
	/* 00A0 */ INT32 nSex;
	/* 00A4 */ WCHAR wszName[25];
	/* 00D6 */ UINT8 bUndying;
	/* 00D7 */ UINT8 bCanBeAttacked;
	/* 00D8 */ UINT8 bHide;

	/* 00D9 */ unsigned char _uUnkVal00D9;
	/* 00DA */ unsigned short _uUnkVal00DA;
	/* 00DC */ int _uUnkVal00DC;//0 65536 = bool

	/* 00E0 */ DOUBLE dCollisionRadius; // NPC default 16
	/* 00E8 */ DOUBLE dCollisionHeight; // NPC default 1000
	/* 00F0 */ INT32 nFaceIndex;
	/* 00F4 */ INT32 nHairShape;
	/* 00F8 */ INT32 nHairColor;

	/* 00FC */ int _uUnkVal00FC;

	/* 0100 */ UINT64 uExp;
	/* 0108 */ UINT32 uSp;
	/* 010C */ INT32 nObjIdAdena;
	/* 0110 */ EquipmentSlot nEquipment;      /* Slot Type */

	/* 0184 */ int _uUnkVal0184[10];

	/* 01AC */ UINT32 uDefaultINT;
	/* 01B0 */ UINT32 uDefaultSTR;
	/* 01B4 */ UINT32 uDefaultCON;
	/* 01B8 */ UINT32 uDefaultMEN;
	/* 01BC */ UINT32 uDefaultDEX;
	/* 01C0 */ UINT32 uDefaultWIT;

	/* 01C4 */ int _uUnkVal01C4;

	/* 01C8 */ DOUBLE dMaxHP;
	/* 01D0 */ DOUBLE dMaxCP;
	/* 01D8 */ DOUBLE dMaxMP;

	/* 01E0 */ int _uUnkVal01E0;

	/* 01E4 */ INT32 nMoveType;
	/* 01E8 */ INT32 nStopType; // 1 standing, 0 sitting

	/* 01EC */ int _uUnkVal01EC;
	/* 01F0 */ int _uUnkVal01F0;//add     rcx, 1F0h //mov     r8d, [rax+1F0h]
	/* 01F4 */ int _uUnkVal01F4;

	/* 01F8 */ INT32 nTargetIndex;
	/* 01FC */ INT32 nTargetObjId;
	/* 0200 */ UINT8 bIsPvP;
	/* 0201 */ UINT8 bIsFreezed;

	/* 0202 */ unsigned char _uUnkVal0202;
	/* 0203 */ unsigned char _uUnkVal0203;

	/* 0204 */ UINT32 uPvPScore;
	/* 0208 */ UINT32 uPKScore;
	/* 020C */ UINT32 uPKPardon;
	/* 0210 */ UINT32 uKarma;
	/* 0214 */ UINT32 uRecommendationsLeft;
	/* 0218 */ UINT32 uRecommendations;
	/* 021C */ UINT32 uEvalScore;

	/* 0220 */ QuestData Quests[16];//.text:00000000004484B0                 lea     r8, [rcx+220h]

	           QuestData QuestsNew[10];
	/* 03C0 */ INT32 questId;
	/* 03C4 */ INT32 questState;
	/* 03C8 */ INT32 questState2;
	/* 03CC */ INT32 questJournal;

	/* 03D0 */ int _uUnkVal03D0;
	/* 03D4 */ int _uUnkVal03D4;
	/* 03D8 */ int _uUnkVal03D8;
	/* 03DC */ int _uUnkVal03DC;

	/* 03E0 */ INT32 nQuestLastRewardTime;

	/* 03E4 */ int _uUnkVal03E4;
	/* 03E8 */ int _uUnkVal03E8;
	/* 03EC */ int _uUnkVal03EC;
	/* 03F0 */ int _uUnkVal03F0;

	/* 03F4 */ INT32 nParamSetting; //mov     eax, [rax+318h] CSParamSettingPacket

	/* 03F8 */ int _uUnkVal03F8;
	/* 03FC */ int _uUnkVal03FC;
	/* 0400 */ int _uUnkVal0400;
	/* 0404 */ int _uUnkVal0404;
	/* 0408 */ int _uUnkVal0408;
	/* 040C */ int _uUnkVal040C;
	/* 0410 */ int _uUnkVal0410;
	/* 0414 */ int _uUnkVal0414;
	/* 0418 */ int _uUnkVal0418;
	/* 041C */ int _uUnkVal041C;
	/* 0420 */ int _uUnkVal0420;
	/* 0424 */ int _uUnkVal0424;
	/* 0428 */ int _uUnkVal0428;
	/* 042C */ int _uUnkVal042C;
	/* 0430 */ int _uUnkVal0430;
	/* 0434 */ int _uUnkVal0434;
	/* 0438 */ int _uUnkVal0438;
	/* 043C */ int _uUnkVal043C;
	/* 0440 */ int _uUnkVal0440;
	/* 0444 */ int _uUnkVal0444;
	/* 0448 */ int _uUnkVal0448;
	/* 044C */ int _uUnkVal044C;
	/* 0450 */ int _uUnkVal0450;
	/* 0454 */ int _uUnkVal0454;
	/* 0458 */ int _uUnkVal0458;
	/* 045C */ int _uUnkVal045C;
	/* 0460 */ int _uUnkVal0460;
	/* 0464 */ int _uUnkVal0464;
	/* 0468 */ int _uUnkVal0468;
	/* 046C */ int _uUnkVal046C;
	/* 0470 */ int _uUnkVal0470;
	/* 0474 */ int _uUnkVal0474;
	/* 0478 */ int _uUnkVal0478;
	/* 047C */ int _uUnkVal047C;
	/* 0480 */ int _uUnkVal0480;
	/* 0484 */ int _uUnkVal0484;
	/* 0488 */ int _uUnkVal0488;
	/* 048C */ int _uUnkVal048C;
	/* 0490 */ int _uUnkVal0490;
	/* 0494 */ int _uUnkVal0494;
	/* 0498 */ int _uUnkVal0498;
	/* 049C */ int _uUnkVal049C;
	/* 04A0 */ int _uUnkVal04A0;
	/* 04A4 */ int _uUnkVal04A4;
	/* 04A8 */ int _uUnkVal04A8;
	/* 04AC */ int _uUnkVal04AC;
	/* 04B0 */ int _uUnkVal04B0;
	/* 04B4 */ int _uUnkVal04B4;
	/* 04B8 */ int _uUnkVal04B8;
	/* 04BC */ int _uUnkVal04BC;
	/* 04C0 */ int _uUnkVal04C0;
	/* 04C4 */ int _uUnkVal04C4;
	/* 04C8 */ int _uUnkVal04C8;
	/* 04CC */ int _uUnkVal04CC;
	/* 04D0 */ int _uUnkVal04D0;
	/* 04D4 */ int _uUnkVal04D4;
	/* 04D8 */ int _uUnkVal04D8;
	/* 04DC */ int _uUnkVal04DC;
	/* 04E0 */ int _uUnkVal04E0;
	/* 04E4 */ int _uUnkVal04E4;
	/* 04E8 */ int _uUnkVal04E8;
	/* 04EC */ int _uUnkVal04EC;
	/* 04F0 */ int _uUnkVal04F0;
	/* 04F4 */ int _uUnkVal04F4;
	/* 04F8 */ int _uUnkVal04F8;
	/* 04FC */ int _uUnkVal04FC;
	/* 0500 */ int _uUnkVal0500; 
	/* 0504 */ int _uUnkVal0504;
	/* 0508 */ int _uUnkVal0508;
	/* 050C */ int _uUnkVal050C;
	/* 0510 */ int _uUnkVal0510;
	/* 0514 */ int _uUnkVal0514;
	/* 0518 */ int _uUnkVal0518;
	/* 051C */ int _uUnkVal051C;
	/* 0520 */ int _uUnkVal0520;
	/* 0524 */ int _uUnkVal0524;
	/* 0528 */ int _uUnkVal0528;
	/* 052C */ int _uUnkVal052C;
	/* 0530 */ int _uUnkVal0530;
	/* 0534 */ int _uUnkVal0534;
	/* 0538 */ int _uUnkVal0538;
	/* 053C */ int _uUnkVal053C;
	/* 0540 */ int _uUnkVal0540;
	/* 0544 */ int _uUnkVal0544;
	/* 0548 */ int _uUnkVal0548;
	/* 054C */ int _uUnkVal054C;
	/* 0550 */ int _uUnkVal0550;
	/* 0554 */ int _uUnkVal0554;
	/* 0558 */ int _uUnkVal0558;
	/* 055C */ int _uUnkVal055C;
	/* 0560 */ int _uUnkVal0560;
	/* 0564 */ int _uUnkVal0564;
	/* 0568 */ int _uUnkVal0568;
	/* 056C */ int _uUnkVal056C;
	/* 0570 */ int _uUnkVal0570;
	/* 0574 */ int _uUnkVal0574;
	/* 0578 */ int _uUnkVal0578;
	/* 057C */ int _uUnkVal057C;
	/* 0580 */ int _uUnkVal0580;
	/* 0584 */ int _uUnkVal0584;
	/* 0588 */ int _uUnkVal0588;
	/* 058C */ int _uUnkVal058C;
	/* 0590 */ int _uUnkVal0590;
	/* 0594 */ int _uUnkVal0594;
	/* 0598 */ int _uUnkVal0598;
	/* 059C */ int _uUnkVal059C;
	/* 05A0 */ int _uUnkVal05A0;
	/* 05A4 */ int _uUnkVal05A4;
	/* 05A8 */ int _uUnkVal05A8;
	/* 05AC */ int _uUnkVal05AC;
	/* 05B0 */ int _uUnkVal05B0;
	/* 05B4 */ int _uUnkVal05B4;
	/* 05B8 */ int _uUnkVal05B8;
	/* 05BC */ int _uUnkVal05BC;
	/* 05C0 */ int _uUnkVal05C0;
	/* 05C4 */ int _uUnkVal05C4;
	/* 05C8 */ int _uUnkVal05C8;
	/* 05CC */ int _uUnkVal05CC;
	/* 05D0 */ int _uUnkVal05D0;
	/* 05D4 */ int _uUnkVal05D4;
	/* 05D8 */ int _uUnkVal05D8;
	/* 05DC */ int _uUnkVal05DC;
	/* 05E0 */ int _uUnkVal05E0;
	/* 05E4 */ int _uUnkVal05E4;
	/* 05E8 */ int _uUnkVal05E8;
	/* 05EC */ int _uUnkVal05EC;
	/* 05F0 */ int _uUnkVal05F0;
	/* 05F4 */ int _uUnkVal05F4;
	/* 05F8 */ int _uUnkVal05F8;
	/* 05FC */ int _uUnkVal05FC;
	/* 0600 */ int _uUnkVal0600;
	/* 0604 */ int _uUnkVal0604;
	/* 0608 */ int _uUnkVal0608;
	/* 060C */ int _uUnkVal060C;
	/* 0610 */ int _uUnkVal0610;
	/* 0614 */ int _uUnkVal0614;
	/* 0618 */ int _uUnkVal0618;
	/* 061C */ int _uUnkVal061C;
	/* 0620 */ int _uUnkVal0620;
	/* 0624 */ int _uUnkVal0624;
	/* 0628 */ int _uUnkVal0628;
	/* 062C */ int _uUnkVal062C;
	/* 0630 */ int _uUnkVal0630;
	/* 0634 */ int _uUnkVal0634;
	/* 0638 */ int _uUnkVal0638;
	/* 063C */ int _uUnkVal063C;
	/* 0640 */ int _uUnkVal0640;
	/* 0644 */ int _uUnkVal0644;
	/* 0648 */ int _uUnkVal0648;
	/* 064C */ int _uUnkVal064C;
	/* 0650 */ int _uUnkVal0650;
	/* 0654 */ int _uUnkVal0654;

	/* 0658 */ INT32 nLastAttackerIndex;

	/* 065C */ int _uUnkVal065C;

	/* 0660 */ INT32 nPledgeId;

	/* 0664 */ int _uUnkVal0664;

	/* 0668 */ INT32 nIsPledgeLeader;
	/* 066C */ INT32 nPledgePowerGrade;

	/* 0670 */ int _uUnkVal0670;
	/* 0674 */ int _uUnkVal0674;

	/* 0678 */ INT32 nPledgePowerGradeId;

	/* 067C */ int _uUnkVal067C;

	/* 0680 */ INT32 nAllianceId;

	/* 0684 */ int _uUnkVal0684;
	/* 0688 */ int _uUnkVal0688;
	/* 068C */ int _uUnkVal068C;
	/* 0690 */ int _uUnkVal0690;
	/* 0694 */ int _uUnkVal0694;
	/* 0698 */ int _uUnkVal0698;
	/* 069C */ int _uUnkVal069C;

	/* 06A0 */ INT32 nResidenceID;
	/* 06A4 */ INT32 nYongmaType;
	/* 06A8 */ INT32 nYongmaClass;
	/* 06AC */ INT32 nStoreMode;

	/* 06B0 */ int _uUnkVal06B0;
	/* 06B4 */ int _uUnkVal06B4;
	/* 06B8 */ int _uUnkVal06B8;

	/* 06BC */ INT32 nIsSoulshot;
	/* 06C0 */ DOUBLE dSpiritshot;//fBaseCritical
	/* 06C8 */ UINT8 bIsSpiritshot; //Spiritshot /Blessed spiritshot = 1 //double SpiritShotMulti;//mov     [rax+6C8h], bpl TurnOffSpiritshot
	/* 06C9 */ UINT8 bIsRiding;

	/* 06CA */ unsigned char _uUnkVal[6];

	/* 06D0 */ DOUBLE dSpiritShotMulti;//double fSoulShotPower; //mov     [rax+6D0h], rbp TurnOffSpiritshot
	/* 06D8 */ DOUBLE dSpiritShotPower;//mov     [rax+6D8h], rbp TurnOffSpiritshot

	/* 06E0 */ int _uUnkVal06E0;
	/* 06E4 */ int _uUnkVal06E4;
	/* 06E8 */ int _uUnkVal06E8;
	/* 06EC */ int _uUnkVal06EC;
	/* 06F0 */ int _uUnkVal06F0;
	/* 06F4 */ int _uUnkVal06F4;
	/* 06F8 */ int _uUnkVal06F8;
	/* 06FC */ int _uUnkVal06FC;
	/* 0700 */ int _uUnkVal0700;
	/* 0704 */ int _uUnkVal0704;
	/* 0708 */ int _uUnkVal0708;
	/* 070C */ int _uUnkVal070C;
	/* 0710 */ int _uUnkVal0710;
	/* 0714 */ int _uUnkVal0714;
	/* 0718 */ int _uUnkVal0718;
	/* 071C */ int _uUnkVal071C;
	/* 0720 */ int _uUnkVal0720;
	/* 0724 */ int _uUnkVal0724;
	/* 0728 */ int _uUnkVal0728;
	/* 072C */ int _uUnkVal072C;
	/* 0730 */ int _uUnkVal0730;
	/* 0734 */ int _uUnkVal0734;
	/* 0738 */ int _uUnkVal0738;

	/* 073C */ INT32 nIsNewbie;
	/* 0740 */ UINT32 uCharId;

	/* 0744 */ int _uUnkVal0744;

	/* 0748 */ INT32 nDefaultWeaponType;
	/* 074C */ INT32 nDefaultDamageRange;
	/* 0750 */ INT32 nDefaultDamageRange1;
	/* 0754 */ INT32 nDefaultDamageRange2;
	/* 0758 */ INT32 nDefaultDamageRange3;
	/* 075C */ INT32 nDefaultRandomDamage;
	/* 0760 */ INT32 nDefaultBasePhysAttack;
	/* 0764 */ INT32 nParamSetting2;//120
	/* 0768 */ INT32 nDefaultBaseAttackSpeed;
	/* 076C */ INT32 nDefaultBaseCritical;
	/* 0770 */ INT32 grade_id;//80
	/* 0774 */ INT32 nBaseAttackSpeed;//300
	/* 0778 */ INT32 nBaseCritical;//4
	/* 077C */ UINT32 uINT;
	/* 0780 */ UINT32 uSTR;
	/* 0784 */ UINT32 uCON;
	/* 0788 */ UINT32 uMEN;
	/* 078C */ UINT32 uDEX;
	/* 0790 */ UINT32 uWIT;
	/* 0794 */ INT32 nHenna1;
	/* 0798 */ INT32 nHenna2;
	/* 079C */ INT32 nHenna3;
	/* 07A0 */ INT32 nFace_index;
	/* 07A4 */ UINT32 uLevel;
	/* 07A8 */ UINT32 uMaxSlot;
	/* 07AC */ INT32 nCurrSlot;
	/* 07B0 */ INT32 nCurrWeight;

	/* 07B4 */ int _uUnkVal07B4;

	/* 07B8 */ DOUBLE dMaxLoad;
	/* 07C0 */ DOUBLE dOrgHP;
	/* 07C8 */ DOUBLE dOrgMP;
	/* 07D0 */ DOUBLE dOrgCP;
	/* 07D8 */ DOUBLE dHP;
	/* 07E0 */ DOUBLE dMP;
	/* 07E8 */ DOUBLE dCP;
	/* 07F0 */ DOUBLE dHpRegen;
	/* 07F8 */ DOUBLE dMpRegen;
	/* 0800 */ DOUBLE dCpRegen;
	/* 0808 */ DOUBLE dOrgHpRegen;
	/* 0810 */ DOUBLE dOrgMpRegen;
	/* 0818 */ DOUBLE dOrgCpRegen;
	/* 0820 */ DOUBLE dOrgSpeed;
	/* 0828 */ DOUBLE dSpeed;
	/* 0830 */ DOUBLE dAccuracy;
	/* 0838 */ DOUBLE dEvasion;

	/* 0840 */ DOUBLE _dUnkVal0840;

	/* 0848 */ INT32 nWeaponID;
	/* 084C */ INT32 nWeaponType;
	/* 0850 */ INT32 nMaterialType;
	/* 0854 */ INT32 nWeaponRange;
	/* 0858 */ INT32 nWeaponRange1;
	/* 085C */ INT32 nWeaponRange2;
	/* 0860 */ INT32 nWeaponPhysDmg;
	/* 0864 */ INT32 nWeaponRandomDmg;
	/* 0868 */ INT32 nWeaponAtkSpeed;
	/* 086C */ INT32 nNoWeaponCritical;
	/* 0870 */ INT32 nWeaponMagicDmg;
	/* 0874 */ INT32 nWeaponMagicRandomDmg;
	/* 0878 */ DOUBLE dPAtk;
	/* 0880 */ DOUBLE dPDef;
	/* 0888 */ DOUBLE dMAtk;
	/* 0890 */ DOUBLE dMDef;
	/* 0898 */ DOUBLE dAtkSpeed;
	/* 08A0 */ DOUBLE dBaseCritical;

	/* 08A8 */ double _dUnkVal08A8;
	/* 08B0 */ double _dUnkVal08B0;

	/* 08B8 */ DOUBLE dBaseAtkSpeed;
	/* 08C0 */ DOUBLE dBaseCastSpeed;
	/* 08C8 */ UINT32 uBuilderLVL;

	/* 08CC */ int _uUnkVal08CC;
	/* 08D0 */ int _uUnkVal08D0;
	/* 08D4 */ int _uUnkVal08D4;

	/* 08D8 */ INT32 nLastBlowWeaponClassID;
	/* 08DC */ INT32 nSSQRoundNumber;
	/* 08E0 */ INT32 nSSQPosition;
	/* 08E4 */ INT32 nSSQPart;
	/* 08E8 */ INT32 nSealSelectionNo;

	/* 08EC */ int _uUnkVal08EC;

	/* 08F0 */ INT32 nSSQSealPoint;

	/* 08F4 */ int _uUnkVal08F4;

	/* 08F8 */ INT32 nSSQ;

	/* 08FC */ int _uUnkVal08FC;

	/* 0900 */ INT32 nSSQ1;

	/* 0904 */ int _uUnkVal0904;

	/* 0908 */ INT32 nSSQ2;

	/* 090C */ int _uUnkVal090C;

	/* 0910 */ INT32 nSSQ3;

	/* 0914 */ int _uUnkVal0914;

	/* 0918 */ INT32 nSSQ4;

	/* 091C */ int _uUnkVal091C;

	/* 0920 */ INT32 nSSQ5;

	/* 0924 */ int _uUnkVal0924;

	/* 0928 */ INT32 nSSQType;
	/* 092C */ INT32 nSSQDawnRound;
	/* 0930 */ INT32 nInPeaceZone;
	/* 0934 */ INT32 nInBattleField;
	/* 0938 */ INT32 nPcCafePoint;   //int _uUnkVal608;//cmp     byte ptr [rax+93Ch] mov     byte ptr [r11+93Ch], 1 BuilderCmd_pccafe
	/* 093C */ UINT8 nPCCafePointType;
	/* 093D */ UINT8 bIsPremiumUser;

	/* 093E */ unsigned char _uUnkVal093E;
	/* 093F */ unsigned char _uUnkVal093F;

	/* 0940 */ UINT32  uPersonalReputation;

	/* 0944 */ int _uUnkVal0944;
	/* 0948 */ int _uUnkVal0948;
	/* 094C */ int _uUnkVal094C;
	/* 0950 */ int _uUnkVal0950;
	/* 0954 */ unsigned char _uUnkVal0954;//.text:00000000004268E8                 cmp     byte ptr [rax+954h], 0
	/* 0955 */ unsigned char _uUnkVal0955;
	/* 0956 */ unsigned char _uUnkVal0956;
	/* 0957 */ unsigned char _uUnkVal0957;
	/* 0958 */ int _uUnkVal0958;
	/* 095C */ int _uUnkVal095C;
	/* 0960 */ int _uUnkVal0960;
	/* 0964 */ int _uUnkVal0964;

	/* 0968 */ WCHAR wszAI[100];

	/* 0A30 */ int _uUnkVal0A30; // .text:000000000075E0C4 int to double cvtsi2sd xmm7, dword ptr [rcx+0A30h]
	/* 0A34 */ int _uUnkVal0A34;// .text:000000000075E0D5 int to double cvtsi2sd xmm9, dword ptr [rcx+0A34h]

	/* 0A38 */ int _uUnkVal0A38;
	/* 0A3C */ int _uUnkVal0A3C;
	/* 0A40 */ double _dUnkVal0A40;// used in CCreature::WeaponHitCorrection
	/* 0A48 */ double _dUnkVal0A48;// used in CCreature::AvoidCorrection
	/* 0A50 */ int _uUnkVal0A50;
	/* 0A54 */ int _uUnkVal0A54;
	/* 0A58 */ int _uUnkVal0A58;
	/* 0A5C */ int _uUnkVal0A5C;
	/* 0A60 */ int _uUnkVal0A60;
	/* 0A64 */ int _uUnkVal0A64;
	/* 0A68 */ int _uUnkVal0A68; //mov     eax, [rcx+0A68h] SCharacterInfoPacket

	/* 0A6C */ INT32 nSummonType;

	/* 0A70 */ int _uUnkVal0A70;//.text:00000000005D4014                 mov     dword ptr [rax+0A70h], 0

	/* 0A74 */ INT32 nMasterID;

	/* 0A78 */ int _uUnkVal0A78;//.text:00000000005D3FF2                 mov     dword ptr [rax+0A78h], 0

	/* 0A7C */ INT32 nNPCClassID;
	/* 0A80 */ INT32 nWeightPoint; 
	/* 0A84 */ INT32 nRespawnTime;
	/* 0A88 */ INT32 nClanRelationIndex; 
	/* 0A8C */ INT32 nClanRelationUnk1;

	/* 0A90 */ int _uUnkVal0A90;//mov     rdx, [rsi+0A90h]//CBotChecker
	/* 0A94 */ int _uUnkVal0A94;
	/* 0A98 */ int _uUnkVal0A98;
	/* 0A9C */ int _uUnkVal0A9C;
	/* 0AA0 */ int _uUnkVal0AA0;

	/* 0AA4 */ INT32 nClanHelpRange; // default 500 (.text:0000000000528050)
	/* 0AA8 */ INT32 nAcquireExpRate; //transform NPCData acquire_exp_rate from int to double

	/* 0AAC */ int _uUnkVal0AAC;

	/* 0AB0 */ INT32 nPState;

	/* 0AB4 */ int _uUnkVal0AB4;
	/* 0AB8 */ int _uUnkVal0AB8;
	/* 0ABC */ int _uUnkVal0ABC;
	/* 0AC0 */ int _uUnkVal0AC0;
	/* 0AC4 */ int _uUnkVal0AC4;

	/* 0AC8 */ int _uUnkVal0AC8;
	/* 0ACC */ int _uUnkVal0ACC;
	/* 0AD0 */ INT32 nAction;

	/* 0AD4 */ int _uUnkVal0AD4;
	/* 0AD8 */ int _uUnkVal0AD8;
	/* 0ADC */ int _uUnkVal0ADC;// mov     eax, [rax+0ADCh]
	/* 0AE0 */ int _uUnkVal0AE0;
	/* 0AE4 */ int _uUnkVal0AE4;
	/* 0AE8 */ int _uUnkVal0AE8;
	/* 0AEC */ int _uUnkVal0AEC;
	/* 0AF0 */ int _uUnkVal0AF0;
	/* 0AF4 */ int _uUnkVal0AF4;
	/* 0AF8 */ int _uUnkVal0AF8;

	/* 0AFC */ INT32 nInLookNeighborByNPC;

	/* 0B00 */ int _uUnkVal0B00;

	/* 0B04 */ INT32 nTypePet;// .text:000000000046981B                 cmp     dword ptr [rdx+0B04h], 3
	/* 0B08 */ INT32 nPetClassID;

	/* 0B0C */ INT32 nFlag;
	/* 0B10 */ INT32 nCurrentFeed;
	/* 0B14 */ INT32 nMaxFeed;
	/* 0B18 */ INT32 nPetDBID;
	/* 0B1C */ UINT8 IsFreezeNpc;//int nStriderLevel;

	/* 0B1D */ unsigned char _uUnkVal0B1D; //.text:0000000000549454                 mov     byte ptr [rax+0B1Dh], 1
	/* 0B1E */ unsigned char _uUnkVal0B1E;
	/* 0B1F */ unsigned char _uUnkVal0B1F;

	/* 0B20 */ UINT32 nMaxMagicLevel;
	/* 0B24 */ INT32 IsEquipDurationItem;

	/* 0B28 */ unsigned char _uUnkVal0B28;//.text:000000000070E81F                 cmp     [rax+0B28h], r13b
	/* 0B29 */ unsigned char _uUnkVal0B29;//.text:0000000000745E9C                 cmp     byte ptr [rax+0B29h], 0
	/* 0B2A */ unsigned char _uUnkVal0B2A;
	/* 0B2B */ unsigned char _uUnkVal0B2B;

	/* 0B2C */ UINT32 uTransformID;
	/* 0B30 */ UINT32 uInZoneID;
	/* 0B34 */ UINT32 uInstantZoneTypeID;
	/* 0B38 */ UINT32 uInstantZoneID;
	/* 0B3C */ UINT32 uVitalityPoint; // max 20000
	/* 0B40 */ UINT32 uVitalityLevel; //4 level
	/* 0B44 */ _SYSTEMTIME timebirthday;

	/* 0B54 */ int _uUnkVal0B54;
	/* 0B58 */ int _uUnkVal0B58;
	/* 0B5C */ int _uUnkVal0B5C;
	/* 0B60 */ int _uUnkVal0B60;
	/* 0B64 */ int _uUnkVal0B64;
	/* 0B68 */ int _uUnkVal0B68;

	/* 0B6C */ INT32 IsYearDate;
	/* 0B70 */ UINT8 bIsDieNpc;//.text:00000000007298FA                 cmp     byte ptr [r12+0B70h], 0

	/* 0B71 */ unsigned char _uUnkVal0B71;
	/* 0B72 */ unsigned char _uUnkVal0B72;
	/* 0B73 */ unsigned char _uUnkVal0B73;

	/* 0B74 */ LONG m_nNpcDie;//.text:000000000072991D                 lock xadd [r12+0B74h], eax

	/* 0B78 */ int _uUnkVal0B78;
	/* 0B7C */ int _uUnkVal0B7C;
	/* 0B80 */ unsigned char _uUnkVal0B80;//.text:00000000005533EB                 cmp     byte ptr [rcx+0B80h], 0
	/* 0B81 */ unsigned char _uUnkVal0B81;
	/* 0B82 */ unsigned char _uUnkVal0B82;
	/* 0B83 */ unsigned char _uUnkVal0B83;

	/* 0B84 */ INT32 nDominionSeigeId;
	/* 0B88 */ INT32 nPledgeDominionSeigeId;

	/* 0B8C */ int _uUnkVal0B8C;//.text:0000000000523637                 mov     [rax+0B8Ch], edx
	/* 0B90 */ int _uUnkVal0B90;
	/* 0B94 */ int _uUnkVal0B94;//.text:00000000008D09A6 bool___cdecl_User::Die(class_CCreature__) cmp     [r11+0B94h], r13b
	/* 0B98 */ int _uUnkVal0B98;//.text:00000000008D09E7 bool___cdecl_User::Die(class_CCreature__) mov     eax, [rcx+0B98h]
	/* 0B9C */ int _uUnkVal0B9C;//.text:00000000008C2FEE bool___cdecl_User::Restart(enum_RestartPoint) mov     eax, [rcx+0B9Ch]
	/* 0BA0 */ int _uUnkVal0BA0;
	/* 0BA4 */ int _uUnkVal0BA4;
	/* 0BA8 */ unsigned char _uUnkVal0BA8;//.text:00000000009077CE                 cmp     byte ptr [rax+0BA8h], 0
	/* 0BA9 */ unsigned char _uUnkVal0BA9;
	/* 0BAA */ unsigned char _uUnkVal0BAA;
	/* 0BAB */ unsigned char _uUnkVal0BAB;

	/* 0BAC */ AbnormalInfo AbnormalTable[46];
	/* 0DD4 */ INT32 nDBValue;
	/* 0DD8 */ INT32 nDualGara1;
	/* 0DDC */ INT32 nDualGara2;
	/* 0DE0 */ INT32 nTradeSkillLevel;

	/* 0DE4 */ int _uUnkVal0DE4;//.text:0000000000709E36 void___cdecl_CMoveAction::OnEnd(bool) cmp     [rax+0DE4h], r14d
	/* 0DE8 */ unsigned char _uUnkVal0DE8;//.text:0000000000426B4A                 cmp     byte ptr [rax+0DE8h], 0

	/* 0DE9 */ UINT32 uLang;// Korea=0, USA=1, Japan=2, Taiwan=3, China=4, Thailand=5,Philippine=6,Indonesia=7,Russia=5;

	/* 0DED */ unsigned char _uUnkVal0DED;
	/* 0DEE */ unsigned char _uUnkVal0DEE;
	/* 0DEF */ unsigned char _uUnkVal0DEF;
	/* 0DF0 */ int _uUnkVal0DF0;
	/* 0DF4 */ int _uUnkVal0DF4;

	/* Extend Variables */
	/* 0DF8 */
	/* 0E00 */
};

#pragma pack(pop)

CompileTimeSizeCheck(CSharedCreatureData, 0x0DF8);
CompileTimeOffsetCheck(CSharedCreatureData,uLang,0xDE9);