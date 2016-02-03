/*include/invengo-protocal/cmd_def.h*/
/*
*	joison, 2016-01-28 
*/
#ifndef __CMD_DEF_H__
#define __CMD_DEF_H__

/*
* command format description
* FORMAT-COMPRISE: CMD_LEN[2]+CMD_TYPE[1]+CMD_BUF[N]+CMD_CRC16[2]
*	@CMD_LEN: two bytes  
*		cmd_len=CMD_LEN[0]<<8 + CMD_LEN[1]
*		CMD_LEN[0] = cmd_len<<8; CMD_LEN[1] = cmd_len & 0xff;
*	@CMD_TYPE:[2]	CMD_TYPE[1]	CMD_BUF(data/parameter)[N]	
*	@CMD_BUF: undefine length bytes , the length defined by the CMD_TYPE
*		and the CMD_OPT
*	@CMD_CRC16: two bytes, the check method is defined in file src/certification/crc.c	
*	
*/

/*command sets*/
/*unused command set currently*/
#define __UNDEF_00_4F_CMD_SET	// 0x00-0x4f
/*epc c1g2 low layer cmd*/
#define __EPCC1G2_LOWLAYER_SET	//0x10-0x1f
/*system control command set*/
#define __SYSCTRL_CMD_SET	//0x50-0x5f
/*reader command set*/
#define __READER_OPT_CMD_SET	//0x60-0x6f
/*ISO18K-6B TAG command set*/
#ifndef READER_TYPE_XCRF860// the 860 reader not support this set
#define __ISO18K_TAG_CMD_SET	//0x70-0x7f
#endif //__READER_TYPE_860
/*EPC C1G2 TAG command set*/
#define __EPCC1G2_TAG_CMD_SET	//0x80-0x9f
/*unused command set currently*/
#define __UNDEF_A0_CF_CMD_SET
/*integration command set*/
#define __INTEGRATION_CMD_SET	//0xd0-0xdf
/*priority for customer*/
#define __CUSTOMER_CMD_SET	//0xe0-0xff

#ifdef __EPCC1G2_LOWLAYER_SET
#define EPCLLCMD_INVNTRY_RD	//take inventory of the card
#define EPCLLCMD_INVNTRY_RPT	// report inventory
#define EPCLLCMD_CONTINUE_INVENTORY	//continue inventory 
#define EPCLLCMD_RD	
#define EPCLLCMD_WT	
#define EPCLLCMD_LOCK
#define EPCLLCMD_KILL	
#define EPCLLCMD_MIXEDCMD	
#endif //__EPCC1G2_LOWLAYER_SET

/*reader command set define*/
#ifdef __READER_OPT_CMD_SET
#define RDCMD_LOW	0x60
#define RDCMD_OPEN_RF_PWAMP	0x60	//open RF power amplifier
#define RDCMD_CLOSE_RF_PWAMP	0x61
#define RDCMD_GET_RD_SYSCONF	0x62	//check reader system configure
#define RDCMD_CONF_RD_SYSCONF	0x63	
#define RDCMD_GET_TAG_OPTCONF	0x64	//check tag cmd configure
#define RDCMD_CONF_TAG_OPTCONF	0x65
#define RDCMD_CALIBRATE_RD_PARA	0x66	//calibrate the reader parameter
#define RDCMD_CONF_RD_TESTMODE	0x67	// set reader test mode
#define RDCMD_GET_SUPER_CMD	0x68	// get supper command
#define RDCMD_CONF_SUPER_CMD	0x69
#define RDCMD_UNDEF_6A_CMD	0x6A	//not used currently
#define RDCMD_UPDATE_RD_BSBAND	0x6B	// update reader base band 
#define RDCMD_RESTART_RD	0x6C	//restart reader 
#define RDCMD_UPDATE_ARM9	0x6D	//update arm9 program 	
#define RDCMD_UNDEF_6E_CMD	0x6E	//unused cmd 0x6e
#define RDCMD_UNDEF_6F_CMD	0x6F	//unused cmd 0x6F
#define RDCMD_HIGH	0x6F
#endif	//__READER_OPT_CMD_SET

