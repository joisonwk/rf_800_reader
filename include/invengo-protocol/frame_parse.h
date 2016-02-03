/*include/invengo-protocol/frame_parse.h*/

#ifndef __FRAME_PARSE_H__
#define __FRAME_PARSE_H__

/*include the user header files*/
#include <manage/conn_manage.h>

#ifndef __FRAME_PARSE_C__
#define FRAME_PARSE_EXTERN	extern
#else
#define FRAME_PARSE_EXTERN
#endif

/*frame type*/
typedef enum frame_type{
	FM_TP_RS232,	
	FM_TP_RS485,
}E_FPM_T;

/*the frame data struct*/
typedef struct frame_data {
	E_FPM_T fd_method;	//frame parse method
	unsigned int fd_len;	//frame len
	char fd_buf[MAX_FRAME_LEN];	//frame buf
	struct frame_data* next;	//next frame
}FM_DATA_T;

FRAME_PARSE_EXTERN int frame_init(void);

#endif// __FRAME_PARSE_H__

