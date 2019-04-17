#include <iostream>
#include "pila.h"
using namespace std;

pila::pila(){
	inicio = NULL;
}

pila::~pila(){
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

