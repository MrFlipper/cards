#include<iostream>
#include<algorithm>
#include<random>
#include<chrono>
#include "deck.h"
#include "card.h"

deck::deck(){

}
void deck::populate(){
	card t; // create temporary card
	
	// nested for loop creates standard deck of 52
	for(int i = 0; i<5;i++){
		if(i<4){
			for(int j = 1; j<=13; j++){
				t.suit = s[i];
				t.value = j;
				cards.push_back(t);
			}
		}
		else{	// add jokers
			t.suit = s[i];
			t.value = 1;
			cards.push_back(t);
			t.suit = s[i];
			t.value = 2;
			cards.push_back(t);
		}
	}

}
void deck::shuffle(){
	srand(time(0));
	random_shuffle(cards.begin(), cards.end());
}
void deck::show(){
	for(it = cards.begin(); it != cards.end(); it++){
		it->show();
		cout<<" ";
	}
}
card deck::pop(){
	card t = cards.front();
	it = cards.begin();
	cards.erase(it);
	return t;

}
card deck::draw(int index){
	it = cards.begin();
	advance(it, --index);
	card t = *it;
	cards.erase(it);
	return t;
}
void deck::replace(card t){
	int s = cards.size()+1;
	this->insert(t, s);
}
void deck::replace(deck t){
	int i = t.cards.size()-1;
	int s = cards.size()+1;
	card c;
	for(i; i>=0; i--){
		if(not t.isEmpty()){
			c = t.pop();
			this->insert(c, s);
		}
	}
}
void deck::insert(card t, int index){
	it = cards.begin();
	advance(it, --index);
	cards.insert(it, t);
}
void deck::removeJ(){
	for(it = cards.begin(); it != cards.end(); it++){
		if(it->suit == s[4]){
			cards.erase(it);
			it--;
		}
	}
}
bool deck::isEmpty(){
	return cards.empty();

}
deck deck::deal(int y){
	deck t;
	for(y; y>0; --y){
		t.cards.push_back(cards.front());
		cards.erase(cards.begin());
	}
	return t;
}
bool deck::operator==(deck t){
	card a, b;
	bool eq = true;
	if(cards.size() == t.cards.size()){
		for(it = cards.begin(); it!=cards.end(); it++){
			if(eq){
				a = this->pop();
				b = t.pop();
				if(a !=b)
					eq = false;
			}
			this->replace(a);
			t.replace(b);
		}
	}
	else
		eq=false;
	return eq;

}
