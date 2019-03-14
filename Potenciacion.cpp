#include <iostream>
using namespace std;

int potenciacion(int x, int n);

int main(){
	
	int x,n;
	cout<<"Ingrese la base\n";
	cin>>x;
	cout<<"Ingrese el exponente\n";
	cin>>n;
	cout<<"Resultado: "<<potenciacion(x,n);
	system("pause");
	return 0;
}

int potenciacion(int x,int n){
	if(n==0){
		return 1;
	}
	else{
		return x*(potenciacion(x,n-1));	 
	}
}

