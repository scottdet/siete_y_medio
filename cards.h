/* *****************************
Scott de Taboada, June 1, 2017

Interface of a simple Card class
***************************** */

#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H
#define CARDS_H

enum suit_t {OROS, COPAS, ESPADAS, BASTOS};
/*
The values for this type start at 0 and increase by one
afterwards until they get to SIETE.
The rank reported by the function Card::get_rank() below is
the value listed here plus one.
E.g:
The rank of AS is reported as    static_cast<int>(AS) + 1   = 0 + 1 =  1
The rank of SOTA is reported as  static_cast<int>(SOTA) + 1 = 9 + 1 = 10
*/
enum rank_t {AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA = 9, CABALLO = 10, REY = 11};

class Card {
public:
	// Constructor assigns random rank & suit to card.
	Card();

	// Accessors
	std::string get_spanish_suit() const;
	std::string get_spanish_rank() const;

	/*
	These are the only functions you'll need to code
	for this class. See the implementations of the two
	functions above to get an idea of how to proceed.
	*/
	std::string get_english_suit() const;
	std::string get_english_rank() const;

	// Converts card rank to number.
	// The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
	int get_rank() const;

	// Converts card rank to value.
	// The possible returns are: 0.5, 1, 2, 3, 4, 5, 6 and 7
	double get_value() const;

	// Compare rank of two cards. E.g: Eight<Jack is true.
	// Assume Ace is always 1.
	// Useful if you want to sort the cards.
	bool operator < (Card card2) const;

private:
	suit_t suit;
	rank_t rank;
};

class Hand { 
public:
	// A vector of Cards
	Hand();

	// Compares the value of two Hands
	bool operator < (Hand hand2) const;

	// Total of cards
	double sum() const;

	// Print last card
	void last() const;

	// Add card to hand
	void draw();

	// Reset hand
	void reset();

	// Sort the hand
	void sortHand();

	// Print all cards in hand
	void print();

	// Write to log file
	void log(std::ofstream& fout);

private:
	std::vector<Card> cards;
};

class Player {
public:
	// Constructor
	// Assigns initial amount of money
	Player(int m);

	// Amount of money
	int getMoney() const;

	// Refresh the amount of money based on previous bet
	void refreshMoney(int bet);

private:
	int money;
};

#endif
