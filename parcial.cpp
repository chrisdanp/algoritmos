
#include <ctime>
#include <cstdlib>
#include <string>
int n;
//La clase producto
class Producto:public Nodo{
    private:
        int day;
        int month;
        int year;
    public:
        Producto(int dato,int d,int m,int y):Nodo(dato)
        {
            day=d;
            month=m;
            year=y;
        }
        Producto(int dato,Producto* n,int d,int m,int y):Nodo(dato,n)
        {
            day=d;
            month=m;
            year=y;
        }
        int getDay(){return day;}
        void setDay(int nuevoDay){day=nuevoDay;}
        int getMonth(){return month;}
        void setMonth(int nuevoMonth){month=nuevoMonth;}
        int getYear(){return year;}
        void setYear(int nuevoYear){year=nuevoYear;}
};
//La clase ListaProducto
//La clase Lista
class ListaProducto
{
    private:
        Producto* first;
    public:
        ListaProducto() //Constructor
        {
        first = NULL;
        }
        void crearLista();
        void visualizarLista();
        void ordenarLista();
        int convertirFechaInt(int,int,int);
        //Continua las demás funciones
        void insertarCabeza(int); 
        Nodo* ultimoNodo(); 
        void insertarUltimo(int);
        Nodo* buscarLista(int);
        void insertarDespues(int,int);
        void eliminar(int);
        void insertaOrden(int);
};
//Crear una listaProducto
void ListaProducto::crearLista()
{
    int i,p,d,m,a;
    srand(time(NULL));
    for(i=1;i<=n;i++){
        //Generando el peso
        p=rand()%11+10;
        //Generando año
        a=rand()%6+2015;
        //Generando mes
        m=rand()%3+1;
        //Generando dia
        if (m==2){
            if (a%4==0)
                d=rand()%29+1;
            else
            d=rand()%28+1;
        }
        else
            d=rand()%31+1;
        first = new Producto(p,first,d,m,a);
    }
};
//Visualizar listaProducto
void ListaProducto::visualizarLista()
{
    Producto* indice;
    int c=1;
    cout<<"\tDir Prod\tPeso\tDay\tMonth\tYear\tAdonde apunta"<<endl;
    for(indice = first; indice !=  NULL;indice = (Producto*)indice->getEnlace())
    cout<<c++<<"\t"<<indice<<"\t"<<indice->getDato()<<"\t"<<indice->getDay()<<"\t"<<indice->getMonth()<<"\t"<<indice->getYear()<<"\t"<<indice->getEnlace()<<endl;
}
//Convertir fecha a entero
int ListaProducto::convertirFechaInt(int d,int m,int a)
{
    string fechaC,dc,mc,ac;
    dc=to_string(d);
    mc=to_string(m);
    ac=to_string(a);
    if (dc.length()==1)
        dc="0"+dc;
    if (mc.length()==1)
        mc="0"+mc;
    fechaC=ac+mc+dc;
    return stoi(fechaC);
}
//Visualizar listaProducto
void ListaProducto::ordenarLista()
{
    Producto *indicej,*indicejmas1;
    int i,j,fechaj,fechajmas1;
    int pesoAux,dayAux,monthAux,yearAux;
    for (i=0;i<n-1;i++){
        indicej=first;
        for (j=0;j<n-1-i;j++){
            fechaj=convertirFechaInt(indicej->getDay(),indicej->getMonth(),indicej->getYear());
            indicejmas1=(Producto*)indicej->getEnlace();
            fechajmas1=convertirFechaInt(indicejmas1->getDay(),indicejmas1->getMonth(),indicejmas1->getYear());
            if (fechaj>fechajmas1){
                //aux=A[j];
                pesoAux=indicej->getDato();
                dayAux=indicej->getDay();
                monthAux=indicej->getMonth();
                yearAux=indicej->getYear();
                //A[j]=A[j+1];
                indicej->setDato(indicejmas1->getDato());
                indicej->setDay(indicejmas1->getDay());
                indicej->setMonth(indicejmas1->getMonth());
                indicej->setYear(indicejmas1->getYear());
                //A[j+1]=aux;
                indicejmas1->setDato(pesoAux);
                indicejmas1->setDay(dayAux);
                indicejmas1->setMonth(monthAux);
                indicejmas1->setYear(yearAux);
            }
            indicej=(Producto*)indicej->getEnlace();
        }
    }
}


int main()
{
    int opc;
    ListaProducto miLista;
    while(true)
    {
        cout<<"1. Crear Lista\n";
        cout<<"2. Visualizar Lista\n";
        cout<<"3. Ordenar Lista\n";
        cout<<"4. Salir\n";
        cout<<"Seleccione una opcion: ";
        cin>>opc;
        if (opc==4)
            break;
        else if (opc==1)
        {
            cout<<"Ingrese la cantidad de fechas: ";
            cin>>n;
            miLista.crearLista();
        }
        else if (opc==2)
            miLista.visualizarLista();
        else if (opc==3)
            miLista.ordenarLista();
        else
            cout<<"Opcion no existe\n";
    }
}