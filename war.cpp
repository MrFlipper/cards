#include<iostream>
#include "deck.h"
using namespace std;
deck war(deck &p1, deck &p2);
int main(){
	deck a, player1, player2, d;
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
		player1.shuffle();
		player1.show();
		cout<<endl;
		cout<<endl<<"Player 2: ";
		player2.shuffle();
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
			d = war(player1, player2);
			if(d==player1){
				cout<<"Winner: Player1!"<<endl;
				player1.replace(c1);
				player1.replace(c2);
			}
			else if (d == player2){
				cout<<"Winner: Player2!"<<endl;
				player2.replace(c1);
				player2.replace(c2);
			}
			else{
				cout<<"Error!"<<endl;
				return 0;
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
	card x, y;
	if(not p1.isEmpty() and not p2.isEmpty()){
		if(p1.cards.size()>=4){
			a = p1.deal(4);
			if(p2.cards.size()>=4)
				b = p2.deal(4);
			else
				b = p2.deal(p2.cards.size());
		}
		else{
			a = p1.deal(p1.cards.size());
			b = p2.deal(4);
		}
		cout<<"Hand 1: ";
		a.show();
		cout<<"	Hand 2: ";
		b.show();
		cout<<endl;
		x = a.draw(a.cards.size());
		y = b.draw(b.cards.size());
		a.replace(x);
		b.replace(y);
		cout<<"Card 1: ";
		x.show();
		cout<<"	Card 2: ";
		y.show();
		cout<<endl;
		if(x>y){
			p1.replace(a);
			p1.replace(b);
			return p1;
		}
		else if(x<y){
			p2.replace(b);
			p2.replace(a);
			return p2;
		}
		else if(x.vEqual(y)){
			cout<<"WAR!!"<<endl;
			return war(p1, p2);
		}

	}
	else if(p1.isEmpty())
		return p2;
	else
		return p1;
}
