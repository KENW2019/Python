/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CanApplication.c
 *        Config:  C:/Users/juhu/Desktop/HuJunjun/20181115/cpm_ioc_source/ioc-nxp/Base/Dione_P1.dpa
 *     SW-C Type:  CanApplication
 *  Generated at:  Mon Nov 19 21:42:34 2018
 *
 *     Generator:  MICROSAR RTE Generator Version 4.18.0
 *                 RTE Core Version 1.18.0
 *       License:  Unlimited license CBD1800257 for Harman International (China) Holdings Co., Ltd.
 *
 *   Description:  C-Code implementation template for SW-C <CanApplication>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * IpcS_InfoDataRef
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * IpcS_InfoTypeRef
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 * MM_PoolIdRef
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence 
 *      of decimal digits (#x30-#x39).
 *      
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_CanApplication.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
 
/*******************************************************************************
|    Include declaration
|******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Os.h" /*OS Api is required only during threshold testing*/
#include "trace_api.h"

#include "can_rx_callouts_gen.h" 
#include "can_tx_signals_gen.h"   /*modify by kenw*/

/*******************************************************************************
|    Macro Definition
|******************************************************************************/
#define CeCANApp_u_IpcChanlNum_IVICan 3u
#define CeCANApp_u_IpcMemoryPoolID_IVICan MM_POOL_CAN

#define CeCANApp_u_OK 1u
#define CeCANApp_u_NOK 0u

#define CeCANApp_u_FALSE 0u
#define CeCANApp_u_TRUE  1u

#define CeCANApp_u_PtrNULL 0u

#define CeCANApp_u_CanMsgHeader_IVICan 0x02u   
#define CeCANApp_u_CanStatus_IVICan 0x00u   /*not be used in SOC side*/
#define CeCANApp_u_BusID__IVICan 0x00u   /*not be used in SOC side*/
#define CeCANApp_u_CanMsgCounter_IVICan 0x00u   /*not be used in SOC side*/

#define CeCANApp_s_IpcData_RxCan_NotInRam -1

#define CeCANApp_u_IpcWriteDataStruct_FixedHeaderLen 8u

#define CeCANApp_u_IpcWriteDataHandler_RetryCntMax 3u

/*******************************************************************************
|    Typedef Definition
|******************************************************************************/
typedef uint16 TeCANApp_w_CanID_Ipc;

typedef struct
{
   uint8   CanMsgHeader;      /*  CAN message header always is 0x02u */
   uint8   CanStatus;         /*  CAN message status */
   uint8   Bus_Id;            /*  it contains can message Id info   */
   uint8   CanMsgCounter;     /*  CAN message counter */
   TeCANApp_w_CanID_Ipc  CanID_PduIndex;    /*  CAN ID */
   uint16  CanDLC;            /*  CAN DLC */
   uint8   CanData[8u];       /*  CAN Data 64 Bytes */
}TsCANApp_h_IpcDataStruct_RxCan;

typedef struct
{
    TsCANApp_h_IpcDataStruct_RxCan e_h_IpcData_RxCan;
    uint8 e_u_IpcDataLen;   
}TsCANApp_h_IpcWrite;

typedef enum
{
    CeCANApp_e_VariableInit = 0u,
    CeCANApp_e_IpcWriteFail = 1u,
    CeCANApp_e_IpcChannelStaException = 2u,
    CeCANApp_e_MemoryPtrNULL = 3u,
    CeCANApp_e_IpcWriteSuccess = 4u
    
}TeCANApp_e_WriteDataToIpcRet;

/*******************************************************************************
|    Const Definition
|******************************************************************************/
static const TeCANApp_w_CanID_Ipc CtCANApp_w_RxCanIDTab[TOTAL_PDUS] = {\
/* CAN Msg ID      ComIPDUHandleId   */       
/*0X0000034a*/			/*0*/		0x034a,	
/*0X00000353*/			/*1*/		0x0353,	
/*0X00000337*/			/*2*/		0x0337,		
/*0X0000049*/			/*3*/		0x049,		
/*0X00000611*/			/*4*/		0x0611,		
/*0X000001b0*/			/*5*/		0x01b0,		
/*0X0000053d*/			/*6*/		0x053d,		
/*0X00000292*/			/*7*/		0x0292,		
/*0X00000558*/			/*8*/		0x0558,		
/*0X0000053f*/			/*9*/		0x053f,		
/*0X00000290*/			/*10*/		0x0290,		
/*0X00000540*/			/*11*/		0x0540,		
/*0X0000051e*/			/*12*/		0x051e,		
/*0X00000335*/			/*13*/		0x0335,		
/*0X00000343*/			/*14*/		0x0343,		
/*0X00000345*/			/*15*/		0x0345,		
/*0X00000539*/			/*16*/		0x0539,		
/*0X00000641*/			/*17*/		0x0641,		
/*0X00000215*/			/*18*/		0x0215,		
/*0X00000240*/			/*19*/		0x0240,		
/*0X00000248*/			/*20*/		0x0248,		
/*0X00000260*/			/*21*/		0x0260,		
/*0X00000330*/			/*22*/		0x0330,		
/*0X00000363*/			/*23*/		0x0363,		
/*0X00000630*/			/*24*/		0x0630,		
/*0X00000236*/			/*25*/		0x0236,		
/*0X00000634*/			/*26*/		0x0634,		
/*0X00000310*/			/*27*/		0x0310,		
/*0X00000338*/			/*28*/		0x0338,		
/*0X0000033a*/			/*29*/		0x033a,		
/*0X0000062*/			/*30*/		0x062,		
/*0X00000324*/			/*31*/		0x0324,		
/*0X00000326*/			/*32*/		0x0326,		
/*0X00000518*/			/*33*/		0x0518,		
/*0X00000373*/			/*34*/		0x0373,		
/*0X00000582*/			/*35*/		0x0582,		
/*0X00000644*/			/*36*/		0x0644,		
/*0X00000645*/			/*37*/		0x0645,		
/*0X000002c0*/			/*38*/		0x02c0,		
/*0X00000217*/			/*39*/		0x0217,		
/*0X00000470*/			/*40*/		0x0470,		
/*0X00000261*/			/*41*/		0x0261,		
/*0X00000268*/			/*42*/		0x0268,		
/*0X00000318*/			/*43*/		0x0318,		
/*0X00000332*/			/*44*/		0x0332,		
/*0X00000562*/			/*45*/		0x0562,		
/*0X00000150*/			/*46*/		0x0150,		
/*0X00000375*/			/*47*/		0x0375,		
/*0X00000151*/			/*48*/		0x0151,		
/*0X00000377*/			/*49*/		0x0377,		
/*0X0000082*/			/*50*/		0x082,		
/*0X0000032c*/			/*51*/		0x032c,		
/*0X0000032e*/			/*52*/		0x032e,		
/*0X0000032f*/			/*53*/		0x032f,		
/*0X00000334*/			/*54*/		0x0334,		
/*0X00000340*/			/*55*/		0x0340,		
/*0X0000033c*/			/*56*/		0x033c,		
/*0X0000033e*/			/*57*/		0x033e,		
/*0X00000346*/			/*58*/		0x0346,		
/*0X00000347*/			/*59*/		0x0347,		
/*0X00000522*/			/*60*/		0x0522,		
/*0X00000298*/			/*61*/		0x0298,		
/*0X00000574*/			/*62*/		0x0574,		
/*0X00000576*/			/*63*/		0x0576,		
/*0X0000037b*/			/*64*/		0x037b,		
/*0X00000333*/			/*65*/		0x0333,		
/*0X00000380*/			/*66*/		0x0380,		
/*0X000004f0*/			/*67*/		0x04f0,		
/*0X0000064*/			/*68*/		0x064,		
/*0X00000471*/			/*69*/		0x0471,		
/*0X00000512*/			/*70*/		0x0512,		
/*0X0000041*/			/*71*/		0x041,		
/*0X00000524*/			/*72*/		0x0524,		
/*0X00000319*/			/*73*/		0x0319,		
/*0X000005c4*/			/*74*/		0x05c4,		
/*0X0000036*/			/*75*/		0x036,		
/*0X00000589*/			/*76*/		0x0589,		
/*0X0000050c*/			/*77*/		0x050c,		
/*0X00000105*/			/*78*/		0x0105,		
/*0X00000214*/			/*79*/		0x0214,		
/*0X00000358*/			/*80*/		0x0358,		
/*0X00000503*/			/*81*/		0x0503,		
/*0X00000504*/			/*82*/		0x0504,		
/*0X00000505*/			/*83*/		0x0505,		
/*0X00000507*/			/*84*/		0x0507,		
/*0X00000511*/			/*85*/		0x0511,		
/*0X00000616*/			/*86*/		0x0616,		
/*0X00000588*/			/*87*/		0x0588,		
/*0X0000032a*/			/*88*/		0x032a,		
/*0X00000271*/			/*89*/		0x0271
};

/*******************************************************************************
|    Static local variables Declaration
|******************************************************************************/
static uint8 SeCANApp_u_IpcChanlConnectSta_IVICan = CeCANApp_u_FALSE;
static uint8 SeCANApp_u_IpcChanlFlowCntrlSta_IVICan = CeCANApp_u_FALSE; 


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * DtEHU_336_Checksum: Integer in interval [0...255]
 *   Factor: 1, Offset: 0
 * DtEHU_ALMCstmSetColorB: Integer in interval [0...255]
 *   Factor: 1, Offset: 0
 * DtEHU_ALMCstmSetColorG: Integer in interval [0...255]
 *   Factor: 1, Offset: 0
 * DtEHU_ALMCstmSetColorR: Integer in interval [0...255]
 *   Factor: 1, Offset: 0
 * DtEHU_DrvrHei: Integer in interval [0...255]
 *   Unit: [cm], Factor: 1, Offset: 0
 * DtEHU_DrvrWght: Integer in interval [0...255]
 *   Unit: [Kg], Factor: 1, Offset: 0
 * DtEHU_GPSHei: Integer in interval [0...2047]
 *   Unit: [m], Factor: 1, Offset: -500
 * DtEHU_GPSLati: Integer in interval [0...262143]
 *   Factor: 0.001, Offset: -90
 * DtEHU_GPSLongi: Integer in interval [0...524287]
 *   Factor: 0.001, Offset: -180
 * DtEHU_GPS_AliveCounter: Integer in interval [0...15]
 *   Factor: 1, Offset: 0
 * DtEHU_GPS_Checksum: Integer in interval [0...255]
 *   Factor: 1, Offset: 0
 * DtEHU_NavCtryCod: Integer in interval [0...255]
 *   Factor: 1, Offset: 0
 * DtEHU_NavDstInfo: Integer in interval [0...1048575]
 *   Factor: 1, Offset: 0
 * DtEHU_NavRoadTyp: Integer in interval [0...15]
 *   Factor: 1, Offset: 0
 * DtEHU_NavSpdLimExitDst: Integer in interval [0...255]
 *   Unit: [m], Factor: 10, Offset: 0
 * DtEHU_SpdLimOffs: Integer in interval [0...15]
 *   Factor: 1, Offset: 0
 * DtEHU_SunroofPercCtrlCmdReq: Integer in interval [0...255]
 *   Unit: [%], Factor: 1, Offset: 0
 * DtEHU_TiChrgEndHrSet: Integer in interval [0...31]
 *   Factor: 1, Offset: 0
 * DtEHU_TiChrgEndMinsSet: Integer in interval [0...63]
 *   Factor: 1, Offset: 0
 * DtEHU_TiChrgStrtHrSet: Integer in interval [0...31]
 *   Factor: 1, Offset: 0
 * DtEHU_TiChrgStrtMinsSet: Integer in interval [0...63]
 *   Factor: 1, Offset: 0
 * DtEHU_UsrSetChrgRmnMilg: Integer in interval [0...255]
 *   Factor: 1, Offset: 0
 * DtEHU_UsrSetDchaEndDrvgMilg: Integer in interval [0...1023]
 *   Unit: [Km], Factor: 1, Offset: 0
 * DtICC_172_AliveCounter: Integer in interval [0...15]
 *   Factor: 1, Offset: 0
 * DtICC_172_CheckSum: Integer in interval [0...255]
 *   Factor: 1, Offset: 0
 * DtICC_312_AliveCounter: Integer in interval [0...15]
 *   Factor: 1, Offset: 0
 * DtICC_312_CheckSum: Integer in interval [0...255]
 *   Factor: 1, Offset: 0
 * DtICC_4F2_AliveCounter: Integer in interval [0...15]
 *   Factor: 1, Offset: 0
 * DtICC_4F2_CheckSum: Integer in interval [0...255]
 *   Factor: 1, Offset: 0
 * DtICC_CalVers: Integer in interval [0...255]
 *   Factor: 1, Offset: 0
 * DtICC_HwVers: Integer in interval [0...255]
 *   Factor: 1, Offset: 0
 * DtICC_PartVers: Integer in interval [0...4294967295]
 *   Factor: 1, Offset: 0
 * DtICC_SwVers: Integer in interval [0...255]
 *   Factor: 1, Offset: 0
 * DtICM_DispTotMilg_ODO: Integer in interval [0...268435455]
 *   Unit: [Km], Factor: 0.01, Offset: 0
 * DtICM_DispVehSpd: Integer in interval [0...255]
 *   Factor: 1, Offset: 0
 * DtICM_MilgOffs_ODO: Integer in interval [0...255]
 *   Unit: [Km], Factor: 1, Offset: 0
 * DtICM_TotMilg_ODO: Integer in interval [0...268435455]
 *   Unit: [Km], Factor: 0.01, Offset: 0
 * DtICM_VehFlameoutTi: Integer in interval [0...65535]
 *   Unit: [min], Factor: 1, Offset: 0
 * sint16: Integer in interval [-32768...32767] (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * DtEHU_3DCrs: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default (0U)
 *   Cx1_On (1U)
 *   Cx2_Off (2U)
 *   Cx3_Inhibit (3U)
 * DtEHU_ACCSwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_ACSwtReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_ADASCtrlSet: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Mode_1_ACC_TJAICA (1U)
 *   Cx2_Mode_2_TJAICA_ACC (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_ADASSnvtySet: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Low_OeAe_ (1U)
 *   Cx2_High_Ae_ (2U)
 *   Cx3_Fault (3U)
 * DtEHU_AEBSwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_ALMColorAdjSig: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_0 (0U)
 *   Cx1_1 (1U)
 *   Cx2_2 (2U)
 *   Cx3_3 (3U)
 *   Cx4_4 (4U)
 *   Cx5_5 (5U)
 *   Cx6_6 (6U)
 *   Cx7_7 (7U)
 *   Cx8_8 (8U)
 *   Cx9_9 (9U)
 *   CxA_A (10U)
 *   CxB_Reserved (11U)
 *   CxC_Reserved (12U)
 *   CxD_Reserved (13U)
 *   CxE_Reserved (14U)
 *   CxF_ (15U)
 * DtEHU_AVMMod: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_default (0U)
 *   Cx1_Standard_View (1U)
 *   Cx2_3D_Surround_View (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_AdpvHiBeamMod: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Normal_Sensitivity (0U)
 *   Cx1_SAE_Mode_Sensitivity (1U)
 * DtEHU_AdpvHiBeamSwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_AirClnSwtReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_ (0U)
 *   Cx1_ (1U)
 * DtEHU_AirVolSet: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_ (0U)
 *   Cx1_ (1U)
 *   Cx2_ (2U)
 *   Cx3_ (3U)
 *   Cx4_Ae_ (4U)
 *   Cx5_ (5U)
 *   Cx6_ (6U)
 *   Cx7_ss_ (7U)
 *   Cx8_Reserved (8U)
 *   Cx9_Reserved (9U)
 *   CxA_Reserved (10U)
 *   CxB_Reserved (11U)
 *   CxC_Reserved (12U)
 *   CxD_Reserved (13U)
 *   CxE_Reserved (14U)
 *   CxF_Reserved (15U)
 * DtEHU_ArmedClsdWinSet: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_AtmLampOpenCmd: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_ (0U)
 *   Cx1_ (1U)
 * DtEHU_AutBrkgActvReq: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_MEB_ON (0U)
 *   Cx1_MEB_OFF (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Reserved (3U)
 *   Cx4_Reserved (4U)
 *   Cx5_Reserved (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_AutCam: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default (0U)
 *   Cx1_On (1U)
 *   Cx2_Off (2U)
 *   Cx3_Inhibit (3U)
 * DtEHU_BSDLCASwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_BackgndBriLvl: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Level_1 (0U)
 *   Cx1_Level_2 (1U)
 *   Cx2_Level_3 (2U)
 *   Cx3_Level_4 (3U)
 *   Cx4_Level_5 (4U)
 *   Cx5_Level_6 (5U)
 *   Cx6_Level_7 (6U)
 *   Cx7_Level_8 (7U)
 *   Cx8_Level_9 (8U)
 *   Cx9_Level_10 (9U)
 *   CxA_Reserved (10U)
 *   CxB_Reserved (11U)
 *   CxC_Reserved (12U)
 *   CxD_Reserved (13U)
 *   CxE_Reserved (14U)
 *   CxF_Reserved (15U)
 * DtEHU_BeepSrcSet: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Beep (0U)
 *   Cx1_Ringtone (1U)
 *   Cx2_Chime (2U)
 *   Cx3_Rplay_Alert (3U)
 *   Cx4_The_Third_APPs_Of_Andriod (4U)
 *   Cx5_Reserved (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_BeepVolSet: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Beep_Volume_Step0 (0U)
 *   Cx1_Beep_Volume_Step5 (1U)
 *   Cx2_Beep_Volume_Step10 (2U)
 *   Cx3_Beep_Volume_Step_15 (3U)
 *   Cx4_Beep_Volume_Step_20 (4U)
 *   Cx5_Beep_Volume_Step_25 (5U)
 *   Cx6_Beep_Volume_Step_30 (6U)
 *   Cx7_Beep_Volume_Step_35 (7U)
 *   Cx8_Beep_Volume_Step_39 (8U)
 *   Cx9_Reserved (9U)
 *   CxA_Reserved (10U)
 *   CxB_Reserved (11U)
 *   CxC_Reserved (12U)
 *   CxD_Reserved (13U)
 *   CxE_Reserved (14U)
 *   CxF_Invalid (15U)
 * DtEHU_BlowFaceReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_BlowFootReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_BluetoothWifiKeyPay: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_NC (0U)
 *   Cx1_NFC_Bluetooth_Mode (1U)
 *   Cx2_NFC_Wifi_Mode (2U)
 *   Cx3_NFC_NFC_Smart_Key (3U)
 *   Cx4_NFC_Mobile_Payment (4U)
 *   Cx5_Reserved (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_BluetoothWifiKeyPaySucFlg: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_NC (0U)
 *   Cx1_Bluetooth_Mode_Success (1U)
 *   Cx2_Wifi_Mode_Success (2U)
 *   Cx3_Oe_AeUe_Oe_Oe_ (3U)
 *   Cx4_Oe_Oe_ (4U)
 *   Cx5_Reserved (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_BriAdj_HUD: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Not_Pressed (0U)
 *   Cx1_Up (1U)
 *   Cx2_Down (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_BriAutoAdjEna_HUD: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_On (0U)
 *   Cx1_Off (1U)
 * DtEHU_BrkMod: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Initializing (0U)
 *   Cx1_Comfort (1U)
 *   Cx2_Sport (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_CentrLockCtrl: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Unlock (1U)
 *   Cx2_Lock (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_CfmResmKey: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_None (0U)
 *   Cx1_Not_Pressed (1U)
 *   Cx2_Pressed (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_CnclKey: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_None (0U)
 *   Cx1_Not_Pressed (1U)
 *   Cx2_Pressed (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_CnclTiChrgSetFlg: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_ae_AeUe (0U)
 *   Cx1_ae_AeUe (1U)
 * DtEHU_CtrlSts_NFC: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Closed (0U)
 *   Cx1_Open (1U)
 * DtEHU_CtrlSts_PWC: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Closed (0U)
 *   Cx1_Open (1U)
 * DtEHU_DEgyRecovLvl: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Reserved (0U)
 *   Cx1_1_ (1U)
 *   Cx2_2_Oe_ (2U)
 *   Cx3_3_ (3U)
 * DtEHU_DOWSwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Fault (3U)
 * DtEHU_DchaBtnAvlFlg: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_ (0U)
 *   Cx1_ (1U)
 * DtEHU_DefrstReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_DoubleFlashCtrl: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_DrvAntithiefEnaCmd: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Reserved (0U)
 *   Cx1_Unactive (1U)
 *   Cx2_Active (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_DrvrEyesPosn: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Level0 (0U)
 *   Cx1_Level1 (1U)
 *   Cx2_Level2 (2U)
 *   Cx3_Level3 (3U)
 *   Cx4_Level4 (4U)
 *   Cx5_Level5 (5U)
 *   Cx6_Level6 (6U)
 *   Cx7_Level7 (7U)
 * DtEHU_DrvrGender: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Reserved (0U)
 *   Cx1_Female (1U)
 *   Cx2_Male (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_DrvrHeiManReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Up (1U)
 *   Cx2_Down (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_DrvrID: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Reserved_nobody_ (0U)
 *   Cx1_No_Request_somebody_ (1U)
 *   Cx2_Mem_1 (2U)
 *   Cx3_Mem_2 (3U)
 *   Cx4_Mem_3 (4U)
 *   Cx5_Mem_4 (5U)
 *   Cx6_Mem_5 (6U)
 *   Cx7_Mem_6 (7U)
 *   Cx8_Mem_7 (8U)
 *   Cx9_Mem_8 (9U)
 *   CxA_Mem_9 (10U)
 *   CxB_Mem_10 (11U)
 *   CxC_Reserved (12U)
 *   CxD_Reserved (13U)
 *   CxE_Reserved (14U)
 *   CxF_Reserved (15U)
 * DtEHU_DrvrOccpy: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Driver_In_Seat (0U)
 *   Cx1_Drive_Not_In_Seat (1U)
 * DtEHU_DrvrSYNCReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_DrvrSeatBackManReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Up (1U)
 *   Cx2_Down (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_DrvrSeatHeatgReq: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Not_Change (0U)
 *   Cx1_High (1U)
 *   Cx2_Med (2U)
 *   Cx3_Low (3U)
 *   Cx4_Off (4U)
 *   Cx5_Reserved (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_DrvrSeatTiltManReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Up (1U)
 *   Cx2_Down (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_DrvrSeatTrackManReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Fwd (1U)
 *   Cx2_Rwd (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_DrvrSeatVentnReq: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Not_Change (0U)
 *   Cx1_High (1U)
 *   Cx2_Med (2U)
 *   Cx3_Low (3U)
 *   Cx4_Off (4U)
 *   Cx5_Reserved (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_DrvrSecRowSeatBackManReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Fwd (1U)
 *   Cx2_Rwd (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_DrvrTSet: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Low (0U)
 *   Cx01_Low (1U)
 *   Cx02_Low (2U)
 *   Cx03_Low (3U)
 *   Cx04_Low (4U)
 *   Cx05_Low (5U)
 *   Cx06_Low (6U)
 *   Cx07_Low (7U)
 *   Cx08_Low (8U)
 *   Cx09_Low (9U)
 *   Cx0A_Low (10U)
 *   Cx0B_Low (11U)
 *   Cx0C_Low (12U)
 *   Cx0D_Low (13U)
 *   Cx0E_Low (14U)
 *   Cx0F_Low (15U)
 *   Cx10_Low (16U)
 *   Cx11_Low (17U)
 *   Cx12_Low (18U)
 *   Cx13_Low (19U)
 *   Cx14_Low (20U)
 *   Cx15_Low (21U)
 *   Cx16_Low (22U)
 *   Cx17_Low (23U)
 *   Cx18_Low (24U)
 *   Cx19_Low (25U)
 *   Cx1A_Low (26U)
 *   Cx1B_Low (27U)
 *   Cx1C_Low (28U)
 *   Cx1D_Low (29U)
 *   Cx1E_Low (30U)
 *   Cx1F_Low (31U)
 *   Cx20_Low (32U)
 *   Cx21_Low (33U)
 *   Cx22_Low (34U)
 *   Cx23_Low (35U)
 *   Cx24_18_32_ (36U)
 *   Cx25_18_32_ (37U)
 *   Cx26_18_32_ (38U)
 *   Cx27_18_32_ (39U)
 *   Cx28_18_32_ (40U)
 *   Cx29_18_32_ (41U)
 *   Cx2A_18_32_ (42U)
 *   Cx2B_18_32_ (43U)
 *   Cx2C_18_32_ (44U)
 *   Cx2D_18_32_ (45U)
 *   Cx2E_18_32_ (46U)
 *   Cx2F_18_32_ (47U)
 *   Cx30_18_32_ (48U)
 *   Cx31_18_32_ (49U)
 *   Cx32_18_32_ (50U)
 *   Cx33_18_32_ (51U)
 *   Cx34_18_32_ (52U)
 *   Cx35_18_32_ (53U)
 *   Cx36_18_32_ (54U)
 *   Cx37_18_32_ (55U)
 *   Cx38_18_32_ (56U)
 *   Cx39_18_32_ (57U)
 *   Cx3A_18_32_ (58U)
 *   Cx3B_18_32_ (59U)
 *   Cx3C_18_32_ (60U)
 *   Cx3D_18_32_ (61U)
 *   Cx3E_18_32_ (62U)
 *   Cx3F_18_32_ (63U)
 *   Cx40_18_32_ (64U)
 *   Cx41_High (65U)
 *   Cx42_High (66U)
 *   Cx43_High (67U)
 *   Cx44_High (68U)
 *   Cx45_High (69U)
 *   Cx46_High (70U)
 *   Cx47_High (71U)
 *   Cx48_High (72U)
 *   Cx49_High (73U)
 *   Cx4A_High (74U)
 *   Cx4B_High (75U)
 *   Cx4C_High (76U)
 *   Cx4D_High (77U)
 *   Cx4E_High (78U)
 *   Cx4F_High (79U)
 *   Cx50_High (80U)
 *   Cx51_High (81U)
 *   Cx52_High (82U)
 *   Cx53_High (83U)
 *   Cx54_High (84U)
 *   Cx55_High (85U)
 *   Cx56_High (86U)
 *   Cx57_High (87U)
 *   Cx58_High (88U)
 *   Cx59_High (89U)
 *   Cx5A_High (90U)
 *   Cx5B_High (91U)
 *   Cx5C_High (92U)
 *   Cx5D_High (93U)
 *   Cx5E_High (94U)
 *   Cx5F_High (95U)
 *   Cx60_High (96U)
 *   Cx61_High (97U)
 *   Cx62_High (98U)
 *   Cx63_High (99U)
 *   Cx64_High (100U)
 *   Cx65_High (101U)
 *   Cx66_High (102U)
 *   Cx67_High (103U)
 *   Cx68_High (104U)
 *   Cx69_High (105U)
 *   Cx6A_High (106U)
 *   Cx6B_High (107U)
 *   Cx6C_High (108U)
 *   Cx6D_High (109U)
 *   Cx6E_High (110U)
 *   Cx6F_High (111U)
 *   Cx70_High (112U)
 *   Cx71_High (113U)
 *   Cx72_High (114U)
 *   Cx73_High (115U)
 *   Cx74_High (116U)
 *   Cx75_High (117U)
 *   Cx76_High (118U)
 *   Cx77_High (119U)
 *   Cx78_High (120U)
 *   Cx79_High (121U)
 *   Cx7A_High (122U)
 *   Cx7B_High (123U)
 *   Cx7C_High (124U)
 *   Cx7D_High (125U)
 *   Cx7E_High (126U)
 *   Cx7F_High (127U)
 *   Cx80_High (128U)
 *   Cx81_High (129U)
 *   Cx82_High (130U)
 *   Cx83_High (131U)
 *   Cx84_High (132U)
 *   Cx85_High (133U)
 *   Cx86_High (134U)
 *   Cx87_High (135U)
 *   Cx88_High (136U)
 *   Cx89_High (137U)
 *   Cx8A_High (138U)
 *   Cx8B_High (139U)
 *   Cx8C_High (140U)
 *   Cx8D_High (141U)
 *   Cx8E_High (142U)
 *   Cx8F_High (143U)
 *   Cx90_High (144U)
 *   Cx91_High (145U)
 *   Cx92_High (146U)
 *   Cx93_High (147U)
 *   Cx94_High (148U)
 *   Cx95_High (149U)
 *   Cx96_High (150U)
 *   Cx97_High (151U)
 *   Cx98_High (152U)
 *   Cx99_High (153U)
 *   Cx9A_High (154U)
 *   Cx9B_High (155U)
 *   Cx9C_High (156U)
 *   Cx9D_High (157U)
 *   Cx9E_High (158U)
 *   Cx9F_High (159U)
 *   CxA0_High (160U)
 *   CxA1_High (161U)
 *   CxA2_High (162U)
 *   CxA3_High (163U)
 *   CxA4_High (164U)
 *   CxA5_High (165U)
 *   CxA6_High (166U)
 *   CxA7_High (167U)
 *   CxA8_High (168U)
 *   CxA9_High (169U)
 *   CxAA_High (170U)
 *   CxAB_High (171U)
 *   CxAC_High (172U)
 *   CxAD_High (173U)
 *   CxAE_High (174U)
 *   CxAF_High (175U)
 *   CxB0_High (176U)
 *   CxB1_High (177U)
 *   CxB2_High (178U)
 *   CxB3_High (179U)
 *   CxB4_High (180U)
 *   CxB5_High (181U)
 *   CxB6_High (182U)
 *   CxB7_High (183U)
 *   CxB8_High (184U)
 *   CxB9_High (185U)
 *   CxBA_High (186U)
 *   CxBB_High (187U)
 *   CxBC_High (188U)
 *   CxBD_High (189U)
 *   CxBE_High (190U)
 *   CxBF_High (191U)
 *   CxC0_High (192U)
 *   CxC1_High (193U)
 *   CxC2_High (194U)
 *   CxC3_High (195U)
 *   CxC4_High (196U)
 *   CxC5_High (197U)
 *   CxC6_High (198U)
 *   CxC7_High (199U)
 *   CxC8_High (200U)
 *   CxC9_High (201U)
 *   CxCA_High (202U)
 *   CxCB_High (203U)
 *   CxCC_High (204U)
 *   CxCD_High (205U)
 *   CxCE_High (206U)
 *   CxCF_High (207U)
 *   CxD0_High (208U)
 *   CxD1_High (209U)
 *   CxD2_High (210U)
 *   CxD3_High (211U)
 *   CxD4_High (212U)
 *   CxD5_High (213U)
 *   CxD6_High (214U)
 *   CxD7_High (215U)
 *   CxD8_High (216U)
 *   CxD9_High (217U)
 *   CxDA_High (218U)
 *   CxDB_High (219U)
 *   CxDC_High (220U)
 *   CxDD_High (221U)
 *   CxDE_High (222U)
 *   CxDF_High (223U)
 *   CxE0_High (224U)
 *   CxE1_High (225U)
 *   CxE2_High (226U)
 *   CxE3_High (227U)
 *   CxE4_High (228U)
 *   CxE5_High (229U)
 *   CxE6_High (230U)
 *   CxE7_High (231U)
 *   CxE8_High (232U)
 *   CxE9_High (233U)
 *   CxEA_High (234U)
 *   CxEB_High (235U)
 *   CxEC_High (236U)
 *   CxED_High (237U)
 *   CxEE_High (238U)
 *   CxEF_High (239U)
 *   CxF0_High (240U)
 *   CxF1_High (241U)
 *   CxF2_High (242U)
 *   CxF3_High (243U)
 *   CxF4_High (244U)
 *   CxF5_High (245U)
 *   CxF6_High (246U)
 *   CxF7_High (247U)
 *   CxF8_High (248U)
 *   CxF9_High (249U)
 *   CxFA_High (250U)
 *   CxFB_High (251U)
 *   CxFC_High (252U)
 *   CxFD_High (253U)
 *   CxFE_High (254U)
 *   CxFF_Invalid (255U)
 *   Factor: 0.5, Offset: 0
 * DtEHU_ECCAUTOReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_ECCIntExtCircReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_ECCOffOnReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_ (0U)
 *   Cx1_ (1U)
 * DtEHU_ELKSwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_ESPSwtSig: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_Pressed (0U)
 *   Cx1_Pressed (1U)
 * DtEHU_ESSSwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Fault (3U)
 * DtEHU_ElecFctEnaSet_PLG: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_EmgyCallSet: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_Action (0U)
 *   Cx1_Action (1U)
 * DtEHU_EndFctSwtReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_ExtremeColdModReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_FCTASwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_FCTBSwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_FCWSwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_FacialRcntn: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Driver_in_seat (0U)
 *   Cx1_Driver_not_in_seat (1U)
 * DtEHU_FaderSet: Enumeration of integer in interval [0...31] with enumerators
 *   Cx00_Rear_10_Rear_1 (0U)
 *   Cx01_Rear_10_Rear_1 (1U)
 *   Cx02_Rear_10_Rear_1 (2U)
 *   Cx03_Rear_10_Rear_1 (3U)
 *   Cx04_Rear_10_Rear_1 (4U)
 *   Cx05_Rear_10_Rear_1 (5U)
 *   Cx06_Rear_10_Rear_1 (6U)
 *   Cx07_Rear_10_Rear_1 (7U)
 *   Cx08_Rear_10_Rear_1 (8U)
 *   Cx09_Rear_10_Rear_1 (9U)
 *   Cx0A_Center (10U)
 *   Cx0B_Front_1_Front_10 (11U)
 *   Cx0C_Front_1_Front_10 (12U)
 *   Cx0D_Front_1_Front_10 (13U)
 *   Cx0E_Front_1_Front_10 (14U)
 *   Cx0F_Front_1_Front_10 (15U)
 *   Cx10_Front_1_Front_10 (16U)
 *   Cx11_Front_1_Front_10 (17U)
 *   Cx12_Front_1_Front_10 (18U)
 *   Cx13_Front_1_Front_10 (19U)
 *   Cx14_Front_1_Front_10 (20U)
 *   Cx15_Reserved (21U)
 *   Cx16_Reserved (22U)
 *   Cx17_Reserved (23U)
 *   Cx18_Reserved (24U)
 *   Cx19_Reserved (25U)
 *   Cx1A_Reserved (26U)
 *   Cx1B_Reserved (27U)
 *   Cx1C_Reserved (28U)
 *   Cx1D_Reserved (29U)
 *   Cx1E_Reserved (30U)
 *   Cx1F_Reserved (31U)
 * DtEHU_FeaReqBasePlateTex: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default (0U)
 *   Cx1_On (1U)
 *   Cx2_Off (2U)
 *   Cx3_Inhibit (3U)
 * DtEHU_FeaReqVehColor: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Default (0U)
 *   Cx1_Color_1 (1U)
 *   Cx2_Color_2 (2U)
 *   Cx3_Color_3 (3U)
 *   Cx4_Color_4 (4U)
 *   Cx5_Color_5 (5U)
 *   Cx6_Color_6 (6U)
 *   Cx7_Color_7 (7U)
 *   Cx8_Color_8 (8U)
 *   Cx9_Color_9 (9U)
 *   CxA_Color_10 (10U)
 *   CxB_Reseverd (11U)
 *   CxC_Reseverd (12U)
 *   CxD_Reseverd (13U)
 *   CxE_Reseverd (14U)
 *   CxF_Reseverd (15U)
 * DtEHU_FeaReqVehTrans: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default (0U)
 *   Cx1_On (1U)
 *   Cx2_Off (2U)
 *   Cx3_Inhibit (3U)
 * DtEHU_FolwMeHomeTiSet: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Not_Use (0U)
 *   Cx1_0 (1U)
 *   Cx2_15 (2U)
 *   Cx3_30 (3U)
 *   Cx4_45 (4U)
 *   Cx5_60 (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_FrntDefrstReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_ (0U)
 *   Cx1_ (1U)
 * DtEHU_FrntFogLampCtrl: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_FrntWiprCtrl: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Low (1U)
 *   Cx2_High (2U)
 *   Cx3_AUTO_ss_ (3U)
 * DtEHU_FrntWshrCtrl: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Off_Not_used_ (0U)
 *   Cx1_On (1U)
 * DtEHU_GesRcntnRes: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Inactive_Default (0U)
 *   Cx1_Turn_left (1U)
 *   Cx2_Turn_right (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_HDCSwtSig: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_Pressed (0U)
 *   Cx1_Pressed (1U)
 * DtEHU_HFTVolSet: Enumeration of integer in interval [0...63] with enumerators
 *   Cx00_HFM_Colume_Step_0_39 (0U)
 *   Cx01_HFM_Colume_Step_0_39 (1U)
 *   Cx02_HFM_Colume_Step_0_39 (2U)
 *   Cx03_HFM_Colume_Step_0_39 (3U)
 *   Cx04_HFM_Colume_Step_0_39 (4U)
 *   Cx05_HFM_Colume_Step_0_39 (5U)
 *   Cx06_HFM_Colume_Step_0_39 (6U)
 *   Cx07_HFM_Colume_Step_0_39 (7U)
 *   Cx08_HFM_Colume_Step_0_39 (8U)
 *   Cx09_HFM_Colume_Step_0_39 (9U)
 *   Cx0A_HFM_Colume_Step_0_39 (10U)
 *   Cx0B_HFM_Colume_Step_0_39 (11U)
 *   Cx0C_HFM_Colume_Step_0_39 (12U)
 *   Cx0D_HFM_Colume_Step_0_39 (13U)
 *   Cx0E_HFM_Colume_Step_0_39 (14U)
 *   Cx0F_HFM_Colume_Step_0_39 (15U)
 *   Cx10_HFM_Colume_Step_0_39 (16U)
 *   Cx11_HFM_Colume_Step_0_39 (17U)
 *   Cx12_HFM_Colume_Step_0_39 (18U)
 *   Cx13_HFM_Colume_Step_0_39 (19U)
 *   Cx14_HFM_Colume_Step_0_39 (20U)
 *   Cx15_HFM_Colume_Step_0_39 (21U)
 *   Cx16_HFM_Colume_Step_0_39 (22U)
 *   Cx17_HFM_Colume_Step_0_39 (23U)
 *   Cx18_HFM_Colume_Step_0_39 (24U)
 *   Cx19_HFM_Colume_Step_0_39 (25U)
 *   Cx1A_HFM_Colume_Step_0_39 (26U)
 *   Cx1B_HFM_Colume_Step_0_39 (27U)
 *   Cx1C_HFM_Colume_Step_0_39 (28U)
 *   Cx1D_HFM_Colume_Step_0_39 (29U)
 *   Cx1E_HFM_Colume_Step_0_39 (30U)
 *   Cx1F_HFM_Colume_Step_0_39 (31U)
 *   Cx20_HFM_Colume_Step_0_39 (32U)
 *   Cx21_HFM_Colume_Step_0_39 (33U)
 *   Cx22_HFM_Colume_Step_0_39 (34U)
 *   Cx23_HFM_Colume_Step_0_39 (35U)
 *   Cx24_HFM_Colume_Step_0_39 (36U)
 *   Cx25_HFM_Colume_Step_0_39 (37U)
 *   Cx26_HFM_Colume_Step_0_39 (38U)
 *   Cx27_HFM_Colume_Step_0_39 (39U)
 *   Cx28_Reserved (40U)
 *   Cx29_Reserved (41U)
 *   Cx2A_Reserved (42U)
 *   Cx2B_Reserved (43U)
 *   Cx2C_Reserved (44U)
 *   Cx2D_Reserved (45U)
 *   Cx2E_Reserved (46U)
 *   Cx2F_Reserved (47U)
 *   Cx30_Reserved (48U)
 *   Cx31_Reserved (49U)
 *   Cx32_Reserved (50U)
 *   Cx33_Reserved (51U)
 *   Cx34_Reserved (52U)
 *   Cx35_Reserved (53U)
 *   Cx36_Reserved (54U)
 *   Cx37_Reserved (55U)
 *   Cx38_Reserved (56U)
 *   Cx39_Reserved (57U)
 *   Cx3A_Reserved (58U)
 *   Cx3B_Reserved (59U)
 *   Cx3C_Reserved (60U)
 *   Cx3D_Reserved (61U)
 *   Cx3E_Reserved (62U)
 *   Cx3F_Invalid (63U)
 * DtEHU_HWASwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_HeiAdj_HUD: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Not_Pressed (0U)
 *   Cx1_Up (1U)
 *   Cx2_Down (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_HeiAutoAdjEna_HUD: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_On (0U)
 *   Cx1_Off (1U)
 * DtEHU_HiBeamCtrl: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Off_Not_used_ (0U)
 *   Cx1_On (1U)
 * DtEHU_HiFrqAudioSet: Enumeration of integer in interval [0...31] with enumerators
 *   Cx00_10_10 (0U)
 *   Cx01_10_10 (1U)
 *   Cx02_10_10 (2U)
 *   Cx03_10_10 (3U)
 *   Cx04_10_10 (4U)
 *   Cx05_10_10 (5U)
 *   Cx06_10_10 (6U)
 *   Cx07_10_10 (7U)
 *   Cx08_10_10 (8U)
 *   Cx09_10_10 (9U)
 *   Cx0A_10_10 (10U)
 *   Cx0B_10_10 (11U)
 *   Cx0C_10_10 (12U)
 *   Cx0D_10_10 (13U)
 *   Cx0E_10_10 (14U)
 *   Cx0F_10_10 (15U)
 *   Cx10_10_10 (16U)
 *   Cx11_10_10 (17U)
 *   Cx12_10_10 (18U)
 *   Cx13_10_10 (19U)
 *   Cx14_10_10 (20U)
 *   Cx15_Reserved (21U)
 *   Cx16_Reserved (22U)
 *   Cx17_Reserved (23U)
 *   Cx18_Reserved (24U)
 *   Cx19_Reserved (25U)
 *   Cx1A_Reserved (26U)
 *   Cx1B_Reserved (27U)
 *   Cx1C_Reserved (28U)
 *   Cx1D_Reserved (29U)
 *   Cx1E_Reserved (30U)
 *   Cx1F_Reserved (31U)
 * DtEHU_HiwayExitAuxReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Not_active (0U)
 *   Cx1_Active (1U)
 * DtEHU_HiwayExitAuxSwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_IESSModReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_iESS_OFF (0U)
 *   Cx1_iESS_Mode_1 (1U)
 *   Cx2_iESS_Mode_2 (2U)
 *   Cx3_iESS_Mode_3 (3U)
 * DtEHU_IntegtOpen: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default (0U)
 *   Cx1_On (1U)
 *   Cx2_Off (2U)
 *   Cx3_Inhibit (3U)
 * DtEHU_IntrLampTiSet: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Not_Use (0U)
 *   Cx1_0 (1U)
 *   Cx2_15 (2U)
 *   Cx3_30 (3U)
 *   Cx4_45 (4U)
 *   Cx5_60 (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_KickFctOpenSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default (0U)
 *   Cx1_Inactive (1U)
 *   Cx2_Active (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_LDWSwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_LKASwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_LeFrntWinCtrl: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Auto_Up (1U)
 *   Cx2_Manual_Up_Reserved_ (2U)
 *   Cx3_Auto_Down (3U)
 *   Cx4_Manual_Down_Reserved_ (4U)
 *   Cx5_Reserved (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_LeMirrAlrmLampFlt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_Failure (0U)
 *   Cx1_Failure (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_LeReWinCtrl: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Auto_Up (1U)
 *   Cx2_Manual_Up_reserved_ (2U)
 *   Cx3_Auto_Down (3U)
 *   Cx4_Manual_Down_Reserved_ (4U)
 *   Cx5_Reserved (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_LeRiBalSet: Enumeration of integer in interval [0...31] with enumerators
 *   Cx00_Lch_10_Lch_1 (0U)
 *   Cx01_Lch_10_Lch_1 (1U)
 *   Cx02_Lch_10_Lch_1 (2U)
 *   Cx03_Lch_10_Lch_1 (3U)
 *   Cx04_Lch_10_Lch_1 (4U)
 *   Cx05_Lch_10_Lch_1 (5U)
 *   Cx06_Lch_10_Lch_1 (6U)
 *   Cx07_Lch_10_Lch_1 (7U)
 *   Cx08_Lch_10_Lch_1 (8U)
 *   Cx09_Lch_10_Lch_1 (9U)
 *   Cx0A_Center (10U)
 *   Cx0B_Rch_1_Rch_10 (11U)
 *   Cx0C_Rch_1_Rch_10 (12U)
 *   Cx0D_Rch_1_Rch_10 (13U)
 *   Cx0E_Rch_1_Rch_10 (14U)
 *   Cx0F_Rch_1_Rch_10 (15U)
 *   Cx10_Rch_1_Rch_10 (16U)
 *   Cx11_Rch_1_Rch_10 (17U)
 *   Cx12_Rch_1_Rch_10 (18U)
 *   Cx13_Rch_1_Rch_10 (19U)
 *   Cx14_Rch_1_Rch_10 (20U)
 *   Cx15_Reserved (21U)
 *   Cx16_Reserved (22U)
 *   Cx17_Reserved (23U)
 *   Cx18_Reserved (24U)
 *   Cx19_Reserved (25U)
 *   Cx1A_Reserved (26U)
 *   Cx1B_Reserved (27U)
 *   Cx1C_Reserved (28U)
 *   Cx1D_Reserved (29U)
 *   Cx1E_Reserved (30U)
 *   Cx1F_Reserved (31U)
 * DtEHU_LoBeamCtrl: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Off_Not_used_ (0U)
 *   Cx1_On (1U)
 * DtEHU_LoFrqAudioSet: Enumeration of integer in interval [0...31] with enumerators
 *   Cx00_10_10 (0U)
 *   Cx01_10_10 (1U)
 *   Cx02_10_10 (2U)
 *   Cx03_10_10 (3U)
 *   Cx04_10_10 (4U)
 *   Cx05_10_10 (5U)
 *   Cx06_10_10 (6U)
 *   Cx07_10_10 (7U)
 *   Cx08_10_10 (8U)
 *   Cx09_10_10 (9U)
 *   Cx0A_10_10 (10U)
 *   Cx0B_10_10 (11U)
 *   Cx0C_10_10 (12U)
 *   Cx0D_10_10 (13U)
 *   Cx0E_10_10 (14U)
 *   Cx0F_10_10 (15U)
 *   Cx10_10_10 (16U)
 *   Cx11_10_10 (17U)
 *   Cx12_10_10 (18U)
 *   Cx13_10_10 (19U)
 *   Cx14_10_10 (20U)
 *   Cx15_Reserved (21U)
 *   Cx16_Reserved (22U)
 *   Cx17_Reserved (23U)
 *   Cx18_Reserved (24U)
 *   Cx19_Reserved (25U)
 *   Cx1A_Reserved (26U)
 *   Cx1B_Reserved (27U)
 *   Cx1C_Reserved (28U)
 *   Cx1D_Reserved (29U)
 *   Cx1E_Reserved (30U)
 *   Cx1F_Reserved (31U)
 * DtEHU_MaiVolSet: Enumeration of integer in interval [0...63] with enumerators
 *   Cx00_Main_Volume_Step_0_39 (0U)
 *   Cx01_Main_Volume_Step_0_39 (1U)
 *   Cx02_Main_Volume_Step_0_39 (2U)
 *   Cx03_Main_Volume_Step_0_39 (3U)
 *   Cx04_Main_Volume_Step_0_39 (4U)
 *   Cx05_Main_Volume_Step_0_39 (5U)
 *   Cx06_Main_Volume_Step_0_39 (6U)
 *   Cx07_Main_Volume_Step_0_39 (7U)
 *   Cx08_Main_Volume_Step_0_39 (8U)
 *   Cx09_Main_Volume_Step_0_39 (9U)
 *   Cx0A_Main_Volume_Step_0_39 (10U)
 *   Cx0B_Main_Volume_Step_0_39 (11U)
 *   Cx0C_Main_Volume_Step_0_39 (12U)
 *   Cx0D_Main_Volume_Step_0_39 (13U)
 *   Cx0E_Main_Volume_Step_0_39 (14U)
 *   Cx0F_Main_Volume_Step_0_39 (15U)
 *   Cx10_Main_Volume_Step_0_39 (16U)
 *   Cx11_Main_Volume_Step_0_39 (17U)
 *   Cx12_Main_Volume_Step_0_39 (18U)
 *   Cx13_Main_Volume_Step_0_39 (19U)
 *   Cx14_Main_Volume_Step_0_39 (20U)
 *   Cx15_Main_Volume_Step_0_39 (21U)
 *   Cx16_Main_Volume_Step_0_39 (22U)
 *   Cx17_Main_Volume_Step_0_39 (23U)
 *   Cx18_Main_Volume_Step_0_39 (24U)
 *   Cx19_Main_Volume_Step_0_39 (25U)
 *   Cx1A_Main_Volume_Step_0_39 (26U)
 *   Cx1B_Main_Volume_Step_0_39 (27U)
 *   Cx1C_Main_Volume_Step_0_39 (28U)
 *   Cx1D_Main_Volume_Step_0_39 (29U)
 *   Cx1E_Main_Volume_Step_0_39 (30U)
 *   Cx1F_Main_Volume_Step_0_39 (31U)
 *   Cx20_Main_Volume_Step_0_39 (32U)
 *   Cx21_Main_Volume_Step_0_39 (33U)
 *   Cx22_Main_Volume_Step_0_39 (34U)
 *   Cx23_Main_Volume_Step_0_39 (35U)
 *   Cx24_Main_Volume_Step_0_39 (36U)
 *   Cx25_Main_Volume_Step_0_39 (37U)
 *   Cx26_Main_Volume_Step_0_39 (38U)
 *   Cx27_Main_Volume_Step_0_39 (39U)
 *   Cx28_Reserved (40U)
 *   Cx29_Reserved (41U)
 *   Cx2A_Reserved (42U)
 *   Cx2B_Reserved (43U)
 *   Cx2C_Reserved (44U)
 *   Cx2D_Reserved (45U)
 *   Cx2E_Reserved (46U)
 *   Cx2F_Reserved (47U)
 *   Cx30_Reserved (48U)
 *   Cx31_Reserved (49U)
 *   Cx32_Reserved (50U)
 *   Cx33_Reserved (51U)
 *   Cx34_Reserved (52U)
 *   Cx35_Reserved (53U)
 *   Cx36_Reserved (54U)
 *   Cx37_Reserved (55U)
 *   Cx38_Reserved (56U)
 *   Cx39_Reserved (57U)
 *   Cx3A_Reserved (58U)
 *   Cx3B_Reserved (59U)
 *   Cx3C_Reserved (60U)
 *   Cx3D_Reserved (61U)
 *   Cx3E_Reserved (62U)
 *   Cx3F_Invalid_Value (63U)
 * DtEHU_MediaCallSrcSet: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_USB (0U)
 *   Cx1_BT_A2DP (1U)
 *   Cx2_MTP (2U)
 *   Cx3_Ipod (3U)
 *   Cx4_Carplay_Music (4U)
 *   Cx5_Carlife_Music (5U)
 *   Cx6_The_Third_APPs_0f_Andriod (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_MemDataUpdReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_NoRequest (0U)
 *   Cx1_Update (1U)
 * DtEHU_MidFrqAudioSet: Enumeration of integer in interval [0...31] with enumerators
 *   Cx00_10_10 (0U)
 *   Cx01_10_10 (1U)
 *   Cx02_10_10 (2U)
 *   Cx03_10_10 (3U)
 *   Cx04_10_10 (4U)
 *   Cx05_10_10 (5U)
 *   Cx06_10_10 (6U)
 *   Cx07_10_10 (7U)
 *   Cx08_10_10 (8U)
 *   Cx09_10_10 (9U)
 *   Cx0A_10_10 (10U)
 *   Cx0B_10_10 (11U)
 *   Cx0C_10_10 (12U)
 *   Cx0D_10_10 (13U)
 *   Cx0E_10_10 (14U)
 *   Cx0F_10_10 (15U)
 *   Cx10_10_10 (16U)
 *   Cx11_10_10 (17U)
 *   Cx12_10_10 (18U)
 *   Cx13_10_10 (19U)
 *   Cx14_10_10 (20U)
 *   Cx15_Reserved (21U)
 *   Cx16_Reserved (22U)
 *   Cx17_Reserved (23U)
 *   Cx18_Reserved (24U)
 *   Cx19_Reserved (25U)
 *   Cx1A_Reserved (26U)
 *   Cx1B_Reserved (27U)
 *   Cx1C_Reserved (28U)
 *   Cx1D_Reserved (29U)
 *   Cx1E_Reserved (30U)
 *   Cx1F_Reserved (31U)
 * DtEHU_MirrCmd: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Fold (1U)
 *   Cx2_Unfold (2U)
 *   Cx3_Not_Used (3U)
 * DtEHU_ModSeln: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_None (0U)
 *   Cx1_Park_in (1U)
 *   Cx2_Park_Out (2U)
 *   Cx3_Not_selected (3U)
 * DtEHU_ModSwt_HUD: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Classic_Model (0U)
 *   Cx1_Mini_Malist_Mode (1U)
 * DtEHU_MuteCtrl: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Unmute (0U)
 *   Cx1_Mute (1U)
 * DtEHU_NavGuidanceInfo: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_no_message (0U)
 *   Cx01_message_1 (1U)
 *   Cx02_message_2 (2U)
 *   Cx03_message_3 (3U)
 *   Cx04_message_4 (4U)
 *   Cx05_message_5 (5U)
 *   Cx06_message_6 (6U)
 *   Cx07_message_7 (7U)
 *   Cx08_message_8 (8U)
 *   Cx09_message_9 (9U)
 *   Cx0A_message_10 (10U)
 *   Cx0B_message_11 (11U)
 *   Cx0C_message_12 (12U)
 *   Cx0D_message_13 (13U)
 *   Cx0E_message_14 (14U)
 *   Cx0F_message_15 (15U)
 *   Cx10_message_16 (16U)
 *   Cx11_message_17 (17U)
 *   Cx12_message_18 (18U)
 *   Cx13_message_19 (19U)
 *   Cx14_message_20 (20U)
 *   Cx15_message_21 (21U)
 *   Cx16_Reserved (22U)
 *   Cx17_Reserved (23U)
 *   Cx18_Reserved (24U)
 *   Cx19_Reserved (25U)
 *   Cx1A_Reserved (26U)
 *   Cx1B_Reserved (27U)
 *   Cx1C_Reserved (28U)
 *   Cx1D_Reserved (29U)
 *   Cx1E_Reserved (30U)
 *   Cx1F_Reserved (31U)
 *   Cx20_Reserved (32U)
 *   Cx21_Reserved (33U)
 *   Cx22_Reserved (34U)
 *   Cx23_Reserved (35U)
 *   Cx24_Reserved (36U)
 *   Cx25_Reserved (37U)
 *   Cx26_Reserved (38U)
 *   Cx27_Reserved (39U)
 *   Cx28_Reserved (40U)
 *   Cx29_Reserved (41U)
 *   Cx2A_Reserved (42U)
 *   Cx2B_Reserved (43U)
 *   Cx2C_Reserved (44U)
 *   Cx2D_Reserved (45U)
 *   Cx2E_Reserved (46U)
 *   Cx2F_Reserved (47U)
 *   Cx30_Reserved (48U)
 *   Cx31_Reserved (49U)
 *   Cx32_Reserved (50U)
 *   Cx33_Reserved (51U)
 *   Cx34_Reserved (52U)
 *   Cx35_Reserved (53U)
 *   Cx36_Reserved (54U)
 *   Cx37_Reserved (55U)
 *   Cx38_Reserved (56U)
 *   Cx39_Reserved (57U)
 *   Cx3A_Reserved (58U)
 *   Cx3B_Reserved (59U)
 *   Cx3C_Reserved (60U)
 *   Cx3D_Reserved (61U)
 *   Cx3E_Reserved (62U)
 *   Cx3F_Reserved (63U)
 *   Cx40_Reserved (64U)
 *   Cx41_Reserved (65U)
 *   Cx42_Reserved (66U)
 *   Cx43_Reserved (67U)
 *   Cx44_Reserved (68U)
 *   Cx45_Reserved (69U)
 *   Cx46_Reserved (70U)
 *   Cx47_Reserved (71U)
 *   Cx48_Reserved (72U)
 *   Cx49_Reserved (73U)
 *   Cx4A_Reserved (74U)
 *   Cx4B_Reserved (75U)
 *   Cx4C_Reserved (76U)
 *   Cx4D_Reserved (77U)
 *   Cx4E_Reserved (78U)
 *   Cx4F_Reserved (79U)
 *   Cx50_Reserved (80U)
 *   Cx51_Reserved (81U)
 *   Cx52_Reserved (82U)
 *   Cx53_Reserved (83U)
 *   Cx54_Reserved (84U)
 *   Cx55_Reserved (85U)
 *   Cx56_Reserved (86U)
 *   Cx57_Reserved (87U)
 *   Cx58_Reserved (88U)
 *   Cx59_Reserved (89U)
 *   Cx5A_Reserved (90U)
 *   Cx5B_Reserved (91U)
 *   Cx5C_Reserved (92U)
 *   Cx5D_Reserved (93U)
 *   Cx5E_Reserved (94U)
 *   Cx5F_Reserved (95U)
 *   Cx60_Reserved (96U)
 *   Cx61_Reserved (97U)
 *   Cx62_Reserved (98U)
 *   Cx63_Reserved (99U)
 *   Cx64_Reserved (100U)
 *   Cx65_Reserved (101U)
 *   Cx66_Reserved (102U)
 *   Cx67_Reserved (103U)
 *   Cx68_Reserved (104U)
 *   Cx69_Reserved (105U)
 *   Cx6A_Reserved (106U)
 *   Cx6B_Reserved (107U)
 *   Cx6C_Reserved (108U)
 *   Cx6D_Reserved (109U)
 *   Cx6E_Reserved (110U)
 *   Cx6F_Reserved (111U)
 *   Cx70_Reserved (112U)
 *   Cx71_Reserved (113U)
 *   Cx72_Reserved (114U)
 *   Cx73_Reserved (115U)
 *   Cx74_Reserved (116U)
 *   Cx75_Reserved (117U)
 *   Cx76_Reserved (118U)
 *   Cx77_Reserved (119U)
 *   Cx78_Reserved (120U)
 *   Cx79_Reserved (121U)
 *   Cx7A_Reserved (122U)
 *   Cx7B_Reserved (123U)
 *   Cx7C_Reserved (124U)
 *   Cx7D_Reserved (125U)
 *   Cx7E_Reserved (126U)
 *   Cx7F_Reserved (127U)
 *   Cx80_Reserved (128U)
 *   Cx81_Reserved (129U)
 *   Cx82_Reserved (130U)
 *   Cx83_Reserved (131U)
 *   Cx84_Reserved (132U)
 *   Cx85_Reserved (133U)
 *   Cx86_Reserved (134U)
 *   Cx87_Reserved (135U)
 *   Cx88_Reserved (136U)
 *   Cx89_Reserved (137U)
 *   Cx8A_Reserved (138U)
 *   Cx8B_Reserved (139U)
 *   Cx8C_Reserved (140U)
 *   Cx8D_Reserved (141U)
 *   Cx8E_Reserved (142U)
 *   Cx8F_Reserved (143U)
 *   Cx90_Reserved (144U)
 *   Cx91_Reserved (145U)
 *   Cx92_Reserved (146U)
 *   Cx93_Reserved (147U)
 *   Cx94_Reserved (148U)
 *   Cx95_Reserved (149U)
 *   Cx96_Reserved (150U)
 *   Cx97_Reserved (151U)
 *   Cx98_Reserved (152U)
 *   Cx99_Reserved (153U)
 *   Cx9A_Reserved (154U)
 *   Cx9B_Reserved (155U)
 *   Cx9C_Reserved (156U)
 *   Cx9D_Reserved (157U)
 *   Cx9E_Reserved (158U)
 *   Cx9F_Reserved (159U)
 *   CxA0_Reserved (160U)
 *   CxA1_Reserved (161U)
 *   CxA2_Reserved (162U)
 *   CxA3_Reserved (163U)
 *   CxA4_Reserved (164U)
 *   CxA5_Reserved (165U)
 *   CxA6_Reserved (166U)
 *   CxA7_Reserved (167U)
 *   CxA8_Reserved (168U)
 *   CxA9_Reserved (169U)
 *   CxAA_Reserved (170U)
 *   CxAB_Reserved (171U)
 *   CxAC_Reserved (172U)
 *   CxAD_Reserved (173U)
 *   CxAE_Reserved (174U)
 *   CxAF_Reserved (175U)
 *   CxB0_Reserved (176U)
 *   CxB1_Reserved (177U)
 *   CxB2_Reserved (178U)
 *   CxB3_Reserved (179U)
 *   CxB4_Reserved (180U)
 *   CxB5_Reserved (181U)
 *   CxB6_Reserved (182U)
 *   CxB7_Reserved (183U)
 *   CxB8_Reserved (184U)
 *   CxB9_Reserved (185U)
 *   CxBA_Reserved (186U)
 *   CxBB_Reserved (187U)
 *   CxBC_Reserved (188U)
 *   CxBD_Reserved (189U)
 *   CxBE_Reserved (190U)
 *   CxBF_Reserved (191U)
 *   CxC0_Reserved (192U)
 *   CxC1_Reserved (193U)
 *   CxC2_Reserved (194U)
 *   CxC3_Reserved (195U)
 *   CxC4_Reserved (196U)
 *   CxC5_Reserved (197U)
 *   CxC6_Reserved (198U)
 *   CxC7_Reserved (199U)
 *   CxC8_Reserved (200U)
 *   CxC9_Reserved (201U)
 *   CxCA_Reserved (202U)
 *   CxCB_Reserved (203U)
 *   CxCC_Reserved (204U)
 *   CxCD_Reserved (205U)
 *   CxCE_Reserved (206U)
 *   CxCF_Reserved (207U)
 *   CxD0_Reserved (208U)
 *   CxD1_Reserved (209U)
 *   CxD2_Reserved (210U)
 *   CxD3_Reserved (211U)
 *   CxD4_Reserved (212U)
 *   CxD5_Reserved (213U)
 *   CxD6_Reserved (214U)
 *   CxD7_Reserved (215U)
 *   CxD8_Reserved (216U)
 *   CxD9_Reserved (217U)
 *   CxDA_Reserved (218U)
 *   CxDB_Reserved (219U)
 *   CxDC_Reserved (220U)
 *   CxDD_Reserved (221U)
 *   CxDE_Reserved (222U)
 *   CxDF_Reserved (223U)
 *   CxE0_Reserved (224U)
 *   CxE1_Reserved (225U)
 *   CxE2_Reserved (226U)
 *   CxE3_Reserved (227U)
 *   CxE4_Reserved (228U)
 *   CxE5_Reserved (229U)
 *   CxE6_Reserved (230U)
 *   CxE7_Reserved (231U)
 *   CxE8_Reserved (232U)
 *   CxE9_Reserved (233U)
 *   CxEA_Reserved (234U)
 *   CxEB_Reserved (235U)
 *   CxEC_Reserved (236U)
 *   CxED_Reserved (237U)
 *   CxEE_Reserved (238U)
 *   CxEF_Reserved (239U)
 *   CxF0_Reserved (240U)
 *   CxF1_Reserved (241U)
 *   CxF2_Reserved (242U)
 *   CxF3_Reserved (243U)
 *   CxF4_Reserved (244U)
 *   CxF5_Reserved (245U)
 *   CxF6_Reserved (246U)
 *   CxF7_Reserved (247U)
 *   CxF8_Reserved (248U)
 *   CxF9_Reserved (249U)
 *   CxFA_Reserved (250U)
 *   CxFB_Reserved (251U)
 *   CxFC_Reserved (252U)
 *   CxFD_Reserved (253U)
 *   CxFE_Reserved (254U)
 *   CxFF_Reserved (255U)
 * DtEHU_NavSpdLim: Enumeration of integer in interval [0...63] with enumerators
 *   Cx00_No_Display (0U)
 *   Cx01_SPL_5 (1U)
 *   Cx02_SPL_10 (2U)
 *   Cx03_SPL_15 (3U)
 *   Cx04_SPL_20 (4U)
 *   Cx05_SPL_25 (5U)
 *   Cx1A_SPL_130 (26U)
 *   Cx1B_Reserved (27U)
 *   Cx1C_Reserved (28U)
 *   Cx1D_Reserved (29U)
 *   Cx1E_Reserved (30U)
 *   Cx1F_Reserved (31U)
 *   Cx20_Reserved (32U)
 *   Cx21_Reserved (33U)
 *   Cx22_Reserved (34U)
 *   Cx23_Reserved (35U)
 *   Cx24_Reserved (36U)
 *   Cx25_Reserved (37U)
 *   Cx26_Reserved (38U)
 *   Cx27_Reserved (39U)
 *   Cx28_Reserved (40U)
 *   Cx29_Reserved (41U)
 *   Cx2A_Reserved (42U)
 *   Cx2B_Reserved (43U)
 *   Cx2C_Reserved (44U)
 *   Cx2D_Reserved (45U)
 *   Cx2E_Reserved (46U)
 *   Cx2F_Reserved (47U)
 *   Cx30_Reserved (48U)
 *   Cx31_Reserved (49U)
 *   Cx32_Reserved (50U)
 *   Cx33_Reserved (51U)
 *   Cx34_Reserved (52U)
 *   Cx35_Reserved (53U)
 *   Cx36_Reserved (54U)
 *   Cx37_Reserved (55U)
 *   Cx38_Reserved (56U)
 *   Cx39_Reserved (57U)
 *   Cx3A_Reserved (58U)
 *   Cx3B_Reserved (59U)
 *   Cx3C_Reserved (60U)
 *   Cx3D_Reserved (61U)
 *   Cx3E_Reserved (62U)
 *   Cx3F_Reserved (63U)
 * DtEHU_NavSpdLimSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_SL_Unknown (0U)
 *   Cx1_SL_Exists (1U)
 *   Cx2_SL_Nolimit (2U)
 *   Cx3_SL_Plural (3U)
 * DtEHU_NavSpdLimUnit: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Unknown (0U)
 *   Cx1_MPH (1U)
 *   Cx2_KMH (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_NavSrcSet: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_VR (0U)
 *   Cx1_Navigation (1U)
 *   Cx2_Carplay_Alternate (2U)
 *   Cx3_Carplay_Telephony (3U)
 *   Cx4_BT_Phone (4U)
 *   Cx5_E_CALL_B_CALL (5U)
 *   Cx6_The_Third_APPs_Of_Andriod (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_NavVolSet: Enumeration of integer in interval [0...63] with enumerators
 *   Cx00_Navi_Volume_Step_0_39 (0U)
 *   Cx01_Navi_Volume_Step_0_39 (1U)
 *   Cx02_Navi_Volume_Step_0_39 (2U)
 *   Cx03_Navi_Volume_Step_0_39 (3U)
 *   Cx04_Navi_Volume_Step_0_39 (4U)
 *   Cx05_Navi_Volume_Step_0_39 (5U)
 *   Cx06_Navi_Volume_Step_0_39 (6U)
 *   Cx07_Navi_Volume_Step_0_39 (7U)
 *   Cx08_Navi_Volume_Step_0_39 (8U)
 *   Cx09_Navi_Volume_Step_0_39 (9U)
 *   Cx0A_Navi_Volume_Step_0_39 (10U)
 *   Cx0B_Navi_Volume_Step_0_39 (11U)
 *   Cx0C_Navi_Volume_Step_0_39 (12U)
 *   Cx0D_Navi_Volume_Step_0_39 (13U)
 *   Cx0E_Navi_Volume_Step_0_39 (14U)
 *   Cx0F_Navi_Volume_Step_0_39 (15U)
 *   Cx10_Navi_Volume_Step_0_39 (16U)
 *   Cx11_Navi_Volume_Step_0_39 (17U)
 *   Cx12_Navi_Volume_Step_0_39 (18U)
 *   Cx13_Navi_Volume_Step_0_39 (19U)
 *   Cx14_Navi_Volume_Step_0_39 (20U)
 *   Cx15_Navi_Volume_Step_0_39 (21U)
 *   Cx16_Navi_Volume_Step_0_39 (22U)
 *   Cx17_Navi_Volume_Step_0_39 (23U)
 *   Cx18_Navi_Volume_Step_0_39 (24U)
 *   Cx19_Navi_Volume_Step_0_39 (25U)
 *   Cx1A_Navi_Volume_Step_0_39 (26U)
 *   Cx1B_Navi_Volume_Step_0_39 (27U)
 *   Cx1C_Navi_Volume_Step_0_39 (28U)
 *   Cx1D_Navi_Volume_Step_0_39 (29U)
 *   Cx1E_Navi_Volume_Step_0_39 (30U)
 *   Cx1F_Navi_Volume_Step_0_39 (31U)
 *   Cx20_Navi_Volume_Step_0_39 (32U)
 *   Cx21_Navi_Volume_Step_0_39 (33U)
 *   Cx22_Navi_Volume_Step_0_39 (34U)
 *   Cx23_Navi_Volume_Step_0_39 (35U)
 *   Cx24_Navi_Volume_Step_0_39 (36U)
 *   Cx25_Navi_Volume_Step_0_39 (37U)
 *   Cx26_Navi_Volume_Step_0_39 (38U)
 *   Cx27_Navi_Volume_Step_0_39 (39U)
 *   Cx28_Reserved (40U)
 *   Cx29_Reserved (41U)
 *   Cx2A_Reserved (42U)
 *   Cx2B_Reserved (43U)
 *   Cx2C_Reserved (44U)
 *   Cx2D_Reserved (45U)
 *   Cx2E_Reserved (46U)
 *   Cx2F_Reserved (47U)
 *   Cx30_Reserved (48U)
 *   Cx31_Reserved (49U)
 *   Cx32_Reserved (50U)
 *   Cx33_Reserved (51U)
 *   Cx34_Reserved (52U)
 *   Cx35_Reserved (53U)
 *   Cx36_Reserved (54U)
 *   Cx37_Reserved (55U)
 *   Cx38_Reserved (56U)
 *   Cx39_Reserved (57U)
 *   Cx3A_Reserved (58U)
 *   Cx3B_Reserved (59U)
 *   Cx3C_Reserved (60U)
 *   Cx3D_Reserved (61U)
 *   Cx3E_Reserved (62U)
 *   Cx3F_Invalid (63U)
 * DtEHU_OffUnlckSet: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_OpenCmd_HUD: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Closed (0U)
 *   Cx1_Open (1U)
 * DtEHU_OpenTiChrgSetFlg: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_ae_AeUe (0U)
 *   Cx1_ae_AeUe (1U)
 * DtEHU_OrintChgKey: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_None (0U)
 *   Cx1_Not_Pressed (1U)
 *   Cx2_Pressed (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_OverlayDstReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default (0U)
 *   Cx1_On (1U)
 *   Cx2_Off (2U)
 *   Cx3_Inhibit (3U)
 * DtEHU_OverlayTubeReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default (0U)
 *   Cx1_On (1U)
 *   Cx2_Off (2U)
 *   Cx3_Inhibit (3U)
 * DtEHU_PASSwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default (0U)
 *   Cx1_On (1U)
 *   Cx2_Off (2U)
 *   Cx3_Inhibit (3U)
 * DtEHU_PassOccpy: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_ (0U)
 *   Cx1_ (1U)
 * DtEHU_PassSYNCReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_PassSeatBackManReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Fwd (1U)
 *   Cx2_Rwd (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_PassSeatHeatgReq: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Not_Change (0U)
 *   Cx1_High (1U)
 *   Cx2_Med (2U)
 *   Cx3_Low (3U)
 *   Cx4_Off (4U)
 *   Cx5_Reserved (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_PassSeatTrackManReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Fwd (1U)
 *   Cx2_Rwd (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_PassSeatVentnReq: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Not_Change (0U)
 *   Cx1_High (1U)
 *   Cx2_Med (2U)
 *   Cx3_Low (3U)
 *   Cx4_Off (4U)
 *   Cx5_Reserved (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_PassSecRowRiSeatBackReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Fwd (1U)
 *   Cx2_Rwd (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_PassTSet: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Low (0U)
 *   Cx01_Low (1U)
 *   Cx02_Low (2U)
 *   Cx03_Low (3U)
 *   Cx04_Low (4U)
 *   Cx05_Low (5U)
 *   Cx06_Low (6U)
 *   Cx07_Low (7U)
 *   Cx08_Low (8U)
 *   Cx09_Low (9U)
 *   Cx0A_Low (10U)
 *   Cx0B_Low (11U)
 *   Cx0C_Low (12U)
 *   Cx0D_Low (13U)
 *   Cx0E_Low (14U)
 *   Cx0F_Low (15U)
 *   Cx10_Low (16U)
 *   Cx11_Low (17U)
 *   Cx12_Low (18U)
 *   Cx13_Low (19U)
 *   Cx14_Low (20U)
 *   Cx15_Low (21U)
 *   Cx16_Low (22U)
 *   Cx17_Low (23U)
 *   Cx18_Low (24U)
 *   Cx19_Low (25U)
 *   Cx1A_Low (26U)
 *   Cx1B_Low (27U)
 *   Cx1C_Low (28U)
 *   Cx1D_Low (29U)
 *   Cx1E_Low (30U)
 *   Cx1F_Low (31U)
 *   Cx20_Low (32U)
 *   Cx21_Low (33U)
 *   Cx22_Low (34U)
 *   Cx23_Low (35U)
 *   Cx24_18_32_ (36U)
 *   Cx25_18_32_ (37U)
 *   Cx26_18_32_ (38U)
 *   Cx27_18_32_ (39U)
 *   Cx28_18_32_ (40U)
 *   Cx29_18_32_ (41U)
 *   Cx2A_18_32_ (42U)
 *   Cx2B_18_32_ (43U)
 *   Cx2C_18_32_ (44U)
 *   Cx2D_18_32_ (45U)
 *   Cx2E_18_32_ (46U)
 *   Cx2F_18_32_ (47U)
 *   Cx30_18_32_ (48U)
 *   Cx31_18_32_ (49U)
 *   Cx32_18_32_ (50U)
 *   Cx33_18_32_ (51U)
 *   Cx34_18_32_ (52U)
 *   Cx35_18_32_ (53U)
 *   Cx36_18_32_ (54U)
 *   Cx37_18_32_ (55U)
 *   Cx38_18_32_ (56U)
 *   Cx39_18_32_ (57U)
 *   Cx3A_18_32_ (58U)
 *   Cx3B_18_32_ (59U)
 *   Cx3C_18_32_ (60U)
 *   Cx3D_18_32_ (61U)
 *   Cx3E_18_32_ (62U)
 *   Cx3F_18_32_ (63U)
 *   Cx40_18_32_ (64U)
 *   Cx41_High (65U)
 *   Cx42_High (66U)
 *   Cx43_High (67U)
 *   Cx44_High (68U)
 *   Cx45_High (69U)
 *   Cx46_High (70U)
 *   Cx47_High (71U)
 *   Cx48_High (72U)
 *   Cx49_High (73U)
 *   Cx4A_High (74U)
 *   Cx4B_High (75U)
 *   Cx4C_High (76U)
 *   Cx4D_High (77U)
 *   Cx4E_High (78U)
 *   Cx4F_High (79U)
 *   Cx50_High (80U)
 *   Cx51_High (81U)
 *   Cx52_High (82U)
 *   Cx53_High (83U)
 *   Cx54_High (84U)
 *   Cx55_High (85U)
 *   Cx56_High (86U)
 *   Cx57_High (87U)
 *   Cx58_High (88U)
 *   Cx59_High (89U)
 *   Cx5A_High (90U)
 *   Cx5B_High (91U)
 *   Cx5C_High (92U)
 *   Cx5D_High (93U)
 *   Cx5E_High (94U)
 *   Cx5F_High (95U)
 *   Cx60_High (96U)
 *   Cx61_High (97U)
 *   Cx62_High (98U)
 *   Cx63_High (99U)
 *   Cx64_High (100U)
 *   Cx65_High (101U)
 *   Cx66_High (102U)
 *   Cx67_High (103U)
 *   Cx68_High (104U)
 *   Cx69_High (105U)
 *   Cx6A_High (106U)
 *   Cx6B_High (107U)
 *   Cx6C_High (108U)
 *   Cx6D_High (109U)
 *   Cx6E_High (110U)
 *   Cx6F_High (111U)
 *   Cx70_High (112U)
 *   Cx71_High (113U)
 *   Cx72_High (114U)
 *   Cx73_High (115U)
 *   Cx74_High (116U)
 *   Cx75_High (117U)
 *   Cx76_High (118U)
 *   Cx77_High (119U)
 *   Cx78_High (120U)
 *   Cx79_High (121U)
 *   Cx7A_High (122U)
 *   Cx7B_High (123U)
 *   Cx7C_High (124U)
 *   Cx7D_High (125U)
 *   Cx7E_High (126U)
 *   Cx7F_High (127U)
 *   Cx80_High (128U)
 *   Cx81_High (129U)
 *   Cx82_High (130U)
 *   Cx83_High (131U)
 *   Cx84_High (132U)
 *   Cx85_High (133U)
 *   Cx86_High (134U)
 *   Cx87_High (135U)
 *   Cx88_High (136U)
 *   Cx89_High (137U)
 *   Cx8A_High (138U)
 *   Cx8B_High (139U)
 *   Cx8C_High (140U)
 *   Cx8D_High (141U)
 *   Cx8E_High (142U)
 *   Cx8F_High (143U)
 *   Cx90_High (144U)
 *   Cx91_High (145U)
 *   Cx92_High (146U)
 *   Cx93_High (147U)
 *   Cx94_High (148U)
 *   Cx95_High (149U)
 *   Cx96_High (150U)
 *   Cx97_High (151U)
 *   Cx98_High (152U)
 *   Cx99_High (153U)
 *   Cx9A_High (154U)
 *   Cx9B_High (155U)
 *   Cx9C_High (156U)
 *   Cx9D_High (157U)
 *   Cx9E_High (158U)
 *   Cx9F_High (159U)
 *   CxA0_High (160U)
 *   CxA1_High (161U)
 *   CxA2_High (162U)
 *   CxA3_High (163U)
 *   CxA4_High (164U)
 *   CxA5_High (165U)
 *   CxA6_High (166U)
 *   CxA7_High (167U)
 *   CxA8_High (168U)
 *   CxA9_High (169U)
 *   CxAA_High (170U)
 *   CxAB_High (171U)
 *   CxAC_High (172U)
 *   CxAD_High (173U)
 *   CxAE_High (174U)
 *   CxAF_High (175U)
 *   CxB0_High (176U)
 *   CxB1_High (177U)
 *   CxB2_High (178U)
 *   CxB3_High (179U)
 *   CxB4_High (180U)
 *   CxB5_High (181U)
 *   CxB6_High (182U)
 *   CxB7_High (183U)
 *   CxB8_High (184U)
 *   CxB9_High (185U)
 *   CxBA_High (186U)
 *   CxBB_High (187U)
 *   CxBC_High (188U)
 *   CxBD_High (189U)
 *   CxBE_High (190U)
 *   CxBF_High (191U)
 *   CxC0_High (192U)
 *   CxC1_High (193U)
 *   CxC2_High (194U)
 *   CxC3_High (195U)
 *   CxC4_High (196U)
 *   CxC5_High (197U)
 *   CxC6_High (198U)
 *   CxC7_High (199U)
 *   CxC8_High (200U)
 *   CxC9_High (201U)
 *   CxCA_High (202U)
 *   CxCB_High (203U)
 *   CxCC_High (204U)
 *   CxCD_High (205U)
 *   CxCE_High (206U)
 *   CxCF_High (207U)
 *   CxD0_High (208U)
 *   CxD1_High (209U)
 *   CxD2_High (210U)
 *   CxD3_High (211U)
 *   CxD4_High (212U)
 *   CxD5_High (213U)
 *   CxD6_High (214U)
 *   CxD7_High (215U)
 *   CxD8_High (216U)
 *   CxD9_High (217U)
 *   CxDA_High (218U)
 *   CxDB_High (219U)
 *   CxDC_High (220U)
 *   CxDD_High (221U)
 *   CxDE_High (222U)
 *   CxDF_High (223U)
 *   CxE0_High (224U)
 *   CxE1_High (225U)
 *   CxE2_High (226U)
 *   CxE3_High (227U)
 *   CxE4_High (228U)
 *   CxE5_High (229U)
 *   CxE6_High (230U)
 *   CxE7_High (231U)
 *   CxE8_High (232U)
 *   CxE9_High (233U)
 *   CxEA_High (234U)
 *   CxEB_High (235U)
 *   CxEC_High (236U)
 *   CxED_High (237U)
 *   CxEE_High (238U)
 *   CxEF_High (239U)
 *   CxF0_High (240U)
 *   CxF1_High (241U)
 *   CxF2_High (242U)
 *   CxF3_High (243U)
 *   CxF4_High (244U)
 *   CxF5_High (245U)
 *   CxF6_High (246U)
 *   CxF7_High (247U)
 *   CxF8_High (248U)
 *   CxF9_High (249U)
 *   CxFA_High (250U)
 *   CxFB_High (251U)
 *   CxFC_High (252U)
 *   CxFD_High (253U)
 *   CxFE_High (254U)
 *   CxFF_Invalid (255U)
 *   Factor: 0.5, Offset: 0
 * DtEHU_PauseKey: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_None (0U)
 *   Cx1_Not_Pressed (1U)
 *   Cx2_Pressed (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_PerpModChg: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Not_selected (0U)
 *   Cx1_Rear (1U)
 *   Cx2_Front (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_PollingFctOpenSts: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default (0U)
 *   Cx1_Inactive (1U)
 *   Cx2_Active (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_PosnLampCtrl: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Off_Not_used_ (0U)
 *   Cx1_On (1U)
 * DtEHU_PrkgSlotc: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_None (0U)
 *   Cx1_Left_Park_Slot_1 (1U)
 *   Cx2_Left_Park_Slot_2 (2U)
 *   Cx3_Left_Park_Slot_3 (3U)
 *   Cx4_Right_Park_Slot_1 (4U)
 *   Cx5_Right_Park_Slot_2 (5U)
 *   Cx6_Right_Park_Slot_3 (6U)
 *   Cx7_Reserved (7U)
 *   Cx8_Reserved (8U)
 *   Cx9_Reserved (9U)
 *   CxA_Reserved (10U)
 *   CxB_Reserved (11U)
 *   CxC_Reserved (12U)
 *   CxD_Reserved (13U)
 *   CxE_Reserved (14U)
 *   CxF_Reserved (15U)
 * DtEHU_RCTASwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_RCTBSwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_RCWSwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Fault (3U)
 * DtEHU_RDPSwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_RainClsdSunroofSet: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_ReDefrstOpenReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Enable (1U)
 *   Cx2_Disable (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_ReFogLampCtrl: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_ReMirrAutoFoldSet: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_ReWiprCtrl: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Off_Not_used_ (0U)
 *   Cx1_On (1U)
 * DtEHU_ReWshrCtrl: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Off_Not_used_ (0U)
 *   Cx1_On (1U)
 * DtEHU_RestoreDftSettings: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default (0U)
 *   Cx1_On (1U)
 *   Cx2_Off (2U)
 *   Cx3_Inhibit (3U)
 * DtEHU_ResuKey: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_None (0U)
 *   Cx1_Not_Pressed (1U)
 *   Cx2_Pressed (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_RiFrntWinCtrl: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Auto_Up (1U)
 *   Cx2_Manual_Up_reserved_ (2U)
 *   Cx3_Auto_Down (3U)
 *   Cx4_Manual_Down_Reserved_ (4U)
 *   Cx5_Reserved (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_RiMirrAlrmLampFlt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_Failure (0U)
 *   Cx1_Failure (1U)
 *   Cx2_Reserved (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_RiReWinCtrl: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Auto_Up (1U)
 *   Cx2_Manual_Up_reserved_ (2U)
 *   Cx3_Auto_Down (3U)
 *   Cx4_Manual_Down_Reserved_ (4U)
 *   Cx5_Reserved (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_RtnStrtKey: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_None (0U)
 *   Cx1_Not_Pressed (1U)
 *   Cx2_Pressed (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_SDWAudioReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default (0U)
 *   Cx1_Mute (1U)
 *   Cx2_Unmute (2U)
 *   Cx3_Inhibit (3U)
 * DtEHU_SLIFSwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Off (1U)
 *   Cx2_Display (2U)
 *   Cx3_Warning (3U)
 * DtEHU_SeatAntithftFctEnaReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Not_Change (0U)
 *   Cx1_Unactive (1U)
 *   Cx2_Active (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_SelKey: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_request (0U)
 *   Cx1_Off (1U)
 *   Cx2_On (2U)
 *   Cx3_Invalid (3U)
 * DtEHU_SetAtmLampBri: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Level_1 (0U)
 *   Cx1_Level_2 (1U)
 *   Cx2_Level_3 (2U)
 *   Cx3_Level_4 (3U)
 *   Cx4_Level_5 (4U)
 *   Cx5_Level_6 (5U)
 *   Cx6_Level_7 (6U)
 *   Cx7_Level_8 (7U)
 *   Cx8_Level_9 (8U)
 *   Cx9_Level_10 (9U)
 *   CxA_Reserved (10U)
 *   CxB_Reserved (11U)
 *   CxC_Reserved (12U)
 *   CxD_Reserved (13U)
 *   CxE_Reserved (14U)
 *   CxF_Reserved (15U)
 * DtEHU_ShowReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Not_request (0U)
 *   Cx1_Request_Open_AVM (1U)
 *   Cx2_Request_Close_AVM (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_ShowSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Not_show (0U)
 *   Cx1_Show (1U)
 * DtEHU_SngPedlSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_ (0U)
 *   Cx1_ (1U)
 * DtEHU_SrcSwt_HUD: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_From_ICC (0U)
 *   Cx1_From_HUD (1U)
 * DtEHU_SteerWhlVbrnAlrmReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_disable (0U)
 *   Cx1_AeUeenable (1U)
 * DtEHU_SunroofCtrlReq: Enumeration of integer in interval [0...7] with enumerators
 *   Cx0_No_Request (0U)
 *   Cx1_Tilt_Up_Request (1U)
 *   Cx2_Tilt_Close_Request (2U)
 *   Cx3_Slide_Open (3U)
 *   Cx4_Slide_Close (4U)
 *   Cx5_Halt (5U)
 *   Cx6_Reserved (6U)
 *   Cx7_Reserved (7U)
 * DtEHU_SunroofshadePercCtrlCmdReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Sunroof (0U)
 *   Cx1_Sunshade_ (1U)
 * DtEHU_SunshadeCtrlReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_Request_ (0U)
 *   Cx1_Sunshade_Open_Request_ (1U)
 *   Cx2_Sunshade_Close_Request_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_SurrndCtrl: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Stereo (0U)
 *   Cx1_Surround (1U)
 * DtEHU_TJAICASwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_TLASwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_TSRSwt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_Switch_Off_ (1U)
 *   Cx2_Switch_On_ (2U)
 *   Cx3_Fault (3U)
 * DtEHU_TouchEveTyp: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Not_touch (0U)
 *   Cx1_Pen_down (1U)
 *   Cx2_Pen_up (2U)
 *   Cx3_Pen_move (3U)
 * DtEHU_TouchXCoor: Enumeration of integer in interval [0...2047] with enumerators
 *   Cx7FF_Invalid (2047U)
 * DtEHU_TouchYCoor: Enumeration of integer in interval [0...1023] with enumerators
 *   Cx3FF_Invalid (1023U)
 * DtEHU_TrActnCmd: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_OpenRequest_Touchscreen_or_Voice_ (1U)
 *   Cx2_CloseRequest_Touchscreen_or_Voice_ (2U)
 *   Cx3_Halt (3U)
 * DtEHU_TrunkLockCtrl: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Close (0U)
 *   Cx1_Open (1U)
 * DtEHU_TypChgKey: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Not_selected (0U)
 *   Cx1_Automated (1U)
 *   Cx2_Remote (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_UsrSetChrgGunAntithft: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_ (0U)
 *   Cx1_ (1U)
 * DtEHU_VSCModReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Off (0U)
 *   Cx1_Low (1U)
 *   Cx2_Mid (2U)
 *   Cx3_High (3U)
 * DtEHU_VSPCtrlCmd: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_disable (0U)
 *   Cx1_AeUeenable (1U)
 * DtEHU_ViewReq: Enumeration of integer in interval [0...63] with enumerators
 *   Cx00_None (0U)
 *   Cx01_AVM_View1 (1U)
 *   Cx02_AVM_View2 (2U)
 *   Cx03_AVM_View3 (3U)
 *   Cx04_AVM_View4 (4U)
 *   Cx05_AVM_View5 (5U)
 *   Cx06_AVM_View6 (6U)
 *   Cx07_AVM_View7 (7U)
 *   Cx08_AVM_View8 (8U)
 *   Cx09_AVM_View9 (9U)
 *   Cx0A_AVM_View10 (10U)
 *   Cx0B_AVM_View11 (11U)
 *   Cx0C_AVM_View12 (12U)
 *   Cx0D_AVM_View13 (13U)
 *   Cx0E_AVM_View14 (14U)
 *   Cx0F_AVM_View15 (15U)
 *   Cx10_AVM_View16 (16U)
 *   Cx11_AVM_View17 (17U)
 *   Cx12_AVM_View18 (18U)
 *   Cx13_AVM_View19 (19U)
 *   Cx14_AVM_View20 (20U)
 *   Cx15_AVM_View21 (21U)
 *   Cx16_AVM_View22 (22U)
 *   Cx17_AVM_View23 (23U)
 *   Cx18_AVM_View24 (24U)
 *   Cx19_AVM_View25 (25U)
 *   Cx1A_Reserved (26U)
 *   Cx1B_Reserved (27U)
 *   Cx1C_Reserved (28U)
 *   Cx1D_Reserved (29U)
 *   Cx1E_Reserved (30U)
 *   Cx1F_Reserved (31U)
 * DtEHU_VoiceCtrlAirClnClsReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlAirClnOpenReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlAirVolSet: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_ (0U)
 *   Cx1_ (1U)
 *   Cx2_ (2U)
 *   Cx3_ (3U)
 *   Cx4_Ae_ (4U)
 *   Cx5_ (5U)
 *   Cx6_ (6U)
 *   Cx7_ss_ (7U)
 *   Cx8_Reserved (8U)
 *   Cx9_Reserved (9U)
 *   CxA_Reserved (10U)
 *   CxB_Reserved (11U)
 *   CxC_Reserved (12U)
 *   CxD_Reserved (13U)
 *   CxE_Reserved (14U)
 *   CxF_Reserved (15U)
 * DtEHU_VoiceCtrlAirVolTurnDwnReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlAirVolTurnUpReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlBlowFootDefrstReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlDrvrTSet: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Low (0U)
 *   Cx01_Low (1U)
 *   Cx02_Low (2U)
 *   Cx03_Low (3U)
 *   Cx04_Low (4U)
 *   Cx05_Low (5U)
 *   Cx06_Low (6U)
 *   Cx07_Low (7U)
 *   Cx08_Low (8U)
 *   Cx09_Low (9U)
 *   Cx0A_Low (10U)
 *   Cx0B_Low (11U)
 *   Cx0C_Low (12U)
 *   Cx0D_Low (13U)
 *   Cx0E_Low (14U)
 *   Cx0F_Low (15U)
 *   Cx10_Low (16U)
 *   Cx11_Low (17U)
 *   Cx12_Low (18U)
 *   Cx13_Low (19U)
 *   Cx14_Low (20U)
 *   Cx15_Low (21U)
 *   Cx16_Low (22U)
 *   Cx17_Low (23U)
 *   Cx18_Low (24U)
 *   Cx19_Low (25U)
 *   Cx1A_Low (26U)
 *   Cx1B_Low (27U)
 *   Cx1C_Low (28U)
 *   Cx1D_Low (29U)
 *   Cx1E_Low (30U)
 *   Cx1F_Low (31U)
 *   Cx20_Low (32U)
 *   Cx21_Low (33U)
 *   Cx22_Low (34U)
 *   Cx23_Low (35U)
 *   Cx24_18_32_ (36U)
 *   Cx25_18_32_ (37U)
 *   Cx26_18_32_ (38U)
 *   Cx27_18_32_ (39U)
 *   Cx28_18_32_ (40U)
 *   Cx29_18_32_ (41U)
 *   Cx2A_18_32_ (42U)
 *   Cx2B_18_32_ (43U)
 *   Cx2C_18_32_ (44U)
 *   Cx2D_18_32_ (45U)
 *   Cx2E_18_32_ (46U)
 *   Cx2F_18_32_ (47U)
 *   Cx30_18_32_ (48U)
 *   Cx31_18_32_ (49U)
 *   Cx32_18_32_ (50U)
 *   Cx33_18_32_ (51U)
 *   Cx34_18_32_ (52U)
 *   Cx35_18_32_ (53U)
 *   Cx36_18_32_ (54U)
 *   Cx37_18_32_ (55U)
 *   Cx38_18_32_ (56U)
 *   Cx39_18_32_ (57U)
 *   Cx3A_18_32_ (58U)
 *   Cx3B_18_32_ (59U)
 *   Cx3C_18_32_ (60U)
 *   Cx3D_18_32_ (61U)
 *   Cx3E_18_32_ (62U)
 *   Cx3F_18_32_ (63U)
 *   Cx40_18_32_ (64U)
 *   Cx41_High (65U)
 *   Cx42_High (66U)
 *   Cx43_High (67U)
 *   Cx44_High (68U)
 *   Cx45_High (69U)
 *   Cx46_High (70U)
 *   Cx47_High (71U)
 *   Cx48_High (72U)
 *   Cx49_High (73U)
 *   Cx4A_High (74U)
 *   Cx4B_High (75U)
 *   Cx4C_High (76U)
 *   Cx4D_High (77U)
 *   Cx4E_High (78U)
 *   Cx4F_High (79U)
 *   Cx50_High (80U)
 *   Cx51_High (81U)
 *   Cx52_High (82U)
 *   Cx53_High (83U)
 *   Cx54_High (84U)
 *   Cx55_High (85U)
 *   Cx56_High (86U)
 *   Cx57_High (87U)
 *   Cx58_High (88U)
 *   Cx59_High (89U)
 *   Cx5A_High (90U)
 *   Cx5B_High (91U)
 *   Cx5C_High (92U)
 *   Cx5D_High (93U)
 *   Cx5E_High (94U)
 *   Cx5F_High (95U)
 *   Cx60_High (96U)
 *   Cx61_High (97U)
 *   Cx62_High (98U)
 *   Cx63_High (99U)
 *   Cx64_High (100U)
 *   Cx65_High (101U)
 *   Cx66_High (102U)
 *   Cx67_High (103U)
 *   Cx68_High (104U)
 *   Cx69_High (105U)
 *   Cx6A_High (106U)
 *   Cx6B_High (107U)
 *   Cx6C_High (108U)
 *   Cx6D_High (109U)
 *   Cx6E_High (110U)
 *   Cx6F_High (111U)
 *   Cx70_High (112U)
 *   Cx71_High (113U)
 *   Cx72_High (114U)
 *   Cx73_High (115U)
 *   Cx74_High (116U)
 *   Cx75_High (117U)
 *   Cx76_High (118U)
 *   Cx77_High (119U)
 *   Cx78_High (120U)
 *   Cx79_High (121U)
 *   Cx7A_High (122U)
 *   Cx7B_High (123U)
 *   Cx7C_High (124U)
 *   Cx7D_High (125U)
 *   Cx7E_High (126U)
 *   Cx7F_High (127U)
 *   Cx80_High (128U)
 *   Cx81_High (129U)
 *   Cx82_High (130U)
 *   Cx83_High (131U)
 *   Cx84_High (132U)
 *   Cx85_High (133U)
 *   Cx86_High (134U)
 *   Cx87_High (135U)
 *   Cx88_High (136U)
 *   Cx89_High (137U)
 *   Cx8A_High (138U)
 *   Cx8B_High (139U)
 *   Cx8C_High (140U)
 *   Cx8D_High (141U)
 *   Cx8E_High (142U)
 *   Cx8F_High (143U)
 *   Cx90_High (144U)
 *   Cx91_High (145U)
 *   Cx92_High (146U)
 *   Cx93_High (147U)
 *   Cx94_High (148U)
 *   Cx95_High (149U)
 *   Cx96_High (150U)
 *   Cx97_High (151U)
 *   Cx98_High (152U)
 *   Cx99_High (153U)
 *   Cx9A_High (154U)
 *   Cx9B_High (155U)
 *   Cx9C_High (156U)
 *   Cx9D_High (157U)
 *   Cx9E_High (158U)
 *   Cx9F_High (159U)
 *   CxA0_High (160U)
 *   CxA1_High (161U)
 *   CxA2_High (162U)
 *   CxA3_High (163U)
 *   CxA4_High (164U)
 *   CxA5_High (165U)
 *   CxA6_High (166U)
 *   CxA7_High (167U)
 *   CxA8_High (168U)
 *   CxA9_High (169U)
 *   CxAA_High (170U)
 *   CxAB_High (171U)
 *   CxAC_High (172U)
 *   CxAD_High (173U)
 *   CxAE_High (174U)
 *   CxAF_High (175U)
 *   CxB0_High (176U)
 *   CxB1_High (177U)
 *   CxB2_High (178U)
 *   CxB3_High (179U)
 *   CxB4_High (180U)
 *   CxB5_High (181U)
 *   CxB6_High (182U)
 *   CxB7_High (183U)
 *   CxB8_High (184U)
 *   CxB9_High (185U)
 *   CxBA_High (186U)
 *   CxBB_High (187U)
 *   CxBC_High (188U)
 *   CxBD_High (189U)
 *   CxBE_High (190U)
 *   CxBF_High (191U)
 *   CxC0_High (192U)
 *   CxC1_High (193U)
 *   CxC2_High (194U)
 *   CxC3_High (195U)
 *   CxC4_High (196U)
 *   CxC5_High (197U)
 *   CxC6_High (198U)
 *   CxC7_High (199U)
 *   CxC8_High (200U)
 *   CxC9_High (201U)
 *   CxCA_High (202U)
 *   CxCB_High (203U)
 *   CxCC_High (204U)
 *   CxCD_High (205U)
 *   CxCE_High (206U)
 *   CxCF_High (207U)
 *   CxD0_High (208U)
 *   CxD1_High (209U)
 *   CxD2_High (210U)
 *   CxD3_High (211U)
 *   CxD4_High (212U)
 *   CxD5_High (213U)
 *   CxD6_High (214U)
 *   CxD7_High (215U)
 *   CxD8_High (216U)
 *   CxD9_High (217U)
 *   CxDA_High (218U)
 *   CxDB_High (219U)
 *   CxDC_High (220U)
 *   CxDD_High (221U)
 *   CxDE_High (222U)
 *   CxDF_High (223U)
 *   CxE0_High (224U)
 *   CxE1_High (225U)
 *   CxE2_High (226U)
 *   CxE3_High (227U)
 *   CxE4_High (228U)
 *   CxE5_High (229U)
 *   CxE6_High (230U)
 *   CxE7_High (231U)
 *   CxE8_High (232U)
 *   CxE9_High (233U)
 *   CxEA_High (234U)
 *   CxEB_High (235U)
 *   CxEC_High (236U)
 *   CxED_High (237U)
 *   CxEE_High (238U)
 *   CxEF_High (239U)
 *   CxF0_High (240U)
 *   CxF1_High (241U)
 *   CxF2_High (242U)
 *   CxF3_High (243U)
 *   CxF4_High (244U)
 *   CxF5_High (245U)
 *   CxF6_High (246U)
 *   CxF7_High (247U)
 *   CxF8_High (248U)
 *   CxF9_High (249U)
 *   CxFA_High (250U)
 *   CxFB_High (251U)
 *   CxFC_High (252U)
 *   CxFD_High (253U)
 *   CxFE_High (254U)
 *   CxFF_Invalid (255U)
 *   Factor: 0.5, Offset: 0
 * DtEHU_VoiceCtrlDrvrTTurnDwnReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlDrvrTTurnUpReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlECCAUTOReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlECCBlowFaceModReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlECCBlowFootModReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlECCBlowModReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlECCClsReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlECCDefrstModExitReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlECCDefrstModReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlECCExtCircReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlECCIntCircReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlECCOpenReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlEndFctClsReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlEndFctOpenReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlPassTSet: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Low (0U)
 *   Cx01_Low (1U)
 *   Cx02_Low (2U)
 *   Cx03_Low (3U)
 *   Cx04_Low (4U)
 *   Cx05_Low (5U)
 *   Cx06_Low (6U)
 *   Cx07_Low (7U)
 *   Cx08_Low (8U)
 *   Cx09_Low (9U)
 *   Cx0A_Low (10U)
 *   Cx0B_Low (11U)
 *   Cx0C_Low (12U)
 *   Cx0D_Low (13U)
 *   Cx0E_Low (14U)
 *   Cx0F_Low (15U)
 *   Cx10_Low (16U)
 *   Cx11_Low (17U)
 *   Cx12_Low (18U)
 *   Cx13_Low (19U)
 *   Cx14_Low (20U)
 *   Cx15_Low (21U)
 *   Cx16_Low (22U)
 *   Cx17_Low (23U)
 *   Cx18_Low (24U)
 *   Cx19_Low (25U)
 *   Cx1A_Low (26U)
 *   Cx1B_Low (27U)
 *   Cx1C_Low (28U)
 *   Cx1D_Low (29U)
 *   Cx1E_Low (30U)
 *   Cx1F_Low (31U)
 *   Cx20_Low (32U)
 *   Cx21_Low (33U)
 *   Cx22_Low (34U)
 *   Cx23_Low (35U)
 *   Cx24_18_32_ (36U)
 *   Cx25_18_32_ (37U)
 *   Cx26_18_32_ (38U)
 *   Cx27_18_32_ (39U)
 *   Cx28_18_32_ (40U)
 *   Cx29_18_32_ (41U)
 *   Cx2A_18_32_ (42U)
 *   Cx2B_18_32_ (43U)
 *   Cx2C_18_32_ (44U)
 *   Cx2D_18_32_ (45U)
 *   Cx2E_18_32_ (46U)
 *   Cx2F_18_32_ (47U)
 *   Cx30_18_32_ (48U)
 *   Cx31_18_32_ (49U)
 *   Cx32_18_32_ (50U)
 *   Cx33_18_32_ (51U)
 *   Cx34_18_32_ (52U)
 *   Cx35_18_32_ (53U)
 *   Cx36_18_32_ (54U)
 *   Cx37_18_32_ (55U)
 *   Cx38_18_32_ (56U)
 *   Cx39_18_32_ (57U)
 *   Cx3A_18_32_ (58U)
 *   Cx3B_18_32_ (59U)
 *   Cx3C_18_32_ (60U)
 *   Cx3D_18_32_ (61U)
 *   Cx3E_18_32_ (62U)
 *   Cx3F_18_32_ (63U)
 *   Cx40_18_32_ (64U)
 *   Cx41_High (65U)
 *   Cx42_High (66U)
 *   Cx43_High (67U)
 *   Cx44_High (68U)
 *   Cx45_High (69U)
 *   Cx46_High (70U)
 *   Cx47_High (71U)
 *   Cx48_High (72U)
 *   Cx49_High (73U)
 *   Cx4A_High (74U)
 *   Cx4B_High (75U)
 *   Cx4C_High (76U)
 *   Cx4D_High (77U)
 *   Cx4E_High (78U)
 *   Cx4F_High (79U)
 *   Cx50_High (80U)
 *   Cx51_High (81U)
 *   Cx52_High (82U)
 *   Cx53_High (83U)
 *   Cx54_High (84U)
 *   Cx55_High (85U)
 *   Cx56_High (86U)
 *   Cx57_High (87U)
 *   Cx58_High (88U)
 *   Cx59_High (89U)
 *   Cx5A_High (90U)
 *   Cx5B_High (91U)
 *   Cx5C_High (92U)
 *   Cx5D_High (93U)
 *   Cx5E_High (94U)
 *   Cx5F_High (95U)
 *   Cx60_High (96U)
 *   Cx61_High (97U)
 *   Cx62_High (98U)
 *   Cx63_High (99U)
 *   Cx64_High (100U)
 *   Cx65_High (101U)
 *   Cx66_High (102U)
 *   Cx67_High (103U)
 *   Cx68_High (104U)
 *   Cx69_High (105U)
 *   Cx6A_High (106U)
 *   Cx6B_High (107U)
 *   Cx6C_High (108U)
 *   Cx6D_High (109U)
 *   Cx6E_High (110U)
 *   Cx6F_High (111U)
 *   Cx70_High (112U)
 *   Cx71_High (113U)
 *   Cx72_High (114U)
 *   Cx73_High (115U)
 *   Cx74_High (116U)
 *   Cx75_High (117U)
 *   Cx76_High (118U)
 *   Cx77_High (119U)
 *   Cx78_High (120U)
 *   Cx79_High (121U)
 *   Cx7A_High (122U)
 *   Cx7B_High (123U)
 *   Cx7C_High (124U)
 *   Cx7D_High (125U)
 *   Cx7E_High (126U)
 *   Cx7F_High (127U)
 *   Cx80_High (128U)
 *   Cx81_High (129U)
 *   Cx82_High (130U)
 *   Cx83_High (131U)
 *   Cx84_High (132U)
 *   Cx85_High (133U)
 *   Cx86_High (134U)
 *   Cx87_High (135U)
 *   Cx88_High (136U)
 *   Cx89_High (137U)
 *   Cx8A_High (138U)
 *   Cx8B_High (139U)
 *   Cx8C_High (140U)
 *   Cx8D_High (141U)
 *   Cx8E_High (142U)
 *   Cx8F_High (143U)
 *   Cx90_High (144U)
 *   Cx91_High (145U)
 *   Cx92_High (146U)
 *   Cx93_High (147U)
 *   Cx94_High (148U)
 *   Cx95_High (149U)
 *   Cx96_High (150U)
 *   Cx97_High (151U)
 *   Cx98_High (152U)
 *   Cx99_High (153U)
 *   Cx9A_High (154U)
 *   Cx9B_High (155U)
 *   Cx9C_High (156U)
 *   Cx9D_High (157U)
 *   Cx9E_High (158U)
 *   Cx9F_High (159U)
 *   CxA0_High (160U)
 *   CxA1_High (161U)
 *   CxA2_High (162U)
 *   CxA3_High (163U)
 *   CxA4_High (164U)
 *   CxA5_High (165U)
 *   CxA6_High (166U)
 *   CxA7_High (167U)
 *   CxA8_High (168U)
 *   CxA9_High (169U)
 *   CxAA_High (170U)
 *   CxAB_High (171U)
 *   CxAC_High (172U)
 *   CxAD_High (173U)
 *   CxAE_High (174U)
 *   CxAF_High (175U)
 *   CxB0_High (176U)
 *   CxB1_High (177U)
 *   CxB2_High (178U)
 *   CxB3_High (179U)
 *   CxB4_High (180U)
 *   CxB5_High (181U)
 *   CxB6_High (182U)
 *   CxB7_High (183U)
 *   CxB8_High (184U)
 *   CxB9_High (185U)
 *   CxBA_High (186U)
 *   CxBB_High (187U)
 *   CxBC_High (188U)
 *   CxBD_High (189U)
 *   CxBE_High (190U)
 *   CxBF_High (191U)
 *   CxC0_High (192U)
 *   CxC1_High (193U)
 *   CxC2_High (194U)
 *   CxC3_High (195U)
 *   CxC4_High (196U)
 *   CxC5_High (197U)
 *   CxC6_High (198U)
 *   CxC7_High (199U)
 *   CxC8_High (200U)
 *   CxC9_High (201U)
 *   CxCA_High (202U)
 *   CxCB_High (203U)
 *   CxCC_High (204U)
 *   CxCD_High (205U)
 *   CxCE_High (206U)
 *   CxCF_High (207U)
 *   CxD0_High (208U)
 *   CxD1_High (209U)
 *   CxD2_High (210U)
 *   CxD3_High (211U)
 *   CxD4_High (212U)
 *   CxD5_High (213U)
 *   CxD6_High (214U)
 *   CxD7_High (215U)
 *   CxD8_High (216U)
 *   CxD9_High (217U)
 *   CxDA_High (218U)
 *   CxDB_High (219U)
 *   CxDC_High (220U)
 *   CxDD_High (221U)
 *   CxDE_High (222U)
 *   CxDF_High (223U)
 *   CxE0_High (224U)
 *   CxE1_High (225U)
 *   CxE2_High (226U)
 *   CxE3_High (227U)
 *   CxE4_High (228U)
 *   CxE5_High (229U)
 *   CxE6_High (230U)
 *   CxE7_High (231U)
 *   CxE8_High (232U)
 *   CxE9_High (233U)
 *   CxEA_High (234U)
 *   CxEB_High (235U)
 *   CxEC_High (236U)
 *   CxED_High (237U)
 *   CxEE_High (238U)
 *   CxEF_High (239U)
 *   CxF0_High (240U)
 *   CxF1_High (241U)
 *   CxF2_High (242U)
 *   CxF3_High (243U)
 *   CxF4_High (244U)
 *   CxF5_High (245U)
 *   CxF6_High (246U)
 *   CxF7_High (247U)
 *   CxF8_High (248U)
 *   CxF9_High (249U)
 *   CxFA_High (250U)
 *   CxFB_High (251U)
 *   CxFC_High (252U)
 *   CxFD_High (253U)
 *   CxFE_High (254U)
 *   CxFF_Invalid (255U)
 *   Factor: 0.5, Offset: 0
 * DtEHU_VoiceCtrlPassTTurnDwnReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlPassTTurnUpReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlRfgnModClsReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlRfgnModOpenReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlSYNCClsReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlSYNCOpenReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlTSet: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_Low (0U)
 *   Cx01_Low (1U)
 *   Cx02_Low (2U)
 *   Cx03_Low (3U)
 *   Cx04_Low (4U)
 *   Cx05_Low (5U)
 *   Cx06_Low (6U)
 *   Cx07_Low (7U)
 *   Cx08_Low (8U)
 *   Cx09_Low (9U)
 *   Cx0A_Low (10U)
 *   Cx0B_Low (11U)
 *   Cx0C_Low (12U)
 *   Cx0D_Low (13U)
 *   Cx0E_Low (14U)
 *   Cx0F_Low (15U)
 *   Cx10_Low (16U)
 *   Cx11_Low (17U)
 *   Cx12_Low (18U)
 *   Cx13_Low (19U)
 *   Cx14_Low (20U)
 *   Cx15_Low (21U)
 *   Cx16_Low (22U)
 *   Cx17_Low (23U)
 *   Cx18_Low (24U)
 *   Cx19_Low (25U)
 *   Cx1A_Low (26U)
 *   Cx1B_Low (27U)
 *   Cx1C_Low (28U)
 *   Cx1D_Low (29U)
 *   Cx1E_Low (30U)
 *   Cx1F_Low (31U)
 *   Cx20_Low (32U)
 *   Cx21_Low (33U)
 *   Cx22_Low (34U)
 *   Cx23_Low (35U)
 *   Cx24_18_32_ (36U)
 *   Cx25_18_32_ (37U)
 *   Cx26_18_32_ (38U)
 *   Cx27_18_32_ (39U)
 *   Cx28_18_32_ (40U)
 *   Cx29_18_32_ (41U)
 *   Cx2A_18_32_ (42U)
 *   Cx2B_18_32_ (43U)
 *   Cx2C_18_32_ (44U)
 *   Cx2D_18_32_ (45U)
 *   Cx2E_18_32_ (46U)
 *   Cx2F_18_32_ (47U)
 *   Cx30_18_32_ (48U)
 *   Cx31_18_32_ (49U)
 *   Cx32_18_32_ (50U)
 *   Cx33_18_32_ (51U)
 *   Cx34_18_32_ (52U)
 *   Cx35_18_32_ (53U)
 *   Cx36_18_32_ (54U)
 *   Cx37_18_32_ (55U)
 *   Cx38_18_32_ (56U)
 *   Cx39_18_32_ (57U)
 *   Cx3A_18_32_ (58U)
 *   Cx3B_18_32_ (59U)
 *   Cx3C_18_32_ (60U)
 *   Cx3D_18_32_ (61U)
 *   Cx3E_18_32_ (62U)
 *   Cx3F_18_32_ (63U)
 *   Cx40_18_32_ (64U)
 *   Cx41_High (65U)
 *   Cx42_High (66U)
 *   Cx43_High (67U)
 *   Cx44_High (68U)
 *   Cx45_High (69U)
 *   Cx46_High (70U)
 *   Cx47_High (71U)
 *   Cx48_High (72U)
 *   Cx49_High (73U)
 *   Cx4A_High (74U)
 *   Cx4B_High (75U)
 *   Cx4C_High (76U)
 *   Cx4D_High (77U)
 *   Cx4E_High (78U)
 *   Cx4F_High (79U)
 *   Cx50_High (80U)
 *   Cx51_High (81U)
 *   Cx52_High (82U)
 *   Cx53_High (83U)
 *   Cx54_High (84U)
 *   Cx55_High (85U)
 *   Cx56_High (86U)
 *   Cx57_High (87U)
 *   Cx58_High (88U)
 *   Cx59_High (89U)
 *   Cx5A_High (90U)
 *   Cx5B_High (91U)
 *   Cx5C_High (92U)
 *   Cx5D_High (93U)
 *   Cx5E_High (94U)
 *   Cx5F_High (95U)
 *   Cx60_High (96U)
 *   Cx61_High (97U)
 *   Cx62_High (98U)
 *   Cx63_High (99U)
 *   Cx64_High (100U)
 *   Cx65_High (101U)
 *   Cx66_High (102U)
 *   Cx67_High (103U)
 *   Cx68_High (104U)
 *   Cx69_High (105U)
 *   Cx6A_High (106U)
 *   Cx6B_High (107U)
 *   Cx6C_High (108U)
 *   Cx6D_High (109U)
 *   Cx6E_High (110U)
 *   Cx6F_High (111U)
 *   Cx70_High (112U)
 *   Cx71_High (113U)
 *   Cx72_High (114U)
 *   Cx73_High (115U)
 *   Cx74_High (116U)
 *   Cx75_High (117U)
 *   Cx76_High (118U)
 *   Cx77_High (119U)
 *   Cx78_High (120U)
 *   Cx79_High (121U)
 *   Cx7A_High (122U)
 *   Cx7B_High (123U)
 *   Cx7C_High (124U)
 *   Cx7D_High (125U)
 *   Cx7E_High (126U)
 *   Cx7F_High (127U)
 *   Cx80_High (128U)
 *   Cx81_High (129U)
 *   Cx82_High (130U)
 *   Cx83_High (131U)
 *   Cx84_High (132U)
 *   Cx85_High (133U)
 *   Cx86_High (134U)
 *   Cx87_High (135U)
 *   Cx88_High (136U)
 *   Cx89_High (137U)
 *   Cx8A_High (138U)
 *   Cx8B_High (139U)
 *   Cx8C_High (140U)
 *   Cx8D_High (141U)
 *   Cx8E_High (142U)
 *   Cx8F_High (143U)
 *   Cx90_High (144U)
 *   Cx91_High (145U)
 *   Cx92_High (146U)
 *   Cx93_High (147U)
 *   Cx94_High (148U)
 *   Cx95_High (149U)
 *   Cx96_High (150U)
 *   Cx97_High (151U)
 *   Cx98_High (152U)
 *   Cx99_High (153U)
 *   Cx9A_High (154U)
 *   Cx9B_High (155U)
 *   Cx9C_High (156U)
 *   Cx9D_High (157U)
 *   Cx9E_High (158U)
 *   Cx9F_High (159U)
 *   CxA0_High (160U)
 *   CxA1_High (161U)
 *   CxA2_High (162U)
 *   CxA3_High (163U)
 *   CxA4_High (164U)
 *   CxA5_High (165U)
 *   CxA6_High (166U)
 *   CxA7_High (167U)
 *   CxA8_High (168U)
 *   CxA9_High (169U)
 *   CxAA_High (170U)
 *   CxAB_High (171U)
 *   CxAC_High (172U)
 *   CxAD_High (173U)
 *   CxAE_High (174U)
 *   CxAF_High (175U)
 *   CxB0_High (176U)
 *   CxB1_High (177U)
 *   CxB2_High (178U)
 *   CxB3_High (179U)
 *   CxB4_High (180U)
 *   CxB5_High (181U)
 *   CxB6_High (182U)
 *   CxB7_High (183U)
 *   CxB8_High (184U)
 *   CxB9_High (185U)
 *   CxBA_High (186U)
 *   CxBB_High (187U)
 *   CxBC_High (188U)
 *   CxBD_High (189U)
 *   CxBE_High (190U)
 *   CxBF_High (191U)
 *   CxC0_High (192U)
 *   CxC1_High (193U)
 *   CxC2_High (194U)
 *   CxC3_High (195U)
 *   CxC4_High (196U)
 *   CxC5_High (197U)
 *   CxC6_High (198U)
 *   CxC7_High (199U)
 *   CxC8_High (200U)
 *   CxC9_High (201U)
 *   CxCA_High (202U)
 *   CxCB_High (203U)
 *   CxCC_High (204U)
 *   CxCD_High (205U)
 *   CxCE_High (206U)
 *   CxCF_High (207U)
 *   CxD0_High (208U)
 *   CxD1_High (209U)
 *   CxD2_High (210U)
 *   CxD3_High (211U)
 *   CxD4_High (212U)
 *   CxD5_High (213U)
 *   CxD6_High (214U)
 *   CxD7_High (215U)
 *   CxD8_High (216U)
 *   CxD9_High (217U)
 *   CxDA_High (218U)
 *   CxDB_High (219U)
 *   CxDC_High (220U)
 *   CxDD_High (221U)
 *   CxDE_High (222U)
 *   CxDF_High (223U)
 *   CxE0_High (224U)
 *   CxE1_High (225U)
 *   CxE2_High (226U)
 *   CxE3_High (227U)
 *   CxE4_High (228U)
 *   CxE5_High (229U)
 *   CxE6_High (230U)
 *   CxE7_High (231U)
 *   CxE8_High (232U)
 *   CxE9_High (233U)
 *   CxEA_High (234U)
 *   CxEB_High (235U)
 *   CxEC_High (236U)
 *   CxED_High (237U)
 *   CxEE_High (238U)
 *   CxEF_High (239U)
 *   CxF0_High (240U)
 *   CxF1_High (241U)
 *   CxF2_High (242U)
 *   CxF3_High (243U)
 *   CxF4_High (244U)
 *   CxF5_High (245U)
 *   CxF6_High (246U)
 *   CxF7_High (247U)
 *   CxF8_High (248U)
 *   CxF9_High (249U)
 *   CxFA_High (250U)
 *   CxFB_High (251U)
 *   CxFC_High (252U)
 *   CxFD_High (253U)
 *   CxFE_High (254U)
 *   CxFF_Invalid (255U)
 *   Factor: 0.5, Offset: 0
 * DtEHU_VoiceCtrlTTurnDwnReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_VoiceCtrlTTurnUpReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_WIFIAPAuthentMechanism: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Open (0U)
 *   Cx1_WPA (1U)
 *   Cx2_PSK (2U)
 *   Cx3_Reserved (3U)
 * DtEHU_WelLampOpenSet: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtEHU_WormSts: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_ (0U)
 *   Cx1_ (1U)
 * DtEHU_ZoomReq: Enumeration of integer in interval [0...15] with enumerators
 *   Cx0_Original_zoom_level (0U)
 *   Cx1_Zoom_level_1 (1U)
 *   Cx2_Zoom_level_2 (2U)
 *   Cx3_Zoom_level_3 (3U)
 *   Cx4_Zoom_level_4 (4U)
 *   Cx5_Zoom_level_5 (5U)
 *   Cx6_Zoom_level_6 (6U)
 *   Cx7_Zoom_level_7 (7U)
 *   Cx8_Reseverd (8U)
 *   Cx9_Reseverd (9U)
 *   CxA_Reseverd (10U)
 *   CxB_Reseverd (11U)
 *   CxC_Reseverd (12U)
 *   CxD_Reseverd (13U)
 *   CxE_Reseverd (14U)
 *   CxF_Reseverd (15U)
 * DtEHU_abdEnaReq: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Inactive (0U)
 *   Cx1_Active (1U)
 * DtICC_SeatWelFctEnaReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Not_Change (0U)
 *   Cx1_Unactive (1U)
 *   Cx2_Active (2U)
 *   Cx3_Reserved (3U)
 * DtICM_ACCTarVehSpd: Enumeration of integer in interval [0...255] with enumerators
 *   Cx00_km_h (0U)
 *   Cx01_km_h (1U)
 *   Cx02_km_h (2U)
 *   Cx03_km_h (3U)
 *   Cx04_km_h (4U)
 *   Cx05_km_h (5U)
 *   Cx06_km_h (6U)
 *   Cx07_km_h (7U)
 *   Cx08_km_h (8U)
 *   Cx09_km_h (9U)
 *   Cx0A_km_h (10U)
 *   Cx0B_km_h (11U)
 *   Cx0C_km_h (12U)
 *   Cx0D_km_h (13U)
 *   Cx0E_km_h (14U)
 *   Cx0F_km_h (15U)
 *   Cx10_km_h (16U)
 *   Cx11_km_h (17U)
 *   Cx12_km_h (18U)
 *   Cx13_km_h (19U)
 *   Cx14_km_h (20U)
 *   Cx15_km_h (21U)
 *   Cx16_km_h (22U)
 *   Cx17_km_h (23U)
 *   Cx18_km_h (24U)
 *   Cx19_km_h (25U)
 *   Cx1A_km_h (26U)
 *   Cx1B_km_h (27U)
 *   Cx1C_km_h (28U)
 *   Cx1D_km_h (29U)
 *   Cx1E_km_h (30U)
 *   Cx1F_km_h (31U)
 *   Cx20_km_h (32U)
 *   Cx21_km_h (33U)
 *   Cx22_km_h (34U)
 *   Cx23_km_h (35U)
 *   Cx24_km_h (36U)
 *   Cx25_km_h (37U)
 *   Cx26_km_h (38U)
 *   Cx27_km_h (39U)
 *   Cx28_km_h (40U)
 *   Cx29_km_h (41U)
 *   Cx2A_km_h (42U)
 *   Cx2B_km_h (43U)
 *   Cx2C_km_h (44U)
 *   Cx2D_km_h (45U)
 *   Cx2E_km_h (46U)
 *   Cx2F_km_h (47U)
 *   Cx30_km_h (48U)
 *   Cx31_km_h (49U)
 *   Cx32_km_h (50U)
 *   Cx33_km_h (51U)
 *   Cx34_km_h (52U)
 *   Cx35_km_h (53U)
 *   Cx36_km_h (54U)
 *   Cx37_km_h (55U)
 *   Cx38_km_h (56U)
 *   Cx39_km_h (57U)
 *   Cx3A_km_h (58U)
 *   Cx3B_km_h (59U)
 *   Cx3C_km_h (60U)
 *   Cx3D_km_h (61U)
 *   Cx3E_km_h (62U)
 *   Cx3F_km_h (63U)
 *   Cx40_km_h (64U)
 *   Cx41_km_h (65U)
 *   Cx42_km_h (66U)
 *   Cx43_km_h (67U)
 *   Cx44_km_h (68U)
 *   Cx45_km_h (69U)
 *   Cx46_km_h (70U)
 *   Cx47_km_h (71U)
 *   Cx48_km_h (72U)
 *   Cx49_km_h (73U)
 *   Cx4A_km_h (74U)
 *   Cx4B_km_h (75U)
 *   Cx4C_km_h (76U)
 *   Cx4D_km_h (77U)
 *   Cx4E_km_h (78U)
 *   Cx4F_km_h (79U)
 *   Cx50_km_h (80U)
 *   Cx51_km_h (81U)
 *   Cx52_km_h (82U)
 *   Cx53_km_h (83U)
 *   Cx54_km_h (84U)
 *   Cx55_km_h (85U)
 *   Cx56_km_h (86U)
 *   Cx57_km_h (87U)
 *   Cx58_km_h (88U)
 *   Cx59_km_h (89U)
 *   Cx5A_km_h (90U)
 *   Cx5B_km_h (91U)
 *   Cx5C_km_h (92U)
 *   Cx5D_km_h (93U)
 *   Cx5E_km_h (94U)
 *   Cx5F_km_h (95U)
 *   Cx60_km_h (96U)
 *   Cx61_km_h (97U)
 *   Cx62_km_h (98U)
 *   Cx63_km_h (99U)
 *   Cx64_km_h (100U)
 *   Cx65_km_h (101U)
 *   Cx66_km_h (102U)
 *   Cx67_km_h (103U)
 *   Cx68_km_h (104U)
 *   Cx69_km_h (105U)
 *   Cx6A_km_h (106U)
 *   Cx6B_km_h (107U)
 *   Cx6C_km_h (108U)
 *   Cx6D_km_h (109U)
 *   Cx6E_km_h (110U)
 *   Cx6F_km_h (111U)
 *   Cx70_km_h (112U)
 *   Cx71_km_h (113U)
 *   Cx72_km_h (114U)
 *   Cx73_km_h (115U)
 *   Cx74_km_h (116U)
 *   Cx75_km_h (117U)
 *   Cx76_km_h (118U)
 *   Cx77_km_h (119U)
 *   Cx78_km_h (120U)
 *   Cx79_km_h (121U)
 *   Cx7A_km_h (122U)
 *   Cx7B_km_h (123U)
 *   Cx7C_km_h (124U)
 *   Cx7D_km_h (125U)
 *   Cx7E_km_h (126U)
 *   Cx7F_km_h (127U)
 *   Cx80_km_h (128U)
 *   Cx81_km_h (129U)
 *   Cx82_km_h (130U)
 *   Cx83_km_h (131U)
 *   Cx84_km_h (132U)
 *   Cx85_km_h (133U)
 *   Cx86_km_h (134U)
 *   Cx87_km_h (135U)
 *   Cx88_km_h (136U)
 *   Cx89_km_h (137U)
 *   Cx8A_km_h (138U)
 *   Cx8B_km_h (139U)
 *   Cx8C_km_h (140U)
 *   Cx8D_km_h (141U)
 *   Cx8E_km_h (142U)
 *   Cx8F_km_h (143U)
 *   Cx90_km_h (144U)
 *   Cx91_km_h (145U)
 *   Cx92_km_h (146U)
 *   Cx93_km_h (147U)
 *   Cx94_km_h (148U)
 *   Cx95_km_h (149U)
 *   Cx96_km_h (150U)
 *   Cx97_km_h (151U)
 *   Cx98_km_h (152U)
 *   Cx99_km_h (153U)
 *   Cx9A_km_h (154U)
 *   Cx9B_km_h (155U)
 *   Cx9C_km_h (156U)
 *   Cx9D_km_h (157U)
 *   Cx9E_km_h (158U)
 *   Cx9F_km_h (159U)
 *   CxA0_km_h (160U)
 *   CxA1_km_h (161U)
 *   CxA2_km_h (162U)
 *   CxA3_km_h (163U)
 *   CxA4_km_h (164U)
 *   CxA5_km_h (165U)
 *   CxA6_km_h (166U)
 *   CxA7_km_h (167U)
 *   CxA8_km_h (168U)
 *   CxA9_km_h (169U)
 *   CxAA_km_h (170U)
 *   CxAB_km_h (171U)
 *   CxAC_km_h (172U)
 *   CxAD_km_h (173U)
 *   CxAE_km_h (174U)
 *   CxAF_km_h (175U)
 *   CxB0_km_h (176U)
 *   CxB1_km_h (177U)
 *   CxB2_km_h (178U)
 *   CxB3_km_h (179U)
 *   CxB4_km_h (180U)
 *   CxB5_km_h (181U)
 *   CxB6_km_h (182U)
 *   CxB7_km_h (183U)
 *   CxB8_km_h (184U)
 *   CxB9_km_h (185U)
 *   CxBA_km_h (186U)
 *   CxBB_km_h (187U)
 *   CxBC_km_h (188U)
 *   CxBD_km_h (189U)
 *   CxBE_km_h (190U)
 *   CxBF_km_h (191U)
 *   CxC0_km_h (192U)
 *   CxC1_km_h (193U)
 *   CxC2_km_h (194U)
 *   CxC3_km_h (195U)
 *   CxC4_km_h (196U)
 *   CxC5_km_h (197U)
 *   CxC6_km_h (198U)
 *   CxC7_km_h (199U)
 *   CxC8_km_h (200U)
 *   CxC9_km_h (201U)
 *   CxCA_km_h (202U)
 *   CxCB_km_h (203U)
 *   CxCC_km_h (204U)
 *   CxCD_km_h (205U)
 *   CxCE_km_h (206U)
 *   CxCF_km_h (207U)
 *   CxD0_km_h (208U)
 *   CxD1_km_h (209U)
 *   CxD2_km_h (210U)
 *   CxD3_km_h (211U)
 *   CxD4_km_h (212U)
 *   CxD5_km_h (213U)
 *   CxD6_km_h (214U)
 *   CxD7_km_h (215U)
 *   CxD8_km_h (216U)
 *   CxD9_km_h (217U)
 *   CxDA_km_h (218U)
 *   CxDB_km_h (219U)
 *   CxDC_km_h (220U)
 *   CxDD_km_h (221U)
 *   CxDE_km_h (222U)
 *   CxDF_km_h (223U)
 *   CxE0_km_h (224U)
 *   CxE1_km_h (225U)
 *   CxE2_km_h (226U)
 *   CxE3_km_h (227U)
 *   CxE4_km_h (228U)
 *   CxE5_km_h (229U)
 *   CxE6_km_h (230U)
 *   CxE7_km_h (231U)
 *   CxE8_km_h (232U)
 *   CxE9_km_h (233U)
 *   CxEA_km_h (234U)
 *   CxEB_km_h (235U)
 *   CxEC_km_h (236U)
 *   CxED_km_h (237U)
 *   CxEE_km_h (238U)
 *   CxEF_km_h (239U)
 *   CxF0_km_h (240U)
 *   CxF1_km_h (241U)
 *   CxF2_km_h (242U)
 *   CxF3_km_h (243U)
 *   CxF4_km_h (244U)
 *   CxF5_km_h (245U)
 *   CxF6_km_h (246U)
 *   CxF7_km_h (247U)
 *   CxF8_km_h (248U)
 *   CxF9_km_h (249U)
 *   CxFA_km_h (250U)
 *   CxFB_km_h (251U)
 *   CxFC_km_h (252U)
 *   CxFD_km_h (253U)
 *   CxFE_km_h (254U)
 *   CxFF_ (255U)
 * DtICM_ADASSigFlt: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_No_Failure (0U)
 *   Cx1_Reversible_Failure (1U)
 *   Cx2_Irrversible_Failure (2U)
 *   Cx3_Reserved (3U)
 * DtICM_DispFlt: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_No_Error_ (0U)
 *   Cx1_Error_ (1U)
 * DtICM_DispVehSpdUnit: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_KMH (0U)
 *   Cx1_MPH (1U)
 * DtICM_LDWAlrmTypReq: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Default_Oe_ (0U)
 *   Cx1_ (1U)
 *   Cx2_ (2U)
 *   Cx3_Reserved (3U)
 * DtICM_MilgDataVld_ODO: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Value_OK (0U)
 *   Cx1_Value_Unreliable (1U)
 * DtICM_MilgRstCntr_ODO: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_ (0U)
 *   Cx1_1_ (1U)
 *   Cx2_2_ (2U)
 *   Cx3_3_ (3U)
 * DtICM_TotMilgVld_ODO: Enumeration of integer in interval [0...1] with enumerators
 *   Cx0_Value_OK (0U)
 *   Cx1_Value_Unreliable (1U)
 * DtICM_VehFlameoutTiVld: Enumeration of integer in interval [0...3] with enumerators
 *   Cx0_Initializing (0U)
 *   Cx1_Valid (1U)
 *   Cx2_Invalid (2U)
 *   Cx3_Reserved (3U)
 * IpcS_InfoDataRef: Enumeration of integer in interval [0...255] with enumerators
 *   IpcS_InitValue (0U)
 *   IpcS_Connected (1U)
 *   IpcS_ClientConnected (2U)
 *   IpcS_XOFF (3U)
 *   IpcS_XON (4U)
 *   IpcS_RxDataEmpty (5U)
 *   IpcS_RxDataAvailable (6U)
 *   IpcS_TxPending (7U)
 *   IpcS_TxCompleted (8U)
 *   IpcS_Error (9U)
 * IpcS_InfoTypeRef: Enumeration of integer in interval [0...255] with enumerators
 *   IpcS_FlowControlState (0U)
 *   IpcS_ConnectState (1U)
 *   IpcS_RxIndication (2U)
 *   IpcS_TxConfirmation (3U)
 *   IpcS_ErrorType (4U)
 * MM_PoolIdRef: Enumeration of integer in interval [0...255] with enumerators
 *   MM_POOL_ONOFF (24U)
 *   MM_POOL_CAN (29U)
 *   MM_POOL_ENV (26U)
 *   MM_POOL_SWDL (26U)
 *   MM_POOL_IPC0 (27U)
 *   MM_POOL_IPC2 (28U)
 *   MM_POOL_RTC (32U)
 *   MM_POOL_CANCLU (30U)
 *   MM_POOL_ONOFF_CLUSTER (25U)
 *   MM_POOL_VPIC_GAUG (37U)
 *   MM_POOL_VPIC_SWC (39U)
 *   MM_POOL_AUDIO (34U)
 *   MM_POOL_SFTT (33U)
 *   MM_POOL_VPIC_WARN (35U)
 *   MM_POOL_VPIC_TTLE (36U)
 *   MM_POOL_VPIC_DINF (38U)
 *   MM_POOL_IVI_Audio (42U)
 *   MM_POOL_Tuner_SWC (41U)
 *   MM_POOL_VPIC_RTC (40U)
 *   MM_POOL_DIAG (31U)
 *   MM_POOL_VPIC_BOOTCONTROL (44U)
 *   MM_POOL_VPIC_SETN (45U)
 *   MM_POOL_NAV (47U)
 *   MM_POOL_VPIC_ADAS (48U)
 *
 * Array Types:
 * ============
 * DtICC_BluetoothMACwifi: Array with 8 element(s) of type uint8
 *
 * Record Types:
 * =============
 * IpcS_ChannelState_st: Record with elements
 *   IpcS_ChannelNo of type uint8
 *   IpcS_InfoType of type IpcS_InfoTypeRef
 *   IpcS_InfoData of type IpcS_InfoDataRef
 *
 *********************************************************************************************************************/


#define CanApplication_START_SEC_CODE
#include "CanApplication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_AVL_P_TYR_FLH
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_AVL_P_TYR_FLH_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_AVL_P_TYR_FLH(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_AVL_P_TYR_FLH
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_AVL_P_TYR_FRH
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_AVL_P_TYR_FRH_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_AVL_P_TYR_FRH(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_AVL_P_TYR_FRH
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_AVL_P_TYR_RLH
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_AVL_P_TYR_RLH_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_AVL_P_TYR_RLH(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_AVL_P_TYR_RLH
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_AVL_P_TYR_RRH
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_AVL_P_TYR_RRH_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_AVL_P_TYR_RRH(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_AVL_P_TYR_RRH
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_Bedienung_Bc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_Bedienung_Bc_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_Bedienung_Bc(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_Bedienung_Bc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_CanRx2Ipc
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_CanRx2Ipc_doc
 *********************************************************************************************************************/

/*******************************************************************************
Name            : CANApp_WriteDataToIpc
Syntax          : None
Parameters(in)  : None
Parameters(out) : None
Returns value   : None
Description     :
Call by         :
History
<No.>   <author>    <time>      <description>
1       KENW        20190227    Primiry edition.
|******************************************************************************/  
static TeCANApp_e_WriteDataToIpcRet CANApp_WriteDataToIpc(uint8* Lp_dw_Data, uint8 Le_u_DataLen)
{
    UINT8* Lp_dw_IpcMemory = CeCANApp_u_PtrNULL;
    sint16 Le_sw_IpcWriteRet = RTE_E_If_IpcSWrite_IPCS_OK;
    TeCANApp_e_WriteDataToIpcRet Le_u_Ret = CeCANApp_e_VariableInit;
    uint8 Le_u_Index = 0u;
  
    if((CeCANApp_u_TRUE == SeCANApp_u_IpcChanlConnectSta_IVICan )&&(CeCANApp_u_TRUE == SeCANApp_u_IpcChanlFlowCntrlSta_IVICan))
	{
		Rte_Call_rp_CanApplication_mmGetMemory_mmGetMemory(CeCANApp_u_IpcMemoryPoolID_IVICan, (uint8*)(&Lp_dw_IpcMemory), Le_u_DataLen); 
        
		if (CeCANApp_u_PtrNULL != Lp_dw_IpcMemory)
		{
		    for(Le_u_Index = 0u; Le_u_Index < Le_u_DataLen; Le_u_Index++)
		    {
                *(Lp_dw_IpcMemory + Le_u_Index) = *(Lp_dw_Data + Le_u_Index);
		    }				 
			 
			Le_sw_IpcWriteRet = Rte_Call_rp_CanApplication_IpcSWrite_ipcWrite(CeCANApp_u_IpcChanlNum_IVICan,\
                                                                        (uint8*)Lp_dw_IpcMemory, Le_u_DataLen);
            
			if (RTE_E_If_IpcSWrite_IPCS_OK != Le_sw_IpcWriteRet)
			{
				Rte_Call_rp_CanApplication_mmFreeMemory_mmFreeMemory((uint8*)Lp_dw_IpcMemory);
                
                Le_u_Ret = CeCANApp_e_IpcWriteFail;
			}
			else
			{
                Le_u_Ret = CeCANApp_e_IpcWriteSuccess;
			}
		}
		else
		{
	        Le_u_Ret = CeCANApp_e_MemoryPtrNULL;
		}
	}
	else
	{
        Le_u_Ret = CeCANApp_e_IpcChannelStaException;
	} 

    return Le_u_Ret;
      
}  
/*******************************************************************************
Name            : CANApp_WriteDataToIpcHandler
Syntax          : None
Parameters(in)  : None
Parameters(out) : None
Returns value   : None
Description     :
Call by         :
History
<No.>   <author>    <time>      <description>
1       KENW        20190228    Primiry edition.
|******************************************************************************/  
static void CANApp_WriteDataToIpcHandler(TsCANApp_h_IpcWrite * Lp_w_IpcWriteData)
{
    TeCANApp_e_WriteDataToIpcRet Le_u_FuncRet_CANApp_WriteDataToIpc = CeCANApp_e_VariableInit;
    uint8 Le_u_RetryCnt = CeCANApp_u_IpcWriteDataHandler_RetryCntMax;

    do
    {
        Le_u_FuncRet_CANApp_WriteDataToIpc =\
                    CANApp_WriteDataToIpc((uint8*)(&(Lp_w_IpcWriteData->e_h_IpcData_RxCan)),Lp_w_IpcWriteData->e_u_IpcDataLen);

        Le_u_RetryCnt--;

        if(CeCANApp_e_IpcWriteSuccess == Le_u_FuncRet_CANApp_WriteDataToIpc)
        {
            break;
        }
        else
        {
            /*do nothing*/
        }
        
    }while(Le_u_RetryCnt > 0u);

    if(0u == Le_u_RetryCnt)
    {
        /* send fail,do nothing currently*/
    }
    else
    {
        /* send success */
    }
    
}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_CanRx2Ipc(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_CanRx2Ipc
 *********************************************************************************************************************/
    TsCANApp_h_IpcWrite Ls_h_IpcWriteData;
    uint16 Le_w_PduID = 0u;
    uint8 Le_u_Index = 0u;

    Ls_h_IpcWriteData.e_h_IpcData_RxCan.CanMsgHeader = CeCANApp_u_CanMsgHeader_IVICan;
    Ls_h_IpcWriteData.e_h_IpcData_RxCan.CanStatus = CeCANApp_u_CanStatus_IVICan;
    Ls_h_IpcWriteData.e_h_IpcData_RxCan.Bus_Id = CeCANApp_u_BusID__IVICan;
    Ls_h_IpcWriteData.e_h_IpcData_RxCan.CanMsgCounter = CeCANApp_u_CanMsgCounter_IVICan;
   

    for(Le_w_PduID = 0u; Le_w_PduID < TOTAL_PDUS; Le_w_PduID++)
    {
        if((CeCANApp_s_IpcData_RxCan_NotInRam != RAM_INDEX(Le_w_PduID))&&(CeCANApp_u_TRUE == getSendPDUFlag(Le_w_PduID)))
        {
            Ls_h_IpcWriteData.e_h_IpcData_RxCan.CanDLC = PDU_DLC(Le_w_PduID);
             
            Ls_h_IpcWriteData.e_u_IpcDataLen = PDU_DLC(Le_w_PduID) + CeCANApp_u_IpcWriteDataStruct_FixedHeaderLen;

            Ls_h_IpcWriteData.e_h_IpcData_RxCan.CanID_PduIndex = CtCANApp_w_RxCanIDTab[Le_w_PduID];
            
            for(Le_u_Index = 0u; Le_u_Index < PDU_DLC(Le_w_PduID); Le_u_Index++)
            {
                Ls_h_IpcWriteData.e_h_IpcData_RxCan.CanData[Le_u_Index] = PDU_Ram_Buffer[RAM_INDEX(Le_w_PduID)+Le_u_Index];
            }  

            CANApp_WriteDataToIpcHandler(&Ls_h_IpcWriteData);
            
            clearSendPDUFlag(Le_w_PduID);
        }
        else
        {
            /*do nothing*/
        }
    }
    
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_CoolantTemp
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_CoolantTemp_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_CoolantTemp(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_CoolantTemp
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_Cyclic10ms
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rp_CanApplication_IpcSNotifyClient_IpcSChannelInfo(IpcS_ChannelState_st *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rp_CanApplication_IpcSMemFree_ipcSMemFree(uint8 uChannel, uint8 *pData)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CanApplication_IpcSRead_ipcRead(uint8 uChannel, uint8 *pData, sint16 *wLength, uint16 *msgs)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CanApplication_IpcSWrite_ipcWrite(uint8 uChannel, uint8 *pData, uint16 wLength)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_If_IpcSWrite_IPCS_ERROR_NO_MEMORY, RTE_E_If_IpcSWrite_IPCS_ERROR_QUEUE_FULL, RTE_E_If_IpcSWrite_IPCS_INVALID_PARAM, RTE_E_If_IpcSWrite_IPCS_OK, RTE_E_If_IpcSWrite_IPCS_OK_BUT_QUEUE_FULL, RTE_E_If_IpcSWrite_IPCS_RES
 *   Std_ReturnType Rte_Call_rp_CanApplication_mmFreeMemory_mmFreeMemory(uint8 *pMem)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CanApplication_mmGetMemory_mmGetMemory(MM_PoolIdRef PoolId, uint8 *pMem, uint32 Size)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_rp_CanApplication_mmRegisterTaskAtPool_mmRegisterTaskAtPool(MM_PoolIdRef PoolId)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_Cyclic10ms_doc
 *********************************************************************************************************************/


uint16 SeCA_u_TestCnt1 = 0u;



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_Cyclic10ms(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_Cyclic10ms
 *********************************************************************************************************************/
 
 #if 0u
    uint8 *Le_p_data = NULL;
    sint16 ret;
    //uint8 Le_u_index;
	
	SeCA_u_TestCnt1++;
 
    if(SeCA_u_TestCnt1 > 20u)
	{
		SeCA_u_TestCnt1 = 0u;
 
		if (TRUE == SeCANApp_u_IpcChanlConnectSta_IVICan )  //&& (TRUE == DIAG_IPC_ChanFlowCntrlState))
		{
			Rte_Call_rp_CanApplication_mmGetMemory_mmGetMemory(MM_POOL_CAN, (uint8*)&Le_p_data, 5u);
		
			if (NULL != Le_p_data)
			{
			  
				*(Le_p_data + 0u) = 0x22;
				*(Le_p_data + 1u) = 0xFD;
				*(Le_p_data + 2u) = 0x04;
				*(Le_p_data + 3u) = 0x00;
				*(Le_p_data + 4u) = 0x01;		
				 
				 
				ret = Rte_Call_rp_CanApplication_IpcSWrite_ipcWrite(CeCANApp_u_IpcChanlNum_IVICan, (uint8*)Le_p_data, 5u);
		
				if (RTE_E_If_IpcSWrite_IPCS_OK != ret)
				{
					Rte_Call_rp_CanApplication_mmFreeMemory_mmFreeMemory((uint8*)Le_p_data);
				}
				else
				{
					/*
					SeAMEdiag_u_TxCNT = 0u;
					SeAMEDiag_u_FlagTx = SeAMEdiag_FD04SendRequeatToSOC_Success;
					*/
				}
			}
			else
			{
		
			}
		}
		else
		{
			/*void*/
		}  
	}
	
#endif

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_DAY_GPS_CAN_Ind
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_DAY_GPS_CAN_Ind_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_DAY_GPS_CAN_Ind(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_DAY_GPS_CAN_Ind
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_DSW_DRD
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_DSW_DRD_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_DSW_DRD(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_DSW_DRD
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_DSW_DVDR
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_DSW_DVDR_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_DSW_DVDR(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_DSW_DVDR
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_DSW_PSD
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_DSW_PSD_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_DSW_PSD(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_DSW_PSD
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_DSW_PSDR
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_DSW_PSDR_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_DSW_PSDR(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_DSW_PSDR
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_EngineSpeed
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_EngineSpeed_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_EngineSpeed(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_EngineSpeed
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_Fuel
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_Fuel_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_Fuel(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_Fuel
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_GearStatus
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_GearStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_GearStatus(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_GearStatus
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_HR_GPS_CAN_Ind
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_HR_GPS_CAN_Ind_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_HR_GPS_CAN_Ind(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_HR_GPS_CAN_Ind
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rp_CanApplication_mmRegisterTaskAtPool_mmRegisterTaskAtPool(MM_PoolIdRef PoolId)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_Init(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_Init
 *********************************************************************************************************************/

 Rte_Call_rp_CanApplication_mmRegisterTaskAtPool_mmRegisterTaskAtPool(MM_POOL_CAN);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_IpcS_Notify
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <IpcSChannelInfo> of PortPrototype <rp_CanApplication_IpcSNotifyClient>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_rp_CanApplication_IpcSNotifyClient_IpcSChannelInfo(IpcS_ChannelState_st *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_336_Checksum_DeEHU_336_Checksum(DtEHU_336_Checksum data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_3DCrs_DeEHU_3DCrs(DtEHU_3DCrs data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ACCSwt_DeEHU_ACCSwt(DtEHU_ACCSwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ACSwtReq_DeEHU_ACSwtReq(DtEHU_ACSwtReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ADASCtrlSet_DeEHU_ADASCtrlSet(DtEHU_ADASCtrlSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ADASSnvtySet_DeEHU_ADASSnvtySet(DtEHU_ADASSnvtySet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_AEBSwt_DeEHU_AEBSwt(DtEHU_AEBSwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ALMColorAdjSig_DeEHU_ALMColorAdjSig(DtEHU_ALMColorAdjSig data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ALMCstmSetColorB_DeEHU_ALMCstmSetColorB(DtEHU_ALMCstmSetColorB data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ALMCstmSetColorG_DeEHU_ALMCstmSetColorG(DtEHU_ALMCstmSetColorG data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ALMCstmSetColorR_DeEHU_ALMCstmSetColorR(DtEHU_ALMCstmSetColorR data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_AVMMod_DeEHU_AVMMod(DtEHU_AVMMod data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_AdpvHiBeamMod_DeEHU_AdpvHiBeamMod(DtEHU_AdpvHiBeamMod data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_AdpvHiBeamSwt_DeEHU_AdpvHiBeamSwt(DtEHU_AdpvHiBeamSwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_AirClnSwtReq_DeEHU_AirClnSwtReq(DtEHU_AirClnSwtReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_AirVolSet_DeEHU_AirVolSet(DtEHU_AirVolSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ArmedClsdWinSet_DeEHU_ArmedClsdWinSet(DtEHU_ArmedClsdWinSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_AtmLampOpenCmd_DeEHU_AtmLampOpenCmd(DtEHU_AtmLampOpenCmd data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_AutBrkgActvReq_DeEHU_AutBrkgActvReq(DtEHU_AutBrkgActvReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_AutCam_DeEHU_AutCam(DtEHU_AutCam data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_BSDLCASwt_DeEHU_BSDLCASwt(DtEHU_BSDLCASwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_BackgndBriLvl_DeEHU_BackgndBriLvl(DtEHU_BackgndBriLvl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_BeepSrcSet_DeEHU_BeepSrcSet(DtEHU_BeepSrcSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_BeepVolSet_DeEHU_BeepVolSet(DtEHU_BeepVolSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_BlowFaceReq_DeEHU_BlowFaceReq(DtEHU_BlowFaceReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_BlowFootReq_DeEHU_BlowFootReq(DtEHU_BlowFootReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_BluetoothWifiKeyPay_DeEHU_BluetoothWifiKeyPay(DtEHU_BluetoothWifiKeyPay data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_BluetoothWifiKeyPaySucFlg_DeEHU_BluetoothWifiKeyPaySucFlg(DtEHU_BluetoothWifiKeyPaySucFlg data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_BriAdj_HUD_DeEHU_BriAdj_HUD(DtEHU_BriAdj_HUD data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_BriAutoAdjEna_HUD_DeEHU_BriAutoAdjEna_HUD(DtEHU_BriAutoAdjEna_HUD data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_BrkMod_DeEHU_BrkMod(DtEHU_BrkMod data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_CentrLockCtrl_DeEHU_CentrLockCtrl(DtEHU_CentrLockCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_CfmResmKey_DeEHU_CfmResmKey(DtEHU_CfmResmKey data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_CnclKey_DeEHU_CnclKey(DtEHU_CnclKey data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_CnclTiChrgSetFlg_DeEHU_CnclTiChrgSetFlg(DtEHU_CnclTiChrgSetFlg data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_CtrlSts_NFC_DeEHU_CtrlSts_NFC(DtEHU_CtrlSts_NFC data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_CtrlSts_PWC_DeEHU_CtrlSts_PWC(DtEHU_CtrlSts_PWC data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DEgyRecovLvl_DeEHU_DEgyRecovLvl(DtEHU_DEgyRecovLvl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DOWSwt_DeEHU_DOWSwt(DtEHU_DOWSwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DchaBtnAvlFlg_DeEHU_DchaBtnAvlFlg(DtEHU_DchaBtnAvlFlg data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DefrstReq_DeEHU_DefrstReq(DtEHU_DefrstReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DoubleFlashCtrl_DeEHU_DoubleFlashCtrl(DtEHU_DoubleFlashCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DrvAntithiefEnaCmd_DeEHU_DrvAntithiefEnaCmd(DtEHU_DrvAntithiefEnaCmd data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DrvrEyesPosn_DeEHU_DrvrEyesPosn(DtEHU_DrvrEyesPosn data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DrvrGender_DeEHU_DrvrGender(DtEHU_DrvrGender data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DrvrHei_DeEHU_DrvrHei(DtEHU_DrvrHei data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DrvrHeiManReq_DeEHU_DrvrHeiManReq(DtEHU_DrvrHeiManReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DrvrID_DeEHU_DrvrID(DtEHU_DrvrID data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DrvrOccpy_DeEHU_DrvrOccpy(DtEHU_DrvrOccpy data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DrvrSYNCReq_DeEHU_DrvrSYNCReq(DtEHU_DrvrSYNCReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DrvrSeatBackManReq_DeEHU_DrvrSeatBackManReq(DtEHU_DrvrSeatBackManReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DrvrSeatHeatgReq_DeEHU_DrvrSeatHeatgReq(DtEHU_DrvrSeatHeatgReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DrvrSeatTiltManReq_DeEHU_DrvrSeatTiltManReq(DtEHU_DrvrSeatTiltManReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DrvrSeatTrackManReq_DeEHU_DrvrSeatTrackManReq(DtEHU_DrvrSeatTrackManReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DrvrSeatVentnReq_DeEHU_DrvrSeatVentnReq(DtEHU_DrvrSeatVentnReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DrvrSecRowSeatBackManReq_DeEHU_DrvrSecRowSeatBackManReq(DtEHU_DrvrSecRowSeatBackManReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DrvrTSet_DeEHU_DrvrTSet(DtEHU_DrvrTSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_DrvrWght_DeEHU_DrvrWght(DtEHU_DrvrWght data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ECCAUTOReq_DeEHU_ECCAUTOReq(DtEHU_ECCAUTOReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ECCIntExtCircReq_DeEHU_ECCIntExtCircReq(DtEHU_ECCIntExtCircReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ECCOffOnReq_DeEHU_ECCOffOnReq(DtEHU_ECCOffOnReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ELKSwt_DeEHU_ELKSwt(DtEHU_ELKSwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ESPSwtSig_DeEHU_ESPSwtSig(DtEHU_ESPSwtSig data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ESSSwt_DeEHU_ESSSwt(DtEHU_ESSSwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ElecFctEnaSet_PLG_DeEHU_ElecFctEnaSet_PLG(DtEHU_ElecFctEnaSet_PLG data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_EmgyCallSet_DeEHU_EmgyCallSet(DtEHU_EmgyCallSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_EndFctSwtReq_DeEHU_EndFctSwtReq(DtEHU_EndFctSwtReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ExtremeColdModReq_DeEHU_ExtremeColdModReq(DtEHU_ExtremeColdModReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_FCTASwt_DeEHU_FCTASwt(DtEHU_FCTASwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_FCTBSwt_DeEHU_FCTBSwt(DtEHU_FCTBSwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_FCWSwt_DeEHU_FCWSwt(DtEHU_FCWSwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_FacialRcntn_DeEHU_FacialRcntn(DtEHU_FacialRcntn data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_FaderSet_DeEHU_FaderSet(DtEHU_FaderSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_FeaReqBasePlateTex_DeEHU_FeaReqBasePlateTex(DtEHU_FeaReqBasePlateTex data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_FeaReqVehColor_DeEHU_FeaReqVehColor(DtEHU_FeaReqVehColor data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_FeaReqVehTrans_DeEHU_FeaReqVehTrans(DtEHU_FeaReqVehTrans data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_FolwMeHomeTiSet_DeEHU_FolwMeHomeTiSet(DtEHU_FolwMeHomeTiSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_FrntDefrstReq_DeEHU_FrntDefrstReq(DtEHU_FrntDefrstReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_FrntFogLampCtrl_DeEHU_FrntFogLampCtrl(DtEHU_FrntFogLampCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_FrntWiprCtrl_DeEHU_FrntWiprCtrl(DtEHU_FrntWiprCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_FrntWshrCtrl_DeEHU_FrntWshrCtrl(DtEHU_FrntWshrCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_GPSHei_DeEHU_GPSHei(DtEHU_GPSHei data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_GPSLati_DeEHU_GPSLati(DtEHU_GPSLati data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_GPSLongi_DeEHU_GPSLongi(DtEHU_GPSLongi data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_GPS_AliveCounter_DeEHU_GPS_AliveCounter(DtEHU_GPS_AliveCounter data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_GPS_Checksum_DeEHU_GPS_Checksum(DtEHU_GPS_Checksum data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_GesRcntnRes_DeEHU_GesRcntnRes(DtEHU_GesRcntnRes data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_HDCSwtSig_DeEHU_HDCSwtSig(DtEHU_HDCSwtSig data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_HFTVolSet_DeEHU_HFTVolSet(DtEHU_HFTVolSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_HWASwt_DeEHU_HWASwt(DtEHU_HWASwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_HeiAdj_HUD_DeEHU_HeiAdj_HUD(DtEHU_HeiAdj_HUD data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_HeiAutoAdjEna_HUD_DeEHU_HeiAutoAdjEna_HUD(DtEHU_HeiAutoAdjEna_HUD data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_HiBeamCtrl_DeEHU_HiBeamCtrl(DtEHU_HiBeamCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_HiFrqAudioSet_DeEHU_HiFrqAudioSet(DtEHU_HiFrqAudioSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_HiwayExitAuxReq_DeEHU_HiwayExitAuxReq(DtEHU_HiwayExitAuxReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_HiwayExitAuxSwt_DeEHU_HiwayExitAuxSwt(DtEHU_HiwayExitAuxSwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_IESSModReq_DeEHU_IESSModReq(DtEHU_IESSModReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_IntegtOpen_DeEHU_IntegtOpen(DtEHU_IntegtOpen data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_IntrLampTiSet_DeEHU_IntrLampTiSet(DtEHU_IntrLampTiSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_KickFctOpenSts_DeEHU_KickFctOpenSts(DtEHU_KickFctOpenSts data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_LDWSwt_DeEHU_LDWSwt(DtEHU_LDWSwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_LKASwt_DeEHU_LKASwt(DtEHU_LKASwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_LeFrntWinCtrl_DeEHU_LeFrntWinCtrl(DtEHU_LeFrntWinCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_LeMirrAlrmLampFlt_DeEHU_LeMirrAlrmLampFlt(DtEHU_LeMirrAlrmLampFlt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_LeReWinCtrl_DeEHU_LeReWinCtrl(DtEHU_LeReWinCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_LeRiBalSet_DeEHU_LeRiBalSet(DtEHU_LeRiBalSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_LoBeamCtrl_DeEHU_LoBeamCtrl(DtEHU_LoBeamCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_LoFrqAudioSet_DeEHU_LoFrqAudioSet(DtEHU_LoFrqAudioSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_MaiVolSet_DeEHU_MaiVolSet(DtEHU_MaiVolSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_MediaCallSrcSet_DeEHU_MediaCallSrcSet(DtEHU_MediaCallSrcSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_MemDataUpdReq_DeEHU_MemDataUpdReq(DtEHU_MemDataUpdReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_MidFrqAudioSet_DeEHU_MidFrqAudioSet(DtEHU_MidFrqAudioSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_MirrCmd_DeEHU_MirrCmd(DtEHU_MirrCmd data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ModSeln_DeEHU_ModSeln(DtEHU_ModSeln data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ModSwt_HUD_DeEHU_ModSwt_HUD(DtEHU_ModSwt_HUD data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_MuteCtrl_DeEHU_MuteCtrl(DtEHU_MuteCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_NavCtryCod_DeEHU_NavCtryCod(DtEHU_NavCtryCod data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_NavDstInfo_DeEHU_NavDstInfo(DtEHU_NavDstInfo data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_NavGuidanceInfo_DeEHU_NavGuidanceInfo(DtEHU_NavGuidanceInfo data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_NavRoadTyp_DeEHU_NavRoadTyp(DtEHU_NavRoadTyp data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_NavSpdLim_DeEHU_NavSpdLim(DtEHU_NavSpdLim data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_NavSpdLimExitDst_DeEHU_NavSpdLimExitDst(DtEHU_NavSpdLimExitDst data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_NavSpdLimSts_DeEHU_NavSpdLimSts(DtEHU_NavSpdLimSts data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_NavSpdLimUnit_DeEHU_NavSpdLimUnit(DtEHU_NavSpdLimUnit data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_NavSrcSet_DeEHU_NavSrcSet(DtEHU_NavSrcSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_NavVolSet_DeEHU_NavVolSet(DtEHU_NavVolSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_OffUnlckSet_DeEHU_OffUnlckSet(DtEHU_OffUnlckSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_OpenCmd_HUD_DeEHU_OpenCmd_HUD(DtEHU_OpenCmd_HUD data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_OpenTiChrgSetFlg_DeEHU_OpenTiChrgSetFlg(DtEHU_OpenTiChrgSetFlg data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_OrintChgKey_DeEHU_OrintChgKey(DtEHU_OrintChgKey data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_OverlayDstReq_DeEHU_OverlayDstReq(DtEHU_OverlayDstReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_OverlayTubeReq_DeEHU_OverlayTubeReq(DtEHU_OverlayTubeReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_PASSwt_DeEHU_PASSwt(DtEHU_PASSwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_PassOccpy_DeEHU_PassOccpy(DtEHU_PassOccpy data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_PassSYNCReq_DeEHU_PassSYNCReq(DtEHU_PassSYNCReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_PassSeatBackManReq_DeEHU_PassSeatBackManReq(DtEHU_PassSeatBackManReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_PassSeatHeatgReq_DeEHU_PassSeatHeatgReq(DtEHU_PassSeatHeatgReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_PassSeatTrackManReq_DeEHU_PassSeatTrackManReq(DtEHU_PassSeatTrackManReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_PassSeatVentnReq_DeEHU_PassSeatVentnReq(DtEHU_PassSeatVentnReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_PassSecRowRiSeatBackReq_DeEHU_PassSecRowRiSeatBackReq(DtEHU_PassSecRowRiSeatBackReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_PassTSet_DeEHU_PassTSet(DtEHU_PassTSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_PauseKey_DeEHU_PauseKey(DtEHU_PauseKey data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_PerpModChg_DeEHU_PerpModChg(DtEHU_PerpModChg data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_PollingFctOpenSts_DeEHU_PollingFctOpenSts(DtEHU_PollingFctOpenSts data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_PosnLampCtrl_DeEHU_PosnLampCtrl(DtEHU_PosnLampCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_PrkgSlotc_DeEHU_PrkgSlotc(DtEHU_PrkgSlotc data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_RCTASwt_DeEHU_RCTASwt(DtEHU_RCTASwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_RCTBSwt_DeEHU_RCTBSwt(DtEHU_RCTBSwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_RCWSwt_DeEHU_RCWSwt(DtEHU_RCWSwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_RDPSwt_DeEHU_RDPSwt(DtEHU_RDPSwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_RainClsdSunroofSet_DeEHU_RainClsdSunroofSet(DtEHU_RainClsdSunroofSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ReDefrstOpenReq_DeEHU_ReDefrstOpenReq(DtEHU_ReDefrstOpenReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ReFogLampCtrl_DeEHU_ReFogLampCtrl(DtEHU_ReFogLampCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ReMirrAutoFoldSet_DeEHU_ReMirrAutoFoldSet(DtEHU_ReMirrAutoFoldSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ReWiprCtrl_DeEHU_ReWiprCtrl(DtEHU_ReWiprCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ReWshrCtrl_DeEHU_ReWshrCtrl(DtEHU_ReWshrCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_RestoreDftSettings_DeEHU_RestoreDftSettings(DtEHU_RestoreDftSettings data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ResuKey_DeEHU_ResuKey(DtEHU_ResuKey data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_RiFrntWinCtrl_DeEHU_RiFrntWinCtrl(DtEHU_RiFrntWinCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_RiMirrAlrmLampFlt_DeEHU_RiMirrAlrmLampFlt(DtEHU_RiMirrAlrmLampFlt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_RiReWinCtrl_DeEHU_RiReWinCtrl(DtEHU_RiReWinCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_RtnStrtKey_DeEHU_RtnStrtKey(DtEHU_RtnStrtKey data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_SDWAudioReq_DeEHU_SDWAudioReq(DtEHU_SDWAudioReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_SLIFSwt_DeEHU_SLIFSwt(DtEHU_SLIFSwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_SeatAntithftFctEnaReq_DeEHU_SeatAntithftFctEnaReq(DtEHU_SeatAntithftFctEnaReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_SelKey_DeEHU_SelKey(DtEHU_SelKey data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_SetAtmLampBri_DeEHU_SetAtmLampBri(DtEHU_SetAtmLampBri data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ShowReq_DeEHU_ShowReq(DtEHU_ShowReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ShowSts_DeEHU_ShowSts(DtEHU_ShowSts data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_SngPedlSts_DeEHU_SngPedlSts(DtEHU_SngPedlSts data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_SpdLimOffs_DeEHU_SpdLimOffs(DtEHU_SpdLimOffs data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_SrcSwt_HUD_DeEHU_SrcSwt_HUD(DtEHU_SrcSwt_HUD data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_SteerWhlVbrnAlrmReq_DeEHU_SteerWhlVbrnAlrmReq(DtEHU_SteerWhlVbrnAlrmReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_SunroofCtrlReq_DeEHU_SunroofCtrlReq(DtEHU_SunroofCtrlReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_SunroofPercCtrlCmdReq_DeEHU_SunroofPercCtrlCmdReq(DtEHU_SunroofPercCtrlCmdReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_SunroofshadePercCtrlCmdReq_DeEHU_SunroofshadePercCtrlCmdReq(DtEHU_SunroofshadePercCtrlCmdReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_SunshadeCtrlReq_DeEHU_SunshadeCtrlReq(DtEHU_SunshadeCtrlReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_SurrndCtrl_DeEHU_SurrndCtrl(DtEHU_SurrndCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_TJAICASwt_DeEHU_TJAICASwt(DtEHU_TJAICASwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_TLASwt_DeEHU_TLASwt(DtEHU_TLASwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_TSRSwt_DeEHU_TSRSwt(DtEHU_TSRSwt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_TiChrgEndHrSet_DeEHU_TiChrgEndHrSet(DtEHU_TiChrgEndHrSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_TiChrgEndMinsSet_DeEHU_TiChrgEndMinsSet(DtEHU_TiChrgEndMinsSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_TiChrgStrtHrSet_DeEHU_TiChrgStrtHrSet(DtEHU_TiChrgStrtHrSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_TiChrgStrtMinsSet_DeEHU_TiChrgStrtMinsSet(DtEHU_TiChrgStrtMinsSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_TouchEveTyp_DeEHU_TouchEveTyp(DtEHU_TouchEveTyp data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_TouchXCoor_DeEHU_TouchXCoor(DtEHU_TouchXCoor data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_TouchYCoor_DeEHU_TouchYCoor(DtEHU_TouchYCoor data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_TrActnCmd_DeEHU_TrActnCmd(DtEHU_TrActnCmd data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_TrunkLockCtrl_DeEHU_TrunkLockCtrl(DtEHU_TrunkLockCtrl data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_TypChgKey_DeEHU_TypChgKey(DtEHU_TypChgKey data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_UsrSetChrgGunAntithft_DeEHU_UsrSetChrgGunAntithft(DtEHU_UsrSetChrgGunAntithft data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_UsrSetChrgRmnMilg_DeEHU_UsrSetChrgRmnMilg(DtEHU_UsrSetChrgRmnMilg data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_UsrSetDchaEndDrvgMilg_DeEHU_UsrSetDchaEndDrvgMilg(DtEHU_UsrSetDchaEndDrvgMilg data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VSCModReq_DeEHU_VSCModReq(DtEHU_VSCModReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VSPCtrlCmd_DeEHU_VSPCtrlCmd(DtEHU_VSPCtrlCmd data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ViewReq_DeEHU_ViewReq(DtEHU_ViewReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlAirClnClsReq_DeEHU_VoiceCtrlAirClnClsReq(DtEHU_VoiceCtrlAirClnClsReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlAirClnOpenReq_DeEHU_VoiceCtrlAirClnOpenReq(DtEHU_VoiceCtrlAirClnOpenReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlAirVolSet_DeEHU_VoiceCtrlAirVolSet(DtEHU_VoiceCtrlAirVolSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlAirVolTurnDwnReq_DeEHU_VoiceCtrlAirVolTurnDwnReq(DtEHU_VoiceCtrlAirVolTurnDwnReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlAirVolTurnUpReq_DeEHU_VoiceCtrlAirVolTurnUpReq(DtEHU_VoiceCtrlAirVolTurnUpReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlBlowFootDefrstReq_DeEHU_VoiceCtrlBlowFootDefrstReq(DtEHU_VoiceCtrlBlowFootDefrstReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlDrvrTSet_DeEHU_VoiceCtrlDrvrTSet(DtEHU_VoiceCtrlDrvrTSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlDrvrTTurnDwnReq_DeEHU_VoiceCtrlDrvrTTurnDwnReq(DtEHU_VoiceCtrlDrvrTTurnDwnReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlDrvrTTurnUpReq_DeEHU_VoiceCtrlDrvrTTurnUpReq(DtEHU_VoiceCtrlDrvrTTurnUpReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlECCAUTOReq_DeEHU_VoiceCtrlECCAUTOReq(DtEHU_VoiceCtrlECCAUTOReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlECCBlowFaceModReq_DeEHU_VoiceCtrlECCBlowFaceModReq(DtEHU_VoiceCtrlECCBlowFaceModReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlECCBlowFootModReq_DeEHU_VoiceCtrlECCBlowFootModReq(DtEHU_VoiceCtrlECCBlowFootModReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlECCBlowModReq_DeEHU_VoiceCtrlECCBlowModReq(DtEHU_VoiceCtrlECCBlowModReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlECCClsReq_DeEHU_VoiceCtrlECCClsReq(DtEHU_VoiceCtrlECCClsReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlECCDefrstModExitReq_DeEHU_VoiceCtrlECCDefrstModExitReq(DtEHU_VoiceCtrlECCDefrstModExitReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlECCDefrstModReq_DeEHU_VoiceCtrlECCDefrstModReq(DtEHU_VoiceCtrlECCDefrstModReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlECCExtCircReq_DeEHU_VoiceCtrlECCExtCircReq(DtEHU_VoiceCtrlECCExtCircReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlECCIntCircReq_DeEHU_VoiceCtrlECCIntCircReq(DtEHU_VoiceCtrlECCIntCircReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlECCOpenReq_DeEHU_VoiceCtrlECCOpenReq(DtEHU_VoiceCtrlECCOpenReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlEndFctClsReq_DeEHU_VoiceCtrlEndFctClsReq(DtEHU_VoiceCtrlEndFctClsReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlEndFctOpenReq_DeEHU_VoiceCtrlEndFctOpenReq(DtEHU_VoiceCtrlEndFctOpenReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlPassTSet_DeEHU_VoiceCtrlPassTSet(DtEHU_VoiceCtrlPassTSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlPassTTurnDwnReq_DeEHU_VoiceCtrlPassTTurnDwnReq(DtEHU_VoiceCtrlPassTTurnDwnReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlPassTTurnUpReq_DeEHU_VoiceCtrlPassTTurnUpReq(DtEHU_VoiceCtrlPassTTurnUpReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlRfgnModClsReq_DeEHU_VoiceCtrlRfgnModClsReq(DtEHU_VoiceCtrlRfgnModClsReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlRfgnModOpenReq_DeEHU_VoiceCtrlRfgnModOpenReq(DtEHU_VoiceCtrlRfgnModOpenReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlSYNCClsReq_DeEHU_VoiceCtrlSYNCClsReq(DtEHU_VoiceCtrlSYNCClsReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlSYNCOpenReq_DeEHU_VoiceCtrlSYNCOpenReq(DtEHU_VoiceCtrlSYNCOpenReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlTSet_DeEHU_VoiceCtrlTSet(DtEHU_VoiceCtrlTSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlTTurnDwnReq_DeEHU_VoiceCtrlTTurnDwnReq(DtEHU_VoiceCtrlTTurnDwnReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_VoiceCtrlTTurnUpReq_DeEHU_VoiceCtrlTTurnUpReq(DtEHU_VoiceCtrlTTurnUpReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_WIFIAPAuthentMechanism_DeEHU_WIFIAPAuthentMechanism(DtEHU_WIFIAPAuthentMechanism data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_WelLampOpenSet_DeEHU_WelLampOpenSet(DtEHU_WelLampOpenSet data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_WormSts_DeEHU_WormSts(DtEHU_WormSts data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_ZoomReq_DeEHU_ZoomReq(DtEHU_ZoomReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_EHU_abdEnaReq_DeEHU_abdEnaReq(DtEHU_abdEnaReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICC_172_AliveCounter_DeICC_172_AliveCounter(DtICC_172_AliveCounter data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICC_172_CheckSum_DeICC_172_CheckSum(DtICC_172_CheckSum data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICC_312_AliveCounter_DeICC_312_AliveCounter(DtICC_312_AliveCounter data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICC_312_CheckSum_DeICC_312_CheckSum(DtICC_312_CheckSum data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICC_4F2_AliveCounter_DeICC_4F2_AliveCounter(DtICC_4F2_AliveCounter data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICC_4F2_CheckSum_DeICC_4F2_CheckSum(DtICC_4F2_CheckSum data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICC_BluetoothMACwifi_DeICC_BluetoothMACwifi(const uint8 *data)
 *     Argument data: uint8* is of type DtICC_BluetoothMACwifi
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICC_CalVers_DeICC_CalVers(DtICC_CalVers data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICC_HwVers_DeICC_HwVers(DtICC_HwVers data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICC_PartVers_DeICC_PartVers(DtICC_PartVers data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICC_SeatWelFctEnaReq_DeICC_SeatWelFctEnaReq(DtICC_SeatWelFctEnaReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICC_SwVers_DeICC_SwVers(DtICC_SwVers data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICM_ACCTarVehSpd_DeICM_ACCTarVehSpd(DtICM_ACCTarVehSpd data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICM_ADASSigFlt_DeICM_ADASSigFlt(DtICM_ADASSigFlt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICM_DispFlt_DeICM_DispFlt(DtICM_DispFlt data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICM_DispTotMilg_ODO_DeICM_DispTotMilg_ODO(DtICM_DispTotMilg_ODO data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICM_DispVehSpd_DeICM_DispVehSpd(DtICM_DispVehSpd data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICM_DispVehSpdUnit_DeICM_DispVehSpdUnit(DtICM_DispVehSpdUnit data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICM_LDWAlrmTypReq_DeICM_LDWAlrmTypReq(DtICM_LDWAlrmTypReq data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICM_MilgDataVld_ODO_DeICM_MilgDataVld_ODO(DtICM_MilgDataVld_ODO data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICM_MilgOffs_ODO_DeICM_MilgOffs_ODO(DtICM_MilgOffs_ODO data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICM_MilgRstCntr_ODO_DeICM_MilgRstCntr_ODO(DtICM_MilgRstCntr_ODO data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICM_TotMilgVld_ODO_DeICM_TotMilgVld_ODO(DtICM_TotMilgVld_ODO data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICM_TotMilg_ODO_DeICM_TotMilg_ODO(DtICM_TotMilg_ODO data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICM_VehFlameoutTi_DeICM_VehFlameoutTi(DtICM_VehFlameoutTi data)
 *   Std_ReturnType Rte_Write_Pp_TxSignal_ICM_VehFlameoutTiVld_DeICM_VehFlameoutTiVld(DtICM_VehFlameoutTiVld data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_IpcS_Notify_doc
 *********************************************************************************************************************/
 
/*******************************************************************************
|    Typedef Definition
|******************************************************************************/
typedef void (* TpCANApp_w_TxCanSigIf)(void);
typedef Std_ReturnType (* TpCANApp_w_TxCanSigIf_OneByteSize)(uint8);
typedef Std_ReturnType (* TpCANApp_w_TxCanSigIf_TwoBytesSize)(uint16);
typedef Std_ReturnType (* TpCANApp_w_TxCanSigIf_FourBytesSize)(uint32);
typedef Std_ReturnType (* TpCANApp_w_TxCanSigIf_EightBytesSize)(uint8*);

typedef struct
{
    TpCANApp_w_TxCanSigIf e_h_TxCanSigIf;
    uint8 e_u_TxCanSigLen;
}TsCANApp_h_TxCanSigIf;

/*******************************************************************************
|    Macro Definition
|******************************************************************************/
#define CeCANApp_u_TxCanSigSize_OneByte 1u
#define CeCANApp_u_TxCanSigSize_TwoBytes 2u
#define CeCANApp_u_TxCanSigSize_FourBytes 4u
#define CeCANApp_u_TxCanSigSize_EightBytes 8u

/*******************************************************************************
|    Const Definition
|******************************************************************************/
static const TsCANApp_h_TxCanSigIf CtCANApp_h_TxCanSigIf[2u] = 
{
    (TpCANApp_w_TxCanSigIf)Rte_Write_Pp_TxSignal_EHU_BeepSrcSet_DeEHU_BeepSrcSet, CeCANApp_u_TxCanSigSize_OneByte,
    (TpCANApp_w_TxCanSigIf)Rte_Write_Pp_TxSignal_EHU_BeepSrcSet_DeEHU_BeepSrcSet, CeCANApp_u_TxCanSigSize_FourBytes,    
};

/*******************************************************************************
Name            : CANApp_MapIpcReceiveDataToTxCan
Syntax          : None
Parameters(in)  : None
Parameters(out) : None
Returns value   : None
Description     :
Call by         :
History
<No.>   <author>    <time>      <description>
1       KENW        20190228    Primiry Created.
|******************************************************************************/
static void CANApp_MapIpcReceiveDataToTxCan(uint8 *Lp_w_IpcReceiveData, uint16 Le_w_IpcReceiveDataLen)
{
    uint8 Le_u_Index;    
    uint16 Le_w_TxCanSigId;
    uint8 Le_u_TxCanSigBuf;
    uint16 Le_w_TxCanSigBuf;
    uint32 Le_dw_TxCanSigBuf;
    uint8 La_u_TxCanSigBuf[8u];
	
	if(CeCANApp_u_PtrNULL == Lp_w_IpcReceiveData)
	{
        return;
	}
    else
    {
        /*go to the next step*/
    }    

    Le_w_TxCanSigId = (((uint16)Lp_w_IpcReceiveData[2u]) << 8u) | (((uint16)Lp_w_IpcReceiveData[1u]) << 0u);

    switch(CtCANApp_h_TxCanSigIf[Le_w_TxCanSigId].e_u_TxCanSigLen)
    {
        case CeCANApp_u_TxCanSigSize_OneByte:
            Le_u_TxCanSigBuf = Lp_w_IpcReceiveData[3u];
            ((TpCANApp_w_TxCanSigIf_OneByteSize)(CtCANApp_h_TxCanSigIf[Le_w_TxCanSigId].e_h_TxCanSigIf))(Le_u_TxCanSigBuf);
            break;
            
        case CeCANApp_u_TxCanSigSize_TwoBytes:
            Le_w_TxCanSigBuf = ((uint16)Lp_w_IpcReceiveData[3u] << 8u) | ((uint16)Lp_w_IpcReceiveData[4u]);
            ((TpCANApp_w_TxCanSigIf_TwoBytesSize)(CtCANApp_h_TxCanSigIf[Le_w_TxCanSigId].e_h_TxCanSigIf))(Le_w_TxCanSigBuf);
            break;
            
        case CeCANApp_u_TxCanSigSize_FourBytes:
            Le_dw_TxCanSigBuf = ((uint32)Lp_w_IpcReceiveData[3u] << 24u) | ((uint32)Lp_w_IpcReceiveData[4u] << 16u) |\
                                            ((uint32)Lp_w_IpcReceiveData[5] << 8) | ((uint32)Lp_w_IpcReceiveData[6u] << 0u);
            ((TpCANApp_w_TxCanSigIf_FourBytesSize)(CtCANApp_h_TxCanSigIf[Le_w_TxCanSigId].e_h_TxCanSigIf))(Le_dw_TxCanSigBuf);
            break;
            
        case CeCANApp_u_TxCanSigSize_EightBytes:
            for(Le_u_Index = 0u; Le_u_Index < 8u; Le_u_Index++)
            {
                *(&La_u_TxCanSigBuf[0u] + Le_u_Index) = *(Lp_w_IpcReceiveData + Le_u_Index + 3u); 
            }
            ((TpCANApp_w_TxCanSigIf_EightBytesSize)(CtCANApp_h_TxCanSigIf[Le_w_TxCanSigId].e_h_TxCanSigIf))(&La_u_TxCanSigBuf[0u]);
            break;
            
        default:
            break;
    }    
}
/*******************************************************************************
Name            : CANApp_IpcNotifyReceive
Syntax          : None
Parameters(in)  : None
Parameters(out) : None
Returns value   : None
Description     :
Call by         :
History
<No.>   <author>    <time>      <description>
1       KENW        20190228    Primiry Created.
|******************************************************************************/
static void CANApp_IpcNotifyReceive(IpcS_ChannelState_st *ptr_IpcS_ChannelState_AppCh)
{
	uint8 *pData;
	uint16 ui16Pending = 1u;   
	sint16 i16Len;
		
	//do
	//{
        Rte_Call_rp_CanApplication_IpcSRead_ipcRead(ptr_IpcS_ChannelState_AppCh->IpcS_ChannelNo, (uint8*)(&pData), &i16Len, &ui16Pending);

        if(i16Len > 0u)
        {
            //TRACE_VALUE( ONOFF_INFO, MOD_ONOFF, "AIPC:MSG Length:%d", i16Len);
        	//TRACE_VALUE4( ONOFF_INFO, MOD_ONOFF, "AIPC:Ver:0x%x cmdType:0x%x CmdLen:%d ReadLen:0x%x", pData[0], pData[1], pData[2], pData[3]);
        	//TRACE_VALUE4( ONOFF_INFO, MOD_ONOFF, "AIPC:wFlag:0x%x Resev:0x%x Data0~1:0x%x 0x%x", pData[4], pData[5], pData[6], pData[7]);
            
        	CANApp_MapIpcReceiveDataToTxCan(pData, (uint16)i16Len);            
        	Rte_Call_rp_CanApplication_mmFreeMemory_mmFreeMemory((uint8*)pData);
        }
        else
        {
            //TRACE_VALUE( ONOFF_INFO, MOD_ONOFF, "AIPC: IPC Read Fail. i16Len:0x%X", i16Len);
        }
	//}
	//while(ui16Pending);
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_IpcS_Notify(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_IpcS_Notify
 *********************************************************************************************************************/ 
    IpcS_ChannelState_st IpcS_ChannelState_AppCh;       
	IpcS_ChannelState_st *ptr_IpcS_ChannelState_AppCh;

	ptr_IpcS_ChannelState_AppCh = &IpcS_ChannelState_AppCh;

	while(RTE_E_OK == Rte_Receive_rp_CanApplication_IpcSNotifyClient_IpcSChannelInfo(ptr_IpcS_ChannelState_AppCh))
	{
		if(CeCANApp_u_IpcChanlNum_IVICan == ptr_IpcS_ChannelState_AppCh->IpcS_ChannelNo)
		{
			switch(ptr_IpcS_ChannelState_AppCh->IpcS_InfoType)
			{
				case IpcS_FlowControlState:					 
					 if(IpcS_XON == ptr_IpcS_ChannelState_AppCh->IpcS_InfoData) /*take required action for XON/XOFF*/
					 {
					 	 //TRACE_TEXT( ONOFF_INFO, MOD_ONOFF, "AIPC:FlowControlState XON");
						 SeCANApp_u_IpcChanlFlowCntrlSta_IVICan = CeCANApp_u_TRUE;
					 }
					 else if(IpcS_XOFF == ptr_IpcS_ChannelState_AppCh->IpcS_InfoData)
					 {
					 	 //TRACE_TEXT( ONOFF_INFO, MOD_ONOFF, "AIPC:FlowControlState XOFF");
						 SeCANApp_u_IpcChanlFlowCntrlSta_IVICan = CeCANApp_u_FALSE;                         
						 //dbprint("[CDD J6] XOFF recived on %d, Possible memory pool overflow\n",ptr_IpcS_ChannelState_AppCh->IpcS_ChannelNo); 			 
					 }
					 else
					 {
						 /*Not a good place to reach*/
						 //dbprint("[CDD J6] Error in flow control handling");
					 }					 
					 break;
                     
				case IpcS_ConnectState:					 
					 if(IpcS_ClientConnected == ptr_IpcS_ChannelState_AppCh->IpcS_InfoData) /*if client connected is received, this means IPC for channel is ready for communication on this channel*/ 	
					 {
					 	 //TRACE_TEXT( ONOFF_INFO, MOD_ONOFF, "AIPC:ConnectState true");
						 SeCANApp_u_IpcChanlConnectSta_IVICan = CeCANApp_u_TRUE;                         
						 //Invoke connection callbacks
					 }
					 else if(IpcS_Connected == ptr_IpcS_ChannelState_AppCh->IpcS_InfoData)
					 {
					 	 //TRACE_TEXT( ONOFF_INFO, MOD_ONOFF, "AIPC:ConnectState false");                            
						 //Clients not yet registered on the SOC						 
						 SeCANApp_u_IpcChanlConnectSta_IVICan = CeCANApp_u_FALSE;
					 }
					 else
					 {
						 //dbprint("[CDD J6] Error in connection state handling"); 
					 }			 
					 break;
                     
				case IpcS_RxIndication: 					  
					 if(IpcS_RxDataAvailable == ptr_IpcS_ChannelState_AppCh->IpcS_InfoData) /*Data is received on channel*/
					 {
					 	 //TRACE_TEXT( ONOFF_INFO, MOD_ONOFF, "AIPC:Received a Message");                            
						 CANApp_IpcNotifyReceive(ptr_IpcS_ChannelState_AppCh);
					 }
					 break;
                     
				case IpcS_TxConfirmation:					 
					 if(IpcS_TxCompleted == ptr_IpcS_ChannelState_AppCh->IpcS_InfoData)  /*Data is transmitted on channel*/
					 {
					     //TRACE_TEXT( ONOFF_INFO, MOD_ONOFF, "AIPC:Send Message completed");
						 //HandleIpcTransmitConfirmationEvent(ptr_IpcS_ChannelState_AppCh->IpcS_ChannelNo);
					 }			 
					 break;
                     
				default:
					 //dbprint("Error in Data recieved");
					 break;
			}	
		}
		else
		{
			//dbprint("[CDD] Data Received on invalid channel");
		}
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_MN_GPS_CAN_Ind
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_MN_GPS_CAN_Ind_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_MN_GPS_CAN_Ind(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_MN_GPS_CAN_Ind
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_MON_GPS_CAN_Ind
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_MON_GPS_CAN_Ind_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_MON_GPS_CAN_Ind(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_MON_GPS_CAN_Ind
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_NightMode
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_NightMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_NightMode(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_NightMode
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_OP_PUBU_AUD_AUTU_STW
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_OP_PUBU_AUD_AUTU_STW_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_OP_PUBU_AUD_AUTU_STW(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_OP_PUBU_AUD_AUTU_STW
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_OP_PUBU_AUD_AVOL_STW
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_OP_PUBU_AUD_AVOL_STW_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_OP_PUBU_AUD_AVOL_STW(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_OP_PUBU_AUD_AVOL_STW
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_OP_PUBU_KRL_STW
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_OP_PUBU_KRL_STW_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_OP_PUBU_KRL_STW(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_OP_PUBU_KRL_STW
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_OP_PUBU_PTT_STW
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_OP_PUBU_PTT_STW_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_OP_PUBU_PTT_STW(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_OP_PUBU_PTT_STW
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_OP_PUBU_TEL_STW
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_OP_PUBU_TEL_STW_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_OP_PUBU_TEL_STW(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_OP_PUBU_TEL_STW
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_Odometrer
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_Odometrer_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_Odometrer(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_Odometrer
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_OperatingMode
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_OperatingMode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_OperatingMode(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_OperatingMode
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_ParkBreak
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_ParkBreak_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_ParkBreak(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_ParkBreak
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_SEC_GPS_CAN_Ind
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_SEC_GPS_CAN_Ind_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_SEC_GPS_CAN_Ind(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_SEC_GPS_CAN_Ind
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_ST_CT_BLT
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_ST_CT_BLT_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_ST_CT_BLT(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_ST_CT_BLT
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_ST_CT_BON
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_ST_CT_BON_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_ST_CT_BON(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_ST_CT_BON
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_SignalReceived
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_SignalReceived_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_SignalReceived(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_SignalReceived
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_TEMP_EVA
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_TEMP_EVA_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_TEMP_EVA(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_TEMP_EVA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_TEMP_HTEX
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_TEMP_HTEX_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_TEMP_HTEX(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_TEMP_HTEX
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_TEMP_INTR
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_TEMP_INTR_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_TEMP_INTR(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_TEMP_INTR
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_TEMP_TAR_DR_IHKA
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_TEMP_TAR_DR_IHKA_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_TEMP_TAR_DR_IHKA(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_TEMP_TAR_DR_IHKA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_TEMP_TAR_PS_IHKA
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_TEMP_TAR_PS_IHKA_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_TEMP_TAR_PS_IHKA(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_TEMP_TAR_PS_IHKA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_TurnIndicator
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_TurnIndicator_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_TurnIndicator(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_TurnIndicator
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_VECH_INFO
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_VECH_INFO_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_VECH_INFO(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_VECH_INFO
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_VehicleSpeed
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_VehicleSpeed_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_VehicleSpeed(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_VehicleSpeed
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CanApplication_YR_GPS_CAN_Ind
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * This runnable is never executed by the RTE.
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_YR_GPS_CAN_Ind_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CanApplication_CODE) CanApplication_YR_GPS_CAN_Ind(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CanApplication_YR_GPS_CAN_Ind
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CanApplication_STOP_SEC_CODE
#include "CanApplication_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
