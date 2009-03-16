#include "toolkit.h"
#include "global.h"

//void Logf(const char *szFileName, int iLineNo, const char *szErr,...) {
void LogFile(const char *in_fileName, const char *in_funcName, int in_line, const char * in_log, ... ) {
	char buf[2000];
	FILE* pLog = fopen("log.txt", "a");
	
	va_list args;
  va_start(args, in_log);
  vsprintf(buf, in_log, args);
 
	if (pLog != NULL) {
		fprintf(pLog, " %s:%d in %s: %s\n", in_fileName, in_line, in_funcName, buf);
		fclose(pLog);
	}
	
	va_end(args);
}
