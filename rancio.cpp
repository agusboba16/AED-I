#include <iostream>

using namespace std;
int i=0;
class Lista{
	private:
	struct nodo{
	nodo* siguiente;
	int dato;	

	};
		void longitudRecursiva(nodo* aux);
	nodo* inicio;
	public:
	Lista();
	~Lista();
	void insertar(int);
	void insertarEnOrden(int);
	void insertarEnPos(int,int);
	void longitudRecursiva();
	void mostrar();
};

Lista::Lista(){
	inicio = NULL;
}
Lista::~Lista(){
	nodo* n = inicio;
	while(n){
		nodo* aux = n;
		n = aux->siguiente;
		delete aux;
		
	}
}
void Lista::insertar(int dato){
	nodo* n = new nodo;
	n->dato = dato;
	n->siguiente = inicio;
	inicio = n;
}

void Lista::insertarEnOrden(int dato){
	nodo* n = new nodo;
	nodo* aux1;
	nodo* aux2;
	n->dato = dato;
	aux1 = inicio;
	while((aux1!=NULL) && (aux1->dato < dato)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if(inicio==aux1){
		inicio = n;
	}
	else{
		aux2->siguiente = n;
	}
	n->siguiente = aux1;
}

void Lista::insertarEnPos(int dato, int posicion){
	nodo* n = new nodo;
	n->dato = dato;
	n->siguiente = NULL;
	nodo* aux1 = new nodo;
	nodo* aux2= new nodo;
	aux1 = inicio;
	for(int i=1;i<posicion;i++){
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	aux2->siguiente = n;
	n->siguiente = aux1;
	
	
}
void Lista::mostrar(){
	nodo* aux = inicio;
	while(aux!=NULL){
		cout<<"->"<<aux->dato;
		aux=aux->siguiente;
	}
}
	void Lista::longitudRecursiva(nodo* aux){
			
			if(aux==NULL){
				cout<<"Longitud: "<<i;
				return;
			}
			else{
				i++;
				longitudRecursiva(aux->siguiente);
			}
		}
		void Lista::longitudRecursiva(){
			longitudRecursiva(inicio);
		}
int main(){
	Lista l1;
	l1.insertar(1);
	l1.insertar(0);
	l1.insertar(3);
	l1.insertar(4);
	cout<<"\n";
	l1.mostrar();
	cout<<"\n";
	l1.insertarEnOrden(2);
	l1.insertarEnPos(100,3);
	l1.mostrar();
	l1.longitudRecursiva();
}
