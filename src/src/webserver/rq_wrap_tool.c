#include "web_app_api.h"
#include "rq_head.h"


PUBLIC int process_web_write_response(Webs *wp, int code, char *buf, int size){
	/* need route the code num in the future */
	websSetStatus(wp, code);
	websWriteHeaders(wp, -1, 0);
	websWriteEndHeaders(wp);
	/* need check the size  */
	websWrite(wp, buf);
	websDone(wp);
}

