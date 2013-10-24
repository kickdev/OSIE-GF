#include "stdafx.h"

CUserOSIE::CUserOSIE()
{
	this->socket = NULL;
}

CUserOSIE::CUserOSIE(wchar_t* pCharName, wchar_t* pAccName, unsigned int uCharId, unsigned int uAccountId, unsigned int uPledgeId, unsigned int uBuilder, unsigned int uGender, unsigned int uRace, unsigned int uClass, unsigned int uWorld, int nPosX, int nPosY, int nPosZ, double fHP, double fMP, unsigned int uSp, unsigned __int64 uExp, unsigned int uLevel, int nAlign, unsigned int uPK, unsigned int uPvP, unsigned int uPKPardon, unsigned int uUnk1, unsigned int uUnk2, unsigned int uUnk3, unsigned int uUnk4, unsigned int uUnk5, unsigned int uUnk6, unsigned int uUnk7, unsigned int uUnk8, unsigned int uUnk9, wchar_t* pCharTitle, unsigned char* pUnkBuff, unsigned int uUnk10, unsigned int uUnk11, unsigned int uUnk12, unsigned int uUnk13, unsigned int uUnk14, unsigned int uUnk15, unsigned int uUnk16, unsigned int uUnk17, unsigned int uUnk18, unsigned int uUnk19, unsigned int uUnk20, unsigned int uUnk21, unsigned int uUnk22, bool bUnk23)
{
	this->socket = NULL;

	ZeroMemory(this->pCharName, 50);
	ZeroMemory(this->pAccName, 50);
	ZeroMemory(this->pCharTitle, 50);

	wcscpy_s(this->pCharName, 50, pCharName);
	wcscpy_s(this->pAccName, 50, pAccName);
	wcscpy_s(this->pCharTitle, 50, pCharTitle);

	this->uCharId = uCharId;
	this->uAccountId = uAccountId;
	this->uPledgeId = uPledgeId;
	this->uBuilder = uBuilder;
	this->uGender = uGender;
	this->uRace = uRace;
	this->uClass = uClass;
	this->uWorld = uWorld;

	this->nPosX = nPosX;
	this->nPosY = nPosY;
	this->nPosZ = nPosZ;

	this->fHP = fHP;
	this->fMP = fMP;

	this->uSp = uSp;
	this->uExp = uExp;
	this->uLevel = uLevel;
	this->nAlign = nAlign;

	this->uPK = uPK;
	this->uPvP = uPvP;
	this->uPKPardon = uPKPardon;

}

CUserOSIE::~CUserOSIE()
{
	if (this->socket != NULL)
		delete this->socket;

#ifdef L2SERVER_DEBUG
	g_Log->Add(CLog::black, L"[%s] released", __WFUNCTION__);
#endif // L2SERVER_DEBUG
}

CUser* CUserOSIE::GetUser()
{
	return (CUser*)(((UINT64)this) - offsetof(CUser, UserOSIE));
}

BOOL CUserOSIE::CheckRace()
{
	return (this->uRace < 5 && this->uRace >=0);
}

CUserSocket* CUserOSIE::GetUserSocket()
{
	if (this->socket != NULL)
		return this->socket;
	else
	{
#ifdef L2SERVER_DEBUG
		g_Log->Add(CLog::black, L"[%s] socket NULL", __WFUNCTION__);
#endif // L2SERVER_DEBUG
		return NULL;
	}
}