#include<iostream>
#include "card.h"

card::card(){
	suit = 'S';
	value = 1;
}
card::card(char s, int v){
	suit = s; 
	value = v;
}
void card::show(){
	cout<<suit<<value;
}
bool card::vEqual(card c){
	if(this->value == c.value)
		return true;
	else
		return false;
}
bool card::operator==(card c){
	if(this->suit == c.suit and this->value == c.value)
		return true;
	else 
		return false;
}
bool card::operator!=(card c){
	if(this->suit == c.suit and this->value == c.value)
		return false;
	else
		return true;

}
bool card::operator>(card c){
	if(this->value > c.value)
		return true;
	else
		return false;
}
bool card::operator<(card c){
	if(this->value < c.value)
		return true;
	else
		return false;
}
