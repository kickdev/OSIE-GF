//#pragma warning(disable: 4018)
//#pragma warning(disable: 4244)
//#pragma warning(disable: 4267)
//#pragma warning(disable: 4311)
//#pragma warning(disable: 4312)
//#pragma warning(disable: 4800)
//#pragma warning(disable: 4065)
//#pragma warning(disable: 4309)
#pragma warning(disable: 4100)	//LVL4
#pragma once

#define WIDEN2(x) L##x
#define WIDEN(x) WIDEN2(x)
#define __WFILE__ WIDEN(__FILE__)
#define __WDATE__ WIDEN(__DATE__)
#define __WTIME__ WIDEN(__TIME__)
#define __WFUNCTION__ WIDEN(__FUNCTION__)
#define __WFUNCDNAME__ WIDEN(__FUNCDNAME__)

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
typedef map<int, int> m_int_int;

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
