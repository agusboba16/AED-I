#include <iostream>
using namespace std;

int main(){
int numero = 45;
int* pNumero = &numero;
cout<< pNumero << endl;
cout<< *pNumero << endl;
*pNumero = 90;
cout<< *pNumero << endl;
cout<< numero << endl;

return 0;
}
