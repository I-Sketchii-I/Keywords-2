#include "pch.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
	//seeding for random number generator
	srand(static_cast<unsigned int>(time(0)));
	//max number of wrong guesses per word
	const int wrong = 15;
	// Display Title of program to user
	cout << "Welcome to the Keywords 2.0 Program!\n";

	// Ask the recruit to login using thier name
	string user;
	cout << "Please enter your name:\n";
	cin >> user;
	// Hold the recruit's name in a var, and address them by it throughout the simulation.

	// Display an overview of what Keywords II is to the recruit
	cout << "\nThis program is, in essence, the game of hangman.\nYou will have 15 of guesses to guess the unknown word.\nEach guess you will be allowed to guess 1 letter.\nYou need to guess 3 words randomly picked from a pool of words.\nGood Luck.";

	// Create a collection of 10 words you had wrote down manually
	vector <string> words = { "SPECTRE", "SKYFALL", "FALLOUT", "GOLDFINGER", "OCTOPUSSY", "BAGMAN", "MOLE", "ESPIONAGE", "COVERT", "ROGUE" };
	random_shuffle(words.begin(), words.end());

	// Create an int var to count the number of simulations being run starting at 1
	int runs = 1;
	// Display the simulation # is staring to the recruit.
	cout << "\n\nStarting Simulation #" << runs << "...\nUser:" << user;

	for (int j = 0; j <= 3; ++j)
	{
		// Pick new 3 random words from your collection as the secret code word the recruit has to guess.
		const string word = words[rand() % 11];

		int incorrect = 0; //number of wrong guesses                                  //wrong
		string wordGuessed(word.size(), '-'); //shows what has been guessed so far   //soFar
		string lettersUsed = ""; //lists the letters guessed                          //used

		// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		while ((incorrect < wrong) && wordGuessed != word)
		{
			//     Tell recruit how many incorrect guesses he or she has left
			cout << "\n\nYou have " << (wrong - incorrect);
			cout << " incorrect guesses left.\n";
			//     Show recruit the letters he or she has guessed
			cout << "\nYou’ve used the following letters:\n" << lettersUsed;
			//     Show player how much of the secret word he or she has guessed
			cout << "\nThe word is so far:\n" << wordGuessed;

			//     Get recruit's next guess
			char guess;
			cout << "\n\nEnter your guess: ";
			cin >> guess;
			// made uppercase since secret words are in uppercase
			guess = toupper(guess);
			//     While recruit has entered a letter that he or she has already guessed
			while (lettersUsed.find(guess) != string::npos)
			{
				//          Get recruit ’s guess
				cout << "\nYou've already guessed " << guess << endl;
				cout << "Enter your guess: ";
				cin >> guess;
				guess = toupper(guess);
			}

			//     Add the new guess to the group of used letters
			lettersUsed += guess;

			//     If the guess is in the secret word
			if (word.find(guess) != string::npos)
			{
				//          Tell the recruit the guess is correct
				cout << "Correct! " << guess << " is in the word.\n";

				//          Update the word guessed so far with the new letter
				for (unsigned int i = 0; i < word.length(); ++i)
				{
					if (word[i] == guess)
					{
						wordGuessed[i] = guess;
					}
				}
			}
			//     Otherwise
			else
			{
				//          Tell the recruit the guess is incorrect
				cout << "Sorry, " << guess << " isn't in the word.\n";
				//          Increment the number of incorrect guesses the recruit has made
				++incorrect;
			}
		}


		// If the recruit has made too many incorrect guesses
		if (incorrect == wrong)
			//     Tell the recruit that he or she has failed the Keywords II course.
			cout << "\nYou've Failed!";
		// Otherwise
		else
			//     Congratulate the recruit on guessing the secret words
			cout << "\nYou Passed!";

		cout << "\nThe word was " << word << endl;

		return 0;
	}
	// Ask the recruit if they would like to run the simulation again
	cout << "\nWould you like to run trhough the simulation again?\nEnter 1 for yes or 0 for no\n";
	int y;
	cin >> y;

	// If the recruit wants to run the simulation again
	if (y == 1)
	{
		++runs;
		// run program again I dont know how to do this
	}
	else
	{
		cout << "\n\n***End of Simulation***\n\n";
	}
	//     Increment the number of simiulations ran counter

	//     Move program execution back up to // Display the simulation # is staring to the recruit. 

	// Otherwise 

	//     Display End of Simulations to the recruit

	//     Pause the Simulation with press any key to continue
}