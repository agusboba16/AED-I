#include<iostream>
#include<queue>

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
		nodo* preorden(nodo *);
		nodo* mostrarAmplitud(nodo *);
		int cantidad(nodo*);
	public:
		Abb();
		//~Abb();
		void insertar(int);
		bool buscar(int);
		nodo* buscarMenor();
		nodo* preorden();
		nodo* mostrarAmplitud();
		int cantidad();
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
cout<<a1.buscar(5)<<endl;
cout<<a1.buscar(3)<<endl;
cout<<a1.buscar(20)<<endl;
cout<<a1.buscarMenor()->dato<<endl;	
cout<<"preorden\n";
a1.preorden();	
cout<<"En Amplitud\n";
a1.mostrarAmplitud();
cout<<"Cantidad: "<<a1.cantidad();

return 0;
}
