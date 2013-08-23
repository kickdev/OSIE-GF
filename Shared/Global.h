//#pragma warning(disable: 4018)
//#pragma warning(disable: 4244)
//#pragma warning(disable: 4267)
//#pragma warning(disable: 4800)
//#pragma warning(disable: 4065)
//#pragma warning(disable: 4309)
#pragma warning(disable: 4311)	//lvl3 warning C4311: 'type cast' : pointer truncation from 'CUserSocket *(__cdecl *)(CUserSocket *,SOCKET)' to 'UINT32' (на местах предусматривается что поинтер меньше 0x7FFFFFFF)
#pragma warning(disable: 4100)	//lvl4 warning C4100: 'pReserved' : unreferenced formal parameter (просто не использовали параметр, может он нам не нужен)
#pragma warning(disable: 4201)	//lvl4 warning C4201: nonstandard extension used : nameless struct/union (удобный трюк, задаем несколько описаний одному и тому же параметру)
#pragma warning(disable: 4312)	//lvl3 warning C4312: 'type cast' : conversion from 'unsigned int' to 'LPVOID' of greater size (в 100% случаев это контролированная конверсия)
#pragma warning(disable: 4706)	//lvl4 warning C4706: assignment within conditional expression (зато компилятору нравится, и в 1 строчку можно записать)
#pragma warning(disable: 4127)	//lvl4 warning C4127: conditional expression is constant (while(true) оптимизирует компилятор в замкнутый цикл без проверки)
#pragma once

#define WIDEN2(x) L##x
#define WIDEN(x) WIDEN2(x)
#define __WFILE__ WIDEN(__FILE__)
#define __WDATE__ WIDEN(__DATE__)
#define __WTIME__ WIDEN(__TIME__)
#define __WFUNCTION__ WIDEN(__FUNCTION__)
#define __WFUNCDNAME__ WIDEN(__FUNCDNAME__)
#define __WFUNCSIG__ WIDEN(__FUNCSIG__)

#include <winsock2.h>
#include <Ws2tcpip.h>
#include <sys/stat.h>
#include <cmath>
#include <cstdarg>
#include <ctime>
#include <set>
#include <map>
#include <list>
#include <string>
#include <vector>
//#include <stdlib.h>
#include <process.h>
//#include <windows.h>
#include <Winternl.h>
#include <tlhelp32.h>
#include <Wininet.h>
#include <Commctrl.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <OleIdl.h>
#include <exdisp.h>		// Defines of stuff like IWebBrowser2. This is an include file with Visual C 6 and above
#include <mshtml.h>		// Defines of stuff like IHTMLDocument2. This is an include file with Visual C 6 and above
#include <crtdbg.h>		// for _ASSERT()
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <ShellAPI.h>
#include <pdh.h>
#include <PDHMsg.h>
#include <Psapi.h>
#include <Iphlpapi.h>
#include <Mswsock.h>

using namespace std;

#include <intrin.h>

#define QWORD unsigned __int64

typedef vector<int> v_int;
typedef vector<unsigned int> v_uint;
typedef map<int, int> m_int_int;
typedef map<unsigned int, unsigned int> m_uint_uint;

class CLog;
class CMemoryObject;
class CIOCriticalSection;
class CObjectSP;
class CUser;
class CSharedData;
class CObject;
class CItem;
class CCreature;

#include "Enumerations.h"
#include "Structures.h"
#include "Utils.h"

#include "IniFile.h"