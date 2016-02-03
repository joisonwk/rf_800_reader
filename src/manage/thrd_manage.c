/*
*	src/manage/thrd_manage.c
*/
#define __THRD_MANAGE_C__

#include <manage/thrd_manage.h>

static THRD_DATA_T* pthrd_head;

int thrd_init(){
/*1.1 create and initiating the task head*/	
	pthrd_head = NULL;
/*1.2 create the insert the default process task according information procedure*/
/*1.3 */
}

/**/
int thrd_add(THRD_DATA_T *task){
	THRD_DATA_T* tmp_thrd = NULL;

	if(task == NULL){
		return EINVAL;
	}	

	/*insert the task to the tail*/
	for(tmp_thrd=pthrd_head;;tmp_thrd = tmp_thrd->next){
		if(NULL = tmp_thrd){
			tmp_thrd = task;
			break;
		}
	};

	return 0;
}

void thrd_exit(void){
	THRD_DATA_T* tmp_thrd = pthrd_head;
	while(tmp_thrd){
		pthrd_head = tmp_thrd->next;	
			
		if(tmp_thrd->thrd_init_arg){
			free(tmp_thrd->thrd_init_arg);
			thrd_init_arg = NULL;
		}

		if(tmp_thrd->thrd_main_arg){
			free(tmp_thrd->thrd_main_arg);
			tmp_thrd->thrd_main_arg = NULL;
		}
	};
}
