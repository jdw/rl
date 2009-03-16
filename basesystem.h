#ifndef SB_BASESYSTEM_H___
#define SB_BASESYSTEM_H___

#include "global.h"
#include "game.h"
//#include "basemessage.h"
class BaseMessage;

class BaseSystem {
public:
	~BaseSystem();
	
	virtual int Init() = 0;
	virtual int Deinit() = 0;
	virtual int Update() = 0;
	virtual int UpdateMsgs() = 0;

protected:
	BaseSystem(GamePart::Enum in_me, list<BaseMessage*>* in_pMessageQue);
	
	std::list<BaseMessage*>* pMsgQue;
	int playerId;
	const GamePart::Enum me; // Type of system (Game.h)
	
private:
	
};
#endif
