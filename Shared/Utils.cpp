#include "stdafx.h"

HANDLE g_Server = NULL;

void WriteMemoryBYTES(unsigned int uAddress, void* bytes, unsigned int len)
{
	DWORD flOldProtect;
	SIZE_T uNumberOfBytesWritten;
	HANDLE hServer;
	
	if((hServer = g_Server))
	{
		VirtualProtectEx(hServer, (LPVOID)uAddress, len, PAGE_WRITECOPY, &flOldProtect);
		WriteProcessMemory(hServer, (LPVOID)uAddress, bytes, len, &uNumberOfBytesWritten);
		FlushInstructionCache(hServer, (LPVOID)uAddress, len);
		VirtualProtectEx(hServer, (LPVOID)uAddress, len, flOldProtect, &flOldProtect);
	}
}

void WriteMemoryQWORD(unsigned int uAddress, unsigned __int64 value) { WriteMemoryBYTES(uAddress, &value, sizeof(unsigned __int64)); }
void WriteMemoryDWORD(unsigned int uAddress, unsigned int value)	 { WriteMemoryBYTES(uAddress, &value, sizeof(unsigned int)); }
void WriteMemoryWORD(unsigned int uAddress, unsigned short value)	 { WriteMemoryBYTES(uAddress, &value, sizeof(unsigned short)); }
void WriteMemoryBYTE(unsigned int uAddress, unsigned char value)	 { WriteMemoryBYTES(uAddress, &value, sizeof(unsigned char)); }

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

//
