#include "player.h"
//----------------------------------------
//          player consturctor
//----------------------------------------
// Constructor, sets everything to 0 or ""
//----------------------------------------
player::player() { 
	name = "";
	jersey_num = 0;
	games_played = 0;
	}
//-------------------------------------------
//             get methods
//-------------------------------------------
// Get the name or jersey numbers of a player
//-------------------------------------------
string player::getName() { 
	return name;
}
int player::getJersey() { // get player's jersey number
	return jersey_num;
}
//-------------------------------------------
//             set methods
//-------------------------------------------
// Sets the name or jersey numbers of a player
//-------------------------------------------
void player::setName(string newName) { 
	name = newName;
}
void player::setJersey(int newJersey) {
	jersey_num = newJersey;
}
//------------------------------------------------------------------------------------------------
//                                         get methods
//------------------------------------------------------------------------------------------------
// Get the number of three pointers, two pointers, or free throws a player made in a specific game
//------------------------------------------------------------------------------------------------
statistic player::getThrees(int game_index) {
	return three_points[game_index];
}

statistic player::getTwos(int game_index) {
	return two_points[game_index];
}
statistic player::getFrees(int game_index) {
	return free_throws[game_index];
}
//------------------------------------------------------------------------------------------------
//                                         set methods
//------------------------------------------------------------------------------------------------
// Sets the number of three points, two pointers, or free throws a player made in a specific game
//------------------------------------------------------------------------------------------------
void player::setThrees(int made, int attempted, int game_index) {
	if (made <= attempted) {
		three_points[game_index].setPointsMade(made);
		three_points[game_index].setPointsPoss(attempted);
	}
	else {
		cout << "Cannot make more shots than attempted. Setting made and attempted to 0...\n";
		three_points[game_index].setPointsMade(0);
		three_points[game_index].setPointsPoss(0);
	}
}
void player::setTwos(int made, int attempted, int game_index) {
	if (made <= attempted) {
		two_points[game_index].setPointsMade(made);
		two_points[game_index].setPointsPoss(attempted);
	}
	else {
		cout << "Cannot make more shots than attempted. Setting made and attempted to 0...\n";
		two_points[game_index].setPointsMade(0);
		two_points[game_index].setPointsPoss(0);
	}
}
void player::setFrees(int made, int attempted, int game_index) {
	if (made <= attempted) {
		free_throws[game_index].setPointsMade(made);
		free_throws[game_index].setPointsPoss(attempted);
	}
	else {
		cout << "Cannot make more shots than attempted. Setting made and attempted to 0...\n";
		free_throws[game_index].setPointsMade(0);
		free_throws[game_index].setPointsPoss(0);

	}
}
//---------------------------------------------------------------------------------------
//             stat_sum method
//---------------------------------------------------------------------------------------
// Finds total number of type of shot made or attempted by a player based on choice given
//---------------------------------------------------------------------------------------
int player::stat_sum(int num_games, int choice) {
	int sum = 0; // set accumulator to 0
	switch (choice) {
	case 1: // free throws made
		for (int i = 0; i < num_games; i++)
			sum += this->getFrees(i).getPointsMade();// add all free throws made
		break;
	case 2: // free throws attempted
		for (int i = 0; i < num_games; i++)
			sum += this->getFrees(i).getPointsPoss(); // add all free throws attempted
		break;
	case 3: // two pointers made
		for (int i = 0; i < num_games; i++)
			sum += this->getTwos(i).getPointsMade(); // add all two pointers made
		break;
	case 4: // two pointers attempted
		for (int i = 0; i < num_games; i++)
			sum += this->getTwos(i).getPointsPoss(); // add all two pointers attempted
		break;
	case 5: // three pointers made
		for (int i = 0; i < num_games; i++)
			sum += this->getThrees(i).getPointsMade(); // add all three pointers made
		break;
	case 6: // three pointers attempted
		for (int i = 0; i < num_games; i++)
			sum += this->getThrees(i).getPointsPoss(); // add all three pointers attempted
		break;
	}
	return sum; // return accumulator
}