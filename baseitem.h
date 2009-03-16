#ifndef SB_BASEITEM_H___
#define SB_BASEITEM_H___

namespace ItemType {
	enum Enum {
		WEAPON = 0,
		SCROLL,
		POTION,
		
		MAX // Faulty
	};
};

class BaseItem {
public:
	ItemType GetType() { return type; }
	Vect2 GetPos() { return pos; }
	
protected:
	BaseItem();
	~BaseItem();

	virtual int Update() = 0;
	
virtual:
private:
	Vect2 pos;
	string name;
	ItemType type;
	char symbol;
	
};
#endif
