#include "basesystem.h"

BaseSystem::BaseSystem(GamePart::Enum in_me, list<BaseMessage*>* in_pMessageQue)
: me(in_me), pMsgQue(in_pMessageQue), playerId(0) {
	//Check(0 <= in_me && in_me < GamePart::MAX);
	// CheckPtr(in_pMessageQue);
	
}

BaseSystem::~BaseSystem() {

}
