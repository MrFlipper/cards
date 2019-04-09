#include<iostream>
#include "deck.h"
using namespace std;
int main(){
	deck a;
	a.populate();
	deck t;
	a.show();
	for(int i = 4; i>0; i--){
		t.replace(a.pop());
	}
	cout<<endl;
	t.show();
	cout<<endl;
	a.replace(t);
	a.show();
	cout<<endl;
}