/*ISO18K-6B TAG operation command set*/
#ifdef __ISO18K_TAG_CMD_SET
#define TAG6BCMD_LOW		0x70
#define TAG6BCMD_CONF_SELECTCONF 	0x70	//tag select configure
#define TAG6BCMD_RD_ID	0x71	//read tag ID
#define TAG6BCMD_RD_DATA	0x72	//read tag data
#define TAG6BCMD_WT_DATA	0x73	
#define TAG6BCMD_LOCK_DATA	0x74	//lock tag data
#define TAG6BCMD_UNDEF_75H	0x75	//not used 0x75
#define TAG6BCMD_UNDEF_76H	0x76
#define TAG6BCMD_UNDEF_77H	0x77
#define TAG6BCMD_UNDEF_78H	0x78
#define TAG6BCMD_UNDEF_79H	0x79
#define TAG6BCMD_UNDEF_7aH	0x7A
#define TAG6BCMD_UNDEF_7bH	0x7B
#define TAG6BCMD_UNDEF_7cH	0x7C
#define TAG6BCMD_UNDEF_7dH	0x7D
#define TAG6BCMD_UNDEF_7eH	0x7E
#define TAG6BCMD_UNDEF_7fH	0x7F
#define TAG6BCMD_HIGH		0x7F
#endif	//__TAG6BCMD

/*epc class1 gen2 tag operation command set*/
#ifdef __EPCC1G2_TAG_CMD_SET
#define TAGEPCC1G2CMD_LOW		0x80
#define TAGEPCC1G2CMD_CONF_SELECTCONF	0x80	//set tag select configure
#define TAGEPCC1G2CMD_RD_EPC	0x81
#define TAGEPCC1G2CMD_RD_TID	0x82
#define TAGEPCC1G2CMD_WT_EPC	0x83
#define TAGEPCC1G2CMD_RD_USR	0x84	//reader user data
#define TAGEPCC1G2CMD_WT_USR	0x85
#define TAGEPCC1G2CMD_BLKWT_USR	0x86	//block wirte user data
#define TAGEPCC1G2CMD_BLKERS_USR	0x87	//block erase user data
#define TAGEPCC1G2CMD_CONF_ACCESSPWD	0x88	//set access password 
#define TAGEPCC1G2CMD_CONF_KILLPWD	0x89	//set destroy password 
#define TAGEPCC1G2CMD_CONF_LOCKSTATE	0x8A	//set lock state
#define TAGEPCC1G2CMD_KILL	0x8B		//kill tag
#define TAGEPCC1G2CMD_CONF_EASFLAG	0x8C	//eas flag config
#define TAGEPCC1G2CMD_SET_EAS_MONITOR	0x8D	//eas monitor set
#define TAGEPCC1G2CMD_CONF_EASFLAG_MATCHFILTER	0x8E	//config match filter
#define TAGEPCC1G2CMD_CONF_TIMEFILTER	0x8F	//config the time filter of identical tag
#define TAGEPCC1G2CMD_BU2_RDONCE	0x90	//bu2 customized read once cmd
#define TAGEPCC1G2CMD_UNDEF_91H		0x91	//not used 91H
#define TAGEPCC1G2CMD_INVG_SUPRD	0x92	//invengo super read cmd
#define TAGEPCC1G2CMD_INVG_SUPWT	0x93	//invengo super write cmd
#define TAGEPCC1G2CMD_NXP_LCK_RDPRTCT	0x94	//NXP chip set read protect cmd
#define TAGEPCC1G2CMD_NXP_UNLCK_RDPRTCT	0x95	//NXP chip unlock read protect 
#define TAGEPCC1G2CMD_IMPINJQT		0x96	//IMPINJQT
#define TAGEPCC1G2CMD_COMRD	0x97		//common read 
#define TAGEPCC1G2CMD_BLK_PERMANENTLOCK	0x98	//block permanent lock
#define TAGEPCC1G2CMD_COMWT	0x99	//common write
#define TAGEPCC1G2CMD_H3_PRIV_9A	0x9A	//remained for h3 private
#define TAGEPCC1G2CMD_H3_PRIV_9B	0x9B	//remained for h3 private
#define TAGEPCC1G2CMD_HIGH		0x9F
#endif	//__TAGEPCC1G2CMD

