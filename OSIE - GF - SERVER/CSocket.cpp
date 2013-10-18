#include "stdafx.h"

//
void CSocket::Send(const char * format, ...)
{
	typedef void (__fastcall *t) (CSocket * pSocket, const char * format, ...); 
	t f = (t)0x00858A80; //test adress C4
	va_list vl;	
	va_start(vl, format);	
	f(this, format, vl);	
	va_end(vl);
}

void CSocket::Close()
{
	typedef void (__thiscall *t) (CSocket * pSocket);
	t f = (t)0x0061E540;  //test adress C4
	this->uSocketStatus = 2;
	f(this);
}
