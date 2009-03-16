#include "game.h"
#include "io.h"
#include "scene.h"
#include "ui.h"
#include "messages.h"
#include "basemessage.h"
#include "toolkit.h"

Game::Game()
: quit(false) {

}

Game::~Game() {

}

int Game::Init() {
	START
	
	sys[GamePart::IO] = new IO(&messages, &quit);
	sys[GamePart::SCENE] = new Scene(&messages);
	sys[GamePart::UI] = new UI(&messages);
	/*
	for (int i = 0; i < GamePart::MAX; i++) {
		if (err) break;
		switch (i) {
			case GamePart::IO: {
				err += (io*)sys[i]->Init();
			} break;
			
			case GamePart::SCENE: {
				err += (scene*)sys[i]->Init();
			} break;
			//ACTORS, // Player, enemies, creatures, NPCs... (anything living)
			//ITEM, // Stones, budles of mud, cookies, swords... (anything movable/usable/interactable, non-living thing)
			//PROPS, // Boulder, wall, floor, ocean of mud (anything unmovable)
			
			case GamePart::UI: {
				err += (ui*)sys[i]->Init();
			} break;
		}
	}
	*/
	
	for (int i = 0; i < GamePart::MAX; i++)
		err += sys[i]->Init();
	
	STOP
}

int Game::Update() {
	START
	
	while (!quit) {
		for (int i = 0; i < GamePart::MAX; i++) {
			LOGF("Updating GamePart: %d", i);
			err += sys[i]->UpdateMsgs();
			err += sys[i]->Update();
		}
		
		err += UpdateMsgs();
	}
	
	STOP
}

int Game::UpdateMsgs() {
	START
	list<BaseMessage*>::iterator it;
	// rm invalid, split to net
	for (it = messages.begin(); it != messages.end();) {
		if (!(*it)->GetValid()) {
			if ((*it)->GetNext() != (BaseMessage*)0) {
				messages.push_back((*it)->GetNext());
				(*it)->SetNext((BaseMessage*)0);
			}
			
			BaseMessage* tmp_msg = (*it);
			it = messages.erase(it);
			delete tmp_msg;
		}
		else {
			it++;	
		}			
	}
	
	STOP
}

// Quiting/stopping systems and exits
int Game::Deinit() {
	START

	for (int i = 0; i < GamePart::MAX; i++) {
		err += sys[i]->Deinit();
	}
	
	STOP
}
