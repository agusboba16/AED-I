#include <iostream>
#define N 64
using namespace std;

class DatoHash{
	private:
		int clave;
		string valor;
	public:
		DatoHash(int, string);
		int getClave();
		string getValor();
};

class TablaHash{
	private:
		DatoHash **tabla;
		funcionHash(int);
	public:
		TablaHash();
		string leer(int);
		void insertar(int, string);
		~TablaHash();
};

DatoHash::DatoHash(int clave, string valor){
	this->clave=clave;
	this->valor=valor;
}

int DatoHash::getClave(){
		return clave;
}
string DatoHash::getValor(){
		return valor;
}



TablaHash::TablaHash(){
	tabla = new DatoHash *[N];
	for(int i = 0; i<N; i++){
		tabla[i] = NULL;
	}
}
TablaHash::~TablaHash(){
	for(int i = 0; i<N; i++){
		if(tabla[i] != NULL){
			delete tabla[i];
		}
	}
		delete[] tabla;
}
int TablaHash::funcionHash(int clave){
	return clave % N;
}
string TablaHash::leer(int clave){
	int hash = funcionHash(clave);
	while(tabla[hash]!=NULL && tabla[hash]->getClave() != clave){
		hash = funcionHash(hash+1);
	if(tabla[hash] == NULL){
		cout<<"pepe\n";
		return "";
	}
	cout<<"pepe2\n";
		return tabla[hash]->getValor();
	}
}

void TablaHash::insertar(int clave,string valor){
	int hash = funcionHash(clave);
		while(tabla[hash]!=NULL && tabla[hash]->getClave() != clave){
		hash = (hash+1) % N;
		if(tabla[hash] != NULL){
			delete tabla[hash];
		}
		tabla[hash] = new DatoHash(clave,valor);
	}
}
int main(){
	TablaHash h1;
	cout<<h1.leer(50);
	cout<<"hola \n";
	h1.insertar(50,"vigil");
	cout<<"agus \n";
	
	 
return 0;	
}
