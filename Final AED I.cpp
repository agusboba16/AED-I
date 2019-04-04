#include <iostream>

using namespace std;

struct nodo{
	int dato;
	nodo* siguiente;
};

class Lista{
	private:
		nodo* inicio;
	public:
		Lista();
		void Insertar(int);
		void Mostrar();
		int ObtenerMenor();
		//void ExtraerMenor();
		//~Lista();		
};

Lista::Lista(){
	inicio = NULL;
}


void Lista::Insertar(int dato){
	nodo* NuevoNodo = new nodo;
	NuevoNodo->dato = dato;
	NuevoNodo->siguiente = inicio;
	inicio = NuevoNodo;
}

void Lista::Mostrar(){
	nodo* NodoActual = inicio;
	while(NodoActual != NULL){
		cout << NodoActual->dato << "-> ";
		NodoActual = NodoActual->siguiente; 
	}
	
}



int Lista::ObtenerMenor(){
	nodo* NodoActual = inicio;
	nodo* NodoSiguiente = inicio->siguiente;
	while(NodoActual != NULL){
		
			if(NodoActual->dato < NodoSiguiente->dato){
			  
		   }
		   	NodoSiguiente = NodoSiguiente->siguiente;	
		NodoSiguiente = NodoActual->siguiente;
		NodoActual = NodoActual->siguiente;		
	}
  cout << menor;
}


int main(){
	
	Lista l = Lista();
	l.Insertar(21); 
	l.Insertar(7); 
	l.Insertar(4); 
	l.Insertar(234); 
	l.Insertar(2); 
	l.Insertar(9); 
	l.Insertar(12); 
	l.Insertar(70); 
	l.Mostrar();
	
	cout << endl;
	
	cout << endl;
	
	cout  << l.ObtenerMenor() << endl;
	//l.ExtraerMenor();
//	cout << "El menor es" << l.ObtenerMenor() << endl;
//	l.Mostrar();
	
	
	return 0;
}
