#ifndef __INVENGO_LOG_H__
#define __INVENGO_LOG_H__
enum invg_log_type {
	INVG_LT_MIX,		//not unclassed
	INVG_LT_SYSCONF,	//system parameter config error
	INVG_LT_THRD_MANAGE,	// task schedule
	INVG_LT_CONN_MANAGE,	// network connection
	INVG_LT_PROTOCOL,	// reader protocol
	INVG_LT_DB,		//database error
	INVG_LT_UART,
	INVG_LT_ETHER,
	INVG_LT_BLT,
	INVG_LT_FRAME_PARSE,
	INVG_LT_CMD_PROCESS,
	INVG_LT_ARM7,
	INVG_LT_MAX_DEV=1024;
}
typedef enum invg_log_type E_INVG_DEV_T;

enum invg_log_level {
	INVG_LOGLVL_FATAL,
	INVG_LOGLVL_ERR,
	INVG_LOGLVL_INFO,
	INVG_LOGLVL_DBG,
}
typedef enum invg_log_level E_INVG_LOGLVL_T;

#define __DEVNO_TO_STR(devno) do{\
	devno == INVG_LT_MIX? "mix" :\
	devno == INVG_LT_SYSCONF? "sysconf" :\
	devno == INVG_LT_THRD_MANAGE? "thrd_manage" : \
	devno == INVG_LT_CONN_MANAGE? "conn_manage" : \
	devno == INVG_LT_PROTOCOL? "protocol" :	\
	devno == INVG_LT_DB?	"rd_db" : \
	devno == INVG_LT_UART? "uart" : \
	devno == INVG_LT_ETHER? "ether" : \
	devno == INVG_LT_BLT? "blue_tooch" : \ 
	devno == INVG_LT_FRAME_PARSE? "frame_parse" : \
	devno == INVG_LT_CMD_PROCESS? "cmd_process":\
	devno == INVG_LT_ARM7? "arm7":\
	"undefine";\
}while(0);

#ifdef INVG_RELEASE	
#define INVG_LOG_FATAL(dev, fmt, arg...)
#define INVG_LOG_ERR(dev, fmt, arg...)
#define INVG_LOG_INFO(dev, fmt, arg...)
#define INVG_LOG_DBG(dev, fmt, arg...)
#define PRINT_BUF(buf, len)
#else
/**/
inline void invg_log_print(int log_level, const char* fmt, ...);

#define INVG_LOG_FATAL(dev, fmt, arg...) do{\
	invg_log_print(INVG_LOGLVL_FATAL, \
	"[FATAL][%s:%d %s] %s:"fmt, __FILE__, __LINE__, \
	__FUNCTION__, __DEVNO_TO_STR(dev), ##arg); \
	abort();	\
}while(0);

#define INVG_LOG_ERR(dev, fmt, arg...) do{\
	invg_log_print(INVG_LOGLVL_ERR, dev, \
	"[ERR][%s:%d %s] %s:"fmt, __FILE__, __LINE__, \
	__FUNCTION__, __DEVNO_TO_STR(dev), ##arg); \
}while(0);

#define INVG_LOG_INFO(dev, fmt, arg...) do{\
	invg_log_print(INVG_LOGLVL_INFO, dev, \
	"[INFO][%s:%d %s] %s"fmt, __FILE__, __LINE__, \
	__FUNCTION__, __DEVNO_TO_STR(dev), ##arg); \
}while(0);

#define INVG_LOG_DBG(dev, fmt, arg...) do{\
	invg_log_print(INVG_LOGLVL_DBG,\
	"[DBG][%s:%d %s] %s"fmt, __FILE__, __LINE__, \
	__FUNCTION__, __DEVNO_TO_STR(dev), ##arg); \
}while(0);

#define PRINT_BUF(buf, len) do{\
	invg_log_print(INVG_LOGLVL_DBG, \
	"[PRINT_BUF][%s:%d %s] "fmt, __FILE__, __LINE__, \
	__FUNCTION__,##arg)\
}while(0);
#endif

#endif//__INVENGO_LOG_H__
