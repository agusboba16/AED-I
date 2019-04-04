#include <iostream>
using namespace std;

int main(){
cout<<"Ingrese los valores del array. \n";
const int N = 5;
int *pArray;
pArray = new int[N];

for(int i=0; i<N; i++){
cin>>*(pArray+i);
}

for(int i=0; i<N; i++){
cout<<"Posicion "<< i << " : "<<*(pArray+i)<<"\nDireccion de memoria: "<< (pArray+i) <<endl;
}

delete[] pArray;
pArray=NULL;
return 0;
}
