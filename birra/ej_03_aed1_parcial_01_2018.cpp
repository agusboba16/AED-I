#include <iostream>

using namespace std;

struct nodo{
	char dato;
	nodo* siguiente;
};

class Lista{
	private:
		nodo* inicio;
	public:
		Lista();
		void insertar(char);
		~Lista();
        void mostrar();
        void invertir(char);
};

Lista::Lista(){
	inicio = NULL;
}

void Lista::insertar(char dato){
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

void Lista::mostrar(){ 
    nodo* nodoActual = inicio;
    cout << "\n\nNULL";
    while(nodoActual != NULL){
        cout << " <--- [" << nodoActual -> dato << "]";
        nodoActual = nodoActual -> siguiente;
    }
}


int main(){
    int n = 0;
	
	Lista l = Lista();
	char letra;	
	cout<< "Ingrese caracteres. Para terminar ingrese 0:" << endl;
	do{
		cin>>letra;
		if (letra != '0')
			l.insertar(letra);
	}while (letra != '0');

// Mostrar los caracteres almacenados en la lista en orden 
	
	l.mostrar();
	
	
	cin.get();
	cin >> n;
	return 0;
}
