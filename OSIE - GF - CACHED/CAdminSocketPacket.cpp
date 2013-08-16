#include "stdafx.h"

#define OKKE 1
#define GLOBAL_ERROR 1
#define ARGUMENTS_NEEDED 2
#define ARGUMENTS_INVALID 3
#define CHAR_NOT_FOUND 4
#define WAREHOUSE_NOT_FOUND 5
#define ACCOUNT_NOT_FOUND 6
#define CHAR_IN_GAME 7
#define TOO_MANY_CHARS 8
#define CHAR_IN_PLEDGE 9
#define CHAR_PLEDGE_OWNER 10
#define CANNOT_BAN 11
#define NAME_EXIST 12
#define OBSOLETE 13
#define INVALID_CHAR_NAME 14
#define CHAR_NOT_IN_GAME 15
#define SAME_CHAR 16
#define CHAR_NOT_IN_PLEDGE 17
#define CHAR_PLEDGE_MASTER 18
#define SERVER_NOT_CONNECTED 19
#define CREATE_PET_FAILED 20
#define PLEDGE_EXIST 21
#define NO_CHARS 22
#define INVALID_ANNOUNCE_ID 23
#define PLEDGE_NOT_FOUND 24
#define CASTLE_NOT_FOUND 25
#define PET_NOT_FOUND 26
#define INVALID_PROTOCOL_REQUIRED 28
#define USED_INVALID_PROTOCOL 30

