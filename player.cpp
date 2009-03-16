#include "player.h"
#include "toolkit.h"

Player::Player(int in_id, ActorSex::Enum in_sex, string in_name)
: BaseActor(ActorType::PLAYER, in_id, in_sex, in_name) {
	//symbol = '@';
	
}

Player::~Player() {

}

int Player::Update() {
	START

	STOP
}
