#ifndef SB_TOOLKIT_H___
#define SB_TOOLKIT_H___

#include "global.h"

void LogFile(const char *in_fileName, const char *in_funcName, int in_line, const char * in_log, ... );

#define LOGF(f, s...) LogFile(__FILE__, __FUNCTION__, __LINE__, f, s)
#define LOG(f) LogFile(__FILE__, __FUNCTION__, __LINE__, f)
#define START LOG("Start"); int err = 0;
#define STOP LOG("Stop"); if (err) LOG("err not 0!");
#endif
