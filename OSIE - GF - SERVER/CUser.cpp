#include "stdafx.h"

CUser* __cdecl CUser::UserConstructor(CUser* pUser, wchar_t* pCharName, wchar_t* pAccName, unsigned int uCharId, unsigned int uAccountId, unsigned int uPledgeId, unsigned int uBuilder, unsigned int uGender, unsigned int uRace, unsigned int uClass, unsigned int uWorld, int nPosX, int nPosY, int nPosZ, double fHP, double fMP, unsigned int uSp, unsigned __int64 uExp, unsigned int uLevel, int nAlign, unsigned int uPK, unsigned int uPvP, unsigned int uPKPardon, unsigned int uUnk1, unsigned int uUnk2, unsigned int uUnk3, unsigned int uUnk4, unsigned int uUnk5, unsigned int uUnk6, unsigned int uUnk7, unsigned int uUnk8, unsigned int uUnk9, wchar_t* pCharTitle, unsigned char* pUnkBuff, unsigned int uUnk10, unsigned int uUnk11, unsigned int uUnk12, unsigned int uUnk13, unsigned int uUnk14, unsigned int uUnk15, unsigned int uUnk16, unsigned int uUnk17, unsigned int uUnk18, unsigned int uUnk19, unsigned int uUnk20, unsigned int uUnk21, unsigned int uUnk22, bool bUnk23)
{
	typedef CUser* (__cdecl *t)(CUser*, wchar_t*, wchar_t*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, int, int, int, double, double, unsigned int, unsigned __int64, unsigned int, int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, wchar_t*, unsigned char*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, bool);
	t f = (t)0x008D435C;
	CUser* pReturn = f(pUser, pCharName, pAccName, uCharId, uAccountId, uPledgeId, uBuilder, uGender, uRace, uClass, uWorld, nPosX, nPosY, nPosZ, fHP, fMP, uSp, uExp, uLevel, nAlign, uPK, uPvP, uPKPardon, uUnk1, uUnk2, uUnk3, uUnk4, uUnk5, uUnk6, uUnk7, uUnk8, uUnk9, pCharTitle, pUnkBuff, uUnk10, uUnk11, uUnk12, uUnk13, uUnk14, uUnk15, uUnk16, uUnk17, uUnk18, uUnk19, uUnk20, uUnk21, uUnk22, bUnk23);
	new (&pUser->UserExt) CUserExt();
	return pReturn;
}

CUser* __cdecl CUser::UserDestructor(CUser* pUser, bool bIsMemoryFreeUsed)
{
	pUser->UserExt.~CUserExt();
	typedef CUser* (__cdecl *t)(CUser*, bool);
	t f = (t)0x008D33C0;
	return f(pUser, bIsMemoryFreeUsed);
}

bool __cdecl CUser::_DeleteItemInInventoryBeforeCommit(CUser* pUser, UINT32 uItemId, UINT64 uItemCount)
{
	Guard(__WFUNCSIG__);

	bool bReturn;
	if(!pUser->IsNowTrade())
	{
		typedef bool (__thiscall *t)(CUser*, UINT32, UINT64);
		t f = (t)0x008E8D54;
		bReturn = f(pUser, uItemId, uItemCount);
	}
	else
	{
		g_Log->Add(CLog::red, L"(FIXED BY L2M.RU) user [%s] try DeleteItemInInventoryBeforeCommit, with opened trade !", pUser->SD->wszName);
		bReturn = false;
	}

	UnGuardRet(bReturn)
}

//
void __thiscall CUser::EnterWorld()
{
	Guard(__WFUNCSIG__);

	typedef void (__thiscall *t)(CUser*);
	t f = (t)0x008CF0E4;
	
	if (true) // Если это нормальный игрок ввойти
	{
		f(this);
		this->UserExt.bIsEnterIntoWorld = true;
		this->UserExt.bIsEnteredIntoWorld = true;
	}
	else // Если нет отключить от сервера
	{
		this->UserExt.bIsEnterIntoWorld = false;
		this->UserExt.bIsEnteredIntoWorld = false;
	}

	UnGuard();
}