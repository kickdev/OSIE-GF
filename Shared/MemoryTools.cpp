#include "stdafx.h"

typedef std::pair<INT64, INT64> Int64Pair;
extern HANDLE g_Server;

HANDLE g_Server = NULL;

struct Int64PairLess
{
	bool operator()(Int64Pair a, Int64Pair b) const
	{
		if (a.first < b.first) return true;
		if (a.first > b.first) return false;
		return a.second < b.second;
	}
};

void WriteInstruction(INT32 Address, INT32 NewAddress, INT32 NopZone, INT8 Instruction)
{
	DWORD OLDPROTECT;
	SIZE_T BytesWritten;
	BYTE Byte = 0x90;
	CHAR *MyAddress = (CHAR *)Address;
	INT32 JAddress = NewAddress - (Address+5);

	if(g_Server)
	{
		VirtualProtectEx(g_Server, (VOID *)Address, 5+NopZone, PAGE_WRITECOPY, &OLDPROTECT);

		WriteProcessMemory(g_Server, MyAddress, (CHAR *)&Instruction, 1, &BytesWritten);
		WriteProcessMemory(g_Server, MyAddress+1, (CHAR *)&JAddress, 4, &BytesWritten);
		for(int i = 0; i < NopZone; i++)
		{
			JAddress = Address+5+i;
			WriteProcessMemory(g_Server, (LPVOID)JAddress, &Byte, 1, &BytesWritten);
		}
		VirtualProtectEx(g_Server, (VOID *)Address, 5+NopZone, OLDPROTECT, &OLDPROTECT);
	}
}

void WriteInstructionCALL(INT64 start, INT64 end, void* target)
{
	INT64 size = end - start;
	if (size >= 5)
		WriteInstruction((INT32)start, (INT32)target, (INT32)(size-5), 0xE8);
}

void WriteInstructionJUMP(INT64 start, INT64 end, void* target)
{
	INT64 size = end - start;
	if (size >= 5)
		WriteInstruction((INT32)start, (INT32)target, (INT32)(size-5), 0xE9);
}

void NOPMemory(INT32 Address, INT32 len)
{
	BYTE Byte = 0x90;
	DWORD OLDPROTECT;
	SIZE_T BW;
	if ( g_Server )
	{
		for ( int i = 0 ; i < len ; i++ )
		{
			INT32 ADDR = Address+i;
			VirtualProtectEx(g_Server, (LPVOID)ADDR, 1, PAGE_WRITECOPY, &OLDPROTECT);
			WriteProcessMemory(g_Server,(LPVOID)ADDR,&Byte,1,&BW);
			VirtualProtectEx(g_Server, (LPVOID)ADDR, 1, OLDPROTECT, &OLDPROTECT);
		}
	}
}

void NULLMemory(INT32 Address, INT32 len)
{
	DWORD OLDPROTECT;
	SIZE_T BW;
	if ( g_Server )
	{
		for ( int i = 0 ; i < len ; i++ )
		{
			INT32 ADDR = Address+i;
			CHAR Byte = 0x00;
			VirtualProtectEx(g_Server, (LPVOID)ADDR, 1, PAGE_WRITECOPY, &OLDPROTECT);
			WriteProcessMemory(g_Server,(LPVOID)ADDR,&Byte,1,&BW);
			VirtualProtectEx(g_Server, (LPVOID)ADDR, 1, OLDPROTECT, &OLDPROTECT);
		}
	}
}

void WriteMemoryBYTES(uintptr_t addr, const void* data, size_t len)
{
	DWORD OLDPROTECT;
	SIZE_T BW;
	if ( g_Server )
	{
		VirtualProtectEx(g_Server, (LPVOID)addr, len, PAGE_WRITECOPY, &OLDPROTECT);
		WriteProcessMemory(g_Server,(LPVOID)addr, data, len, &BW);
		VirtualProtectEx(g_Server, (LPVOID)addr, len, OLDPROTECT, &OLDPROTECT);
	}
}

void WriteMemoryBYTES(uintptr_t addr, const char* text)
{
	std::basic_string<unsigned char> buf;
	char* end = 0;

	for (;; text = end)
	{
		unsigned long value = strtoul(text, &end, 16);
		if (text == end)
			break;
		buf.push_back((unsigned char)value);
	}
	if (buf.size() > 0)
	{
		WriteMemoryBYTES(addr, buf.c_str(), buf.size());
	}
}

