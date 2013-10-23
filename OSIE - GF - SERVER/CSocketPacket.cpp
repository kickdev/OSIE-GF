#include "stdafx.h"

bool __cdecl _CharacterCreatePacket(CSocket* pSocket, unsigned char* packet)
{
	Guard(__WFUNCSIG__);

	bool bResult = false;

	typedef bool (__thiscall *t)(CSocket*, unsigned char*);
	t f = (t)0x00924EF0;
	bResult = f(pSocket, packet);

	UnGuardRet(bResult);
}