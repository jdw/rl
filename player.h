#ifndef SB_PLAYER_H___
#define SB_PLAYER_H___

#include "baseactor.h"

class Player : public BaseActor {
public:
	Player(int in_id, ActorSex::Enum in_sex, string in_name);
	~Player();
	
	int Update();

private:
	
};
#endif
