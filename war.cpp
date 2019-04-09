#include<iostream>
#include "deck.h"
using namespace std;
deck war(deck &p1, deck &p2);
int main(){
	deck a, player1, player2;
	card c1, c2;
	a.populate();
	a.removeJ();
	a.shuffle();
	int l = a.cards.size()/2;
	int c = 1;
	player1 = a.deal(l);
	player2 = a.deal(l);
	while(not player1.isEmpty() and not player2.isEmpty()){
		
		cout<<endl<<"Round "<<c<<": "<<endl<<endl;
		c1 = player1.pop();
		c2 = player2.pop();
		cout<<"Player 1: ";
		c1.show();
		cout<<"    Player 2: ";
		c2.show();
		cout<<endl;
		if(c1 > c2){
			cout<<"Winner: Player 1!"<<endl;
			player1.replace(c1);
			player1.replace(c2);
			cout<<endl;
		}
		else if(c2 > c1){
			cout<<"Winner: Player2!"<<endl;
			player2.replace(c1);
			player2.replace(c2);
			cout<<endl;
		}
		else if(c1.vEqual(c2)){
			cout<<"WAR!!"<<endl;
			if(war(player1, player2)==player1){
				player1.replace(c1);
				player1.replace(c2);
			}
			else{
				player2.replace(c1);
				player2.replace(c2);
			}
		}
		c++;
	}
	if(player1.isEmpty())
		cout<<"PLAYER 2 WINS!!"<<endl;
	else
		cout<<"PLAYER 1 WINS!!"<<endl;
	return 0;
}

deck war(deck &p1, deck &p2){
	deck a, b;
	if(p1.cards.size()>4 && p2.cards.size()>4){
		a = p1.deal(4);
		b = p2.deal(4);
	}
	else if(p1.cards.size()<4){
		a = p1.deal(p1.cards.size()-1);
		b = p2.deal(4);
	}
	else if(p2.cards.size()<4){
		a = p1.deal(4);
		b = p2.deal(p2.cards.size()-1);
	}
	else{
		a = p1.deal(4);
		b = p2.deal(4);
	}
	if(a.cards.end() > b.cards.end()){
		cout<<"Winner: Player 1!"<<endl;
		p1.replace(a);
		p1.replace(b);
		return p1;
	}
	else if(a.cards.end() < b.cards.end()){
		cout<<"Winner: Player 2!"<<endl;
		p2.replace(a);
		p2.replace(b);
		return p2;
	}
	else if(a.cards.end() == b.cards.end()){
		cout<<"WAR!!"<<endl;
		if(war(p1, p2) == p1){
			p1.replace(a);
			p1.replace(b);
			return a;
		}
		else{
			p2.replace(a);
			p2.replace(b);
			return b;
		}
	}
}
