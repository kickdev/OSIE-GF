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
