/*joison,20160201*/
/*include/invengo-protocol/invengo_errno.h*/
/*invengo error code tables, refer to error table of invengo reader and writer protocol manual*/
#ifndef __INVENGO_ERR_CODE_H__
#define __INVENGO_ERR_CODE_H__
/*there are table index for the following tables*/
#define __READER_SYS_ERR_CODE	//0x01-0x5f	refer to table C.1
#define __READER_OPT_ERR_CODE	//0x11-0x1f	refer to TABLE C.2
#define __CMD_RSSND_ERR_CODE	//0x20-0x3f	refer to TABLE C.3
#define __EPCC1G2_ERR_CDOE	//0x60-0x7f	refer to TABLE C.4
#define __ISO18K6A_ERR_CODE	//0x80-0x8f	refer to TABLE C.5, this is not define in the invengo reader protocol manual
#define __ISO18K6B_ERR_CODE	//0x90-0x9f	refer to TABLE C.5
#define __UNDEF_ERR_CODE	//0xa0-0xff 

/*reader error code, refer to error table C.1*/
#ifdef __SYS_ERR_CODE
#define RSERR_CODEC_REV	0x01	//reader FPGA/DSP software error
#define RSERR_BSBDHW_REV	0x02	//base board hardware revesion error
#define RSERR_RFBDHW_REV	0x03	//RF board hardware revesion error
#define RSERR_SYSPARA	0x04	//
#endif

/*reader operation error, refer to error TABLE C.2*/
#ifdef __READER_OPT_ERR_CODE	
#define ROERR_PASSWD	0x11
#define ROERR_ANT	0x12
#define ROERR_TSTMD	0x13
#endif 	//__READER_OPT_ERR_CODE

/*command transfer error when send or recieve, refer to error TABLE C.3*/
#ifdef __CMD_RSSND_ERR_CODE
#define CRSERR_UNCOMPLETE	0x20	
#endif //__CMD_RSSND_ERR_CODE

/*EPC tag operation error, refer to error table C.4*/
#ifdef __EPCC1G2_ERR_CDOE	
#define EOERR_UNRSPN	0x60	//the epc tag non-existent or not responding
#endif //__EPCC1G2_ERR_CDOE

/*ISO18K-6B or ISO18K-6A tag operation error code , refer to error TABLE C.5*/
#if defined __ISO18K6A_ERR_CODE || __ISO18K6B_ERR_CODE
#define IOERR_UNRSPN	0x90	//non-existent or tag not responding
#endif 

#endif //__INVENGO_ERR_CODE_H__
