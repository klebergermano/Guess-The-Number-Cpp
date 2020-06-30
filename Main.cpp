#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
using std::cout; 
using std::cin;
using std::endl;
using std::string; 

int rand_number() {
	int rand_num; 
	srand(time(NULL));
	rand_num = rand() % 100 +1; // rand number of 1 to 100;
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

void play_game() {
	int rand_num = rand_number();
	int guess; 
	int num_guesses = 0; 
	const int limit_guesses = 1;
	int arr_guesses[limit_guesses] = {};
	int arr_guesses_size = sizeof(arr_guesses) / sizeof(arr_guesses[0]);
	   
cout << R"(
#-----------------------------------------------------------------------------------------------|
#     _____                       _______ _            _   _                 _                  |
#    / ____|                     |__   __| |          | \ | |               | |                 |
#   | |  __ _   _  ___  ___ ___     | |  | |__   ___  |  \| |_   _ _ __ ___ | |__   ___ _ __    |
#   | | |_ | | | |/ _ \/ __/ __|    | |  | '_ \ / _ \ | . ` | | | | '_ ` _ \| '_ \ / _ \ '__|   | 
#   | |__| | |_| |  __/\__ \__ \    | |  | | | |  __/ | |\  | |_| | | | | | | |_) |  __/ |      |
#    \_____|\__,_|\___||___/___/    |_|  |_| |_|\___| |_| \_|\__,_|_| |_| |_|_.__/ \___|_|      |
#                                                                                               |
#-----------------------------------------------------------------------------------------------|   
#||||||||||||||||||||||||||||||||||||| By Kleber Germano |||||||||||||||||||||||||||||||||||||||| 
#-----------------------------------------------------------------------------------------------|                                                                          
)" << "\n";



	cout << "#### Guess The Number Game #### \n\n";
	cout << "In this game you have to guess the random number between 1 and 100 \n\n";
	cout << "You have "<< limit_guesses <<" chances\n\n";
	

	while (num_guesses < limit_guesses) {
		cin >> guess;
		// Store Guesses maked
		arr_guesses[num_guesses] = guess;

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
	

	//Show Guesses maked
	show_guesses(arr_guesses, arr_guesses_size); 


	cout << "### \n";

	// You Lose message
	if (num_guesses >= limit_guesses) {
		string you_lose =  R"(
|||||||||||||||||||||||||||||||||||||||||||||||||||||
-----------------------------------------------------
--------------------YOU LOSE !!!---------------------
-----------------------------------------------------
              The right number was answer       
-----------------------------------------------------
|||||||||||||||||||||||||||||||||||||||||||||||||||||
			)";


		you_lose.replace(you_lose.find("answer") , 6, std::to_string(guess));
		cout << you_lose; 

		// Show the right number
		cout << "\n" <<"The right number was: " << rand_num;
		return;
	}
};

int menu(int choice) {
	if (choice == 0) {
		return 0;
	}
	else if (choice == 1) {
		play_game();
	}
}

int main() {
	play_game(); 
	return 0; 
}