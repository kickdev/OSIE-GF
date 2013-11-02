#include "stdafx.h"

//
void __cdecl CSharedCreatureData::ExtendCreatureSharedData()
{
	DWORD NewSize = sizeof(CSharedCreatureData);
	//Constructor Creature_::AddById
	WriteMemoryDWORD(0x523CAE , NewSize);//.text:0000000000523CAB Creature_::AddById(int)                		imul    rdi, 0DF8h              
	WriteMemoryDWORD(0x523CDB , NewSize);//.text:0000000000523CD9 Creature_::AddById(int)                		mov     r8d, 0DF8h      ; size_t
	WriteMemoryDWORD(0x523CEB , NewSize);//.text:0000000000523CE8 Creature_::AddById(int)                		imul    r11, 0DF8h              
	//Destructor Creature_::RemoveByIndex
	WriteMemoryDWORD(0x524065 , NewSize);//.text:0000000000524062 Creature_::RemoveByIndex(int)          		imul    r11, 0DF8h              
	WriteMemoryDWORD(0x524070 , NewSize);//.text:000000000052406D Creature_::RemoveByIndex(int)          		imul    rax, 0DF8h              
	WriteMemoryDWORD(0x524084 , NewSize);//.text:0000000000524081 Creature_::RemoveByIndex(int)          		imul    r8, 0DF8h               

	//Creature_::Push
	WriteMemoryDWORD(0x80F949 , NewSize);//.text:000000000080F946 Creature_::Push(int_int_&_int)         		imul    rdx, 0DF8h
	WriteMemoryDWORD(0x80F9AD , NewSize);//.text:000000000080F9AA Creature_::Push(int_int_&_int)         		imul    rcx, 0DF8h              
	//Creature_::Pop
	WriteMemoryDWORD(0x80FA89 , NewSize);//.text:000000000080FA86 Creature_::Pop(int_int_&)              		imul    r8, 0DF8h               
	WriteMemoryDWORD(0x80FB0F , NewSize);//.text:000000000080FB0C Creature_::Pop(int_int_&)              		imul    rax, 0DF8h              
	WriteMemoryDWORD(0x80FB4F , NewSize);//.text:000000000080FB4C Creature_::Pop(int_int_&)              		imul    rax, 0DF8h              
	WriteMemoryDWORD(0x80FB92 , NewSize);//.text:000000000080FB8F Creature_::Pop(int_int_&)              		imul    rax, 0DF8h              
	WriteMemoryDWORD(0x80FBDD , NewSize);//.text:000000000080FBDA Creature_::Pop(int_int_&)              		imul    rax, 0DF8h              
	WriteMemoryDWORD(0x80FBF4 , NewSize);//.text:000000000080FBF1 Creature_::Pop(int_int_&)              		imul    rdx, 0DF8h              

	//Creature_::Change
	WriteMemoryDWORD(0x80FCC6 , NewSize);//.text:000000000080FCC3 Creature_::Change(int_int_&_int_&_int) 		imul    r8, 0DF8h               
	WriteMemoryDWORD(0x80FD8F , NewSize);//.text:000000000080FD8C Creature_::Change(int_int_&_int_&_int) 		imul    rax, 0DF8h              
	WriteMemoryDWORD(0x80FDD2 , NewSize);//.text:000000000080FDCF Creature_::Change(int_int_&_int_&_int) 		imul    rax, 0DF8h              
	WriteMemoryDWORD(0x80FE18 , NewSize);//.text:000000000080FE15 Creature_::Change(int_int_&_int_&_int) 		imul    rax, 0DF8h              
	WriteMemoryDWORD(0x80FE67 , NewSize);//.text:000000000080FE64 Creature_::Change(int_int_&_int_&_int) 		imul    rax, 0DF8h              
	WriteMemoryDWORD(0x80FE7E , NewSize);//.text:000000000080FE7B Creature_::Change(int_int_&_int_&_int) 		imul    rdx, 0DF8h              
	WriteMemoryDWORD(0x80FEAA , NewSize);//.text:000000000080FEA7 Creature_::Change(int_int_&_int_&_int) 		imul    rcx, 0DF8h              

	//Changes in other funcs
	WriteMemoryDWORD(0x534986, NewSize);//.text:0000000000534984 sub_5348D4                             		mov     r8d, 0DF8h      ; size_t

	WriteMemoryDWORD(0x428D8F , NewSize);//.text:0000000000428D8C CAirShip::InSight                      		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x429447 , NewSize);//.text:0000000000429444 CAirShip::OutOfSight                   		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x429ADE , NewSize);//.text:0000000000429ADB CAirShip::KickoutAllPassengers         		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x42A1B3 , NewSize);//.text:000000000042A1B0 CAirShip::HavePassengers(void)         		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x42AC7F , NewSize);//.text:000000000042AC7C CAirShip::SeeDropItem                  		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x42E920 , NewSize);//.text:000000000042E91D CAirShip::Landing(int)                 		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x540353 , NewSize);//.text:0000000000540350 CCreature::SetVisible(bool)            		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x54073D , NewSize);//.text:000000000054073A CCreature::SetVisible(bool)            		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x68636F , NewSize);//.text:000000000068636C sub_68635C                             		imul    rax, 0DF8h                    
	WriteMemoryDWORD(0x7392D2 , NewSize);//.text:00000000007392CF NpcMovePacket                          		imul    rax, 0DF8h              
	WriteMemoryDWORD(0x73B46B , NewSize);//.text:000000000073B468 NpcLeaveWorld                          		imul    rax, 0DF8h              
	WriteMemoryDWORD(0x811E1C , NewSize);//.text:0000000000811E19 CContainerDB::ContainerChanged         		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x812359 , NewSize);//.text:0000000000812356 CContainerDB::ContainerChanged         		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x812B68 , NewSize);//.text:0000000000812B65 sub_812B0C                             		imul    r11d, 0DF8h             
	WriteMemoryDWORD(0x812C64 , NewSize);//.text:0000000000812C61 sub_812B0C                             		add     r8, 0DF8h               
	// .text:0000000000812C68                 mov     [rax+r8-0DA0h], ecx
	WriteMemoryDWORD(0x812C6C, 0x58 - NewSize);
	//.text:0000000000812C74                 mov     [rax+r8-0DA4h], edx
	WriteMemoryDWORD(0x812C78, 0x54 - NewSize);
	WriteMemoryDWORD(0x812C96 , NewSize);//.text:0000000000812C93 sub_812B0C                             		imul    rcx, 0DF8h              
	// .text:0000000000812C9A                 mov     [rcx+rax-0DA0h], esi
	WriteMemoryDWORD(0x812C9D, 0x58 - NewSize);
	WriteMemoryDWORD(0x8BF076 , NewSize);//.text:00000000008BF073 User::InSight                          		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x8BF609 , NewSize);//.text:00000000008BF606 User::InSight                          		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x8BFEB6 , NewSize);//.text:00000000008BFEB3 User::OutOfSight                       		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x8C042B , NewSize);//.text:00000000008C0428 User::OutOfSight                       		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x92E5E8 , NewSize);//.text:000000000092E5E5 ReloadPacket                           		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x955153 , NewSize);//.text:0000000000955150 CVehicle::ProcessStopDrive(void)       		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x9567E0 , NewSize);//.text:00000000009567DD CVehicle::InSight                      		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x956E8D , NewSize);//.text:0000000000956E8A CVehicle::OutOfSight                   		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x9574C4 , NewSize);//.text:00000000009574C1 CVehicle::KickTransformer(void)        		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x95777F , NewSize);//.text:000000000095777C CVehicle::InformVehicleStart(bool)     		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x957C6D , NewSize);//.text:0000000000957C6A CVehicle::KickIllegal                  		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x958060 , NewSize);//.text:000000000095805D CVehicle::SeeDropItem                  		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x967259 , NewSize);//.text:0000000000967256 CWorld::__async_AsyncStaticObjectAppear 		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x9678ED , NewSize);//.text:00000000009678EA CWorld::__async_AsyncStaticObjectDisappear 	imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x968032 , NewSize);//.text:000000000096802F CWorld::__async_AsyncEnterWorld         		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x968AC4 , NewSize);//.text:0000000000968AC1 CWorld::__async_AsyncLeaveWorld         		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x9691A0 , NewSize);//.text:000000000096919D CWorld::__async_AsyncPickAndDeleteItem  		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x969762 , NewSize);//.text:000000000096975F CWorld::__async_AsyncPickItem           		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x969EC3 , NewSize);//.text:0000000000969EC0 CWorld::__async_AsyncPutItem            		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x96A49B , NewSize);//.text:000000000096A498 CWorld::__async_AsyncPutItem            		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x96ABD1 , NewSize);//.text:000000000096ABCE CWorld::__async_AsyncVehicleEnterWorld  		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x96B46D , NewSize);//.text:000000000096B46A CWorld::__async_AsyncGetOffAirShip      		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x96B8A1 , NewSize);//.text:000000000096B89E CWorld::__async_AsyncGetOffAirShip      		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x96C0CD , NewSize);//.text:000000000096C0CA CWorld::__async_AsyncAirShipEnterWorld  		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x96C885 , NewSize);//.text:000000000096C882 CWorld::__async_AsyncLoadStaticObject   		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x96D065 , NewSize);//.text:000000000096D062 CWorld::__async_AsyncUnLoadStaticObject 		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x9735BF , NewSize);//.text:00000000009735BC CWorld::__async_AsyncVehicleMove        		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x97591A , NewSize);//.text:0000000000975917 CWorld::__async_AsyncAirShipMove        		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x975BE4 , NewSize);//.text:0000000000975BE1 sub_975B30                              		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x975CA1 , NewSize);//.text:0000000000975C9E sub_975B30                              		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x977545 , NewSize);//.text:0000000000977542 CWorld::__async_AsyncVehicleLeaveWorld  		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x97811F , NewSize);//.text:000000000097811C CWorld::__async_AsyncAirShipTeleport    		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x9783EC , NewSize);//.text:00000000009783E9 CWorld::__async_AsyncAirShipTeleport    		imul    rcx, 0DF8h              
	WriteMemoryDWORD(0x978EA6 , NewSize);//.text:0000000000978EA3 CWorld::__async_AsyncAirShipLeaveWorld  		imul    rcx, 0DF8h           

}