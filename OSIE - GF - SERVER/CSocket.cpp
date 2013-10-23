#include "stdafx.h"

//
void CSocket::Send(const char * format, ...)
{
	typedef void (__thiscall *t) (CSocket * pSocket, const char * format, va_list); 
	t f = (t)0x00858A80; //test adress
	va_list vl;	
	va_start(vl, format);	
	f(this, format, vl);	
	va_end(vl);
}

void CSocket::Close()
{
	typedef void (__thiscall *t) (CSocket * pSocket);
	t f = (t)0x004564D8;
	this->uSocketStatus = 2;
	f(this);
}
