#include<string>

class Player {//as soon as the player object will be created we need to initialize few attribute, that will be using constructor (default constructor)
	public:
		Player(); //definition of constructor in in player.cpp file
		std::string name; //since this program is in header file so namespace is like this
		int id;
		int runsScored;
		int ballsPlayed;
		int ballsBowled;
		int runsGiven;
		int wicketsTaken;


};
