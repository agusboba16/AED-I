#include <iostream>

using namespace std;

void ordenamiento(int a[], int n){
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
            }
        }
    }
}

float mediana(int a[], int n){
    float mediana = 0;
    int mitad = 0; //Se usa solo para los indices del array.
    
    if(n%2!=0){
        return n/2;
    }
    if(n%2==0){
        mitad = (n/2); //=7.
        return (a[mitad-1]+a[mitad])/2.0;
    }
}

int main(){
	int n1 = 0;
	int a1[] = {4,5,4,1,9,7,3,6,7,10,4,11,2,21};
	n1 = sizeof(a1)/sizeof(int);
	
	ordenamiento(a1, n1);
	
	cout << "a1: ";
    for(int i=0; i<n1; i++){ //Muestra array ordenado
        cout << a1[i] << " ";
    }
	// Calcular y mostrar la mediana de a1
	cout << "\nLa mediana de a1 es: " << mediana(a1, n1) << endl;
	
	
	cout << endl;
	
	int n2 = 0;
	int a2[] = {3,8,4,20,9,1,2,8,7};
	n2 = sizeof(a2)/sizeof(int);
	
	ordenamiento(a2, n2);
	cout << "a2: ";
    for(int i=0; i<n2; i++){ //Muestra array ordenado
        cout << a2[i] << " ";
    }
	
	// Calcular y mostrar la mediana de a2
	int indice2 = mediana(a2, n2);
	cout << "\nLa mediana de a2 es: " << a2[indice2] << endl;
	
	cin.get();
	return 0;
}
