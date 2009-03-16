#include "basemessage.h"

BaseMessage::BaseMessage(MessageType::Enum in_type, GamePart::Enum in_tran, GamePart::Enum in_rec, int in_delay) :
type(in_type), transmitter(in_tran), receiver(in_rec), delay(in_delay), isValid(TRUE) {
	//Check(in_type < MessageType::MAX);	
	pNext = (BaseMessage*)0;
	
}

BaseMessage::~BaseMessage() {
	
}
