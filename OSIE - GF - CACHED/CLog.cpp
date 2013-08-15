#include "stdafx.h"

void CLog::_Add(CLog* pLog, LogType type, const char* format, ...)
{
	va_list va;
	va_start(va, format);
	pLog->AddV(type, format, va);
	va_end(va);
}

void CLog::_Add(CLog* pLog, LogType type, const wchar_t* format, ...)
{
	va_list va;
	va_start(va, format);
	pLog->AddV(type, format, va);
	va_end(va);
}

void CLog::Add(LogType type, const char* format, ...)
{
	va_list va;
	va_start(va, format);
	this->AddV(type, format, va);
	va_end(va);
}

void CLog::Add(LogType type, const wchar_t* format, ...)
{
	va_list va;
	va_start(va, format);
	this->AddV(type, format, va);
	va_end(va);
}

void CLog::AddV(LogType type, const char* format, va_list va)
{
	typedef void (__thiscall *t)(CLog*, LogType, const char*, va_list);
	t f = (t)0x0047D2A4;
	f(this, type, format, va);
}

void CLog::AddV(LogType type, const wchar_t* format, va_list va)
{
	typedef void (__thiscall *t)(CLog*, LogType, const wchar_t*, va_list);
	t f = (t)0x0047DCF0;
	f(this, type, format, va);
}

void CLog::CallStack(LogType type)
{
	typedef void (*t)(LogType);
	t f = (t)0x0046209C;
	f(type);
}