void WriteMemoryBYTES(uintptr_t addr, size_t len, ...)
{
	if (len <= 0) return;
	BYTE* bytes = (BYTE*)alloca(len);
	va_list ap;
	va_start(ap, len);

	for (int i = 0; i < (int)len; i++)
	{
		bytes[i] = va_arg(ap, BYTE);
	}
	va_end(ap);
	WriteMemoryBYTES(addr, bytes, len);
}

void WriteMemoryQWORD(INT32 Address, INT64 value)     
{
	WriteMemoryBYTES(Address, &value, 8);
}
void WriteMemoryFWORD(INT32 Address, INT64 value)     
{
	WriteMemoryBYTES(Address, &value, 6);
}
void WriteMemoryDWORD(INT32 Address, INT32 value)     
{
	WriteMemoryBYTES(Address, &value, 4);
}
void WriteMemoryWORD(INT32 Address, INT16 value)      
{
	WriteMemoryBYTES(Address, &value, 2);
}
void WriteMemoryBYTE(INT32 Address, INT8 value)       
{
	WriteMemoryBYTES(Address, &value, 1);
}

UINT64 WriteRelativeAddress(INT64 nOrgAddress, INT64 nWriteFrom, VOID *pArray, INT64 nOffsetIndex) 
{
	UINT64 nAddressToPatch  = nOrgAddress+nWriteFrom;
	UINT64 nRIPAddress      = nOrgAddress+nWriteFrom+4;
	UINT64 nPointerAddress  = (UINT64)pArray;
	UINT64 nRelativeAddress = ((nPointerAddress + nOffsetIndex) - nRIPAddress);

	//char MyBigBuffer[256];
	//sprintf(MyBigBuffer, "IDA Address : 0x%04X\nRIP Address : 0x%04X\nDB Address : 0x%04X\nRelative Address 0x%04X", nOrgAddress, nRIPAddress, nPointerAddress, nRelativeAddress);
	//MessageBox( NULL, MyBigBuffer, "", 0 );

	WriteMemoryDWORD((UINT32)nAddressToPatch, (UINT32)nRelativeAddress);
	return nRelativeAddress;
}

void ReadMemoryBYTES(INT32 Address, VOID *bytes, INT32 len)
{
	SIZE_T BR;
	HANDLE Client = OpenProcess(PROCESS_ALL_ACCESS | PROCESS_VM_READ | PROCESS_VM_WRITE, false, GetCurrentProcessId());
	if ( Client )
		ReadProcessMemory(Client,(LPVOID)Address,bytes,len,&BR);
	CloseHandle(Client);
}

void ReadMemoryQWORD(INT32 Address, INT64 *Value) 
{
	ReadMemoryBYTES(Address, Value, 8);
}
void ReadMemoryDWORD(INT32 Address, INT32 *Value) 
{
	ReadMemoryBYTES(Address, Value, 4);
}
void ReadMemoryWORD(INT32 Address, INT16 *Value)  
{
	ReadMemoryBYTES(Address, Value, 2);
}
void ReadMemoryBYTE(INT32 Address, INT8 *Value)   
{
	ReadMemoryBYTES(Address, Value, 1);
}

INT32 ReadRIPPointer(INT32 address, int instructionSize, int addrPosition)
{
	INT32 RIPPointer;
	INT32 result;
	INT8 instruction;

	ReadMemoryBYTE(address, &instruction);
	if (instruction == 0xE9)
	{
		ReadMemoryDWORD(address + addrPosition, &RIPPointer);
		result = RIPPointer + address + instructionSize;
	}
	else
	{
		result = address;
	}

	return result;
}

INT32 ReadJumpAddress(INT32 address)
{
	return ReadRIPPointer(address, 5, 1);
}

INT32 WriteDirectJMP(INT32 address, INT32 newFunc)
{
	LONG_PTR realNewFunc = ReadJumpAddress(newFunc);
	WriteInstruction(address, (INT32)realNewFunc, 0, 0xE9);
	return (INT32)realNewFunc;
}

void EnlargeMemoryDWORD(INT32 Address, INT32 value)
{
	INT32 old;
	ReadMemoryDWORD(Address, &old);
	WriteMemoryDWORD(Address, old + value);
}

void EnlargeMemoryWORD(INT32 Address, INT16 value)
{
	INT16 old;
	ReadMemoryWORD(Address, &old);
	WriteMemoryWORD(Address, old + value);
}
