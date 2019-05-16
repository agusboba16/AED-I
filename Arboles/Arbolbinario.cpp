#include<iostream>

using namespace std;

struct nodo{
	int dato;
	nodo *izq;
	nodo *der;
};

nodo* crearNodo(int dato){
	nodo * n = new nodo;
	n->dato = dato;
	n->izq = NULL;
	n->der = NULL;
	return n;
}

int main(){
	
nodo *r = crearNodo(1);
r->izq = crearNodo(2);
r->der = crearNodo(3);
r->izq->izq = crearNodo(4);	
r->izq->der = crearNodo(6);
	
	
	return 0;
}
