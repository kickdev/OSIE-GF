#include "stdafx.h"

CObjectSP::~CObjectSP()
{ 
#ifdef L2CACHE_DEBUG
	if(this->pMemoryObject)
	{
		g_Log->Add(CLog::red, L"[%s][%d] non released object at function end, lolka", __WFILE__, __LINE__, this->pMemoryObject);
		CLog::CallStack(CLog::red);
	}
#endif //L2CACHE_DEBUG
}
