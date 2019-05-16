#include<iostream>

using namespace std;
struct nodo{
		int dato;
		nodo *izq;
		nodo *der;
		};

class Abb{
	private:
		nodo* raiz;
		nodo* crearNodo(int);
		nodo* insertarAbb(int,nodo*);
		bool buscar(int,nodo*);
	public:
		Abb();
		//~Abb();
		void insertar(int);
		bool buscar(int);
};
	Abb::Abb(){
		raiz = NULL;
	}
nodo* Abb::crearNodo(int dato){
	nodo * n = new nodo;
	n->dato = dato;
	n->izq = NULL;
	n->der = NULL;
	return n;
}
nodo* Abb::insertarAbb(int dato,nodo*n){
	if(n==NULL){
		n = crearNodo(dato);
	}
	else if(dato < n->dato){
		n->izq = insertarAbb(dato , n->izq);
	}
	else if(dato > n->dato){
		n->der = insertarAbb(dato , n->der);
	}
	return n;	
	}
	
void Abb::insertar(int dato){
	raiz = insertarAbb(dato,raiz);
}
bool Abb::buscar(int x,nodo *n){
		if(n==NULL){
			return false;
		}
		else{
			if (x > n->dato){
				buscar(x,n->der);
			}
			else{
			if( x < n->dato){	
				buscar(x,n->izq);
			}
			else{
				return true ;
			}
		}
	}
}
bool Abb::buscar(int x){
	return buscar(x,raiz);
	
}	

int main(){
Abb a1;
a1.insertar(1);
a1.insertar(5);
a1.insertar(3);
a1.insertar(4);
a1.insertar(15);
a1.insertar(2);
cout<<a1.buscar(5)<<endl;
cout<<a1.buscar(3)<<endl;
cout<<a1.buscar(20)<<endl;		
return 0;
}
