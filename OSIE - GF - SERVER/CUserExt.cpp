#include "stdafx.h"

CUserExt::CUserExt()
{
	this->bFlag0000 = false;
	this->uBuilderLvL = NULL;
}

CUserExt::~CUserExt()
{
#ifdef L2SERVER_DEBUG
	g_Log->Add(CLog::black, L"[%s] released", __WFUNCTION__);
#endif // L2SERVER_DEBUG
}

CUser* CUserExt::GetUser()
{
	return (CUser*)(((UINT64)this) - offsetof(CUser, UserExt));
}

//
