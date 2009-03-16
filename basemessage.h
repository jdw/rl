#ifndef SB_BASEMESSAGE_H___
#define SB_BASEMESSAGE_H___

#include "game.h"

namespace MessageType {
	enum Enum {
		DAMAGE = 0,
		HEAL,
		SAY,
		DIE,
		KILL,
		TELEPORT,
		SOUND,
		PRINT,
		MOVE,
		PLAYERID,
		
		MAX // Faulty
	};
}

class BaseMessage {
public:
	~BaseMessage();
	
	MessageType::Enum GetType() { return type; }
	GamePart::Enum GetReceiver() { return receiver; }
	GamePart::Enum GetTransmitter() { return transmitter; }
	int GetDelay() { return delay; }
	BaseMessage* GetNext() { return pNext; }
	bool GetValid() { return isValid; }
	
	void SetDelay(int in_del) { delay = in_del; }
	void SetNext(BaseMessage* in_pNext) { /*Checkptr...*/ pNext = in_pNext; }
	void SetValid(bool in_valid) { isValid = in_valid; }
	
protected:
	BaseMessage(MessageType::Enum in_type, GamePart::Enum in_tran, GamePart::Enum in_rec, int in_delay);
		
private:
	const MessageType::Enum type;
	const GamePart::Enum receiver;
	const GamePart::Enum transmitter;
	int delay;
	BaseMessage* pNext;
	bool isValid; // FALSE if it is time to throw away
	
};
#endif
