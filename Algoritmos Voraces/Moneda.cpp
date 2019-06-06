#include <iostream>

using namespace std;


void monedero(int monto, int solucion[], int denominaciones[]){
	for(int i=0; i<4; i++){
		solucion[i] = (monto / denominaciones[i]);
		int resto = (monto % denominaciones[i]);
		monto = resto; 
	}
}

void imprimirSolucion(int monto, int solucion[], int denominaciones[]){
	for(int i=0; i<4; i++){
		cout<<solucion[i]<<" Monedas de "<<denominaciones[i]<<"\n";
	}
}
int main(){
	int denominaciones[] = {25,10,5,1};
	int solucion[]= {0,0,0,0};
	int monto = 221;
	monedero(monto, solucion, denominaciones);
	imprimirSolucion(monto, solucion, denominaciones);
	return 0;
}
