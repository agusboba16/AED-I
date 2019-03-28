#include<iostream>
#include<sstream>
using namespace std;

class Persona{
	private:
		string nombre;
		string apellido;	
		int edad;
	public:
		Persona(){
			cout<<"Aca estamos en el constructor sin parametros"<<endl;
		
			edad = 18;
		} //constructor
		Persona(string _nombre, string _apellido){
			nombre = _nombre;
			apellido = _apellido;
		}
		Persona(string _apellido, int edad){
			nombre = "nn";	
			apellido = _apellido;
			this->edad = edad;
		}
		~Persona(){
			//cout<<"Este es el destructor"<<endl;
		}
		int getEdad(){
			return edad;
		}
		void setEdad(int edad){
			if (edad>17 && edad<101){
			this->edad = edad;
			}
			else{
				throw 14;
			}
			
		}
		string toString(){
			stringstream s;
			s<< " Hola, mi nombre es " <<nombre<< " "<< apellido<< " y mi edad es: "<< edad<<endl;
			return s.str();		
		}
		/*void Saludar(){
			cout<< " Hola, mi nombre es " <<nombre<< " "<< apellido<<endl;
		}*/
		};
int main(){
	
try{
	Persona p1;
	Persona p2 = Persona();
	Persona p3("Pedro", "Garcia");
	Persona p4("Juarez", 20);
	//if (p1.setEdad(550) == -1){
	//	cout<<"La edad debe estar entre 18 y 100 "<<endl;haciendo return -1 cambiando void por int en funcion setEdad
	//}
	//p1.Saludar();
	//p2.Saludar();
	//p3.Saludar();
	//p4.Saludar();
	//p1.nombre = "Juan";
	cout<<p3.toString()<<endl;
	cout<<p4.toString()<<endl;
	cout<<p1.toString()<<endl;
}
catch(int nError){
	if (nError == 14){
		cout<<"La edad debe estar entre 18 y 100 "<<endl;
	}
	
}
return 0;
}
