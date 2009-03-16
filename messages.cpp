#include "messages.h"

PrintMsg::PrintMsg(GamePart::Enum in_tran, GamePart::Enum in_rec, int in_delay, string in_msg)
: BaseMessage(MessageType::PRINT, in_tran, in_rec, in_delay)
, msg(in_msg) {
}

PrintMsg::~PrintMsg() {

}

/*
SayMessage::SayMessage(BaseActor* in_from, BaseActor* in_to, string in_msg)
: BaseMessage(MessageType::SAY)
, from(in_from), to(in_to), msg(in_msg) {

}

SayMessage::~SayMessage() {

}
*/

MoveMsg::MoveMsg(GamePart::Enum in_from, GamePart::Enum in_to, int in_delay)
: BaseMessage(MessageType::MOVE, in_from, in_to, in_delay) {
		
}

MoveMsg::~MoveMsg() {
	
}

PlayerIdMsg::PlayerIdMsg(GamePart::Enum in_from, GamePart::Enum in_to, int in_id)
: BaseMessage(MessageType::PLAYERID, in_from, in_to, 0), id(in_id) {
		
}

PlayerIdMsg::~PlayerIdMsg() {
	
}
