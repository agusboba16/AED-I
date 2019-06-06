#include <iostream>
#include <algorithm>

using namespace std;

struct objeto{
	int valor;
	int peso;
};

bool compararObjetos(objeto a, objeto b){
	double vr1 = (double)a.valor / a.peso;
	double vr2 = (double)b.valor / b.peso;
	return vr1 > vr2;
}
double llenarMochila(int p, objeto objetos[], int n){
	sort(objetos,objetos+n,compararObjetos);
	int pesoActual = 0;
	double valorActual = 0;
	for(int i=0;i<n;i++){
		if(pesoActual + objetos[i].peso <= p){
			pesoActual += objetos[i].peso;
			valorActual += objetos[i].valor;
		}
		else{
			int resto = p - pesoActual;
			valorActual += objetos[i].valor * ((double)resto / objetos[i].peso);
			break;
		}
	}
	return valorActual;	
}

int main(){
	int p = 10;
	objeto objetos[] = {{12,6},{11,6},{10,5}};
	int n = sizeof(objetos) / sizeof(objetos[0]);
	double beneficio = llenarMochila(p,objetos,n);
	cout<<"Maximo valor en mochila: " << beneficio << endl;
	return 0;
}


