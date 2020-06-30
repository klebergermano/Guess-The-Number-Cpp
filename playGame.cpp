#include <iostream>
#include <string>
#include <time.h>
using std::cout;
using std::cin;
using std::endl; 
using std::string;


int rand_number() {
	int rand_num;
	srand(time(NULL));
	rand_num = rand() % 100 + 1; // rand number of 1 to 100;
	return rand_num;
}

void show_guesses(int arr_guesses[], int size) {
	cout << "### ";
	for (int i = 0; i < size; i++) {
		if (arr_guesses[i] != 0) {
			cout << arr_guesses[i] << " ";

		}
	}
}


void playGame() {

	int rand_num = rand_number();
	int guess;
	int num_guesses = 0;
	const int limit_guesses = 10;
	int arr_guesses[limit_guesses] = {};
	int arr_guesses_size = sizeof(arr_guesses) / sizeof(arr_guesses[0]);

	cout << "You have " << limit_guesses << " chances\n\n";
	while (num_guesses < limit_guesses) {
		cin >> guess;
		// Store the guesses maked
		arr_guesses[num_guesses] = guess;

		//Win message
		if (guess == rand_num) {
			cout << R"(
	|||||||||||||||||||||||||||||||||||||||||||||||||||||
	-----------------------------------------------------
	--------------------YOU WIN!!!-----------------------
	-----------------------------------------------------
	||||| CONGRATULATIONS YOU HIT THE RIGHT NUMBER ||||||
	-----------------------------------------------------
	|||||||||||||||||||||||||||||||||||||||||||||||||||||
					  )";
			cout << "\n\n";
			break;
		}
		else {
			if (guess > rand_num) {
				cout << "Too high \n\n";
			}
			else if (guess < rand_num) {
				cout << "Too low \n\n";
			}
			num_guesses++;
		}
	}

	//Show guesses maked
	show_guesses(arr_guesses, arr_guesses_size);


	cout << "### \n";

	// You Lose message
	if (num_guesses >= limit_guesses) {
		string you_lose = R"(
	|||||||||||||||||||||||||||||||||||||||||||||||||||||
	-----------------------------------------------------
	------------------- YOU LOSE!!! ---------------------
	-----------------------------------------------------
				  The right number was answer       
	-----------------------------------------------------
	|||||||||||||||||||||||||||||||||||||||||||||||||||||
			)";


		you_lose.replace(you_lose.find("answer"), 6, std::to_string(rand_num));
		cout << you_lose;

		// Show the right number
		cout << "\n" << "The right number was: " << rand_num;
		return;
	}

}
