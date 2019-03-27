#include<iostream>
#include<sstream>
using namespace std;
class Autor{
		private:	
		string nombre,apellido;
		public:
			Autor(string _nombre,string _apellido){
				this->nombre = _nombre;
				this->apellido = _apellido;
			}
			void setNombre(string){
				this->nombre = nombre;
			}
			void setApellido(string){
				this->apellido = apellido;
			}
			string getNombre(string){
				return nombre;
			}
				string getApellido(string){
				return apellido;
			}			
			string toString(){
			stringstream s;
			s<<" Nombre: "<<nombre<<" Apellido: "<<apellido<<endl;
			return s.str();
		}		
};
class Libro{
	private:
		 Autor* autor;
		string titulo;
		double precio;
		int cantidad;
	public:
		Libro(string _titulo,Autor* _autor, double _precio,int _cantidad){
			titulo = _titulo;
			precio = _precio;
			cantidad = _cantidad;
			autor = _autor;
		}
		string getTitulo(string){
			return titulo;
		}	
		 Autor getAutor(){
			return *autor;
		}	
		double getprecio(double){
			return precio;
		}
		int getcantidad(int){
			return cantidad;
		}
		void setPrecio(double precio){
		this ->precio = precio;
		}
		void setCantidad(int cantidad){
		this ->cantidad = cantidad;
		}
		string toString(){
			stringstream s;
			s<<" Titulo: "<<titulo<<" Precio: "<<precio<<" Cantidad: "<<cantidad<<endl;
			s<<autor->toString();
			return s.str();
		}			
		
};
	


int main(){
Autor a1("Daniel","San");
Libro l1("Debug Master",&a1,100,500);
cout<<l1.toString()<<"\n";
	
	
	
	
	return 0;
}
