#include <iostream>
#include <string>
using namespace std;

void lectura(int vector[],int n){
    for (int i=0;i<n;i++){
        cout<<"Ingrese un dato ("<<i<<"): ";
        cin>>vector[i];
    }
}

void lectura(string vector[],int n){
    for (int i=0;i<n;i++){
        cout<<"Ingrese un dato ("<<i<<"): ";
        getline(cin,vector[i]);
    }
}

int busquedaLineal(int vector[],int n,int clave){
    for (int i=0;i<n;i++)
        if (vector[i]==clave)
            return i;
    return -1;
}

int busquedaLineal(string vector[],int n,string clave){
    for (int i=0;i<n;i++)
        if (vector[i]==clave)
            return i;
    return -1;
}

int main(){
    int n,ind,opc;
    cout<<"Cuantos datos desea ingresar: ";
    cin>>n;
    cout<<"Ingresara enteros (1) o cadenas (2): ";
    cin>>opc;
    if (opc==1){
	    int clave;
		int* vector=new int[n];
	    lectura(vector,n);
	    cout<<"Que desea buscar: ";
	    cin>>clave;
	    ind=busquedaLineal(vector,n,clave);
	}
	else{
		string clave;
		string* vector=new string[n];
		cin.ignore();
	    lectura(vector,n);
	    cout<<"Que desea buscar: ";
	    getline(cin,clave);
	    ind=busquedaLineal(vector,n,clave);
	}
	if (ind!=-1)
	    cout<<"La clave se encuentra en el indice: "<<ind<<endl;
	else
	    cout<<"La clave no se encontro"<<endl;
    return 0;
}
