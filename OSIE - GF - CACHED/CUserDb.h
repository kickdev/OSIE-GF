#pragma once

class CUserDb
{
public:
	CUserDb() {};
	~CUserDb() {};

	CObjectSP* GetUser(CObjectSP* pObjectSP, UINT32 uUserId, bool bLoadIfNotExist);

	/* 0000 */ unsigned int _padding2356;
	/* 0000 */ 
};
