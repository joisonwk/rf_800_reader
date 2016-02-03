/*include/invengo-protocol/cmd_process.h*/

#ifndef __CMD_PROCESS_H__
#define __CMD_PROCESS_H__
#include <invengo_types.h>

#ifndef __CMD_PROCESS_C__
#define CMD_PROCESS_EXTERN extern
#else
#define CMD_PROCESS_EXTERN 
#endif

/*command struct*/
typedef struct cmd_data{
	unsigned short 	cmd_len;
	unsigned char	cmd_type;
	unsigned char	cmd_prmt[MAX_CMD_PRMT_LEN];
	unsigned char cmd_crc16[2];
	struct cmd_data* next;
}ST_CMD_T;

/*insert new command to the command process task*/
CMD_PARSE_EXTERN cmd_insert(ST_CMD_T* new_cmd);

#endif //__CMD_PROCESS_H__