bool __cdecl MoveItem2Packet(CAdminSocket* pAdminSocket, unsigned char* packet)
{
	Guard(__WFUNCSIG__);
	bool bTransactResult;
	CItemAttributeData LogAttributeData;
	wchar_t pAdminName[256] = {0}, pItemAttrLogData[256], pItemLogData[256];
	CObjectSP SenderCharSP, ReceiverCharSP, SenderWareHouseSP, ReceiverWareHouseSP, TransferItemSP;
	UINT32 uSenderCharDbId, uTransferItemDbId, uReceiverCharDbId, uReceiverWareHouseType, uItemWareHouseSourceType, uItemTypeId;
	uSenderCharDbId = uTransferItemDbId = uReceiverCharDbId = uReceiverWareHouseType = 0;
	Disassemble(packet, "ddddS", &uSenderCharDbId, &uTransferItemDbId, &uReceiverCharDbId, &uReceiverWareHouseType, 512, &pAdminName);
	if(uSenderCharDbId != uReceiverCharDbId)
	{
		g_UserDb->GetUser(&SenderCharSP, uSenderCharDbId, true);
		g_UserDb->GetUser(&ReceiverCharSP, uReceiverCharDbId, true);
		if(SenderCharSP.pUser && ReceiverCharSP.pUser)
		{
			if(!SenderCharSP.pUser->bCharInGame && !ReceiverCharSP.pUser->bCharInGame)
			{
				if((uItemWareHouseSourceType = SenderCharSP.pUser->GetItemWare(uTransferItemDbId)) < 2)
				{
					SenderCharSP.pUser->GetWareHouse(&SenderWareHouseSP, uItemWareHouseSourceType, true);
					ReceiverCharSP.pUser->GetWareHouse(&ReceiverWareHouseSP, uReceiverWareHouseType, true);
					if(SenderWareHouseSP.pWareHouse && ReceiverWareHouseSP.pWareHouse)
					{
						uItemTypeId = 0;
						SenderWareHouseSP.pWareHouse->GetItem(&TransferItemSP, uTransferItemDbId);
						if(TransferItemSP.pItem)
							uItemTypeId = TransferItemSP.pItem->uItemType;
						else
						{
							pAdminSocket->SendError(0x28, GLOBAL_ERROR);
							goto ReturnBlock1;
						}

						bTransactResult = SenderWareHouseSP.pWareHouse->MoveItemToChar(uTransferItemDbId, ReceiverWareHouseSP.pWareHouse);

						//1)
						new (&LogAttributeData) CItemAttributeData(TransferItemSP.pItem->AttributeData);

						//2)
						memset(&pItemAttrLogData, 0x00, (256 * 2));
						wsprintfW(pItemAttrLogData, L"%d:%d:%d:%d:%d:%d:%d:%d:%d", 
							LogAttributeData.nAtkAttrElement, 
							LogAttributeData.uAtkAttrPower, 
							LogAttributeData.uDefAttr[0], 
							LogAttributeData.uDefAttr[1], 
							LogAttributeData.uDefAttr[2], 
							LogAttributeData.uDefAttr[3], 
							LogAttributeData.uDefAttr[4], 
							LogAttributeData.uDefAttr[5], 
							LogAttributeData.uDefEnch[0]);

						//3)
						memset(&pItemLogData, 0x00, (256 * 2));
						swprintf_s(pItemLogData, 256, L"%d:%d:%d:%s", 
							TransferItemSP.pItem->uUnk0070, TransferItemSP.pItem->uUnk0068, TransferItemSP.pItem->uUnk006C, 
							pItemAttrLogData);

						if(bTransactResult)
						{
							pAdminSocket->SendSuccess(0x28);

							g_Log->Add(CLog::file_in, L"%I64d,%I64d,%I64d,,,,,,%s,%s,%s,%I64d,%I64d,%I64d,%I64d,,,,,,,%s,%s,,,%I64d", 
								(UINT64)640, (UINT64)0, (UINT64)0, 
								SenderCharSP.pUser->GetCharName(), ReceiverCharSP.pUser->GetCharName(), pItemLogData, 
								(UINT64)SenderCharSP.pUser->GetId(), (UINT64)ReceiverCharSP.pUser->GetId(), (UINT64)uItemTypeId, (UINT64)0, 
								pAdminName, pAdminName, 
								(UINT64)uTransferItemDbId);

							//08/16/2013 09:17:16.031, 640,0,0,,,,,,Admin,Noob,0:0:0:-2:0:0:0:0:0:0:0:0,1,2,6608,0,,,,,,,ÂåáÀäì³í,ÂåáÀäì³í,,,18
						}
						else
							pAdminSocket->SendError(0x28, GLOBAL_ERROR);
ReturnBlock1:
						TransferItemSP.Release();
					}
					else
						pAdminSocket->SendError(0x28, WAREHOUSE_NOT_FOUND);
					SenderWareHouseSP.Release();
					ReceiverWareHouseSP.Release();
				}
				else if(uItemWareHouseSourceType == 1001)
				{
					SenderCharSP.pUser->GetWareHouse(&SenderWareHouseSP, uReceiverWareHouseType, true);
					if(SenderWareHouseSP.pWareHouse)
					{
						uItemTypeId = 0;
						CItem::Load(&TransferItemSP, uTransferItemDbId);
						if(TransferItemSP.pItem)
							uItemTypeId = TransferItemSP.pItem->uItemType;
						else
						{
							pAdminSocket->SendError(0x28, GLOBAL_ERROR);
							goto ReturnBlock2;
						}

						bTransactResult = SenderCharSP.pUser->SetSeizedItemOwner(uTransferItemDbId, ReceiverCharSP.pUser->GetId(), SenderWareHouseSP.pWareHouse);

						//1)
						new (&LogAttributeData) CItemAttributeData(TransferItemSP.pItem->AttributeData);

						//2)
						memset(&pItemAttrLogData, 0x00, (256 * 2));
						wsprintfW(pItemAttrLogData, L"%d:%d:%d:%d:%d:%d:%d:%d:%d", 
							LogAttributeData.nAtkAttrElement, 
							LogAttributeData.uAtkAttrPower, 
							LogAttributeData.uDefAttr[0], 
							LogAttributeData.uDefAttr[1], 
							LogAttributeData.uDefAttr[2], 
							LogAttributeData.uDefAttr[3], 
							LogAttributeData.uDefAttr[4], 
							LogAttributeData.uDefAttr[5], 
							LogAttributeData.uDefEnch[0]);

						//3)
						memset(&pItemLogData, 0x00, (256 * 2));
						swprintf_s(pItemLogData, 256, L"%d:%d:%d:%s", 
							TransferItemSP.pItem->uUnk0070, TransferItemSP.pItem->uUnk0068, TransferItemSP.pItem->uUnk006C, 
							pItemAttrLogData);

						if(bTransactResult)
						{
							pAdminSocket->SendSuccess(0x28);

							g_Log->Add(CLog::file_in, L"%I64d,%I64d,%I64d,,,,,,%s,%s,%s,%I64d,%I64d,%I64d,%I64d,,,,,,,%s,%s,,,%I64d", 
								(UINT64)640, (UINT64)0, (UINT64)0, 
								SenderCharSP.pUser->GetCharName(), ReceiverCharSP.pUser->GetCharName(), pItemLogData, 
								(UINT64)SenderCharSP.pUser->GetId(), (UINT64)ReceiverCharSP.pUser->GetId(), (UINT64)uItemTypeId, (UINT64)0, 
								pAdminName, pAdminName, 
								(UINT64)uTransferItemDbId);

							//08/16/2013 09:17:16.031, 640,0,0,,,,,,Admin,Noob,0:0:0:-2:0:0:0:0:0:0:0:0,1,2,6608,0,,,,,,,ÂåáÀäì³í,ÂåáÀäì³í,,,18
						}
						else
							pAdminSocket->SendError(0x28, GLOBAL_ERROR);
ReturnBlock2:
						TransferItemSP.Release();
					}
					SenderWareHouseSP.Release();
				}
				else
					pAdminSocket->SendError(0x28, GLOBAL_ERROR);
			}
			else
				pAdminSocket->SendError(0x28, CHAR_IN_GAME);
		}
		else
			pAdminSocket->SendError(0x28, CHAR_NOT_FOUND);
		SenderCharSP.Release();
		ReceiverCharSP.Release();
	}
	else
		pAdminSocket->SendError(0x28, SAME_CHAR);
	UnGuard();
	return false;
}
