#include "stdafx.h"

BOOL CHTMLCacheManager::_IsValidHtmlLink(CHTMLCacheManager* pHTMLCacheManager, UINT64 _html_data, WCHAR* link, CUser* pUser)
{
	Guard(__WFUNCSIG__);

	BOOL nReturn;
	if(!wcscmp(link, L"_bbsclan"))
		nReturn = IDOK;
	else if(!wcscmp(link, L"_bbshome"))
		nReturn = IDOK;
	else if(!wcscmp(link, L"manor_menu_select"))
		nReturn = IDOK;
	else
	{
		pUser->html_cs.Lock(__WFUNCTION__, __LINE__);
		
		typedef BOOL (__thiscall *t)(CHTMLCacheManager*, UINT64, WCHAR*, UINT32);
		t f = (t)0x669D8C;
		nReturn = f(pHTMLCacheManager, _html_data, link, NULL);
		
		typedef UINT64 (__thiscall *tStdHTMLCmdDataDestructor)(UINT64);
		tStdHTMLCmdDataDestructor fStdHTMLCmdDataDestructor = (tStdHTMLCmdDataDestructor)0x8D2C88;
		fStdHTMLCmdDataDestructor(_html_data);

		pUser->html_cs.UnLock(__WFUNCTION__, __LINE__);
	}

	UnGuardRet(nReturn)
}
