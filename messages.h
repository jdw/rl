#ifndef SB_MESSAGES_H___
#define SB_MESSAGES_H___

#include "global.h"
#include "basemessage.h"

class BaseActor;

class PrintMsg : public BaseMessage {
public:
	PrintMsg(GamePart::Enum in_tran, GamePart::Enum in_rec, int in_delay, string in_msg);
	~PrintMsg();
	
	const string msg;
	
private:
};
/*
class SayMsg : public BaseMessage {
public:
	SayMsg(BaseActor* in_from, BaseActor* in_to, string in_msg);
	~SayMsg();
	
	const string msg;
	BaseActor* from;
	BaseActor* to;
	
private:
};
*/
class MoveMsg : public BaseMessage {
public:
	MoveMsg(GamePart::Enum in_from, GamePart::Enum in_to, int in_delay);
	~MoveMsg();
	
};

class PlayerIdMsg : public BaseMessage {
public:
	PlayerIdMsg(GamePart::Enum in_from, GamePart::Enum in_to, int in_id);
	~PlayerIdMsg();
	
	int GetId() { return id; }

private:
	int id;

};
#endif
