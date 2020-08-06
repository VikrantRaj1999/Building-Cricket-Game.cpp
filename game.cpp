#include "game.h"
using namespace std;
Game::Game(){
	
	playersPerTeam=4;
	maxBalls=6;
	totalPlayers=11;
	
	players[0]="Virat";
	players[1]="Rohit";
	players[2]="Dhavan";
	players[3]="Pant";
	players[4]="Karthik";
	players[5]="KLRahul";
	players[6]="Jadeja";
	players[7]="Hardik";
	players[8]="Bumrah";
	players[9]="BKumar";
	players[10]="Ishant";
	
	isFirstInnings = false;
	teamA.name="Team-A";
	teamB.name="Team-B";
}

void Game::welcomeMessage()
{
	cout<<"---------------------------------------"<<endl;
	cout<<"|============  CRIC-IN  ==============|"<<endl;
	cout<<"|                                     |"<<endl;
	cout<<"|-------------------------------------|"<<endl;
	cout<<"|   Welcome to Virtual Cricket Game   |"<<endl;
	cout<<"---------------------------------------"<<endl<<endl;	
}

void Game::basicInstruction()
{
	cout<<"----------------------------------------"<<endl;
	cout<<"|             INSTRUCTIONS             |"<<endl;
	cout<<"|--------------------------------------|"<<endl;
	cout<<"|                                      |"<<endl;	
	cout<<"|1. Create two teams (TEAM-A & TEAM-B) |"<<endl;
	cout<<"|   with 4 players each from a given   |"<<endl;
	cout<<"|   pool of 11 players.                |"<<endl;
	cout<<"|2. Lead the Toss and decide the choice|"<<endl;
	cout<<"|   of play.                           |"<<endl;
	cout<<"|3. Each Inning will be of 6 balls.    |"<<endl;
	cout<<"|                                      |"<<endl;
	cout<<"----------------------------------------"<<endl<<endl;
}

void Game::showAllPlayers()
{
	cout<<"---------------------------------------"<<endl;
	cout<<"|           Pool of Players           |"<<endl;
	cout<<"---------------------------------------"<<endl<<endl;
	
	for(int i=0; i<totalPlayers; i++)
	{
		cout<<"\t\t[" <<i<< "]" <<players[i]<<endl;
	}
	
}

int Game::takeIntegerInput() //function taking only integer value as an input
{
	int n;
	//to enter the integer value untill the user enters it...
	while (!(cin >> n))
	{
		cin.clear();                                          //to clear those error flags, i.e. if user enters wrong values like characters or any other thing
		cin.ignore(numeric_limits<streamsize>::max(),'\n');   //to clear the input buffer memory
		cout << "Invalid input! Please try again with valid input: ";
	}
	return n;
}

bool Game::validateSelectedPlayer(int index) //to validate the selected playe i.e. one player cant be selected more than one time
{
	int n;
	vector<Player> players;

	players = teamA.players;
	n = players.size();
	for (int i = 0; i < n; i++) {
        if (players[i].id == index) {
        	return false;
        }
    }

    players = teamB.players;
    n = players.size();
    for (int i = 0; i < n; i++) {
        if (players[i].id == index) {
            return false;
        }
    }

    return true;
}

void Game::selectPlayers()
{
	cout<<"---------------------------------------"<<endl;
	cout<<"|      Create TEAM-A & TEAM-B         |"<<endl;
	cout<<"---------------------------------------"<<endl<<endl;
	
	for(int i=0; i<playersPerTeam; i++)
	{
		//Add player to team A
		teamASelection:
			cout<<endl<<"Select Player"<<i+1<<" of Team A - ";
			int playerIndexTeamA = takeIntegerInput();               //to take integer values from function created above.
			
			if(playerIndexTeamA < 0 || playerIndexTeamA >10)   //player should be selected from the list only
			{
				cout << endl << "Please select from the given players" << endl;
				goto teamASelection;
			}
			else if(!validateSelectedPlayer(playerIndexTeamA)) //once a player is selected then he cant be selected again
			{
				cout << endl << "Player has been already selected. Please select other player" << endl;
				goto teamASelection;
			}
			else
			{
				Player teamAPlayer;                                    //initialize the player object
				teamAPlayer.id=playerIndexTeamA;                      //assign unique id to this player
				teamAPlayer.name = players[playerIndexTeamA];         //initialize the name of player // in this player is a string
				teamA.players.push_back(teamAPlayer);                //adding players into the vector // in this player is a vector present in the class "Team"
		    }
		    
		//Add player to team B
		teamBSelection:
			cout<<endl<<"Select Player"<<i+1<<" of Team B - ";
			int playerIndexTeamB = takeIntegerInput();         //to take integer values from function created above.
			
			if(playerIndexTeamB < 0 || playerIndexTeamB >10) //player should be selected from the list only
			{
				cout << endl << "Please select from the given players" << endl;
				goto teamBSelection;
			}
			else if(!validateSelectedPlayer(playerIndexTeamB)) //once a player is selected then he cant be selected again
			{
				cout << endl << "Player has been already selected. Please select other player" << endl;
				goto teamBSelection;
			}
			else
			{
				Player teamBPlayer;                                //initialize the player object
				teamBPlayer.id=playerIndexTeamB;                   //assign unique id to this player
				teamBPlayer.name = players[playerIndexTeamB];      //initialize the name of player // in this player is a string
				teamB.players.push_back(teamBPlayer);              //adding players into the vector // in this player is a vector present in the class "Team"
			}
	}	
}

