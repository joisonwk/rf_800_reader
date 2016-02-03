/*
*	src/invengo-protocol/cmd_process.c
*/
#define __CMD_PROCESS_C__
#include <semaphore.h>

#include <manage/thrd_manage.h>
#include <invengo-protocol/cmd_process.h>

static THRD_DATA_T* cp_task = NULL;	//cmd process task 

int cmd_process_init(){
	int ret = -1;
	ssize_t td_size = sizeof(THRD_DATA_T);
	cp_task = malloc(td_size);	
	if(NULL = cp_task){
		INVG_LOG_ERR(DEV_CMD_PROCESS,"allocate memory for commond parsing task failed\n");
		return ENOMEM;
	}

	memset(task, 0, td_size);
	ret = sem_init(&cmd_process_task);
	if(ret < 0)
		goto sem_init_err;	
	thrd_add(task);
	return 0;

sem_init_err:
	free(task);
	return ret;
}

void cmd_process_exit(){
	/**/
}
thrd_add();
