#pragma once

class CLog
{
public:
	CLog() {};
	~CLog() {};

	enum LogType
	{
		black = 0,
		blue = 1,
		red = 2,
		file_in = 6,
		file_db = 7,
		file_audit = 8,
		file_chat = 9,
	};

	static void _Add(CLog* pLog, LogType type, const char* format, ...);
	static void _Add(CLog* pLog, LogType type, const wchar_t* format, ...);

	void Add(LogType type, const char* format, ...);
	void Add(LogType type, const wchar_t* format, ...);

	void AddV(LogType type, const char* format, va_list va);
	void AddV(LogType type, const wchar_t* format, va_list va);

	static void CallStack(LogType type);

	/* 0000 */ unsigned int _padding2356;
	/* 0000 */ 
};
