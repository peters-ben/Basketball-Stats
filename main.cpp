//-----------------------------------------------------------------------------
//                      CS 215 – Spring 2020
//                          Project 3
//-----------------------------------------------------------------------------
// Author:  Ben Peters
// Section:  009
// Description: Creates a roster of basketball players with stats for each game 
// Assistance: None
//------------------------------------------------------------------------------
#include "team.h"
using namespace std;

//------------------------------------------------------------------
//                           printLogo
//------------------------------------------------------------------
void printLogo() {
	cout << "-----------------------------------------------------\n";
	cout << "                BASKETBALL STATS SUPREME \n";
	cout << "                  by Ben Peters \n";
	cout << "-----------------------------------------------------\n";
} // printLogo()

//------------------------------------------------------------------
//                           askMenuOption
//------------------------------------------------------------------
// Returns: the menu option entered by the user
// Prints a menu and allows the user to enter a value. It extracts
// and capitalizes the first letter of the user's input.
//------------------------------------------------------------------
char askMenuOption() {
	string choice;
	cout << endl;
	cout << "P - Print team \n";
	cout << "A - Add game \n";
	//cout << "N - New player \n";
	cout << "D - Display player \n";
	cout << "R - Remove player\n";
	cout << "N - Sort list by name \n";
	cout << "J - Sort list by jersey number\n";
	cout << "X - Exit\n";
	cout << "Enter selection: ";
	cin >> choice;
	return (char)(toupper(choice[0])); // upper case of first character
} // askMenuOption()

//------------------------------------------------------------------
//                           main
//------------------------------------------------------------------
int main() {
	team t;				// create a team object
	char option;		// menu option

	// print logo and read data from input file on startup
	printLogo();
	t.read();

	// repeat menu until eXit is selected
	do {
		option = askMenuOption();
		switch (option) {
		case 'P': t.print();		break;
		case 'A': t.addGame();		break;
		case 'D': t.displayPlayer();break;
		case 'N': t.sortByName();	break;
		case 'J': t.sortByJersey(); break;
		case 'R': t.removePlayer(); break;
		case 'X': t.write();		break; 
		default:  cout << "Invalid option! Try again!\n";
		}
	} while (option != 'X'); 

	system("pause");
	return 0;
} // main()