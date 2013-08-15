#pragma once

#pragma pack(push, 1)

class CAdminSocket : public CSocket
{
public:
	CAdminSocket() {};
	~CAdminSocket() {};

	__forceinline void SendSuccess(BYTE uPacketId) { this->Send("cd", uPacketId, 0x01); };
	__forceinline void SendError(BYTE uPacketId, UINT32 uErrorId) { this->Send("cdd", uPacketId, 0x00, uErrorId); };

	/* 01A0 */ unsigned int _uUnkVal01A0;
	/* 01A4 */ unsigned int _padding01A4;
	/* 01A8 */ 
};

#pragma pack(pop)

CompileTimeSizeCheck(CAdminSocket, 0x1A8);

bool __cdecl MoveItem2Packet(CAdminSocket* pAdminSocket, unsigned char* packet);
