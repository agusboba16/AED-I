#include <iostream>

using namespace std;


void mostrar_A(int A[],int n){
	cout<<"A: \n";
	for(int i=0;i<n;i++){
		cout<<A[i]<<"\n";
	}
}
int particion(int A[],int principio,int fin){
	int pivot = A[fin];
	int p = principio;
	for(int i = principio; i<fin; i++){
		if(A[i] <= pivot){
			swap(A[i], A[p]);
			p++;
		}
	}
	swap(A[p], A[fin]);
	return p;
}

void quicksort(int A[],int principio,int fin){
	if(principio < fin){
		//mostrar_A(A,fin);
		int p = particion(A,principio,fin);
		quicksort(A,principio,p-1);
		quicksort(A, p+1, fin);
	}
}
	
int main(){
	int A[]={1,5,7,8,3,28,2,4};
	int n = sizeof(A) / sizeof(A[0]);
	
	mostrar_A(A,n);
	quicksort(A,0,n);
	mostrar_A(A,n);	
	return 0;
}


