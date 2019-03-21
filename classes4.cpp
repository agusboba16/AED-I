#include <iostream>
#include <sstream>
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
  	this->nombre = "nn";
 	this->edad = _edad;
 	this->apellido = apellido;
 }
 
 //destructor
 ~Persona(){
 	cout<<"este es el destructor\n";
 }
 
 string toString(){
 	stringstream s;
 	s << "Hola, mi nombre es " << nombre << " " << apellido <<"\n";
 	return s.str();//metodo que convierte a string
 }
 
 /*void saludar(){
 	cout<<"Hola, mi nombre es " << nombre << " " << apellido <<"\n";
 }
};*/


int main(){	

Persona p1;
Persona p2;//objetos
Persona p3("Pedro","Garcia");
Persona p4("Juarez", "20");
/*p1.saludar();
p2.saludar();
p3.saludar();
p4.saludar();
/*cout<<"Ingrese el nombre\n";
cin >> p1.nombre;
cout<<"Ingrese la edad\n";
cin >> p1.edad;*/
cout << p3.toString()<<"\n";
cout << p4.toString()<<"\n";

	return 0;
}


