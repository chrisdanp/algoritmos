#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Nodo{
    private:
        int dato;
        Nodo *enlace;
    public:
		Nodo(int d){
			dato=d;
			enlace=NULL;
		}
		Nodo(int d,Nodo *n){
			dato=d;
			enlace=n;
		}
		int getDato(){ return dato; }
		int setDato(int nuevoDato){ dato=nuevoDato; }
		Nodo *getEnlace(){ return enlace; }
		void setEnlace(Nodo *sgte){ enlace=sgte; }
};

class Producto:public Nodo{
    private:
        int day;
        int month;
        int year;
    public:
        Producto (int _dato, int _day, int _month, int _year) : Nodo(_dato){
            day = _day;
            month = _month;
            year = _year;
        }
        int getDay(){return day;}
        void setDay(int d){ day = d;}
        int getMonth(){return month;}
        void setMonth(int m){ month = m;}
        int getYear(){return year;}
        void setYear(int y){ year = y;}
};

class ListaProducto{
	private:
	    Producto *first;
	public:
	    ListaProducto(){
            first = NULL;
        }
        void crearLista();
        void visualizarLista();
        void insertar(int,int,int,int);
        void ordenarLista();
};

void ListaProducto::crearLista(){
    first = NULL; //Resetear lista
    int dato, day, month, year;
    for(int i = 0; i < 300; i++){
        dato = 10 + rand()%191;
        year = 2015 + rand()%6;
        month = 1 + rand()%3;
        if(month == 2) {
            if(year == 2016 || year == 2020) day = 1 + rand()%29;
            else day = 1 + rand()%28;
        }
        else{
            day = 1 + rand()%31;
        }
        insertar(dato, day, month, year);
    }
    cout << "\nLista creada aleatoriamente\n\n";
}

void ListaProducto::insertar(int dato, int day, int month, int year){
    Producto *nuevo = new Producto(dato, day, month, year);
    Producto *indice = first;
    if (first == NULL){
        first = nuevo;
        return;
    }
    while(indice->getEnlace() != NULL){
        indice = (Producto*)indice->getEnlace();
    }
    indice->setEnlace(nuevo);
}

void ListaProducto::visualizarLista(){
    Producto *ind = first;
    cout << "\nDireccion del Producto\tPeso\tDay\tMonth\tYear\tDireccion a donde apunta\n";
    while(ind != NULL){
        cout<< ind << "\t\t" << ind->getDato() << "\t" << ind->getDay() << "\t" << ind->getMonth() << "\t" << ind->getYear() << "\t" << ind->getEnlace() << "\n";
        ind = (Producto*)ind->getEnlace();
    }
}

void ListaProducto::ordenarLista(){
    int fecha1, fecha2;
    for(Producto *ind1 = first; (Producto*)ind1->getEnlace() != NULL; ind1 = (Producto*)ind1->getEnlace()){
        for(Producto *ind2 = (Producto*)ind1->getEnlace(); ind2 != NULL; ind2 = (Producto*)ind2->getEnlace()){
            fecha1 = (ind1->getYear())*10000 + (ind1->getMonth())*100 + (ind1->getDay());
            fecha2 = (ind2->getYear())*10000 + (ind2->getMonth())*100 + (ind2->getDay());
            if(fecha1 > fecha2){
                int _dato, _day, _month, _year;
                _dato = ind1->getDato(); _day = ind1->getDay(); _month = ind1->getMonth(); _year = ind1->getYear();
                ind1->setDato(ind2->getDato()); ind1->setDay(ind2->getDay()); ind1->setMonth(ind2->getMonth()); ind1->setYear(ind2->getYear());
                ind2->setDato(_dato); ind2->setDay(_day); ind2->setMonth(_month); ind2->setYear(_year);

            }
        }
    }
    visualizarLista();
}

void menu(){
    int opcion;
    ListaProducto miLista;
    do{
        cout << "1. Crear lista\n";
        cout << "2. Visualizar lista\n";
        cout << "3. Ordenar lista\n";
        cout << "4. Salir\n";
        cout << "Elija su opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1: miLista.crearLista();
                    break;
            case 2: miLista.visualizarLista();
                    break;
            case 3: miLista.ordenarLista();
                    break;
            case 4: cout << "Fin del programa\n";
                    break;
            default: cout << "Opcion equivocada\n";
        }
    }while(opcion != 4);
}


int main(){
    srand(time(NULL));
    menu();
    return 0;
}
