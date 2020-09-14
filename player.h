#pragma once
#include "statistic.h"
#include <iostream>
#include <string>
using namespace std;
const int MAX_GAMES = 15;
//-----------------------------------------
//              class player
//-----------------------------------------
// Implements a player on a basketball team
//-----------------------------------------
class player {
public: 
	player();
	string getName();
	void setName(string newName);
	int getJersey();
	void setJersey(int newJersey);
	statistic getThrees(int index);
	void setThrees(int made, int attempted, int index);
	statistic getTwos(int index);
	void setTwos(int made, int attempted, int index);
	statistic getFrees(int index);
	void setFrees(int made, int attempted, int index); 
	int stat_sum(int num_games, int choice);
private:
	string name;
	int jersey_num;
	int games_played;
	statistic three_points[MAX_GAMES];
	statistic two_points[MAX_GAMES];
	statistic free_throws[MAX_GAMES];
};