#include "statistic.h"
//---------------------------------------------------------------------------------------
//             statistic constructor
//---------------------------------------------------------------------------------------
// Sets data members to 0
//---------------------------------------------------------------------------------------
statistic::statistic() {
	points_made = 0;
	points_poss = 0;
}
//---------------------------------------------------------------------------------------
//             set methods
//---------------------------------------------------------------------------------------
// Sets the values of the different data members
//---------------------------------------------------------------------------------------
void statistic::setPointsMade(int made) {
	points_made = made;
}

void statistic::setPointsPoss(int poss) {
	points_poss = poss;
}
//---------------------------------------------------------------------------------------
//             get methods
//---------------------------------------------------------------------------------------
// Gets the values of the different data members
//---------------------------------------------------------------------------------------
int statistic::getPointsMade() {
	return points_made;
}
int statistic::getPointsPoss() {
	return points_poss;
}
//---------------------------------------------------------------------------------------------------
//             getPercent methods
//---------------------------------------------------------------------------------------------------
// Finds the percentage of two numbers, in this case the # of shots made and the # of shots attempted
//---------------------------------------------------------------------------------------------------
double statistic::getPercent(double made, double poss) {
	double percent;
	if (poss != 0) // ensure no division by 0
		percent = made / poss * 100;
	else // if division by 0
		percent = 0;
	return percent;
}