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


	
	//Play Game
	cout << "\n";
	cout << " 0. Quit the Game \n \n ";
	cout << "1. Play the Game \n \n ";

	int option; 
	cin >> option;
	if (option == 0) {
		return 0; 
	}
	else if (option == 1) {
		// Info Game
		cout << "#### Guess The Number Game #### \n\n";
		cout << "In this game you have to guess the random number between 1 and 100 \n\n";
		playGame();
	}
	else {
		cout << "Invalid command!";
	}
	return 0; 
}