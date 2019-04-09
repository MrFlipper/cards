#ifndef DECK_H_
#define DECK_H_
#include<iostream>
#include<vector>
#include "card.h"
using namespace std;
const int max_cards = 54;
class deck{
	public:
		deck();
		void populate();// Builds standard 54-card deck
		void shuffle(); // Shuffle the deck of cards
		void show();	// Outputs deck to ostream
		card pop();	// Returns then removes the top card of deck
		card draw(int);	// Draws the card at "int" position
		void swap(int, int);	// Swaps two cards
		void insert(card, int);	// inserts a card at "int" position
		void replace(card);	// Places card on bottom of deck
		void replace(deck);	//Places a number of cards on bottom of deck
		void removeJ();	// Removes Jokers from deck
		bool isEmpty(); // Check if deck is empty
		deck deal(int);// Returns a vector of dealt cards from the top of the deck
		vector <card> cards;	// Vector represents deck of cards
		vector <card>::iterator it;	// Iteration variable for cards
		char s[5] = {'S', 'H', 'C', 'D','J'};	// List of "suits" for the cards (S=Spades, H=Hearts, etc.)
		bool operator==(deck);
		bool operator!=(deck);
		bool isValid(card);
};
#endif
