#include "stdafx.h"
#include "SharedCreatureData.h"

void __cdecl CSharedCreatureData::ExtendCreatureSharedData()
{
	DWORD NewSize = sizeof(CSharedCreatureData);
	WriteMemoryDWORD(0x44F21F , NewSize); //.text:000000000044F21C sub_44F20C    imul    rax, 0DF8h
	WriteMemoryDWORD(0x44FD28 , NewSize); //.text:000000000044FD25 class_CSharedCreatureData____cdecl_GlobalObject::Party_GetCreature(class_CSharedCreatureData___int)                 imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x4640C7 , NewSize); //.text:00000000004640C4 void___cdecl_GlobalObject::AddLog(int_class_CSharedCreatureData___int)                                              imul    rdi, 0DF8h              
	WriteMemoryDWORD(0x46BB7F , NewSize); //.text:000000000046BB7C sub_46BB6C                                                                                                          imul    rax, 0DF8h              
	WriteMemoryDWORD(0x4A442D , NewSize); //.text:00000000004A442A class_FVector___cdecl_CNPC::GetFollowPosition(class_CNPC___int)                                                     imul    rax, 0DF8h              
	WriteMemoryDWORD(0x4A6478 , NewSize); //.text:00000000004A6475 bool___cdecl_CNPC::OnPacketDesireManipulation(int_int_int)                                                          imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x4A7896 , NewSize); //.text:00000000004A7893 class_CSharedCreatureData____cdecl_CNPC::GetLeaderOfParty(class_CSharedPartyData__)                                 imul    rax, 0DF8h              
	WriteMemoryDWORD(0x4A797C , NewSize); //.text:00000000004A7979 class_CSharedCreatureData____cdecl_CNPC::GetMemberOfParty(class_CSharedPartyData___int)                             imul    rax, 0DF8h              
	WriteMemoryDWORD(0x4AF493 , NewSize); //.text:00000000004AF490                                                                                                                     imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x4AF538 , NewSize); //.text:00000000004AF535 class_CSharedCreatureData____cdecl_CNPC::Pledge_GetLeader(class_CSharedCreatureData__)                              imul    rax, 0DF8h              
	WriteMemoryDWORD(0x4BF73E , NewSize); //.text:00000000004BF73B bool___cdecl_CNPC::Set(unsigned_int_unsigned_int)                                                                   imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x4BF82C , NewSize); //.text:00000000004BF829 bool___cdecl_CNPC::Set(unsigned_int_unsigned_int)                                                                   imul    rax, 0DF8h              
	WriteMemoryDWORD(0x4C7543 , NewSize); //.text:00000000004C7540 class_CSharedCreatureData____cdecl_CNPC::FindNeighborHero(int)                                                      imul    rbx, 0DF8h              
	WriteMemoryDWORD(0x5789E8 , NewSize); //.text:00000000005789E7 sub_5789D4                                                                                                          mov     ecx, 0DF8h      ; size_t
	WriteMemoryDWORD(0x578A60 , NewSize); //.text:0000000000578A5F sub_578A4C                                                                                                          mov     ecx, 0DF8h      ; size_t
	WriteMemoryDWORD(0x5838C8 , NewSize); //.text:00000000005838C5 bool___cdecl_TeleportRequestedEventPacket(class_CSocket___const_unsigned_char__)                                    imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x583A60 , NewSize); //.text:0000000000583A5D bool___cdecl_BuyRequestedEventPacket(class_CSocket___const_unsigned_char__)                                         imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x583BF8 , NewSize); //.text:0000000000583BF5 bool___cdecl_SellRequestedEventPacket(class_CSocket___const_unsigned_char__)                                        imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x583DFD , NewSize); //.text:0000000000583DFA bool___cdecl_MenuSelectEventPacket(class_CSocket___const_unsigned_char__)                                           imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x5844F0 , NewSize); //.text:00000000005844ED bool___cdecl_OneSkillSelected(class_CSocket___const_unsigned_char__)                                                imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x5846E0 , NewSize); //.text:00000000005846DD bool___cdecl_OneEnchantSkillSelect(class_CSocket___const_unsigned_char__)                                           imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x5848C8 , NewSize); //.text:00000000005848C5 bool___cdecl_OneEnchantSkillSelectDetail(class_CSocket___const_unsigned_char__)                                     imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x584AA0 , NewSize); //.text:0000000000584A9D bool___cdecl_LearnSkillRequest(class_CSocket___const_unsigned_char__)                                               imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x584C85 , NewSize); //.text:0000000000584C82 bool___cdecl_EnchantSkillRequest(class_CSocket___const_unsigned_char__)                                             imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x584E68 , NewSize); //.text:0000000000584E65 bool___cdecl_SkillQuestAccept(class_CSocket___const_unsigned_char__)                                                imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x585050 , NewSize); //.text:000000000058504D bool___cdecl_ClassChangeRequest(class_CSocket___const_unsigned_char__)                                              imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x585228 , NewSize); //.text:0000000000585225 bool___cdecl_ClanAttack(class_CSocket___const_unsigned_char__)                                                      imul    rbx, 0DF8h              
	WriteMemoryDWORD(0x585591 , NewSize); //.text:000000000058558E bool___cdecl_ClanDiedEvent(class_CSocket___const_unsigned_char__)                                                   imul    rbx, 0DF8h              
	WriteMemoryDWORD(0x5858CD , NewSize); //.text:00000000005858CA bool___cdecl_ClanSpelled(class_CSocket___const_unsigned_char__)                                                     imul    rdi, 0DF8h              
	WriteMemoryDWORD(0x585927 , NewSize); //.text:0000000000585924 bool___cdecl_ClanSpelled(class_CSocket___const_unsigned_char__)                                                     imul    rbx, 0DF8h              
	WriteMemoryDWORD(0x585B3C , NewSize); //.text:0000000000585B39 bool___cdecl_CreatePledge(class_CSocket___const_unsigned_char__)                                                    imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x585D5A , NewSize); //.text:0000000000585D57 bool___cdecl_CreateAcademy(class_CSocket___const_unsigned_char__)                                                   imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x585FA1 , NewSize); //.text:0000000000585F9E bool___cdecl_CreateSubPledge(class_CSocket___const_unsigned_char__)                                                 imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x5861B4 , NewSize); //.text:00000000005861B1 bool___cdecl_UpdateSubPledgeMaster(class_CSocket___const_unsigned_char__)                                           imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x58639C , NewSize); //.text:0000000000586399 bool___cdecl_UpgradeSubPledgeMemberCount(class_CSocket___const_unsigned_char__)                                     imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x58657C , NewSize); //.text:0000000000586579 bool___cdecl_DismissPledge(class_CSocket___const_unsigned_char__)                                                   imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x586764 , NewSize); //.text:0000000000586761 bool___cdecl_RevivePledge(class_CSocket___const_unsigned_char__)                                                    imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x586B24 , NewSize); //.text:0000000000586B21 bool___cdecl_CreateAlliance(class_CSocket___const_unsigned_char__)                                                  imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x586D14 , NewSize); //.text:0000000000586D11 bool___cdecl_ManageCastleSiege(class_CSocket___const_unsigned_char__)                                               imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x5876BC , NewSize); //.text:00000000005876B9 bool___cdecl_DoorHpLevelInfo(class_CSocket___const_unsigned_char__)                                                 imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x587864 , NewSize); //.text:0000000000587861 bool___cdecl_ConrolTowerLevelInfo(class_CSocket___const_unsigned_char__)                                            imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x587D6E , NewSize); //.text:0000000000587D6B bool___cdecl_RegisterTeamBattleEvent(class_CSocket___const_unsigned_char__)                                         imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x587F46 , NewSize); //.text:0000000000587F43 bool___cdecl_QueryTeamBattleNpcEvent(class_CSocket___const_unsigned_char__)                                         imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x58811C , NewSize); //.text:0000000000588119 bool___cdecl_QueryTeamBattlePledgeEvent(class_CSocket___const_unsigned_char__)                                      imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x588326 , NewSize); //.text:0000000000588323 bool___cdecl_GetBattleRoyalPledgeList(class_CSocket___const_unsigned_char__)                                        imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x5885A0 , NewSize); //.text:000000000058859D bool___cdecl_GetSubJobList(class_CSocket___const_unsigned_char__)                                                   imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x588787 , NewSize); //.text:0000000000588784 bool___cdecl_UserLevelUpEvent(class_CSocket___const_unsigned_char__)                                                imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x588924 , NewSize); //.text:0000000000588921 bool___cdecl_CreateSubJob(class_CSocket___const_unsigned_char__)                                                    imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x588AD4 , NewSize); //.text:0000000000588AD1 bool___cdecl_ChangeSubJob(class_CSocket___const_unsigned_char__)                                                    imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x588C84 , NewSize); //.text:0000000000588C81 bool___cdecl_RenewSubJob(class_CSocket___const_unsigned_char__)                                                     imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x588E2C , NewSize); //.text:0000000000588E29 bool___cdecl_SetAgitDecoReturned(class_CSocket___const_unsigned_char__)                                             imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x588FD4 , NewSize); //.text:0000000000588FD1 bool___cdecl_ResetAgitDecoReturned(class_CSocket___const_unsigned_char__)                                           imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x58917F , NewSize); //.text:000000000058917C bool___cdecl_AuctionAgitGetCostInfoReturned(class_CSocket___const_unsigned_char__)                                  imul    rbx, 0DF8h              
	WriteMemoryDWORD(0x58969D , NewSize); //.text:000000000058969A bool___cdecl_QuestAcceptedEventPacket(class_CSocket___const_unsigned_char__)                                        imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x5898F9 , NewSize); //.text:00000000005898F6 bool___cdecl_ManorMenuSelectEventPacket(class_CSocket___const_unsigned_char__)                                      imul    rbx, 0DF8h              
	WriteMemoryDWORD(0x592539 , NewSize); //.text:0000000000592536 sub_592520                                                                                                          imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x59255E , NewSize); //.text:000000000059255B sub_592520                                                                                                          imul    rax, 0DF8h              
	WriteMemoryDWORD(0x592A79 , NewSize); //.text:0000000000592A76                                                                                                                     imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x592A9C , NewSize); //.text:0000000000592A99                                                                                                                     imul    rax, 0DF8h              
	WriteMemoryDWORD(0x592C39 , NewSize); //.text:0000000000592C36 sub_592C20                                                                                                          imul    rax, 0DF8h              
	WriteMemoryDWORD(0x5ADC7A , NewSize); //.text:00000000005ADC77 bool___cdecl_User::Set(unsigned_int)                                                                                imul    rax, 0DF8h              

}