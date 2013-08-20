#include "stdafx.h"

CUserSocketExt::CUserSocketExt()
{
	CUser* _pUser;
	memset(&this->uLastPacketTickCount, 0x00, (256 * sizeof(DWORD)));
	memset(&this->uLastPacketExTickCount, 0x00, ((MAX_GAME_EX_PROTOCOL + 1) * sizeof(DWORD)));
	this->nLoginStage = 1;
	if((_pUser = this->GetUserSocket()->User()))
	{
		this->uBuilderLVL = _pUser->SD->uBuilderLVL;
	}
	else
	{
		this->uBuilderLVL = NULL;
	}
}

CUserSocketExt::~CUserSocketExt()
{
#ifdef L2SERVER_DEBUG
	g_Log->Add(CLog::black, L"[%s] released", __WFUNCTION__);
#endif // L2SERVER_DEBUG
}

CUserSocket* CUserSocketExt::GetUserSocket()
{
	return (CUserSocket*)(((UINT64)this) - offsetof(CUserSocket, UserSocketExt));
}

//
