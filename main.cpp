#include<iostream>
#include<vector>
#include<algorithm>
#include "deck.h"
using namespace std;
int main(){
	deck a;
	a.populate();
	deck b;
	b.populate();
	b.shuffle();
	if(a!=b)
		cout<<"success";
	if(a==b)
		cout<<":("<<endl;
	//l = count(b.cards.begin(), b.cards.end(),t);
	//cout<<l; 
	/*if(a==b)
		cout<<"Equal; Order"<<endl;
	b.shuffle();
	if(a==b)
		cout<<"Equal; Shuffle"<<endl;
	cout<<endl;
	cout<<endl<<endl;
	if(a!=b)
		cout<<"Not Equal"<<endl;*/
}
