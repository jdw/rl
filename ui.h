#ifndef SB_UI_H___
#define SB_UI_H___

// Takes care of status and messages windows, menus and dialogs

#include "global.h"
#include "basesystem.h"

class BaseMessage;

namespace UIWindow {
	enum Enum {
		WORLD = 0,
		STATUS,
		MESSAGES,
		
		MAX // Faulty
	};	
}

class UI : public BaseSystem {
public:
	UI(list<BaseMessage*>* in_pQue);
	~UI();

	int Init();
	int Deinit();
	int Update();
	int UpdateMsgs();
	
protected:

private:
	WINDOW* win[UIWindow::MAX];
	PANEL* panel[UIWindow::MAX];
	list<string> lines;
};
#endif
