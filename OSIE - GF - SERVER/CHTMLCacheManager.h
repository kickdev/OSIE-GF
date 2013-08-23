#pragma once

#pragma pack(push, 1)

class CHTMLCacheManager : public CHTMLCache
{
public:
	CHTMLCacheManager() {};
	~CHTMLCacheManager() {};

	/* 050 */ 

	static BOOL _IsValidHtmlLink(CHTMLCacheManager* pHTMLCacheManager, UINT64 _html_data, WCHAR* link, CUser* pUser);

	/* 0300 */ unsigned int _uUnkVal0300[4102];
	/* 4318 */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(CHTMLCacheManager, 0x4318);
