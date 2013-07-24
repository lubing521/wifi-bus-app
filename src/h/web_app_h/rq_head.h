/*
    rq_head.h -- webserver web layer Header
  
    Copyright (c) All Rights Reserved. See details at the end of the file.
 */

#ifndef RQ_HEAD_H_
#define RQ_HEAD_H_

#define BUS_SEARCH_LINE	"type_line"
#define BUS_SEARCH_STA		"type_sta"
#define BUS_SEARCH_RIDE	"type_ride"

/******************** bus���ò���  ***************************/
#define BUS_CONFIG_CUR_LINE		"cur_line"
#define BUS_CONFIG_STA_STATUS		"sta_status"

#define RET_ERROR		-1
#define RET_OK			0

#define TEST_PRA_STR_NOT_VOLID(x)		\
	( (NULL == x) || (strcmp(x, "") == 0) || (strlen(x) <=0) )

#define DEBUG 1
#if DEBUG			
#define WEB_STRACE(format,...) \
		printf("WEB_STRACE <%10s> <%04d> "format"\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)
#else
	#define WEB_STRACE(format,...)
#endif

#define JSON_STR_FREE(x)	\
	if(x){ free(x); }

/* ��������״̬ */
enum{
	HELP_SUCCESS = 1,
	HELP_HW_ERROR,
	HELP_NETWORK_ERROR,
	HELP_FORBID,
	HELP_NOT_PERMIT
}help_status;
/* ��·���� */
enum{
	KIND_OUTBOUND = 1,
	KIND_INBOUND,
	KIND_LOOP
}line_kind;

/* �г�״̬ */
enum{
	BUS_STATUS_IN_STATION = 1,	 //��վ
	BUS_STATUS_INBOUND,		//��վ,ָ����ʻ���վ
	BUS_STATUS_OUTBOUND,	//��վ,ָ����ʻ���վ
	BUS_STATUS_TERMINAL,		//�����յ�վ
	BUS_STATUS_BEGIN,			//��ʼ����
	BUS_STATUS_MAX			//״̬���ֵ
}bus_drv_status;

enum{
	STA_PASSED = 1,				//�Ѿ�����
	STA_IN_STA,					//��վ��
	STA_INBOUND,				//��վ
	STA_OUTBOUND,				//��վ
	STA_NOT_REACH				//δ����
}sta_status;

/* ******************* function prototype ******************* */

/*
 *		a wrap function of write response
 *		@param code 
 				the http response status number
 *		@param buf 
 				the buffer pointer which will output to browser
 * 		@param size
 				the buffer size
 *		@return write json format data to page
 */
PUBLIC  int process_web_write_response(Webs *wp, int code, char *buf, int size);

#endif

