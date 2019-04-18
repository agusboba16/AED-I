#include<iostream>
using namespace std;

class pila{
	private:
		struct nodo{
			char dato;
			nodo* siguiente;
		};
		nodo* inicio;
	public:
		pila();
		~pila();
		void push(char dato);//agrega el elemento arriba en la pila
		void pop();//remueve el elemento de mas arriba de la pila
		char top();//Devuelve una referencia al elemento de más arriba de la pila
		bool empty();//devuelve si la pila está vacia
		int size();//devuelve el tamaño de la pila
};

pila::pila(){
	inicio = NULL;
}

pila::~pila(){
	nodo* n = inicio;
	while(n!=NULL){
		nodo* aux = n;
		n = aux->siguiente;
		delete aux;
	}
}

void pila::push(char dato){
	nodo* n = new nodo;
	n->dato = dato;
	n->siguiente = inicio;
	inicio = n;
}

bool pila::empty(){
	return inicio==NULL;
}

void pila::pop(){
	if(!empty()){
		nodo* aux = inicio;
		inicio = inicio->siguiente;
		delete aux;
	}
}

char pila::top(){
	if(!empty()){
		return inicio->dato;
	}
	else{
		return 0;
	}
}

int pila::size(){
	int s=0;
	nodo* n = inicio;
	while(n!=NULL){
		s++;
		n=n->siguiente;
	}
	return s;
}

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
	pila p;
	p.push('A');
	p.push('B');
	cout<<"Tamaño: "<<p.size()<<endl;
	cout<<"Top: "<<p.top()<<endl;
	string palabra;
	while(palabra != "salir"){
	cout<<"Ingrese una palabra: ";
	getline(cin, palabra);
	cout<<palabra << (esCapicua(palabra)?" es capicua" : " no es capicua")<<endl;
	}
	return 0;
}


