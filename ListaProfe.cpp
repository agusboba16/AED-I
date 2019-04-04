#include <iostream>
#include <sstream>
using namespace std;

class Lista{
	private:
		struct nodo{
			int dato;
			nodo *siguiente;
		};
		nodo *inicio;
		
	public:
		Lista();
		void Insertar(int);
		void Mostrar();
		void esta_vacia();
		int longitud();
};
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
		
int main(){
	
	Lista l1;
	/*l1.Insertar(5);
	l1.Insertar(1);
	l1.Insertar(9);
	l1.Insertar(2);*/
	l1.Mostrar();
	l1.esta_vacia();
	cout<<l1.longitud();
	
return 0;
}
