#ifndef SB_IO_H___
#define SB_IO_H___

#include "basesystem.h"

class BaseMessage;

class IO : public BaseSystem {
public:
	IO(list<BaseMessage*>* in_pQue, bool* in_quit);
	~IO();
	
	int Init();
	int Deinit();
	int Update();
	int UpdateMsgs();
	
private:
	bool* quit;
	
};
#endif
