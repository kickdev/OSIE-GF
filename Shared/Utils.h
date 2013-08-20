#pragma once

void WriteMemoryBYTES(unsigned int uAddress, void* bytes, unsigned int len);
void WriteMemoryQWORD(unsigned int uAddress, unsigned __int64 value);
void WriteMemoryDWORD(unsigned int uAddress, unsigned int value);
void WriteMemoryWORD(unsigned int uAddress, unsigned short value);
void WriteMemoryBYTE(unsigned int uAddress, unsigned char value);
void NOPMemory(unsigned int uAddress, unsigned int len);
void NULLMemory(unsigned int uAddress, unsigned int len);
void WriteInstruction(unsigned int uAddress, unsigned int uDestination, unsigned char uFirstByte);
void WriteInstructionJmp(unsigned int uAddress, unsigned int uDestination, unsigned int uNopEnd = NULL);
void WriteInstructionCall(unsigned int uAddress, unsigned int uDestination, unsigned int uNopEnd = NULL);

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
	bool RestoreFunctionCode(unsigned int uAddress);
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
