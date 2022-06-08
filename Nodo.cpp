//Clase Nodo
#include<iostream>
using namespace std;
class Nodo{
	private:
		int dato;      // Dato del nodo
		Nodo *enlace; // Direccion a otro Nodo,
	public:
		Nodo(int d){
			dato=d; //Asigna el dato=d a este Nodo
			enlace=NULL; //Este nodo apunta a NULL
		}
		Nodo(int d,Nodo *n){
			dato=d;
			enlace=n;
		}
		int getDato(){  //Devuelve el dato
			return dato;
		}
		int setDato(int nuevoDato) {//Fija un nuevo dato
			dato=nuevoDato;
		}
		Nodo *getEnlace(){  //Devuelve la direcci�n a donde apunta
			return enlace;
		}
		void setEnlace(Nodo *sgte){  //Fija un nuevo enlace
			enlace=sgte;
		}
};
