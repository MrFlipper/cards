#ifndef CARD_H_
#define CARD_H_
#include<iostream>
using namespace std;
class card{
	public:
		card(); // Default Constructor (not useful)
		card(char s, int v);	// Useful Constructor
		void show();	// Outputs card to ostream
		char suit;	// Stores the suit of card 
		int value;	// Stores the value of card
		bool vEqual(card);
		bool operator==(card);	// Overload operator == to check if two cards are equivalent
		bool operator!=(card);	// Overload operator != to check if two cards are no equal
		bool operator<(card);
		bool operator>(card);
	

};
#endif
