#include<iostream>
#include<sstream>
#include<math.h>
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
		
		double distancia(Punto p){
			double d;
			d=sqrt((pow((x-p.getX()),2))+(pow((y-p.getY()),2)));
			return d;
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
		
		double distancia(Vehiculo v){
			return d;
		}
		
};

int main(){
	Punto p1(55,55);
	Punto p2(60,60);
	cout<<p1.toString();
	Vehiculo v1("Motomel", p1.getX(), p1.getY());
	Vehiculo v2("Audi", p2.getX(), p2.getY());
	cout<<v1.toString();
	cout<<v2.toString();
	cout<<"Distancia: "<<p2.distancia(p1);
	
	return 0;
	
}
