#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using std::cout; 
using std::cin;
using std::endl;

int rand_number() {
	int rand_num; 

	srand(time(NULL));
	rand_num = rand() % 100 +1; // rand number of 1 to 100;
	return rand_num; 
}


void play_game() {


	int rand_num = rand_number();
	int guess; 
	int num_guesses = 0; 
	int limit_guesses = 10;



	cout << "#### Gueess The Number Game #### \n";
	cout << "Gueess the random number between 1 and 100 \n";
	cout << "You have "<< limit_guesses <<" chances\n\n";


	while (num_guesses < limit_guesses) {
		cin >> guess;
		
		if (guess == rand_num) {
			cout << "### CONGRATULATIONS YOU HAVE HIT THE RIGHT NUMBER ### \n\n";
			return; 
		}
		else {
			if (guess > rand_num) {
				cout << "Too High\n";
			}
			else if (guess < rand_num) {
				cout << "Too Low \n";

			}

			num_guesses++; 
			
		
		}
	}
	if (num_guesses >= limit_guesses) {
		cout << "YOU LOSE!!! :) ";
		return;
	}
	

	/*
	while (num_guesses <=  limit_guesses) {

		if (guess > rand_num) {
			cout << "Too High";
		}
		else if (guess < rand_num) {
			cout << "Too Low";

		}
		if (guess == rand_num) {
			cout << "### CONGRATULATIONS YOU HAVE HIT THE RIGHT NUMBER ### \n\n";
		}
		else {
	
	
		}
	}
	*/

	cout << "\n" << rand_num; 



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
//teste
	play_game(); 

	return 0; 
}