#include <iostream>
#include <string>
//"<nombre_funcion>+[<tipo1>,<tipo2>...]"   <<<<<< signature
using namespace std;

class Persona{

private: //atributos privados
	string nombre;
	string apellido;
	int edad;

public: //atributos publicos
 Persona(){
 	edad=18;
	cout<<"Aca estamos en el constructor sin parametros\n";	
 }
//constructor 
 Persona(string _nombre, string _apellido){
 	nombre = _nombre;
 	apellido = _apellido;
 }
 
  Persona(int _edad, string _apellido){
  	nombre = "nn";
 	this->edad = _edad;
 	this->apellido = _apellido;
 }
 
 //destructor
 ~Persona(){
 	cout<<"este es el destructor\n";
 }
 
 void saludar(){
 	cout<<"Hola, mi nombre es " << nombre << " " << apellido <<"\n";
 }
};


int main(){	

Persona p1;
Persona p2;//objetos
Persona p3("Pedro","Garcia");
Persona p4("Juarez", "20");
p1.saludar();
p2.saludar();
p3.saludar();
p4.saludar();
/*cout<<"Ingrese el nombre\n";
cin >> p1.nombre;
cout<<"Ingrese la edad\n";
cin >> p1.edad;*/


	return 0;
}


