#include<iostream>
#include "pila.h"

using namespace std;

bool esCapicua(string palabra){
	pila p;
	int l = palabra.length();
	
	for(int i=0;i<l/2; i++){
		p.push(palabra[i]);
	}
	int mitad = l/2 + l%2;
	for(int i=mitad; i<l; i++){
		if(palabra[i] != p.top()){
			return false;
		}
		else{
			p.pop();	
			}
		}
	if(p.size()){
		return false;
	}
	return true;
}

int main(){
	/*pila p;
	p.push('A');
	p.push('B');
	cout<<"Tamaño: "<<p.size()<<endl;
	cout<<"Top: "<<p.top()<<endl;*/
	string palabra;
	while(palabra != "salir"){
			cout<<"Ingrese una palabra: ";
			getline(cin, palabra);
			cout<<palabra << (esCapicua(palabra)?" es capicua" : " no es capicua")<<endl;
	return 0;
	}
}

