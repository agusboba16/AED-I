#include <iostream>
using namespace std;

void cambiar(int*a,int*b);

int main(){

int a,b;
cout<<"Ingrese el valor de a: ";
cin>>a;
cout<<"Ingrese el valor de b";
cin>>b;
cout<<"a = "<< a << " b = " << b << endl;
int *puntA=&a;
int *puntB=&b;
cambiar(&a,&b);
cout<<"a = " << a << "b = "<< b;
return 0;
}

void cambiar(int*a,int*b){
	int aux=*a;
	*a=*b;
	*b=aux;
}
