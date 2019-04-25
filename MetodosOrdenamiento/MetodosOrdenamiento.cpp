#include <iostream>

using namespace std;

void mostrar_array(int array[],int n){
	cout<<"Array: \n";
	for(int i=0;i<n;i++){
		cout<<array[i]<<"\n";
	}
}

void ordenar_burbuja(int array[], int n){
	int p=100;
	while(p>0){
		p=0;
		for(int j=0; j<n-1; j++){
			if(array[j]>array[j+1]){
				swap(array[j],array[j+1]);
				p++;
			}
		}
	}
	mostrar_array(array,n);
}
/*void ordenar_seleccion(int array[], int n){
	for(int i=0; i<n-1; i++){;
		for(int j=i+1; j<n; j++){
			if(array[i]>array[j]){
				int minimo = j;
				swap(array[minimo],array[i]);
			}
		}
	}
	mostrar_array(array,n);
}*/

/*void ordenar_insercion(int array[], int n){
	for(int i=1; i<n; i++){
		int j=i;
		while(j > 0 && array[j]<array[j-1]){
			swap(array[j-1],array[j]);
			j--;
		}
	}
	mostrar_array(array,n);
}*/

int main(){	
	int array[]={6,5,4,2,1,3};
	
	int n = sizeof(array) / sizeof(array[0]);
	
	mostrar_array(array,n);
	//ordenar_seleccion(array,n);
	//ordenar_insercion(array,n);
	ordenar_burbuja(array,n);
	return 0;
}

