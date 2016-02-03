/*
* main.c 
*/
#define  __MAIN_C__
/*include the sys header file*/

/*include user-defined header file*/
#include <user-defined-headers.h>

/*define golable varibles*/

int load_sysparam(const char* file_name){
	return 0;
}
int main()
{
/*1.0 loading system parameter form configure file*/
	sysparam_init();
/*1.1 initiating the environments*/
	evn_init();
/*1.2 initiating the boards's hardware*/
	dev_init();
/*1.3 initiating the system thread manage*/
	thrd_init();
/*1.4 initiating the connection method*/
	conn_init();
/*2.0 enter the main loop*/
	while(1){

	}
	exit(0);
	return 0;
}
