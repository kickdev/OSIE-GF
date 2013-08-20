#include "stdafx.h"

#define MSG_BUFFER_SIZE 8192

void Msg(const char* title, const char* format, ...)
{
	char pBuff[MSG_BUFFER_SIZE];
	va_list va;
	va_start(va, format);
	UINT32 ret_size = (UINT32)vsprintf_s(pBuff, MSG_BUFFER_SIZE, format, va);
	if(ret_size < MSG_BUFFER_SIZE)
		MessageBoxA(NULL, pBuff, title, MB_OK);
	va_end(va);
}

void Msg(const wchar_t* title, const wchar_t* format, ...)
{
	wchar_t pBuff[MSG_BUFFER_SIZE];
	va_list va;
	va_start(va, format);
	UINT32 ret_size = (UINT32)vswprintf_s(pBuff, MSG_BUFFER_SIZE, format, va);
	if(ret_size < MSG_BUFFER_SIZE)
		MessageBoxW(NULL, pBuff, title, MB_OK);
	va_end(va);
}
