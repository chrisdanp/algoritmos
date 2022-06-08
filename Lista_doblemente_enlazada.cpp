//Lista doblemente enlazada
#include<iostream>
using namespace std;
//Clase Nodo Doble
class NodoDoble {
    private:
        int dato;
        NodoDoble* adelante; //A la derecha 
        NodoDoble* atras; //A la izquierda
    public:
        NodoDoble(int d){
            dato = d;
            adelante = atras = NULL;
        }
        int getDato() { return dato; }
        void setDato(int a) { dato = a; }
        NodoDoble* getAdelante() { return adelante; }
        void setAdelante(NodoDoble* a) { adelante = a; }
        NodoDoble* getAtras() { return atras; }
        void setAtras(NodoDoble* a) { atras = a; }
};
//Clase Lista Doble
    class ListaDoble{
    private:
        NodoDoble* cabeza;
        NodoDoble* cola;
    public:
        ListaDoble(){ //Constructor
            cabeza = cola = NULL;
        }
        void crearLista();
        void visualizarLista();
        void insertarCabeza(int);
        void insertarDespues(int, int);
        void eliminar(int);
        //Continua las demás funciones
        NodoDoble *buscaNodoDoble(int);
        void insertarFinalLista(int);
        void insertarAntes(int, int);
        void modificarDato(int,int);
        //Ejercicio
        void invertir();
        void ordenar();
};

//Implementa la lista doble
void ListaDoble::crearLista(){
	int x;
	cout << "Termina con -1" << endl;
	do{
		cin >> x;
		if (x != -1){
			insertarCabeza(x);
		}
	}while(x != -1);
};

void ListaDoble::insertarCabeza(int dato){
	NodoDoble *nuevo = new NodoDoble(dato);
	if(cabeza != NULL){
		cabeza->setAtras(nuevo);
		nuevo->setAdelante(cabeza);
		cabeza = nuevo;	
	}
	else
		cabeza = cola = nuevo;	
}

void ListaDoble::visualizarLista(){
	//Direccion atras - Direccion del dato - Dato - Direccion adelante
	NodoDoble *indice;
	for (indice = cabeza; indice != NULL; indice = indice->getAdelante())
		cout << indice->getAtras() << "\t" << indice << "\t" << indice->getDato() << "\t" << indice->getAdelante() << endl;
	cout << "-------------------------\n";
}

NodoDoble *ListaDoble::buscaNodoDoble(int dato){
	NodoDoble *indice;
	for (indice = cabeza; indice != NULL; indice = indice->getAdelante())
		if (indice->getDato() == dato)
			return indice;
	return NULL;
}

void ListaDoble::insertarDespues(int datoAnt,int dato){
	NodoDoble *nuevo = new NodoDoble(dato);
	NodoDoble *anterior = buscaNodoDoble(datoAnt);
	if (anterior == NULL)
		return;
	if (anterior->getAdelante() != NULL){
		nuevo->setAdelante(anterior->getAdelante());
		anterior->getAdelante()->setAtras(nuevo);
		anterior->setAdelante(nuevo);
		nuevo->setAtras(anterior);
	}
	else{ //Caso en que el anterior es la cola
		nuevo->setAtras(anterior);
		anterior->setAdelante(nuevo);
		cola = nuevo;
	}	
}

void ListaDoble::eliminar(int dato){
	NodoDoble *indice = buscaNodoDoble(dato);
	if (indice!=NULL){
		if (indice == cabeza){
			cabeza = indice->getAdelante();
			cabeza->setAtras(NULL);
		}
		else if (indice == cola){
			cola = indice->getAtras();
			cola->setAdelante(NULL);
		}
		else{
			indice->getAtras()->setAdelante(indice->getAdelante());
			indice->getAdelante()->setAtras(indice->getAtras());
		}		
	}
	delete indice;
}

void ListaDoble::insertarFinalLista(int dato){
	NodoDoble *nuevo = new NodoDoble(dato);
	if(cabeza != NULL){
		cola->setAdelante(nuevo);
		nuevo->setAtras(cola);
		cola = nuevo;
	}
	else
		cabeza = cola = nuevo;
}

void ListaDoble::insertarAntes(int datoPos,int dato){
	NodoDoble* nuevo = new NodoDoble(dato);
	NodoDoble* posterior = buscaNodoDoble(datoPos);
	if (posterior == NULL)
		return;
	if (posterior->getAtras() != NULL){
		nuevo->setAdelante(posterior);
		nuevo->setAtras(posterior->getAtras());
		posterior->getAtras()->setAdelante(nuevo);
		posterior->setAtras(nuevo);
	}
	else{
		nuevo->setAdelante(posterior);
		posterior->setAtras(nuevo);
		cabeza = nuevo;
	}
}

void ListaDoble::modificarDato(int datoAntiguo,int datoNuevo){
	NodoDoble *antiguo = buscaNodoDoble(datoAntiguo);
	if(antiguo == NULL){
		return;
	}
	antiguo->setDato(datoNuevo);

}

void ListaDoble::invertir(){
	/*int aux;
	NodoDoble* primero = cabeza;
	NodoDoble* ultimo = cola;
	while (primero != ultimo && primero->getAtras() != ultimo) {
		aux = primero->getDato();
		primero->setDato(ultimo->getDato());
		ultimo->setDato(aux);
		primero = primero->getAdelante();
		ultimo = ultimo->getAtras();
	}*/

	/*NodoDoble *indice=cabeza,*indice1=cola;
	int aux;
	if(cabeza==NULL) return;
	
	while(indice>indice1)
	{
		aux=indice->getDato();
		indice->setDato(indice1->getDato());
		indice1->setDato(aux);
		indice=indice->getAdelante();
		indice1=indice1->getAtras();
	}*/
}

void ListaDoble::ordenar(){
	int aux;
	NodoDoble* inicio = cabeza;
	NodoDoble* indice;
	NodoDoble* fin = cola;
	while (inicio != fin) {
		for (indice = inicio; indice != fin; indice = indice->getAdelante()) {
			if (indice->getDato() > indice->getAdelante()->getDato()) {
				aux = indice->getDato();
				indice->setDato(indice->getAdelante()->getDato());
				indice->getAdelante()->setDato(aux);
			}
		}
		fin = fin->getAtras();
	}

	/*int menor,aux;
	NodoDoble *indice,*indice2;
	for(indice=cabeza;indice!=NULL;indice=indice->getAdelante())
	{
		menor=indice->getDato();
		for(indice2=indice;indice2!=NULL;indice2=indice2->getAdelante())
		{
			if(indice2->getDato()<menor)
			{
				menor=indice2->getDato();
				aux=indice->getDato();
		        indice->setDato(indice2->getDato());
		        indice2->setDato(aux);
			}
		}
	}*/
}

int main(){
	ListaDoble miLista;
	miLista.crearLista();
	miLista.visualizarLista();
	//miLista.ordenar();
	//miLista.visualizarLista();
	return 0;	
}