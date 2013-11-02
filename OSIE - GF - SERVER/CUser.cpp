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

bool __thiscall CUser::IsNowTrade()
{
	typedef bool (__thiscall *t)(CUser*);
	t f = (t)0x008A4E8C;
	return f(this);
};

CTrade* __thiscall CUser::GetTrade()
{
	typedef CTrade* (__thiscall *t)(CUser*);
	t f = (t)0x008A0DE4;
	return f(this);
};

void __thiscall CUser::EnterWorld()
{
	typedef void (__thiscall *t)(CUser*);
	t f = (t)0x008CF0E4;
	f(this);
}

void __thiscall CUser::Say(wchar_t* msg)
{
	typedef void (__thiscall *t)(CUser*, wchar_t*);
	t f = (t)0x008AB200;
	f(this, msg);
}

void __thiscall CUser::ShowHTML(const wchar_t* HTML_NAME, const wchar_t* HTML_TEXT, unsigned int uClassID)
{
	typedef void (__thiscall *t)(CUser*, const wchar_t*, const wchar_t*, unsigned int);
	t f = (t)0x008D6594;
	f(this, HTML_NAME, HTML_TEXT, uClassID);
}

__int64 __thiscall CUser::ExpInc(__int64 exp, bool bVar)
{
	typedef __int64 (__thiscall *t)(CUser*, __int64, bool);
	t f = (t)0x0088BF30;
	return f(this, exp, bVar);
}

void __thiscall CUser::SetVitalityPoint(int nPoint, bool bVar)
{
	typedef void (__thiscall *t)(CUser*, int, bool);
	t f = (t)0x0089C66C;
	f(this, nPoint, bVar);
}

void __thiscall CUser::AddVitalityPoint(int nPoint, int nHowToGetPointType, bool bVar)
{
	typedef void (__thiscall *t)(CUser*, int, int, bool);
	t f = (t)0x0089C918;
	f(this, nPoint, nHowToGetPointType, bVar);
}

//static
void __cdecl CUser::_UserEnterWorld(CUser* pUser)
{
	Guard(__WFUNCSIG__);

	pUser->EnterWorld();
		
	UnGuard();
}

void __cdecl CUser::_Say(CUser* pUser, wchar_t* msg)
{
	Guard(__WFUNCSIG__);

	pUser->Say(msg);

	UnGuard();
}

void __cdecl CUser::_ShowHTML(CUser* pUser, const wchar_t* HTML_NAME, const wchar_t* HTML_TEXT, unsigned int uClassID)
{
	Guard(__WFUNCSIG__);

	pUser->ShowHTML(HTML_NAME, HTML_TEXT, uClassID);

	UnGuard();
}

void __cdecl CUser::ShowHTMLInitialize()
{
	WriteInstructionCall(0x40DD9A, (UINT32)_ShowHTML);
	WriteInstructionCall(0x445356, (UINT32)_ShowHTML);
	WriteInstructionCall(0x44A476, (UINT32)_ShowHTML);
	WriteInstructionCall(0x452CC4, (UINT32)_ShowHTML);
	WriteInstructionCall(0x54E7B7, (UINT32)_ShowHTML);
	WriteInstructionCall(0x5B5B42, (UINT32)_ShowHTML);
	WriteInstructionCall(0x5B6388, (UINT32)_ShowHTML);
	WriteInstructionCall(0x62AD6D, (UINT32)_ShowHTML);
	WriteInstructionCall(0x66535E, (UINT32)_ShowHTML);
	WriteInstructionCall(0x73A5C7, (UINT32)_ShowHTML);
	WriteInstructionCall(0x746EAB, (UINT32)_ShowHTML);
	WriteInstructionCall(0x74D7F5, (UINT32)_ShowHTML);
	WriteInstructionCall(0x74DC3D, (UINT32)_ShowHTML);
	WriteInstructionCall(0x76F113, (UINT32)_ShowHTML);
	WriteInstructionCall(0x778949, (UINT32)_ShowHTML);
	WriteInstructionCall(0x7E6F51, (UINT32)_ShowHTML);
	WriteInstructionCall(0x81B4DB, (UINT32)_ShowHTML);
	WriteInstructionCall(0x81B70F, (UINT32)_ShowHTML);
	WriteInstructionCall(0x94A433, (UINT32)_ShowHTML);
	WriteInstructionCall(0x94A4CA, (UINT32)_ShowHTML);
}

__int64 __cdecl CUser::_ExpInc(CUser* pUser, __int64 exp, bool bVar)
{
	Guard(__WFUNCSIG__);
	
	if(pUser->SD->uExp + exp > 6299999999)
	{
		exp = 6299999999 - pUser->SD->uExp;
	}

	__int64 ret = pUser->ExpInc(exp, bVar);

	UnGuardRet(ret);
}

void __cdecl CUser::_SetVitalityPoint(CUser* pUser, int nPoint, bool bVar)
{
	Guard(__WFUNCSIG__);

	pUser->SetVitalityPoint(0, bVar);

	g_Log->Add(CLog::blue, L"[OSIE] _SetVitalityPoint %d, %d", nPoint, bVar);

	UnGuard();
}

void __cdecl CUser::_AddVitalityPoint(CUser* pUser, int nPoint, int nHowToGetPointType, bool bVar)
{
	Guard(__WFUNCSIG__);

	pUser->AddVitalityPoint(0, nHowToGetPointType, bVar);

	g_Log->Add(CLog::blue, L"[OSIE] _AddVitalityPoint %d, %d, %d", nPoint, nHowToGetPointType, bVar);

	UnGuard();
}

void __cdecl CUser::VitalityPointInitialize()
{
	WriteInstructionCall(0x5E2048, (UINT32)CUser::_SetVitalityPoint);
	WriteInstructionCall(0x89CA16, (UINT32)CUser::_SetVitalityPoint);

	WriteInstructionCall(0x487FCE, (UINT32)CUser::_AddVitalityPoint);
	WriteInstructionCall(0x73731E, (UINT32)CUser::_AddVitalityPoint);
	WriteInstructionCall(0x75CAF2, (UINT32)CUser::_AddVitalityPoint);
	WriteInstructionCall(0x75EBB6, (UINT32)CUser::_AddVitalityPoint);
	WriteInstructionCall(0x75ECFA, (UINT32)CUser::_AddVitalityPoint);
	WriteInstructionCall(0x760700, (UINT32)CUser::_AddVitalityPoint);
	WriteInstructionCall(0x83AE20, (UINT32)CUser::_AddVitalityPoint);
	WriteInstructionCall(0x89EE61, (UINT32)CUser::_AddVitalityPoint);
	WriteInstructionCall(0x8A191F, (UINT32)CUser::_AddVitalityPoint);
	WriteInstructionCall(0x8CFE24, (UINT32)CUser::_AddVitalityPoint);
}