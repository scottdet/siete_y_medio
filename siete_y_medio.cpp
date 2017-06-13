#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include "cards.h"

using namespace std;

int main() {
	ofstream fout;
	fout.open("gamelog.txt");

	// Start with $100 and keep count of games played
	Player player = Player(100); 
	int game_num = 0; 

	do {
		srand(static_cast<int>(time(0)));
		game_num++;

		// Declare some variables
		int money = player.getMoney();
		int bet = 0;
		char choice;

		// Declare hands for player and dealer
		Hand Player_hand = Hand();
		Hand Dealer_hand = Hand();

		cout << '\n' << "You have $" << money << ". " << "Enter bet: ";
		cin >> bet;

		if (bet > money) {
			cout << "Please enter a valid amount." << endl;
		}

		else {
			
			do {
				cout << '\n' << "Your cards: " << '\n';
				Player_hand.print();

				cout << '\t' << "* Your total is " << Player_hand.sum() << "\n";
				cout << '\n' << "Do you want another card (y/n): ";
				cin >> choice;

				if (choice == 'n') {
					cout << '\n' << "Dealer's cards: " << '\n';
					Dealer_hand.print();
					cout << '\t' << "* The dealer's total is " << Dealer_hand.sum() << "\n";

					// Game play statistics are added to the log file
					fout << '\n' << "-------------------------------------------------" << '\n';
					fout << '\n' << "Game number: " << game_num << '\n' << "Money left: $" << player.getMoney() << '\n' << "Bet: " << bet << "\n";

					fout << '\n' << "Your cards:" << '\n';
					Player_hand.log(fout);
					fout << '\t' << "* Your total: " << Player_hand.sum() << "\n";

					fout << '\n' << "Dealer's cards: " << '\n';
					Dealer_hand.log(fout);
					fout << '\t' << "* Dealer's total: " << Dealer_hand.sum() << "\n";

					// Check for correct scoring and dealer play
					while (Dealer_hand.sum() < 5.5) {
						Dealer_hand.draw();
						cout << '\n' << "New card: " << '\n';
						Dealer_hand.last();

						cout << '\n' << "Dealer's cards: " << '\n';
						Dealer_hand.print();
						cout << '\t' << "* The dealer's total is " << Dealer_hand.sum() << "\n";
					}

					if (Player_hand.sum() > 7.5) {
						cout << '\n' << "Too bad. You lose " << bet << "\n";
						player.refreshMoney(-bet);
					}

					else if (Player_hand.sum() <= 7.5 && Dealer_hand.sum() > 7.5) {
						cout << '\n' << "You win " << bet << "\n";
						player.refreshMoney(bet);
					}

					else if (Player_hand.sum() == Dealer_hand.sum()) {
						cout << '\n' << "It's a tie." << '\n';
					}

					// Last element of gameplay to check, what if neither dealer nor player exceed 7.5?
					else {

						// The player wins the bet if he closer to 7.5
						if (Dealer_hand < Player_hand) {
							cout << '\n' << "You win " << bet << "!\n";
							player.refreshMoney(bet);
						}

						else {
							cout << '\n' << "You lose " << bet << ".\n";
							player.refreshMoney(-bet);
						}
					}
				}

				// Otherwise, if the player chooses to draw another card
				else {
					Player_hand.draw();
					cout << '\n' << "New card:" << '\n';
					Player_hand.last();
				}
			} 
			
			// While pertaining to else statement above
			while (choice == 'y');

			if (player.getMoney() == 0) {
				cout << '\n' << "You have $0. Please leave the casino immediately." << '\n';
				fout << '\n' << "-------------------------------------------------" << '\n';
				system("pause");
				fout.close();
				break;
			}

			//The player cannot play anymore if the dealer looses 900 or more
			else if (player.getMoney() >= 1000) {
				cout << '\n' << "The casino is all out of money!" << '\n';
				fout << '\n' << "-------------------------------------------------" << '\n';
				system("pause");
				break;
			}

			//If none of the above scenarios apply a new game begins
			else {
				continue;
			}
		}
	} 

	// While the player has between 0 and 1000 dollars continue starting new games
	while (player.getMoney() > 0 && player.getMoney() < 1000); 
	return 0;
}