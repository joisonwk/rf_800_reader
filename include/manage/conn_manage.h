/*
* src/manage/conn_manage.h
* joison, 20160201
* manage the networking connection
*/
#ifndef __CONN_MANAGE_H__
#define __CONN_MANAGE_H__
#include <util/invengo_log.h>
#include <invengo-protocol/frame_parse.h>
#ifndef __CONN_MANAGE_C__
#define CONN_EXTERN extern
#else
#define CONN_EXTERN
#endif

#define MAX_CONNTYPE 32
enum conn_type{
	E_CT_COM = 0,
	E_CT_INNER_COM,
	E_CT_IRP_TCP,
	E_CT_IRP_UDP,
	E_CT_BT,
	E_CT_RS485,
	E_CT_MAX MAX_CONNTYPE,
};
typedef enum conn_type CONN_TYPE_T;

typedef struct conn_method_data {
	int fd;		//connect file descriptor	
} CONN_MTHD_DATA_T;
typedef struct conn_data{
	unsigned int cd_state;		//record communication methods
	CONN_MTHD_DATA_T* cd_methods[MAX_CONNTYPE];
}CONN_DATA_T;

/*conn_init: create the communication facilities*/
CONN_EXTERN int conn_init(void);
/*conn_exit: free the connection task*/
CONN_EXTERN int conn_exit(void);
/*conn_add: according connection type create and insert new communication method*/
CONN_EXTERN int conn_add(CONN_TYPE_T conn);
/*conn_del: free and delte the connnect method*/
CONN_EXTERN int conn_del(CONN_TYPE_T conn);
/*get_data_handle: get the raw data from the connection*/
CONN_EXTERN DATA_HANDLE_T* get_data_handle();

#endif	//__CONN_MANAGE_H__

