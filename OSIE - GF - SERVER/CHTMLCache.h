#pragma once

#pragma pack(push, 1)

class CHTMLCache : public CIOObject
{
public:
	CHTMLCache() {};
	~CHTMLCache() {};

	/* 050 */ 

	/* 0018 */ unsigned int _uUnkVal0018;
	/* 001C */ unsigned int _uUnkVal001C;
	/* 0020 */ unsigned int _uUnkVal0020[148];
	/* 0270 */ unsigned __int64 _uUnkVal0270;
	/* 0278 */ unsigned __int64 _uUnkVal0278;
	/* 0280 */ unsigned __int64 _uUnkVal0280;
	/* 0288 */ unsigned int _uUnkVal0288[8];
	/* 02A8 */ unsigned int _uUnkVal02A8;
	/* 02AC */ unsigned int _uUnkVal02AC;
	/* 02B0 */ unsigned int _uUnkVal02B0;
	/* 02B4 */ unsigned int _padding02B4;
#ifdef IS_VS2005_RELEASE
	/* 02B8 */ m_uint_uint unk_map02B8;  
#else //IS_VS2005_RELEASE
	/* 02B8 */ unsigned char _padding02B8[VS2005_RELEASE_MAP_SIZE];
#endif //IS_VS2005_RELEASE 
	/* 02D0 */ CIOCriticalSection cache_cs;
	/* 0300 */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(CHTMLCache, 0x0300);
