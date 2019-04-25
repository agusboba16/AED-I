#include <iostream>
#include <stack>
using namespace std;

string invertir(string);

int main(){
	string cadena;
	
	cout<<"Ingrese la palabra\n";
	getline(cin,cadena);
	cout<<cadena<<"\n";
	cout<<invertir(cadena);
	return 0;
}

string invertir(string cadena){
	stack<char> p;
	string invertida = "";
	
	for(int i=0; i<cadena.length();i++){
	p.push(cadena[i]);
	}	
	while(!p.empty()){
	invertida+=p.top();
	p.pop();
	}
	return invertida;
}

