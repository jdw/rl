#ifndef SB_BASETILE_H___
#define SB_BASETILE_H___

#include "global.h"

namespace TileType {
	enum Enum {
		ACTOR = 0,
		ITEM,
		//EFFECT,
		//PROPS
		MAX // Faulty
	};
}

class BaseTile {
public:
	~BaseTile();

	Vect2 GetPos() { return pos; }
	string GetName() { return name; }
	char GetSymbol() { return symbol; };
	TileType::Enum GetTileType()  { return tileType; }
	int GetID() { return id; }
	
	void SetPos(int in_x, int in_y) { pos.x = in_x; pos.y = in_y; }
	void SetName(string in_name) { name = in_name; }
	void SetSymbol(char in_sym) { symbol = in_sym; }
	void SetTileType(TileType::Enum in_type) { tileType = in_type; }
	
protected:
	BaseTile(int id);
	BaseTile(int id, Vect2 in_pos, string in_name, TileType::Enum in_type, char in_sym);
	
private:
	const int id;
	Vect2 pos;
	string name;
	TileType::Enum tileType;
	char symbol;

};
#endif
