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
	
	//Play Menu
	cout << "\n";
	cout << " [q] - Quit the Game \n \n ";
	cout << "[s] - Start the Game \n \n ";

	string option; 
	cin >> option;

	if (option == "q" || option == "Q") {
		return 0; 
	}

	else if (option == "s" || option == "S") {
		playGame();
	}
	else {
		cout << "Invalid command!";
	}
	return 0; 
}