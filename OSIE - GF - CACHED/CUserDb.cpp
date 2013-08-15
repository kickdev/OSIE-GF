#include "stdafx.h"

CObjectSP* CUserDb::GetUser(CObjectSP* pObjectSP, UINT32 uUserId, bool bLoadIfNotExist)
{
	typedef CObjectSP* (__thiscall *t)(CUserDb*, CObjectSP*, UINT32, bool);
	t f = (t)0x005512B8;
	return f(this, pObjectSP, uUserId, bLoadIfNotExist);
}
