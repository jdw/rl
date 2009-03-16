#include "io.h"
//#include "basemessage.h"
#include "global.h"
#include "messages.h"
#include "toolkit.h"

IO::IO(list<BaseMessage*>* in_pQue, bool* tmp_quit)
: BaseSystem(GamePart::IO, in_pQue), quit(tmp_quit) {
	
}

IO::~IO() {
}

int IO::Init() {
	START
	
	STOP
}

int IO::Deinit() {
	START
	
	STOP
}

int IO::Update() {
	START
	
	int c = getch(); // refresh, accept single keystroke of input
	//if (show) cout << c << endl;

	switch (c) {
		case 27: { // ESC
			*quit = TRUE;
		}	break;
		
		case 112: { // "p"
			//show = !show;
			//pMsgQue->push_back(new PrintMessage("Hej"));
		} break;
		
		case KEY_DOWN: {
			/*
			if (wmove(win[0], y + 1, x) != ERR) {
				wmove(win[0], y, x);
				waddch(win[0], '.');
				y++;
				wmove(win[0], y, x);
				waddch(win[0], '@');
			}
			*/
		} break;
		
		case KEY_UP: {
		
		} break;
		
		case KEY_LEFT: {
			//pMsgQue->push_back(new MoveMsg());
		} break;
		
		case KEY_RIGHT: {
			
		} break;
	}
	
	STOP
}

int IO::UpdateMsgs() {
	START

	LOGF("Me: %d", me);
	
	list<BaseMessage*>::iterator it;
	for (it = pMsgQue->begin(); it != pMsgQue->end(); it++) {
		LOGF("(*it)->GetReceiver(): %d", (*it)->GetReceiver());
		LOGF("(*it)->GetType(): %d", (*it)->GetType());
		
		if ((*it)->GetReceiver() != me) continue; // If this class is not the addressee, skip this msg
		
		switch ((*it)->GetType()) {
			case MessageType::PLAYERID: {
				playerId = ((PlayerIdMsg*)(*it))->GetId();
				LOGF("playerId: %d", playerId);	
				(*it)->SetValid(FALSE);
			} break;
		
		}
	}
	
	STOP
}
