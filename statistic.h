#pragma once
//-------------------------------------
//          class statistic
//-------------------------------------
//  Implements a basketball statistic
//-------------------------------------
class statistic {
public:
	statistic();
	void setPointsMade(int made); // set number of points made
	int getPointsMade(); // get number of points made 
	void setPointsPoss(int poss); // set the number of points attempted
	int getPointsPoss(); // get the number of points attempted
	double getPercent(double made, double poss); // find percentage of made versus attempted
private:
	int points_made, points_poss;
};