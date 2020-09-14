#pragma once
#include "player.h"
const int MAX_PLAYERS = 10; // max players on roster
//-------------------------------------
//             class team
//-------------------------------------
//    Implements a team of players
//-------------------------------------
class team {
public:
	team(); // constructor
	void read(); // read from file
	void print(); // print team
	void displayPlayer(); // display a player  
	void addGame(); // add a game for each player
	void sortByName(); // sort roster by name
	void sortByJersey(); // sort roster by jersey number
	void removePlayer(); // remove a player from roster
	void write(); // output roster to text file
private:
	player roster[MAX_PLAYERS]; // array of players
	int num_players; 
	int num_games;
};