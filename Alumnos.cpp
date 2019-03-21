#include <iostream>
#include <sstream>

using namespace std;

class Alumno{
	private:
	int legajo;
	string apellido;
	int calificaciones[3];
	
	public:
		Alumno( int _legajo, string _apellido){
		legajo = _legajo;
		apellido = _apellido;
		}
		~Alumno(){
		}
		int getLegajo(){
			return legajo;
		}
		
		string getApellido(){
			return apellido;
		}
		
		void setApellido(string apellido){
		this->apellido= apellido;	
		}
		
		void addcalificaciones(){
			int suma = 0;
			for(int i=0; i<3; i++){
				cin>>calificaciones[i];
				suma = suma+calificaciones[i];
			}
			cout<<"asda" << suma;
		}
		
		double getPromedio(){
			
		}
};


int main(){
	Alumno p1(1,"Rancio");
	p1.addcalificaciones();
	
return 0;
}
