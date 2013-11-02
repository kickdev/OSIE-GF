#include "stdafx.h"

CUserSocket* __cdecl CUserSocket::UserSocketConstructor(CUserSocket* pUserSocket, SOCKET _s)
{
	typedef CUserSocket* (__cdecl *t)(CUserSocket*, SOCKET);
	t f = (t)0x0093CADC;
	CUserSocket* pReturn = f(pUserSocket, _s);
	new (&pUserSocket->UserSocketL2M) CRPGClubUserSocketExtL2M();
	new (&pUserSocket->UserSocketExt) CUserSocketExt();
	return pReturn;
}

CUserSocket* __cdecl CUserSocket::UserSocketDestructor(CUserSocket* pUserSocket, bool bIsMemoryFreeUsed)
{
	pUserSocket->UserSocketExt.~CUserSocketExt();
	pUserSocket->UserSocketL2M.~CRPGClubUserSocketExtL2M();
	typedef CUserSocket* (__cdecl *t)(CUserSocket*, bool);
	t f = (t)0x0092DE7C;
	return f(pUserSocket, bIsMemoryFreeUsed);
}

//
void __thiscall CUserSocket::SendSystemMessage(const wchar_t* pSender, const wchar_t* pMsg)
{
	typedef void (__thiscall *t)(CUserSocket*, const wchar_t*, const wchar_t*);
	t f = (t)0x009244F0;
	f(this, pSender, pMsg);
}

void __thiscall CUserSocket::BindUser(CUser* pUser)
{
	typedef void (__thiscall *t)(CUserSocket*, CUser*);
	t f = (t)0x009246DC;
	f(this, pUser);
}

void __cdecl CUserSocket::_BindUser(CUserSocket* pUserSocket, CUser* pUser)
{
	Guard(__WFUNCSIG__);

	if (!(pUser->SD->nRace < 5 && pUser->SD->nRace >= 0))
	{
		pUserSocket->Close();
#ifdef L2SERVER_DEBUG
		g_Log->Add(CLog::blue, L"[OSIE] Kill race Kamael user name - %s", pUser->SD->wszName);
#endif
	}

	pUserSocket->BindUser(pUser);

	UnGuard();
}