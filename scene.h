#ifndef SB_SCENE_H___
#define SB_SCENE_H___

#include "basesystem.h"

class BaseMessage;

class Scene : public BaseSystem {
public:
	Scene(list<BaseMessage*>* in_pQue);
	~Scene();
	
	int GetNewId() { static int id = 0; id++; return id; }
	
	int Init();
	int Deinit();
	int Update();
	int UpdateMsgs();
	
private:
	unsigned int scene[10][10];
	
};
#endif
