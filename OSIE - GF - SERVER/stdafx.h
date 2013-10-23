#pragma once

#ifndef WINVER				// Allow use of features specific to Windows XP or later.
#define WINVER 0x0501		// Change this to the appropriate value to target other versions of Windows.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#endif						

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 6.0 or later.
#define _WIN32_IE 0x0600	// Change this to the appropriate value to target other versions of IE.
#endif

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#define _AMD64_

#include "../Shared/Global.h"

#define L2SERVER_DEBUG 1
//#define IS_VS2005_RELEASE 1
#define VS2005_RELEASE_MAP_SIZE 24
#define VS2005_RELEASE_VECTOR_SIZE 32
#define VS2005_RELEASE_STRING_SIZE 40
#define L2SERVER_USE_DELAY_SYSTEM 1
//#define L2SERVER_USE_DELAY_KICK 1
#define L2SERVER_SEND_DELAY_MSG 1
#define L2SERVER_DEBUG_PACKET_DELAY 1

#define L2SERVER_USE_REPORT_MIN_DELAY_SYSTEM 1
//#define L2SERVER_INCOMING_SHOW_PACKET_INFO 1

#define L2SERVER_L2M_TEST_SOCKET 1

// TODO: reference additional headers your program requires here
#include "OSIEGFS.h"
#include "Config.h"

#include "CIOCriticalSection.h"
#include "CYieldLock.h"
#include "CLog.h"

#include "CMemoryObject.h"
#include "CObjectSP.h"
#include "CTrade.h"
#include "CTradeManager.h"
#include "CIOObject.h"
#include "CHTMLCache.h"
#include "CIOSocket.h"
#include "CSocket.h"
#include "CUserSocket.h"
#include "CObject.h"
#include "CSharedPledgeData.h"
#include "CPledge.h"
#include "CWorldObject.h"
#include "CSharedCreatureData.h"
#include "CCreature.h"
#include "CUser.h"
#include "CHTMLCacheManager.h"

//#include "Resource.h"

#include "Vars.h"

//blablabla...

extern GFS g_GFS;
extern CLog* g_Log;
extern CTradeManager* g_TradeManager;

//
extern CVars* g_Vars; // global params