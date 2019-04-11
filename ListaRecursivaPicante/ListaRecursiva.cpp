#include <iostream>
#include <sstream>
using namespace std;
int i=0;
class Lista{
	private:
		struct nodo{
			int dato;
			nodo *siguiente;
		};
		nodo *inicio;
		void mostrarRecursiva(nodo* aux);
		void longitudRecursiva(nodo* aux);
		
	public:
		Lista();
		
		void Insertar(int);
		void Mostrar();
		void esta_vacia();
		int longitud();
		void mostrarRecursiva();
		void longitudRecursiva();
		void remover();
		void removerUltimo();
		void Invertir();
		~Lista(){
			nodo* n = inicio;
			while(n){
				nodo* aux= n;
				n = aux->siguiente;
				delete aux;
			}
		}
};

		void Lista::remover(){
			nodo* n = inicio;
			if(inicio==NULL){
				cout<<"nada";
				return;
			}
			else{
			inicio=n->siguiente;
				delete n;
			}
			}
			
		void Lista::removerUltimo(){
			nodo* n = inicio;
			nodo * aux;
			do{
				aux = n;
				n = n->siguiente;
			}while(n->siguiente!=NULL);
			
			delete n;
			aux->siguiente = NULL;	
		}
		Lista::Lista(){
			inicio = NULL;
		}

		void Lista::Insertar(int dato){
			nodo* n = new nodo;
			n->dato = dato;
			n->siguiente=inicio;
			inicio = n;
			}
		void Lista::Mostrar(){
			nodo* aux = inicio;
			while(aux!=NULL){
				cout<<"numeros: "<<aux->dato<<endl;;
				aux = aux->siguiente;
				}
			}
			
		void Lista::mostrarRecursiva(nodo* aux){
			if(aux==NULL){	
			cout<<" \n"	;
			return ;
			}
			else{
				cout<<"\n ->"<< aux->dato;
				mostrarRecursiva(aux->siguiente);
			}
			
		}
		void Lista::mostrarRecursiva(){
			mostrarRecursiva(inicio);
		}
		
		
		void Lista::esta_vacia(){
			nodo* aux = inicio;
			int i =0;
			while(aux!=NULL){
				aux = aux->siguiente;
				i++;
				}
				if(i==0){
					cout<<"La lista esta vacia.\n";
					}
				else{
					cout<<"La lista posee "<< i << "elementos.\n";
					}
			}
		
		int Lista::longitud(){
			nodo* aux = inicio;
			int i = 0;
			while(aux!=NULL){
				aux = aux->siguiente;
				i++;
				}
					return i;
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
		void Lista::Invertir(){
			nodo* nodoAnterior = NULL;
			nodo* nodoActual = inicio;
			nodo* nodoSiguiente= NULL;
			while(nodoActual!=NULL){
				nodoSiguiente=nodoActual->siguiente;
				nodoActual->siguiente = nodoAnterior;//cambia el puntero hacia el nodo anterior
				nodoAnterior = nodoActual;
				nodoActual = nodoSiguiente;
			}
			inicio = nodoAnterior;
		}

	
int main(){
	
	Lista l1;
	
	
	l1.Insertar(5);
	l1.Insertar(1);
	l1.Insertar(9);
	l1.Insertar(2);
	//l1.remover();
	//l1.removerUltimo();
	l1.Mostrar();
	l1.esta_vacia();
	l1.mostrarRecursiva();
	l1.longitudRecursiva();
	l1.Invertir();
	
	
return 0;
}
