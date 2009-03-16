/*
 *      main.cpp
 *      
 *      Copyright 2008 Johannes Wirde <wired@hadouken>
 *      
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *      
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *      
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#include "global.h"
#include "game.h"
#include "toolkit.h"

int main(int argc, char* argv[]) {
	//Check(TRUE);

	LOG("Starting...");
	
  if (argc != 1) {
		cout << "Contact Hannes for help!" << endl;
		exit(0);
	}

	int err = 0;
	Game* pGame = new Game();
	
	err += pGame->Init(); // Start game
	if (!err) err += pGame->Update(); // Run game
	err += pGame->Deinit(); // Exit game
		
	exit(err);
}
