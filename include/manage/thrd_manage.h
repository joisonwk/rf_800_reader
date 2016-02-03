/**
* include/manage/thrd_manage.h
*
*/
#ifndef __THRD_MANAGE_H__
#define __THRD_MANAGE_H__
#ifndef __THRD_MANAGE_C__

#include <semaphore.h>

#define THRD_EXTERN	extern
#else
#define THRD_EXTERN	
#endif

typedef enum thrd_flag {
	FRAME_TF,
	CMD_PARSE_TF,
	ARM7_TF,	
} E_THRD_FLAG_T;

/*the task interface*/
typedef int (* THRD_INIT_T)(void* thrd_data);
typedef void (* THRD_EXIT_T)(void);
typedef void (* THRD_MAIN_T)(void);

/*task context*/
typedef struct thrd_data{
	sem_t	thrd_sem;	
	E_THRD_FLAG_T thrd_flag;	 
	void* thrd_init_arg;	//task initiate data
	THRD_INIT_T thrd_init;
	void* thrd_main_arg;	//task main process data
	THRD_MAIN_T thrd_main;
	THRD_EXIT_T thrd_exit;
	struct thrd_data* next;
}THRD_DATA_T;


/*initiate the task schedule*/
THRD_EXTERN int thrd_init();
THRD_EXTERN int thrd_add(THRD_DATA_T* new_thrd);
THRD_EXTERN void thrd_exit(void);

#endif //__THRD_MANAGE_H__