#ifdef __INTEGRATION_CMD_SET
#define INTCMD_LOW	0xD0	
#define INTCMD_RD_CARD	0xD0	//read card
#define INTCMD_PORT_OUT	0xD1	//IO-PORT output 
#define INTCMD_PORT_IN	0xD2	
#define INTCMD_RD6B_ID_DATA	0xD3	//read 6b tag id and data area
#define INTCMD_RDEPCG2_ID_DATA	0xD4	//read epc g2 id and data area
#define INTCMD_TRIGGER_OF_PESISTTIME_SET	0xD5	//set the trigger of reading persist time 
#define INTCMD_UNFSHCARD_ALERTTIME_SET	0xD6	//set the alert time didn't scaned reader card
#define INTCMD_CARDINFO_TRANSFER	0xD7	//upper monitor card information transfer
#define INTCMD_QUERY_PEOPLENUMBER	0xD8	//query the number of people
#define INTCMD_VERIFY_READER	0xD9	//reader card verify
#define INTCMD_TRSPRNT_TRANSFER	0xDF	//transparent transfer
#define INTCMD_HIGH	0xDF		
#endif	//__INTEGRATION_CMD_SET

#ifdef __CUSTOMER_CMD_SET
#define CSTMCMD_LOW	0xE0
#define CSTMCMD_RPT_ERR	0xE0	//report reader error 
#define CSTMCMD_RPT_ALERT	0xE1	//report reader alert 
#define CSTMCMD_RPT_INF		0xE2	//report reader inform 
#define CSTMCMD_RPT_IO_TRIGGER_STATE	0xE4	//report oi trigger state
#define CSTMCMD_RPT_HEARTBEAT	0xE5	//report heart beat state
#define CSTMCMD_CUSTOM_DATA	0xE6	//customer private data
#define CSTMCMD_CUSTOM_CMD	0xE7	//customer private cmd
#define CSTMCMD_EXTEND_CMD_F6B	0xE8	//6b protocol command extend
#ifdef READER_XCRF850
#define CSTMCMD_EXTEND_CMD_F850RD	0xE9	//extend cmd just for XCRF850
#endif
#define CSTMCMD_6B6C_MIXRD	0xF0	//mix read 6B and 6C 
#define CSTMCMD_6C_TAG_RPT	0xF1	//report 6c tag data
#define CSTMCMD_6B_TAG_RPT	0xF2	//report 6B tag data

#define CSTMCMD_HIGH	0xFF
#endif

/*wild command define*/
#define WILDCMD_GET_SUPPLY_VOL	0xA7	//check the supply voltage
#define WILDCMD_SET_SUPPLY_ALERTVOL 0xA8	//set supply voltage alert value

/*antena port define*/
#if defined READER_TYPE_XCRF804 || READER_TYPE_XCRF811 || READER_TYPE_XCRF801 \
	|| READER_TYPE_XCRF860 || READER_TYPE_XCRF803 || READER_TYPE_XCRF807 \
	|| READER_TYPE_XCRF806
#define ANT1_OPT_REQ	1
#define ANT2_OPT_REQ	2
#define ANT3_OPT_REQ	3
#define ANT4_OPT_REQ	4
#define ANTN_OPT_REQ	0
#endif //READER_TYPES1

#if defined READER_TYPE_XCRF860 || READER_TYPE_XCRF803 || READER_TYPE_XCRF807 \
	|| READER_TYPE_XCRF806
#define __BIT(n)	(1<<(n))
#define EN_ANT1_OPT_REQ	__BIT(0)
#define EN_ANT2_OPT_REQ	__BIT(1)
#define EN_ANT3_OPT_REQ	__BIT(2)
#define EN_ANT4_OPT_REQ	__BIT(3)
#endif	//READER_TYPES2

/*operation times*/
#define	OPT_TIME_ONE	0x00
#define OPT_TIME_REP	0x01


#endif // __CMD_DEF_H__
