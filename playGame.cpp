#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <limits>
#include <windows.h>

using std::cout;
using std::cin;
using std::endl; 
using std::string;
void playGame(); 
string winAscii();
string loseAscii(int rand_num);
string title();

void playAgain() {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

	string play_again = "n";

	cout << "You Wanna play again? \n \n";
	cout << "[y] to YES \n \n";
	cout << "[n] to NO \n \n";
	cin >> play_again;

	if (play_again == "y" || play_again == "Y") {
		system("CLS"); 
		//Title of the Game
		cout << title();
		playGame();
	}
	else {
		cout << "Tank you for play, see ya o/ \n \n";
	}
}

int rand_number() {
	int rand_num;
	srand(time(NULL));
	rand_num = rand() % 100 + 1; // rand number of 1 to 100;
	return rand_num;
}

void show_guesses(std::vector<int> arr_guesses) {
	cout << "### ";
	for (int i = 0; i < arr_guesses.size(); i++) {
		if (arr_guesses[i] != 0) {
			cout << arr_guesses[i] << " ";
		}
	}
}


void playGame() {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	int rand_num = rand_number();
	cout << "The right number is: " << rand_num << "\n \n \n ";
	int guess;
	int num_guesses = 0;
	const int limit_guesses = 5;
	std::vector<int> arr_guesses;

	// Info Game
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);

	cout << "#### GAME GUESS THE NUMBER #### \n \n";
	cout << "In this game you have to guess the random number between 1 and 100. \n";
	cout << "You have " << limit_guesses << " chances \n \n";

	while (num_guesses < limit_guesses) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		cout << "Type your guess: ";
		cin >> guess; 

		if (cin.fail()) {
			cin.clear();
			cin.ignore(255, '\n');
			cout << " You have entered a wrong input. \n Only numbers are acceptable." << endl;
		}
		else {
		
			cout << "\n";
			// Store the guesses maked 
			arr_guesses.push_back(guess);

			//Win message
			if (guess == rand_num) {

				//win message
				cout << winAscii();
				cout << "\n \n";
				 
				//playAgain
				playAgain();
				break;
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);

				if (guess > rand_num) {
					cout << "Too high \n \n";
				}
				else if (guess < rand_num) {
					cout << "Too low \n \n";
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				num_guesses++;
			}
		}
	}

	//Show guesses maked
	show_guesses(arr_guesses);

	cout << "### \n";
	// You Lose message
	if (num_guesses >= limit_guesses) {
		cout << loseAscii(rand_num);
		cout << "\n \n";
		playAgain();
	}
}
