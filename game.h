#ifndef SB_GAME_H___
#define SB_GAME_H___

//#include "basesystem.h"
#include "global.h"

class BaseSystem;
class BaseMessage;

namespace GamePart {
	enum Enum {
		IO = 0, // IO gotta go first! (Redirects messages, ends game)
		SCENE, // Map (Stuff that is not movable (walls, trees, doors, floor, sea...)
		//ACTORS, // Player, enemies, creatures, NPCs... (anything living)
		//ITEM, // Stones, budles of mud, cookies, swords... (anything movable/usable/interactable, non-living thing)
		//PROPS, // Boulder, wall, floor, ocean of mud (anything unmovable)
		UI, // Last (to see results of last update), shows money, messages, menus...
		
		MAX // Faulty
	};
}

class Game {
public:
	Game();
	~Game();
	
	int Init();
	int Deinit();
	int Update();
	int UpdateMsgs();

private:
	BaseSystem* sys[GamePart::MAX];
	bool quit;
	list<BaseMessage*> messages;
	
};
#endif
