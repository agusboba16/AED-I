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
		void insertar(int);
		~Lista();
        bool estaOrdenada();		
};

Lista::Lista(){
	inicio = NULL;
}

void Lista::insertar(int dato){
	nodo* nuevoNodo = new nodo;
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = inicio;
	inicio = nuevoNodo;
}

Lista::~Lista(){
        nodo *nodoActual = inicio;

        while(nodoActual) {
            nodo *nodoABorrar = nodoActual;
            nodoActual = nodoActual->siguiente;     
            delete nodoABorrar;
        }
}

/*bool Lista::estaOrdenada(){
    bool resultado = false;
    //nodo * nodoActual = inicio; //Inicializacion (a NULL).
    //nodoActual -> dato = dato;
    nodo*nodoActual = inicio;
    
    nodo* siguiente2 = nodoActual -> siguiente;
    int nodoSiguiente = siguiente2 -> dato;
    
    while(nodoActual != NULL){
        //if(nodoActual -> dato > nodoActual -> siguiente){
        if(nodoActual -> dato > nodoSiguiente){
            resultado = true;
        }
        else{
            resultado = false;
        }
        
        nodoActual -> dato = dato;
	    nodoActual -> siguiente = inicio;
     	inicio = nodoActual;
     	siguiente2 = nodoActual -> siguiente;
     	nodoSiguiente = siguiente2 -> dato;
    }
    return resultado;
}*/

bool Lista::estaOrdenada(){
    bool resultado = true;
    
    nodo * nodoActual = inicio;
    nodo * nodoSiguiente = nodoActual -> siguiente;
    
    while(nodoSiguiente != NULL){
        if(nodoActual -> dato > nodoSiguiente -> dato){
            resultado = false;
        }
        
        nodoActual = nodoActual -> siguiente;
        nodoSiguiente = nodoActual -> siguiente;
    }
    
    return resultado;
}

int main(){
	
	Lista l1 = Lista();
	l1.insertar(92);
	l1.insertar(51);
	l1.insertar(30);
	l1.insertar(21);
	l1.insertar(14);
	l1.insertar(11);
	l1.insertar(7);
	l1.insertar(5);
	l1.insertar(4);
	l1.insertar(1);

// Mostrar si l1 está ordenada
    if(l1.estaOrdenada() == true){
        cout << "La lista 1 esta ordenada de forma ascendente.\n\n";
    }
    else{
        cout << "La lista 1 no esta ordenada de forma ascendente.\n\n";
    }

	
	Lista l2 = Lista();
	l2.insertar(21);
	l2.insertar(42);
	l2.insertar(15);
	l2.insertar(7);
	l2.insertar(1);

// Mostrar si l2 está ordenada
    if(l2.estaOrdenada() == true){
        cout << "La lista 2 esta ordenada de forma ascendente.\n\n";
    }
    else{
        cout << "La lista 2 no esta ordenada de forma ascendente.\n\n";
    }
	
	cin.get();
	return 0;
}
