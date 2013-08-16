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

#define L2CACHE_DEBUG 1
//#define IS_VS2005_RELEASE 1
#define VS2005_RELEASE_MAP_SIZE 24

//#define APP_VECTOR_LEN sizeof(std::vector)
//#define APP_STRING_LEN sizeof(std::string)

// TODO: reference additional headers your program requires here
#include "OSIEGFC.h"

#include "RWLock.h"

#include "CLog.h"

#include "CMemoryObject.h"
#include "CIOObject.h"

#include "CItem.h"

#include "CWareHouse.h"
#include "CUser.h"

#include "CObjectSP.h"
#include "CUserDb.h"

#include "CIOSocket.h"
#include "CSocket.h"
#include "CAdminSocket.h"

//#include "Resource.h"

//blablabla...

extern CLog* g_Log;
extern CUserDb* g_UserDb;

//
