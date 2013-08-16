#pragma once

#pragma pack(push, 1)

typedef map<unsigned int, CUser*> m_uint_user;

class CUserDbMap //only in 2005 at release mode
{
public:
	CUserDbMap() {};
	~CUserDbMap() {};

#ifdef IS_VS2005_RELEASE
	/* 0000 */ m_uint_user dbid_to_user;
#else //IS_VS2005_RELEASE
	/* 0000 */ unsigned char _padding[VS2005_RELEASE_MAP_SIZE];
#endif //IS_VS2005_RELEASE
	/* 0000 */ 
};

class CUserDb
{
public:
	CUserDb() {};
	~CUserDb() {};

	CObjectSP* GetUser(CObjectSP* pObjectSP, UINT32 uUserId, bool bLoadIfNotExist);

	/* 000000 */ CUserDbMap UserDbMap[16383];
	/* 05FFE8 */ RWLock UserBlockLock[16383];
	/* 13FFB0 */ unsigned int _padding13FFE8[20];
	/* 140000 */ RWLock user_db_cs;
	/* 140038 */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(CUserDbMap, VS2005_RELEASE_MAP_SIZE);
CompileTimeOffsetCheck(CUserDb, UserBlockLock, 0x05FFE8);
CompileTimeSizeCheck(CUserDb, 0x140038);
