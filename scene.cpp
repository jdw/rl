#include "scene.h"
#include "messages.h"
#include "player.h"
#include "toolkit.h"

namespace ScenePart {
	enum Enum {
		HAS_ITEM = 1<<0,
		HAS_OBJECT = 1<<1,
		HAS_ACTOR = 1<<2,
		BLOCKS_MOVEMENT = 1<<3,
		BLOCKS_LIGHT = 1<<4,
		IS_MAPPED = 1<<5,
		IS_VISIBLE = 1<<6	
	};	
}

Scene::Scene(list<BaseMessage*>* in_pQue)
: BaseSystem(GamePart::SCENE, in_pQue) {
//CheckPtr
}

Scene::~Scene() {
	
}

int Scene::Init() {
	START

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			scene[i][j] = 0;

	// create message here with players id and tell all systems
	if (playerId == 0) {
		playerId = GetNewId();
		
		PlayerIdMsg* pPIDMsg;
		pPIDMsg = new PlayerIdMsg(GamePart::SCENE, GamePart::IO, playerId);
		pMsgQue->push_back(pPIDMsg);
		pPIDMsg = new PlayerIdMsg(GamePart::SCENE, GamePart::UI, playerId);
		pMsgQue->push_back(pPIDMsg);
		//pPIDMsg = 0;
	}
	
	STOP
}

int Scene::Deinit() {
	START
	
	STOP
}

int Scene::Update() {
	START
	
	STOP
}

int Scene::UpdateMsgs() {
	START
	
	STOP
}
