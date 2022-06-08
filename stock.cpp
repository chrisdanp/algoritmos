#include<iostream>
using namespace std;
//variables
string producto[25];
int stock[25];
int ind=0;
string prod;
int cant;
int indice;

//funciones
void insertar();
void modificar();
void eliminar();
void consultar();
void incrementar();
void estadistica();
void listar();
void burbuja();
int buscar(string);

int main(){
	int opcion;
	do{
		cout<<"Que desea hacer\n";
		cout<<"1. Insertar\n";
		cout<<"2. Modificar\n";
		cout<<"3. Eliminar\n";
		cout<<"4. Consultar\n";
		cout<<"5. Incrementar\n";
		cout<<"6. Estadistica\n";
		cout<<"7. Listar\n";
		cout<<"8. Burbuja\n";
		cout<<"9. Salir\n";
		cin>>opcion;
		switch(opcion){
			case 1:
				insertar();
				break;
			case 2:
				modificar();
				break;
			case 3:
				eliminar();
				break;
			case 4:
				consultar();
				break;
			case 5:
				incrementar();
				break;
			case 6:
				estadistica();
				break;
			case 7:
				listar();
				break;
			case 8:
				burbuja();
				break;
			case 9:
				cout<<"Fin del programa\n";
				break;
			default:
				cout<<"Opcion equivocada\n";
		}
	}while(opcion!=9);
	return 0;
}

void insertar(){
	cout<<"Ingrese el producto "<<ind+1<<": ";
	cin>>prod;
	cout<<"Ingrese la cantidad "<<ind+1<<": ";
	cin>>cant;
	indice=buscar(prod);
	if (indice==-1){
		producto[ind]=prod;
		stock[ind]=cant;
		ind++;
	}
	else{
		stock[indice]=stock[indice]+cant;
	}
}

void modificar(){
	cout<<"Cual producto desea modificar: ";
	cin>>prod;
	indice=buscar(prod);
	if (indice!=-1){
		cout<<"Ingrese la nueva cantidad: ";
		cin>>cant;
		stock[indice]=cant;
	}
}

int buscar(string prod){
	for(int i=0;i<ind;i++)
		if (producto[i]==prod)
			return i;
	return -1;
}

void eliminar(){
	cout<<"Cual producto desea eliminar: ";
	cin>>prod;
	indice=buscar(prod);
	if (indice!=-1){	
		for (int i=indice;i<ind-1;i++){
			producto[i]=producto[i+1];
			stock[i]=stock[i+1];
		}
		ind--;
	}
}

void consultar(){
	cout<<"Cual producto desea consultar: ";
	cin>>prod;
	indice=buscar(prod);
	if (indice!=-1)
		cout<<"El stock del producto es: "<<stock[indice]<<endl;
}

void incrementar(){
	cout<<"Cual producto desea incrementar: ";
	cin>>prod;
	indice=buscar(prod);
	if (indice!=-1){
		cout<<"Ingrese la cantidad a incrementar: ";
		cin>>cant;
		stock[indice]=stock[indice]+cant;
	}
}

void estadistica(){
	int s=0;
	for (int i=0;i<ind;i++)
		s=s+stock[i];
	cout<<"La cantidad de productos es: "<<ind<<endl;
	cout<<"La suma de stock es: "<<s<<endl;
}

void listar(){
	cout<<"Producto"<<"\t\t"<<"Stock"<<endl;
	for(int i=0;i<ind;i++)
		cout<<producto[i]<<"\t\t\t"<<stock[i]<<endl;
}

void burbuja(){
	int i, j,auxs;
	string aux;
	for (int i=0;i<ind-1;i++)
		for (int j=0;j<ind-i-1;j++)
			if (producto[j]>producto[j+1]){
				aux=producto[j];
				producto[j]=producto[j+1];
				producto[j+1]=aux;
				auxs=stock[j];
				stock[j]=stock[j+1];
				stock[j+1]=auxs;
			}
	
}
