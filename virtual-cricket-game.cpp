#include "game.h"
using namespace std;

int main() {
	Game game;
	game.welcomeMessage();
	game.basicInstruction();
	
	cout<<"\nPress Enter Key to Continue.";
	getchar();
	
	// another method for same
	
//	do 
//    {
//     cout << '\n' << "Press a key to continue...";
//    } 
//    while (cin.get() != '\n');

	game.showAllPlayers();
	
	do 
    {
     cout << '\n' << "Press Enter Key to Continue.";
    } 
    while (cin.get() != '\n');
    
    game.selectPlayers();
    
    game.showTeamPlayers();
    
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); //for clearing the buffer memory
    
    cout<<"\nPress Enter to TOSS.";   //if we dont write above line, then sometimes program will not wait for us to press enter, due to some value stored in buffer
	getchar();
	
    game.toss();
    
    game.startFirstInnings();

	return 0;
}
