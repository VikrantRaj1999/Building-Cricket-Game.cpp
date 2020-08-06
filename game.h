#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
#include "team.h" // <string>, <vector>, "player.h"


class Game {
	public:
		Game(); //constructor
		int playersPerTeam;
		int maxBalls;
		int totalPlayers;
		std::string players[11];
		
		bool isFirstInnings;
		Team teamA, teamB;
		Team *battingTeam, *bowlingTeam;
		Player *batsman, *bowler;
		
		void welcomeMessage();
		void basicInstruction();
		
		void showAllPlayers();
		
		int takeIntegerInput();
		
		void selectPlayers();
		
		bool validateSelectedPlayer(int);
		
		void showTeamPlayers();
		
		void toss();
		
		void tossChoice(Team);
		
		void startFirstInnings();
		
		void initializePlayers();
		
		void playInnings();
		
		void bat();
		
		bool validateInningsScore();
		
		void showGameScorecard();
};
