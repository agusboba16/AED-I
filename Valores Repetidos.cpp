#include <iostream>

using namespace std;

int main(){
	
	int i,j;
	int array[10];
	
	cout<<"Ingrese los elementos del array\n";
	for(i=0;i<10;i++){
		cin>>array[i];
	}
	for(int i=0;i<10;i++){
		for(j=i+1;j<10;j++){
			if(array[i]==array[j]){
				cout<< " Valor: "<<  array[i] << " repetido en posicion "<<i+1<< " y " << j+1<<endl;
			}
		}
	}
	
	
	return 0;
}
