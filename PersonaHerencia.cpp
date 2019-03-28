#include <iostream>
#include <sstream>
using namespace std;

class Persona{
	protected:
		string nombre;
		string apellido;
		int edad;
	public:
	//	Persona(string, string, int);
		Persona(string nombre, string apellido, int edad){
			this->nombre=nombre;
			this->apellido=apellido;
			this->edad=edad;
		}
		virtual string toString(){
			stringstream s;
			s<<"Nombre: "<<nombre<<", Apellido: "<<apellido<<", Edad: "<<edad;
			return s.str();
		}	
		
};

class Alumno: public Persona{
	private:
		int legajo;
		double promedio;
	public:
		//Alumno(string,string,int,int,double);
		Alumno(string nombre, string apellido, int edad, int legajo, double promedio):Persona(nombre,apellido,edad){
			this->legajo= legajo;
			this->promedio = promedio;
		}
		
		//virtual string toString();
		
		virtual string toString(){
			stringstream s;
			s<<"Soy alumno.\n";
			s<<Persona::toString()<<"\n";
			s<<"Legajo: "<<legajo<<", Promedio: "<<promedio;
			//"Nombre: "<<nombre<<", Apellido: "<<apellido<<", Edad: "<<edad<<
			return s.str();
		}
};

class Profesor: public Persona{
	private:
		int legajo;
		string materia;
	public:
		//Profesor(string,string,int,int,string);
		Profesor(string nombre, string apellido, int edad, int legajo, string materia):Persona(nombre,apellido,edad){
			this->legajo= legajo;
			this->materia = materia;
		}
		//virtual string toString();
		
		virtual string toString(){
			stringstream s;
			s<<"Nombre: "<<nombre<<", Apellido: "<<apellido<<", Edad: "<<edad<<", Legajo: "<<legajo<<", Materia: "<<materia;
			return s.str();
		}
};

int main(){
	Alumno p1("Waldo","Geremia",69,2019,3.99);
	cout<<p1.toString(); 
	return 0;
}

