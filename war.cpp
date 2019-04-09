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
		cout<<"Player 1: ";
		player1.show();
		cout<<endl;
		cout<<endl<<"Player 2: ";
		player2.show();
		cout<<endl<<endl;
		c1 = player1.pop();
		c2 = player2.pop();
		cout<<"Card 1: ";
		c1.show();
		cout<<endl;
		cout<<"Card  2: ";
		c2.show();
		cout<<endl;
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
		else if(c1.vEqual(c2) and not player1.isEmpty() and not player2.isEmpty()){
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
		player1.shuffle();
		player2.shuffle();
	}
	if(player1.isEmpty())
		cout<<"PLAYER 2 WINS!!"<<endl;
	else
		cout<<"PLAYER 1 WINS!!"<<endl;
	return 0;
}

deck war(deck &p1, deck &p2){
	deck a, b;
	if(int(p1.cards.size())>=4 && int(p2.cards.size())>=4){
		a = p1.deal(4);
		b = p2.deal(4);
	}
	else if(int(p1.cards.size())<4){
		if(int(p1.cards.size()) > 1)
			a = p1.deal(int(p1.cards.size()));
		else
			a = p1.deal(1);
		b = p2.deal(4);
	}
	else if(int(p2.cards.size())<4){
		a = p1.deal(4);
		if(int(p2.cards.size()) > 1)
			b = p2.deal(int(p2.cards.size()));
		else
			b = p2.deal(1);
	}
	card x, y;
	if(int(a.cards.size()) != 0){
		x = a.draw(int(a.cards.size()));
		a.replace(x);
	}
	if(int(b.cards.size()) != 0){
		y = b.draw(int(b.cards.size()));
		b.replace(y);
	}
	cout<<"Player 1: ";
	a.show();
	cout<<"__Card: ";
	x.show();
	cout<<"    Player 2: ";
	b.show();
	cout<<"__Card: ";
	y.show();
	cout<<endl;
	if(x > y){
		cout<<"Winner: Player 1!"<<endl;
		p1.replace(a);
		p1.replace(b);
		return p1;
	}
	else if(x < y){
		cout<<"Winner: Player 2!"<<endl;
		p2.replace(a);
		p2.replace(b);
		return p2;
	}
	else if(x.vEqual(y)){
		cout<<"WAR!!"<<endl;
		if(war(p1, p2) == p1){
			p1.replace(a);
			p1.replace(b);
			return p1;
		}
		else{
			p2.replace(a);
			p2.replace(b);
			return p2;
		}
	}
}
