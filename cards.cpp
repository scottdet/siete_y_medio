#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <string>

// You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>

/* *************************************************
Card class
************************************************* */

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.
*/
Card::Card() {
	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}

// Accessor: returns a string with the suit of the card in Spanish
std::string Card::get_spanish_suit() const {
	std::string suitName;
	switch (suit) {
	case OROS:
		suitName = "oros";
		break;
	case COPAS:
		suitName = "copas";
		break;
	case ESPADAS:
		suitName = "espadas";
		break;
		case BASTOS:
	suitName = "bastos";
		break;
	default: break;
	}
	return suitName;
}

//Accessor: returns a string with the rank of the card in Spanish
std::string Card::get_spanish_rank() const {
	std::string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}

//Accessor: returns a string with the suit of the card in English
std::string Card::get_english_suit() const {
	std::string englishSuitName;
	switch (suit) {
	case OROS:
		englishSuitName = "coins";
		break;
	case COPAS:
		englishSuitName = "cups";
		break;
	case ESPADAS:
		englishSuitName = "swords";
		break;
	case BASTOS:
		englishSuitName = "clubs";
		break;
	default: break;
	}
	return englishSuitName;
}

//Accessor: returns a string with the rank of the card in English
std::string Card::get_english_rank() const {
	std::string englishRankName;
	switch (rank) {
	case AS:
		englishRankName = "Ace";
		break;
	case DOS:
		englishRankName = "Two";
		break;
	case TRES:
		englishRankName = "Three";
		break;
	case CUATRO:
		englishRankName = "Four";
		break;
	case CINCO:
		englishRankName = "Five";
		break;
	case SEIS:
		englishRankName = "Six";
		break;
	case SIETE:
		englishRankName = "Seven";
		break;
	case SOTA:
		englishRankName = "Jack";
		break;
	case CABALLO:
		englishRankName = "Knight";
		break;
	case REY:
		englishRankName = "King";
		break;
	default: break;
	}
	return englishRankName;
}

// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}

// Assigns value based on the rank of the card
// AS=1, DOS=2, TRES=3, CUATRO=4, CINCO=5, SEIS=6, SIETE=7, SOTA=0.5, CABALLO=0.5, REY=0.5
double Card::get_value() const {
	double value = static_cast<double>(get_rank());
	if (value > 0 && value < 8)
		return value;
	else
		return 0.5;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}

/* *************************************************
Hand class
************************************************* */

// Default constructor initializes a random card to the hand of cards
Hand::Hand() {
	Card newCard;
	cards.push_back(newCard);
}

// Prints the last card
void Hand::last() const {
	int i = cards.size() - 1;
	std::cout << '\t' << cards[i].get_spanish_rank() + " de " + cards[i].get_spanish_suit() << 
		'\t' << "(" + cards[i].get_english_rank() + " of " + cards[i].get_english_suit() + ")." << '\n';
}

// Total value of hand
double Hand::sum() const {
	double sum = 0.0;
	for (int i = 0; i < cards.size(); i++) {
		sum += cards[i].get_value();
	}
	return sum;
}

// Compare value of objects in hand
bool Hand::operator < (Hand hand2) const {
	double sum1 = sum();
	double sum2 = hand2.sum();
	return sum1 < sum2;
}

// Add random card to hand
void Hand::draw() {
	Card newCard;
	cards.push_back(newCard);
}

// Resets hand
void Hand::reset() {
	cards.resize(0);
}

// Sorts hand
void Hand::sortHand() {
	sort(cards.begin(), cards.end());
}

// Print hand
void Hand::print() {
	sortHand();//The cards are sorted first
	for (int i = 0; i < cards.size(); i++) {
		std::cout << '\t' << cards[i].get_spanish_rank() + " de " + cards[i].get_spanish_suit() << 
			'\t' << "(" + cards[i].get_english_rank() + " of " + cards[i].get_english_suit() + ")." << '\n';
	}
}

// Print hand to log file
void Hand::log(std::ofstream& fout) {
	sortHand();//The cards are sorted first
	for (int i = 0; i < cards.size(); i++) {
		fout << '\t' << cards[i].get_spanish_rank() + " de " + cards[i].get_spanish_suit() << 
			'\t' << "(" + cards[i].get_english_rank() + " of " + cards[i].get_english_suit() + ")." << '\n';
	}
}

/* *************************************************
Player class
************************************************* */

//Default constructor intializes m amount of money
Player::Player(int cash) {
	money = cash;
}

// Returns the amount of money
int Player::getMoney() const {
	return money;
}

// Refreshed amount of money based on previous games bet/outcome
void Player::refreshMoney(int change) {
	money += change;
}