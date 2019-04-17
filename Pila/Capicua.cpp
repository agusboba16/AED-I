#include<iostream>
#include "pila.h"

using namespace std;

int main(){
	pila p;
	p.push('A');
	p.push('B');
	cout<<"Tamaño: "<<p.size()<<endl;
	cout<<"Top: "<<p.top()<<endl;
	return 0;
}

