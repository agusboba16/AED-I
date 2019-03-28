#include<iostream>
#include<sstream>
using namespace std;

class Punto{
	private:
		int x;
		int y;
	
	public:	
		Punto(int _x, int _y){
			this->x = _x;
			this->y = _y;
		}
		int setX(int){
			this->x = x;
		}
		int setY(int){
			this->y = y;
		}
		string toString(){
			stringstream s;
			s<<"Punto x: "<< x <<", y: "<< y <<"\n";
			return s.str();
		}
		~Punto(){
			
		}
		int getX(){
		return x;
		}
		int getY(){
			return y;
		}
};

class Vehiculo{
	private:
		string nombre;
		Punto posicion;
		
	public:
		
		Vehiculo(string _nombre):posicion(0,0){
			this->nombre = _nombre;
					
		}
		Vehiculo(string _nombre, int _x, int _y):posicion(_x,_y){
			this->nombre=_nombre;
	
		}

		int moverA(int x, int y){
			return x, y;
		}		
		
		string toString(){
			stringstream s;
			s<<"Marca: "<<nombre<<", Posicion: "<<posicion.toString()<<"\n";
			return s.str();
		}
};

int main(){
	Punto p1(55,55);
	cout<<p1.toString();
	Vehiculo v1("Motomel", p1.getX(), p1.getY());
	cout<<v1.toString();
	return 0;
	
}
