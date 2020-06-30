#include <iostream>
//#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>

using std::cout; 
using std::cin;
using std::endl;
using std::string; 

string title();
void playGame();


int menu(int choice) {
	if (choice == 0) {
		return 0;
	}
	else if (choice == 1) {
		playGame();
	}
}

int main() {

	//Title of the Game
	cout << title();
	
	// Info Game
	cout << "#### Guess The Number Game #### \n\n";
	cout << "In this game you have to guess the random number between 1 and 100 \n\n";
	
	//Play Game
	playGame(); 
	return 0; 
}