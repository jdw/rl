#ifndef SB_BASEACTOR_H___
#define SB_BASEACTOR_H___

#include "basetile.h"

namespace ActorType {
	enum Enum {
		PLAYER = 0,
		BADBOY,
		
		MAX // Faulty
	};
}

namespace ActorSex {
	enum Enum {
		MALE = 0,
		FEMALE,
		ANDROGYNOUS,
		
		MAX // Faulty
	};
}

class BaseActor : public BaseTile {
public:
	~BaseActor();
	
	ActorType::Enum GetType() { return type; }
	
protected:
	BaseActor(ActorType::Enum in_type, int in_id, ActorSex::Enum in_sex, string in_name);


	virtual int Update() = 0;
			
private:
	ActorType::Enum type;
	ActorSex::Enum sex;
	
	// inventory
	// health
	// damage
};
#endif
