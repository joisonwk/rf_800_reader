/*include/invengo-types.h*/
#ifndef __INVENGO_TYPES_H__
#define __INVENGO_TYPES_H__

/*
*area length limitation
*/
#define MAX_CMD_PRMT_LEN	510
#define MAX_CMD_LEN	(MAX_CMD_PRMT_LEN+3)	//cmd = buf[n] + type + len[2]
#define MAX_FRAME_LEN	(MAX_CMD_LEN+2)		//frame = cmd + frame header byte	

/*
*frame definition
*/
enum frame_state{
	FMST_LENGTH16_HIGH,
	FMST_LENGTH16_LOW,
	FMST_RS485_FLAG,	/*when the frame is rs485, after the length is 485 flag*/
	FMST_RS485_ADD,	/*after the rs485 flag is one byte address*/
	FMST_DATA,
	FMST_CRC16_HIGH,
	FMST_CRC16_LOW,	
	FMST_COMPLITE,
	FMST_CODE_ERROR,
};
typedef enum frame_state E_FMST_T;

enum frame_type {
	FMTP_RS232,
	FMTP_RS485,
};
typedef enum frame_type E_FMTP_T;

#define FMFG_HEAD	0x55
#define	FMFG_RS485_FLAG	0xde

struct rs232_frame_data{
	E_FMTP_T	frame_type;
	unsigned short frame_len;
	E_FMST_T	frame_state;
};
typedef struct rs232_frame_data ST_RS232_FRAME_T;

#endif //__INVENGO_TYPES_H__
