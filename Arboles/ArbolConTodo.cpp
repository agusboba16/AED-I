#include<iostream>
#include<queue>
#define salto 9
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
		nodo* buscarMenor(nodo*);
		nodo* preorden(nodo*);
		nodo* mostrarAmplitud(nodo*);
		int cantidad(nodo*);
		int altura(nodo*);
		void mostrar(nodo*,int);
		bool esSubabbmayor(nodo*,int);
		bool esSubabbmenor(nodo*,int);
		bool esAbb(nodo*);
		void removerSubarbol(nodo*);
		nodo* borrar(nodo*, int);
		 
	public:
		Abb();
		~Abb();
		void insertar(int);
		bool buscar(int);
		nodo* buscarMenor();
		nodo* preorden();
		nodo* mostrarAmplitud();
		int cantidad();
		int altura();
		void mostrar();
		bool esSubabbmayor();
		bool esSubabbmenor();
		bool esAbb();
		void talarArbol();
		void removerSubarbol();
		nodo* borrar();
		
};
	Abb::Abb(){
		raiz = NULL;
	}
	
	
void Abb::removerSubarbol(nodo* n){
	if(n!=NULL){
		removerSubarbol(n->izq);
		removerSubarbol(n->der);
		delete n;
		n=NULL;
	}
}
	
	Abb::~Abb(){
		removerSubarbol(raiz);
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

nodo* Abb::buscarMenor(nodo* n){
	if(n==NULL){
		return NULL;
	}
	else if(n->izq!=NULL){
		buscarMenor(n->izq);
	}
	else{
		return n;
	}
}
nodo* Abb::buscarMenor(){
	return buscarMenor(raiz);
}

nodo* Abb::preorden(nodo* n){
	if(n!=NULL){
		cout<<n->dato<<"\n";
		preorden(n->izq)->dato;
		preorden(n->der)->dato;
	}
	else{
		return NULL;
	}
}

nodo* Abb::preorden(){
	return preorden(raiz);
}
nodo* Abb::mostrarAmplitud(){
	queue<nodo*> c;
	nodo* n = raiz;
	while(n!=NULL){
		cout<<n->dato<<"->";
		if(n->izq!=NULL){
		c.push(n->izq);
		}
		if(n->der!=NULL){
		c.push(n->der);
		}
		n = c.front();		
		c.pop();		
	}
}

int Abb::cantidad(nodo* n){
	if(n!=NULL){
		return cantidad(n->izq)+1+cantidad(n->der);
	}
	return 0;
}
int Abb::cantidad(){
	return cantidad(raiz);
}

int Abb::altura(nodo* n){
	
	if(n!=NULL){
		if(n->der == NULL && n->izq==NULL){
			return 0;
		}
		else{
			return 1 + max(altura(n->der),altura(n->izq));
		}
	}
	else{
		return 0;
	}
	
}

int Abb::altura(){
	altura(raiz);
}

void Abb::mostrar(nodo* n, int espacio){
	if(n==NULL){
		return;
	}
	espacio+=salto;
	mostrar(n->der, espacio);
	cout << endl;
	for(int i = salto; i < espacio; i++){
		cout<<" ";
	}
	cout <<"[" <<n->dato<< "]\n";
	mostrar(n->izq, espacio);
}

void Abb::mostrar(){
	mostrar(raiz,0);
}

bool Abb::esSubabbmenor(nodo* n,int dato){
	if(n!=NULL){
		if(esSubabbmenor(n->izq, dato) && esSubabbmenor(n->der, dato)&& n->dato < dato){
		return true;
		}
			return false;
	}return true;
}

bool Abb::esSubabbmayor(nodo* n,int dato){
	if(n!=NULL){
		if(esSubabbmayor(n->izq, dato) && esSubabbmayor(n->der, dato)&& n->dato > dato){
		return true;
		}
			return false;
	}return true;
}
bool Abb::esAbb(nodo* n){

	if(n==NULL){
		return true;
	}
	if(esSubabbmayor(n->der,n->dato)&&esSubabbmenor(n->izq,n->dato)&& esAbb(n->izq)&& esAbb(n->der)){
		return true;
	}
	else{
		return false;
	}
}
bool Abb::esAbb(){
	esAbb(raiz);
}

void Abb::talarArbol(){
	raiz->izq->der->dato = 20;
}

nodo* Abb::borrar(nodo* n, int x){
	if(n==NULL)return n;
	else if(x<n->dato){
		n->izq = borrar(n->izq,x);
	}
	else if(x<n->dato){
		n->der = borrar(n->der,x);
	}
	else{
		//caso 1: es un nodo
		if(n->izq == NULL && n->der == NULL){
			delete n;
			n = NULL;
		}
		//caso 2: 1 solo hijo
		else if(n->der==NULL){
			nodo* aux = n;
			n = n->izq;
			delete aux;
		}
		//caso 3: tiene dos hijos
		else{
			nodo* aux = buscarMenor(n->der);
			n->dato = aux->dato;
			borrar(n->der, aux->dato);
		}
	}
	return n;
}

nodo* Abb::borrar(){
	borrar(raiz,0);
}

int main(){
Abb a1;
a1.insertar(10);
a1.insertar(5);
a1.insertar(3);
a1.insertar(6);
a1.insertar(9);
a1.insertar(17);
a1.insertar(4);
a1.insertar(15);
a1.insertar(2);
a1.insertar(1);
//a1.talarArbol();
cout<<a1.buscar(5)<<endl;
cout<<a1.buscar(3)<<endl;
cout<<a1.buscar(20)<<endl;
cout<<a1.buscarMenor()->dato<<endl;	
cout<<"preorden\n";
a1.preorden();	
cout<<"En Amplitud\n";
a1.mostrarAmplitud();
cout<<"Cantidad: "<<a1.cantidad()<<endl;
cout<<"Altura maxima del arbol: " <<a1.altura()<<endl;
a1.mostrar();
cout<<endl;
cout<<a1.esAbb();
return 0;
}
