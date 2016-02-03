/* src/util/sysconf.c*/
#define __SYSCONF_C__
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/*self defined header*/
#include <util/invengo_log.h>
#include <util/sysparam.h>
struct sysparam_data{
		
};

/*system parameter validity checking*/
inline bool chkvld_sysparam(E_SYSPARAM_TYPE_T param_type){
	if((param_type<=SP_MIN) || param_type>=SP_MAX){
		/*print error log and return errno*/
	}
}

/*configure the system structure frome the configure file*/
int load_sysparam(const char* file_name){
	int fp = -1;

	fp = open(file, O_RDWR | O_CREAT);
	if(fd<0){
		INVG_DBG("");
	}
}

int set_sysparam(const void* data, E_SYSPARAM_TYPE_T param_type){
	if(data==NULL || chkvld_sysparam(param_type)){
		/*return errno and record the error information*/
		return -1;//return the error number
	}	
	/**/
	switch(param_type){
	case 1:
	}
}