void Game::showTeamPlayers() 
{
    vector<Player> teamAPlayers = teamA.players;
    vector<Player> teamBPlayers = teamB.players;

    cout << endl << endl;
    cout << "--------------------------\t\t--------------------------" << endl;
    cout << "|=======  Team-A  =======|\t\t|=======  Team-B  =======|" << endl;
    cout << "--------------------------\t\t--------------------------" << endl;

    for (int i = 0; i < playersPerTeam; i++) {
        cout << "|\t" << "[" << i << "] " << teamAPlayers[i].name << "\t |"
        	<< "\t\t"
			<< "|\t" << "[" << i << "] " << teamBPlayers[i].name << "\t |" << endl;
    }
    cout << "--------------------------\t\t--------------------------" << endl << endl;
}

void Game::toss() {

	cout << endl;
	cout << "-----------------------------------" << endl;
	cout << "|========== Let's Toss  ==========|" << endl;
	cout << "-----------------------------------" << endl << endl;

	cout << "Tossing the coin..." << endl << endl;

	srand(time(NULL));
	int randomValue = rand() % 2;	// 0 or 1

    switch (randomValue) {
		case 0:
			cout << "Team-A won the toss" << endl << endl;
			tossChoice(teamA);
			break;
		case 1:
			cout << "Team-B won the toss" << endl << endl;
			tossChoice(teamB);
			break;
    }
}

void Game::tossChoice(Team tossWinnerTeam) {

	cout << "Enter 1 to bat or 2 to bowl first. " << endl
       		 << "1. Bat" << endl
        	 << "2. Bowl " << endl;

	int tossInput = takeIntegerInput();

	cin.ignore(numeric_limits<streamsize>::max(),'\n'); // not mandatory, just for clearing buffer memory

	switch (tossInput) {
		case 1:
			cout << endl << tossWinnerTeam.name << " won the toss and elected to bat first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {	 // if Team-A is the toss winner
				battingTeam = &teamA;
				bowlingTeam = &teamB;
			} else {	// else Team-B is the toss winner
				battingTeam = &teamB;
				bowlingTeam = &teamA;
			}

			break;
		case 2:
			cout << endl << tossWinnerTeam.name << " won the toss and choose to bowl first" << endl << endl;

			if (tossWinnerTeam.name.compare("Team-A") == 0) {	// if Team-A is the toss winner
				bowlingTeam = &teamA;
				battingTeam = &teamB;
			} else {	// else Team-B is the toss winner
				bowlingTeam = &teamB;
				battingTeam = &teamA;
			}

			break;
		default:
			cout << endl << "Invalid input. Please try again:" << endl << endl;
			tossChoice(tossWinnerTeam);
			break;
   	}
}

void Game::startFirstInnings() 
{
	cout << "\t\t ||| FIRST INNINGS STARTS ||| " << endl << endl;

	isFirstInnings = true;

	initializePlayers();
	playInnings();
}

void Game::initializePlayers() 
{
	// Choose batsman and bowler: Initialize *batsman and *bowler
	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout << battingTeam->name << " - " << batsman->name << " is batting " << endl;
	cout << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;
}

void Game::playInnings() {

	for (int i = 0; i < maxBalls; i++) {

		cout << "Press Enter to bowl...";
		getchar();
		cout << "Bowling..." << endl;

		bat();
		
	    if (!validateInningsScore()) 
		{
	    	break;
	    }
	}
}

void Game::bat() {

	srand(time(NULL));
	int runsScored = rand() % 7;

	// Update batting team and batsman score
	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

	// Update bowling team and bowler score
	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;

    if (runsScored != 0) {	// if runsScored = 1, 2, 3, 4, 5, or 6
    	cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
    	showGameScorecard();
    } else { 	// else runScored = 0 and the batsman is ‘OUT’
    	cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

    	battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
    	bowler->wicketsTaken = bowler->wicketsTaken + 1;

    	showGameScorecard();

    	int nextPlayerIndex = battingTeam->wicketsLost;
    	batsman = &battingTeam->players[nextPlayerIndex];
    }
}
bool Game::validateInningsScore() {

	if (isFirstInnings) {

		if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {

			cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;

			cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
					<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled
					<< ")" << endl;

			cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
					<< " runs to win the match" << endl << endl;

			return false;
		}

	} else {	// Else 2nd innings

	}

	return true;
}  

void Game::showGameScorecard() {

    cout << "--------------------------------------------------------------------------" << endl;

    cout << "\t" << battingTeam->name << "  " << battingTeam->totalRunsScored << " - "
      << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ") | " << batsman->name
      << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " "
	  << bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketsTaken << "\t" << endl;

    cout << "--------------------------------------------------------------------------" << endl << endl;
}
