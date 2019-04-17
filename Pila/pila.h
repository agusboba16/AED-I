class pila{
	private:
		struct nodo{
			char dato;
			nodo* siguiente;
		};
		nodo* inicio;
	public:
		pila();
		~pila();
		void push(char dato);//agrega el elemento arriba en la pila
		void pop();//remueve el elemento de mas arriba de la pila
		char top();//Devuelve una referencia al elemento de m�s arriba de la pila
		bool empty();//devuelve si la pila est� vacia
		int size();//devuelve el tama�o de la pila
};

