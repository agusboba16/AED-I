#include <iostream>

using namespace std;


void mostrar_A(int A[],int n){
	cout<<"A: \n";
	for(int i=0;i<n;i++){
		cout<<A[i]<<"\n";
	}
}

void merge(int A[],int I[],int D[],int n,int nI,int nD){
	int i=0,j=0,k=0;
	while(i<nI && j<nD){
		cout<<"asdas";
		if(I[i]<D[j]){
			A[k] = I[i];
			k++;
			i++;
		}
		else{
		A[k] = D[j];
			k++;
			j++;	
		}
	}
	while(i<nI){
		A[k] = I[i];
		k++;
		i++;
	}
	while(j<nD){
			A[k] = D[j];
			k++;
			j++;
	}
	
}

void mergesort(int A[],int n){
	if(n<2){
		return;
	}
	int mitad = n/2;
	int *I= new int [mitad];
	int *D= new int [n-mitad];
	
	for(int i=0;i<mitad;i++){
		I[i] = A[i];
	}
	for(int i=mitad; i<n; i++){
		D[i-mitad] = A[i];
	}
	mostrar_A(I,mitad);
	cout<<"\n";
	mostrar_A(D,n-mitad);
	cout<<"\n";
	mergesort(I,mitad);
	mergesort(D,n-mitad);
	merge(A,I,D,n,mitad,n-mitad);
}

int main(){
	int A[]={1,5,7,8,3,28,2,4};
	int n = sizeof(A) / sizeof(A[0]);
	mostrar_A(A,n);
	mergesort(A,n);
	mostrar_A(A,n);	
	return 0;
}


