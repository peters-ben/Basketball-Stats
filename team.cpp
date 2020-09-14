#include "team.h"
#include "statistic.h"
#include <iomanip>
#include <fstream>
//-------------------------------------------
//             read methods
//-------------------------------------------
// Opens input file to be read in to roster
//-------------------------------------------
void team::read() {
	ifstream teamRoster("bballin.txt"); // open input file
	if (teamRoster.fail()) { // if file fails to open
		cout << "Failed to open file!\n";
	}
	else { // if file opens
		teamRoster >> num_players >> num_games; // read in number of players and number of games
		int made_holder, attempt_holder, jersey_holder;
		string name_holder;
		for(int i = 0; i < num_players; i++) { // read in every player based on number of players given
			teamRoster >> jersey_holder; 
			roster[i].setJersey(jersey_holder);
			if (teamRoster.peek() == ' ') teamRoster.ignore();
			getline(teamRoster, name_holder);
			roster[i].setName(name_holder);
			for (int j = 0; j < num_games; j++) { // read in every game for every player based on number of games given
				teamRoster >> made_holder;
				teamRoster >> attempt_holder;
				roster[i].setThrees(made_holder, attempt_holder, j);
				teamRoster >> made_holder;
				teamRoster >> attempt_holder;
				roster[i].setTwos(made_holder, attempt_holder, j);
				teamRoster >> made_holder;
				teamRoster >> attempt_holder;
				roster[i].setFrees(made_holder, attempt_holder, j);
			}
		} 
	} 
}
//-------------------------------------------
//             team methods
//-------------------------------------------
// Constructor, sets members to 0
//-------------------------------------------
team::team() { 
	num_games = 0;
	num_players = 0;
}
//------------------------------------------------------
//             displayPlayer methods
//------------------------------------------------------
// Displays the stats for each game by a specific player
//------------------------------------------------------
void team::displayPlayer() {
	int jersey_num; 
	int found = -1; // assume not found
	cout << "Enter jersey number: ";
	cin >> jersey_num; // get jersey number from user
	for (int i = 0; i < num_players; i++) {
		if (roster[i].getJersey() == jersey_num) // if jersey number matches player on roster
			found = i; 
}
		if (found != -1) { // when jersey number was found
			cout << roster[found].getName() << "   [" << jersey_num << "]\n"; // output stats
			cout << "Game  3-Point FGs   2-Point FGs   Free Throws   Total\n";
			cout << "----  ------------  ------------  ------------  -----\n";
			for (int j = 0; j < num_games; j++) { 
				cout << fixed << setprecision(0) << setw(4) << right << j << setw(4) << roster[found].getThrees(j).getPointsMade() << "/" << setw(2) << roster[found].getThrees(j).getPointsPoss() << " (" << setw(3) << roster[found].getThrees(j).getPercent(roster[found].getThrees(j).getPointsMade(), roster[found].getThrees(j).getPointsPoss()) << "%)";
				cout << setw(4) << roster[found].getTwos(j).getPointsMade() << "/" << setw(2) << roster[found].getTwos(j).getPointsPoss() << " (" << setw(3) << roster[found].getTwos(j).getPercent(roster[found].getTwos(j).getPointsMade(), roster[found].getTwos(j).getPointsPoss()) << "%)";
				cout << setw(4) << roster[found].getFrees(j).getPointsMade() << "/" << setw(2) << roster[found].getFrees(j).getPointsPoss() << " (" << setw(3) << roster[found].getFrees(j).getPercent(roster[found].getFrees(j).getPointsMade(), roster[found].getFrees(j).getPointsPoss()) << "%)";
				cout << setw(7) << (3 * roster[found].getThrees(j).getPointsMade() + 2 * roster[found].getTwos(j).getPointsMade() + roster[found].getFrees(j).getPointsMade()) << endl;
			}
			cout << " ALL" << setw(4) << roster[found].stat_sum(num_games, 5) << "/" << setw(2) << roster[found].stat_sum(num_games, 6) << " (" << setw(3) << roster[found].getThrees(num_games).getPercent(roster[found].stat_sum(num_games, 5), roster[found].stat_sum(num_games, 6)) << "%)" << setw(4) << roster[found].stat_sum(num_games, 3) << "/" << setw(2) << roster[found].stat_sum(num_games, 4) << " (" << setw(3) << roster[found].getTwos(num_games).getPercent(roster[found].stat_sum(num_games, 3), roster[found].stat_sum(num_games, 4)) << "%)" << setw(4) << roster[found].stat_sum(num_games, 1) << "/" << setw(2) << roster[found].stat_sum(num_games, 2) << " (" << setw(3) << roster[found].getFrees(num_games).getPercent(roster[found].stat_sum(num_games, 1), roster[found].stat_sum(num_games, 2)) << "%)" << setw(7) << roster[found].stat_sum(num_games, 1) + 2 * roster[found].stat_sum(num_games, 3) + 3 * roster[found].stat_sum(num_games, 5) << endl;
		}
		else
			cout << "Player not found.\n";
}
//--------------------------------------------
//                print method
//--------------------------------------------
// Prints the stats every player for each game
//--------------------------------------------
void team::print() {
	cout << "Number of games: " << num_games << " Number of Players: " << num_players << endl;
	for (int i = 0; i < num_players; i++) { // for every player
		cout << fixed << setprecision(0) << roster[i].getName() << "   [" << roster[i].getJersey() << "]\n";
		cout << "Game  3-Point FGs   2-Point FGs   Free Throws   Total\n";
		cout << "----  ------------  ------------  ------------  -----\n";
		for (int j = 0; j < num_games; j++) { // for every game
			cout << setw(4) << right << j << setw(4) << roster[i].getThrees(j).getPointsMade() << "/" << setw(2) << roster[i].getThrees(j).getPointsPoss() << " (" << setw(3) << roster[i].getThrees(j).getPercent(roster[i].getThrees(j).getPointsMade(), roster[i].getThrees(j).getPointsPoss()) << "%)";
			cout << setw(4) << roster[i].getTwos(j).getPointsMade() << "/" << setw(2) << roster[i].getTwos(j).getPointsPoss() << " (" << setw(3) << roster[i].getTwos(j).getPercent(roster[i].getTwos(j).getPointsMade(), roster[i].getTwos(j).getPointsPoss()) << "%)";;
			cout << setw(4) << roster[i].getFrees(j).getPointsMade() << "/" << setw(2) << roster[i].getFrees(j).getPointsPoss() << " (" << setw(3) << roster[i].getFrees(j).getPercent(roster[i].getFrees(j).getPointsMade(), roster[i].getFrees(j).getPointsPoss()) << "%)";;
			cout << setw(7) << (3 * roster[i].getThrees(j).getPointsMade() + 2 * roster[i].getTwos(j).getPointsMade() + roster[i].getFrees(j).getPointsMade()) << endl;
		}
		cout << " ALL" << setw(4) << roster[i].stat_sum(num_games, 5) << "/" << setw(2) << roster[i].stat_sum(num_games, 6) << " (" << setw(3) << roster[i].getThrees(num_games).getPercent(roster[i].stat_sum(num_games, 5), roster[i].stat_sum(num_games, 6)) << "%)" << setw(4) << roster[i].stat_sum(num_games, 3) << "/" << setw(2) << roster[i].stat_sum(num_games, 4) << " (" << setw(3) << roster[i].getTwos(num_games).getPercent(roster[i].stat_sum(num_games, 3), roster[i].stat_sum(num_games, 4)) << "%)" << setw(4) << roster[i].stat_sum(num_games, 1) << "/" << setw(2) << roster[i].stat_sum(num_games, 2) << " (" << setw(3) << roster[i].getFrees(num_games).getPercent(roster[i].stat_sum(num_games, 1), roster[i].stat_sum(num_games, 2)) << "%)" << setw(7) << roster[i].stat_sum(num_games, 1) + 2 * roster[i].stat_sum(num_games, 3) + 3 * roster[i].stat_sum(num_games, 5) << endl << endl;
	}
	system("pause");
}
//--------------------------------------------
//             addGame method
//--------------------------------------------
// Add the stats for a new game to each player
//--------------------------------------------
void team::addGame() {
	int temp_made, temp_attempt;
	if (num_games >= MAX_GAMES) // if number of games is at max
		cout << "Maximum number of games added.\n";
	else { 
		for (int i = 0; i < num_players; i++) { // for every player
			cout << "Enter stats for " << roster[i].getName() << " [" << roster[i].getJersey() << "]\n";
			cout << "3 Pointers (made attempted): ";
			cin >> temp_made >> temp_attempt; 
			roster[i].setThrees(temp_made, temp_attempt, num_games);
			cout << "2 Pointers (made attempted): ";
			cin >> temp_made >> temp_attempt;
			roster[i].setTwos(temp_made, temp_attempt, num_games);
			cout << "Free Throws (made attempted): ";
			cin >> temp_made >> temp_attempt;
			roster[i].setFrees(temp_made, temp_attempt, num_games);
		}
		num_games++;
	}
}
//-------------------------------------------
//             removePlayer method
//-------------------------------------------
// Remove a player from the roster
//-------------------------------------------
void team::removePlayer() {
	int jersey_num, found = -1; // holder var, assume not found
	player deletedPlayer; // create player to hold removed player
	cout << "Enter a jersey number to remove: ";
	cin >> jersey_num;
	for (int i = 0; i < num_players; i++) { // validate jersey number matches player on roster
		if (roster[i].getJersey() == jersey_num)
			found = i;
	}
	if (found != -1) { // if player found
		deletedPlayer = roster[found];
		num_players--; // decrease number of players by one
		for (int i = found; i < num_players; i++)
			roster[i] = roster[i + 1]; // lower every element by one in array
		cout << "Player " << deletedPlayer.getName() << " [" << deletedPlayer.getJersey() << "] removed.\n";
	}
	else
		cout << "Player not found.\n";
}
//-------------------------------------------------------------
//                      sortByName method
//-------------------------------------------------------------
// Sorts the roster of players by first letter of last name A-Z
//-------------------------------------------------------------
void team::sortByName() {
	for (int i = 0; i < num_players - 1; i++) { // bubble sort
		for (int j = i + 1; j < num_players; j++) {
			string sort1 = roster[i].getName();
			string sort2 = roster[j].getName();
			if (sort1 > sort2) {
				player player_temp = roster[i]; // temporary holder
				roster[i] = roster[j];
				roster[j] = player_temp;
			}
		}
	}
	cout << "Players sorted by name\n";
}
//---------------------------------------------------------------
//             sortByJersey method
//---------------------------------------------------------------
// Sorts the roster of players by jersey number lowest to highest
//---------------------------------------------------------------
void team::sortByJersey() {
	for (int i = 0; i < num_players - 1; i++) { // bubble sort 
		for (int j = i + 1; j < num_players; j++) {
			int sort1 = roster[i].getJersey();
			int sort2 = roster[j].getJersey();
			if (sort1 > sort2) {
				player player_temp = roster[i]; // temporary holder
				roster[i] = roster[j];
				roster[j] = player_temp;
			}
		}
	}
	cout << "Players sorted by jersey number\n";
}
//-------------------------------------------
//             write method
//-------------------------------------------
// Outputs the player roster to a text file
//-------------------------------------------
void team::write() {
	ofstream rosterOut("bballout.txt"); // open output file
	if (rosterOut.fail()) { // if file fails to open
		cout << "Outfile file failed to open!\n";
	}
	else {
		rosterOut << num_players << " " << num_games << endl; // output roster to file
		for (int i = 0; i < num_players; i++) {
			rosterOut << roster[i].getJersey() << " " << roster[i].getName() << endl;
			for (int j = 0; j < num_games; j++) {
				rosterOut << roster[i].getThrees(j).getPointsMade() << " " << roster[i].getThrees(j).getPointsPoss() << " " << roster[i].getTwos(j).getPointsMade() << " " << roster[i].getTwos(j).getPointsPoss() << " " << roster[i].getFrees(j).getPointsMade() << " " << roster[i].getFrees(j).getPointsPoss() << endl;
			}
		}
	}
}