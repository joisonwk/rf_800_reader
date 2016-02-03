/*include/invengo-protocol/reader_opt.h*/
/*joison, 20160201
*this file refer to the section 2.4 reader operation process
*/
#ifndef __READER_OPT_H__
#define __READER_OPT_H__
#ifndef __READER_OPT_C__
#include <invengo-protocol/cmd_def.h>
#include <invengo-protocol/invengo-types.h>
#include <invengo-protocol/invengo-errno.h>
#define RO_EXTERN	extern
#else
#define RO_EXTERN
#endif
/*2.4 reader operation*/
RO_EXTERN ROERR_reader_cmd_process(ST_CMD_T* pcmd);
/*	2.4.1 open power amplifier operation*/
/*we need indicate the antenna number when open the amplifier, the antenna defined in the FILE[cmd_def.h] */
RO_EXTERN int open_amp(unsigned char ant_num);
/*	2.4.2 close power amplifier operation*/
RO_EXTERN int close_amp(unsigned char ant_num);
/*	2.4.3 query or set the reader parameter*/
RO_EXTERN int rd_prmt_opt(ST_CMD_T* pcmd);
/*	2.4.4 query or set the tag operation parameter*/
RO_EXTERN int tag_prmt_opt(ST_CMD_T* pcmd);
/*	2.4.5 calibrate reader system parameter */
RO_EXTERn int 
/*	2.6.7 reader test mode seting*/
/*	2.6.8 update command*/
/*	2.6.9 restart command*/

#endif //__READER_OPT_H__
