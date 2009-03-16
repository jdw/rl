#include "baseactor.h"

BaseActor::BaseActor(ActorType::Enum in_type, int in_id, ActorSex::Enum in_sex, string in_name)
	: BaseTile(in_id), sex(in_sex), type(in_type) {
		SetTileType(TileType::ACTOR);
		SetName(in_name);
		SetSymbol('T');	
	}
	
BaseActor::~BaseActor() {
	
}
