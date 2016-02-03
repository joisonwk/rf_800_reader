/*src/util/invengo_log.h*/
#define __INVENGO_LOG_H__
#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>
#include <util/invengo_log.h>

#define LOG_IDENT	

static E_INVG_LOGLVL_T invg_dbg_level = 0;
void invg_log_print(E_INVG_LOGLVL_T log_level,const char* fmt, ...){
	if(log_level<=invg_dbg_level){
		syslog(LOG_DEBUG, fmt, ...);
	}	
}

int invg_log_init(E_INVG_LOGLVL_T dbg_level){
	invg_dbg_level = dbg_level
	opensys(LOG_IDENT, LOG_ODELAY, LOG_USER);
}
