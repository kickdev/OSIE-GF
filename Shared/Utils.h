#pragma once

void WriteMemoryBYTES(unsigned int uAddress, void* bytes, unsigned int len);
void WriteMemoryQWORD(unsigned int uAddress, unsigned __int64 value);
void WriteMemoryDWORD(unsigned int uAddress, unsigned int value);
void WriteMemoryWORD(unsigned int uAddress, unsigned short value);
void WriteMemoryBYTE(unsigned int uAddress, unsigned char value);
void NOPMemory(unsigned int uAddress, unsigned int len);
void NULLMemory(unsigned int uAddress, unsigned int len);
void WriteInstruction(unsigned int uAddress, unsigned int uDestination, unsigned char uFirstByte);
void WriteInstructionCallJmpEax(unsigned int uAddress, unsigned int uDestination, unsigned int uNopEnd = NULL);
void WriteInstructionCall(unsigned int uAddress, unsigned int uDestination, unsigned int uNopEnd = NULL);
void WriteInstructionJmp(unsigned int uAddress, unsigned int uDestination, unsigned int uNopEnd = NULL);

class CodeRestoratorOpcodeVariation
{
public:
	CodeRestoratorOpcodeVariation();
	~CodeRestoratorOpcodeVariation();

	/* 0000 */ unsigned char opcode_signature[16];
	/* 0010 */ unsigned int opcode_signature_len;
	/* 0014 */ 
};

typedef vector<CodeRestoratorOpcodeVariation> v_crov;

class CodeRestoratorOpcodeInfo
{
public:
	CodeRestoratorOpcodeInfo();
	~CodeRestoratorOpcodeInfo();

	/* 0000 */ v_crov crov;
	/* unks */ 
};

typedef map<unsigned char, v_uint > m_byte_rci;

class CCodeRestorator
{
public:
	CCodeRestorator(bool _bIsUseLog = true, bool _bIsShowRate = false);
	~CCodeRestorator()
	{
		BYTE* _pFileMem;
		FILE* _pLogFile;
		if((_pFileMem = this->pFileMem))
			free(_pFileMem);
		if((_pLogFile = this->pLogFile))
			fclose(_pLogFile);
	};

	bool OpenParentFile(void* _hServer, unsigned __int64 uAppHash);
	bool RestoreFunctionCode(unsigned int uAddress, unsigned int uControlSize = NULL);
	void AddToLog(const wchar_t* format, ...);

	/* 0000 */ unsigned char* pFileMem;
	/* 0008 */ void* hServer;
	/* 0010 */ unsigned int uBaseAddrOffset;
	/* 0014 */ unsigned int uTextAddrOffset;
	/* 0018 */ unsigned int uTextSectionOffset;
	/* 001C */ bool bIsUseLog;
	/* 001D */ bool bIsShowRate;
	/* 001E */ bool _padding001E[2];
	/* 0020 */ FILE* pLogFile;
	//* 0028 */ m_byte_rci rci;
	/* 0028 */ 
};

#define FILE_LOG_ELEMENT_BUFFER_SIZE 2038
#define FILE_LOG_COUNT_TO_SAVE 1024

class CFileLogLine
{
public:
	~CFileLogLine() {};

	/* 0000 */ SYSTEMTIME log_time;
	/* 0000 */ WCHAR buff[FILE_LOG_ELEMENT_BUFFER_SIZE];
	/* 0000 */ UINT32 buff_size;
	/* 0000 */ 
};

class CFileLog
{
public:
	~CFileLog() { this->Save(); };

	bool OpenLogFile(const wchar_t* pLogFilePath);
	void AddToLog(const wchar_t* format, ...);
	void Save();
	void Enter()
	{
		while(true)
		{
			if(!InterlockedCompareExchange(&this->lock, 1, 0))
				break;
			Sleep(10);
		}
	};
	void Leave() { InterlockedExchange(&this->lock, 0); };

	/* 0000 */ volatile long lock;
	/* 0000 */ volatile long log_data_counter;
	/* 0000 */ wchar_t log_file_path[MAX_PATH];
	/* 0000 */ CFileLogLine log_line[FILE_LOG_COUNT_TO_SAVE];
	/* 0000 */ 
};

void Msg(const char* title, const char* format, ...);
void Msg(const wchar_t* title, const wchar_t* format, ...);

template <typename Type, int Size, int RequiredSize>
struct TypeSizeCheck;

template <typename Type, int Size>
struct TypeSizeCheck<Type, Size, Size>
{};

#define UniqueSizeCheckName2(c) TypeSizeCheck__##c
#define UniqueSizeCheckName1(c) UniqueSizeCheckName2(c)
#define UniqueSizeCheckName     UniqueSizeCheckName1(__COUNTER__)

#define CompileTimeSizeCheck(Type, Size)									\
	struct UniqueSizeCheckName : TypeSizeCheck<Type, sizeof(Type), Size>	\
	{}

template <typename Type, typename Member, int Offset, int RequiredOffset>
struct MemberOffsetCheck;

template <typename Type, typename Member, int Offset>
struct MemberOffsetCheck<Type, Member, Offset, Offset>
{};

#define CompileTimeOffsetCheck(Type, Member, Offset)								\
	typedef size_t Type##__##Member##__;											\
	struct Type##__##Member##__OffsetCheck :										\
	MemberOffsetCheck<Type, Type##__##Member##__, offsetof(Type, Member), Offset>	\
	{}
