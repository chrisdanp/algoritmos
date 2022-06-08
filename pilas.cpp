//Pilas con Array
#include <iostream>
using namespace std;

const int TAMPILA = 6; 

class Pila{
	private:
		int pCima; //Es el índice del último elemento ingresado en la pila, o sea la cima
		int listaPila[TAMPILA]; //El tamaño de la lista esta definido al inicio
	public:
		Pila(){  //Constructor que crea la pila
			pCima = -1; // Condición de pila vacía
		}
		void insertar(int); //push
		int quitar(); //pop
		bool pilaVacia(); //Comprueba si la pila esta vacía
		bool pilaLlena(); //Comprueba si la pila esta llena
		void limpiarPila(); //Quita todos los elementos de la pila
		int cimaPila(); //Obtiene la cima de la pila
		int getCima(); //Obtiene el valor de pCima, o sea le apuntador
		int tamanoPila(); //Número de elementos  actual de la pila
		void visualizarPila(); //Retira y muestra los elementos de la pila
		void llenarPila(); //Crea una pila
		int datoCimaPila(); //Devuelve el dato que esta en la cima 
};

bool Pila::pilaLlena(){
	return pCima==TAMPILA-1;
}

bool Pila::pilaVacia(){
	return pCima==-1;
}

void Pila::insertar(int dato){
	if (!pilaLlena()){
		pCima++;
		listaPila[pCima]=dato;
	}
	else
		cout<<"Desbordamiento (overflow)";
}

int Pila::quitar(){
	int dato;
	if (!pilaVacia()){
		dato=listaPila[pCima];
		pCima--;
		return dato;
	}
	else {
		cout << "Desbordamiento negativo (undeflow)\n";
		return -1;
	}
}

int Pila::getCima(){
	return pCima;
}

void Pila::visualizarPila(){
	int dato;
	while(!pilaVacia()){
		dato=quitar();
		cout<<dato<<" Cima pila: "<<pCima<<endl;	
	}
}

void Pila::llenarPila(){
	int n,dato;
	cout<<"Cuantos elementos ingresara. Maximo "<<TAMPILA<<": ";
	cin>>n;
	for (int i=0;i<n;i++){
		cout<<"Ingrese dato "<<i<<": ";
		cin>>dato;
		insertar(dato);
		cout<<"pCima: "<<pCima<<endl;
	}
}

int Pila::tamanoPila(){
	return pCima+1;
}

int Pila::datoCimaPila(){
	if (!pilaVacia())
		return listaPila[pCima];
	else{
		cout<<"Pila vacia\n";
		return -1;
	}
	
}

void Pila::limpiarPila(){
	pCima=-1;
}

int main(){
	Pila pila; //Crea una pila vacía
	pila.llenarPila();
	pila.visualizarPila();
	return 0;
}