#include <iostream>
#include <sstream>

using namespace std;

class Cuenta{
	private:
		int numero_cuenta;
		double balance;
	
	public:
		//constru
		Cuenta(int _numero_cuenta, double _balance){
			numero_cuenta = _numero_cuenta;
			balance = _balance;
		}
		
		~Cuenta(){
			cout<<"\nDestructor";
		}
		
int getNumero_cuenta(){
	return numero_cuenta;
 }
double getBalance(){
	return balance;
 }

void setBalance(double balance){
if(balance >= 0){
	this->balance = balance;
}
	else{
		throw 0;
	}
}
	
double Credito(double monto){
	this->balance = this-> balance+monto;
	return balance;
}

double Debito(double monto){
	
	if(monto>balance){
		cout<<"No puede retirar dinero.\n";
	}
	else{
		this->balance = this->balance-monto;
		cout<<"Su balance es: "<<balance;
		return balance;
	}
}

string toString(){//representacion de los campos del objeto
	stringstream s;
	s << "Numero de cuenta: " << numero_cuenta << "\n Balance: "<<balance<<"\n";
	return s.str();
 }

};//fin class

int main(){
	try{
		cout << "Bienvenido\n";
		Cuenta p1(555, 1500);
		p1.setBalance(550);
		cout << p1.toString();
		p1.Credito(50);
		p1.Debito(25);
		
	}
	
	catch(int nError){
	if(nError == 0){
		cout<<"w/e.\n";
	}
}
	
	
	
	return 0;
}
