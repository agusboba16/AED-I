#include <iostream>

using namespace std;

int busquedaBinaria(int A[],int i, int f, int x){
	if(i<=f){
		int mitad = i+((f-i)/2);
		if(x==A[mitad]){
		return mitad;	
		}
		if(x<A[mitad]){
			busquedaBinaria(A,i,mitad-1,x);
		}
		else{
			busquedaBinaria(A,mitad+1,f,x);
		}
	}
	else{
		return -1;
	}
}

void mostrar_A(int A[],int n){
	cout<<"A: \n";
	for(int i=0;i<n;i++){
		cout<<A[i]<<"\n";
	}
}
int main(){
	int x;
	int A[]={1,2,3,4,5,6,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
	int n = sizeof(A) / sizeof(A[0]);
	mostrar_A(A,n);
	cout<<"Ingrese el numero a buscar: \n";
	cin>>x;
	cout<<"Posicion: "<<busquedaBinaria(A,0,n-1,x);
	return 0;
}
