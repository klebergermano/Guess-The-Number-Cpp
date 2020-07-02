#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using std::cout;
using std::cin;
using std::endl; 
using std::string;
void playGame(); 
string winAscii();
string loseAscii(int rand_num);

void playAgain() {
	string play_again = "n";

	cout << "You Wanna play again? \n \n";
	cout << "[y] to YES \n \n";
	cout << "[n] to NO \n \n";
	cin >> play_again;

	if (play_again == "y" || play_again == "Y") {
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

	int rand_num = rand_number();
	cout << "The right number is: " << rand_num << "\n";
	int guess;
	int num_guesses = 0;
	const int limit_guesses = 5;
	std::vector<int> arr_guesses;

	// Info Game
	cout << "#### Guess The Number Game #### \n \n";
	cout << "In this game you have to guess the random number between 1 and 100 \n \n";
	cout << "You have " << limit_guesses << " chances \n \n";

	while (num_guesses < limit_guesses) {
		cin >> guess;
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
	
			if (guess > rand_num) {
				cout << "Too high \n \n";
			}
			else if (guess < rand_num) {
				cout << "Too low \n \n";
			}
			num_guesses++;
		}
	}

	//Show guesses maked
	show_guesses(arr_guesses);

	cout << "### \n";
	// You Lose message
	if (num_guesses >= limit_guesses) {
		cout << loseAscii(rand_num);

		// Show the right number
		cout << "\n" << "The right number was: " << rand_num << "\n \n";
		playAgain();
	}
}
