#include "ui.h"
#include "basemessage.h"
#include "messages.h"
#include "game.h"
#include "toolkit.h"

UI::UI(list<BaseMessage*>* in_pQue)
: BaseSystem(GamePart::SCENE, in_pQue) {
	
}

UI::~UI() {
	
}

int UI::Init() {
	START
	
	//(void) signal(SIGINT, finish);/* arrange interrupts to terminate */
	(void) initscr();      /* initialize the curses library */
	keypad(stdscr, TRUE);  /* enable keyboard mapping */
	(void) nonl();         /* tell curses not to do NL->CR/NL on output */
	(void) cbreak();       /* take input chars one at a time, no wait for \n */
	(void) noecho();       /* don't echo input */
	curs_set(0); // Hiding cursor
	
	// Color assignment
	if (has_colors()) {
		start_color();
		init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
		init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
		init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
		init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
		init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
		init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
	}
	
	// Windows
	win[UIWindow::STATUS] = newwin(LINES - 9, 30, 0, COLS - 30); // Status
	win[UIWindow::MESSAGES] = newwin(10, COLS, LINES - 10, 0); // Messages
	box(win[UIWindow::STATUS], 0, 0);
	box(win[UIWindow::MESSAGES], 0, 0);
	
	panel[UIWindow::WORLD] = new_panel(win[UIWindow::WORLD]);
	panel[UIWindow::STATUS] = new_panel(win[UIWindow::STATUS]);
	panel[UIWindow::MESSAGES] = new_panel(win[UIWindow::MESSAGES]);
	
	update_panels();
	doupdate();
	//refresh();
	
	STOP
}

int UI::Deinit() {
	START
	endwin();
	
	STOP
}

int UI::Update() {
	START

	int p = 0;
	for (list<string>::iterator it = lines.begin(); it != lines.end(); it++) {
		p++;
		if (wmove(win[UIWindow::MESSAGES], 9 - (p + 1), 2) == ERR) break;
		waddstr(win[UIWindow::MESSAGES], (*it).c_str());
	}
	
	update_panels();
	doupdate();
	//refresh();
	
	STOP
}

int UI::UpdateMsgs() {
	START
	
	LOGF("Me: %u", me);
	
	// Interpreting messages
	for (list<BaseMessage*>::iterator it = pMsgQue->begin(); it != pMsgQue->end(); it++) {
		switch ((*it)->GetType()) {
			case (MessageType::PRINT): {
				/*
				lines.push_front(((PrintMsg*)(*it))->msg);
				PrintMsg* tmp_msg = (PrintMsg*)(*it);
				delete tmp_msg;
				it = pMsgQue->erase(it);
				*/
			} break;
			
			case MessageType::PLAYERID: {
				playerId = ((PlayerIdMsg*)(*it))->GetId();
				LOGF("playerId: %d", playerId);
				(*it)->SetValid(FALSE);
			} break;
		}
	}
	
	STOP
}
