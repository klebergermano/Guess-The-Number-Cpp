#include <iostream>
//#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
#include<windows.h>

using std::cout; 
using std::cin;
using std::endl;
using std::string; 

string title();
void playGame();



int main() {

	//Title of the Game
	cout << title();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

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

		system("CLS"); 
		cout << title();

		playGame();
	}
	else {
		cout << "Invalid command!";
	}
	return 0; 
}