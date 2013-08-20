#include "stdafx.h"

CObjectSP::~CObjectSP()
{ 
#ifdef L2SERVER_DEBUG
	if(this->pMemoryObject)
	{
		g_Log->Add(CLog::red, L"[%s][%d] non released object [0x%08X] at function end, lolka", __WFILE__, __LINE__, this->pMemoryObject);
		CLog::CallStack(CLog::red);
	}
#endif //L2SERVER_DEBUG
}
