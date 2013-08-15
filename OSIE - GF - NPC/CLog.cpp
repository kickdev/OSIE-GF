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
	//
}

void CLog::AddV(LogType type, const wchar_t* format, va_list va)
{
	//
}
