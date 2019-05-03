
bool Lista::estaOrdenada(){
    bool resultado = true;
    
    nodo * nodoActual = inicio;
    nodo * nodoSiguiente = nodoActual -> siguiente;
    
    while(nodoSiguiente != NULL){
        if(nodoActual -> dato > nodoSiguiente -> dato){
            resultado = false;
        }
        
        nodoActual = nodoActual -> siguiente;
        nodoSiguiente = nodoActual -> siguiente;
    }
    
    return resultado;
}

void ordenamiento(int a[], int n  ){
    
    for(int i=0; i<n; i++){
       int    min=i;
        for(int j=i+1; j<5; j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
       int  aux=a[i];
        a[i] =a[min];
         a[min]=aux;
    }
}
	
//	int n2 = 0;
//	int a2[] = {3,8,4,20,9,1,2,8,7};
//	n2 = sizeof(a2)/sizeof(int);
	
	ordenamiento(a2, n2);


void Lista::mostrar(){ 
    nodo* nodoActual = inicio;
    cout << "\n\nNULL";
    while(nodoActual != NULL){
        cout << " <--- [" << nodoActual -> dato << "]";
        nodoActual = nodoActual -> siguiente;
    }
}
