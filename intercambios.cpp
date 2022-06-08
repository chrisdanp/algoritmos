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

void imprimir(int vector[],int n){
	for (int i=0;i<n;i++)
		cout<<vector[i]<<endl;
	cout<<endl;
}

void imprimir(string vector[],int n){
	for (int i=0;i<n;i++)
		cout<<vector[i]<<endl;
	cout<<endl;
}

void intercambiar(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void intercambiar(string& x, string& y) {
	string temp = x;
	x = y;
	y = temp;
}

void ordIntercambio(int vector[], int n){
	//int index = 0;
	for(int i = 0;i<n-1;i++){
		for(int j = i+1; j<n;j++){
			if(vector[i] > vector[j]){
				intercambiar(vector[i], vector[j]);
			}
		}
		//index++;
	}
}

void ordIntercambio(string vector[],int n){
    for(int i = 0;i<n-1;i++){
		for(int j = i+1; j<n;j++){
			if(vector[i] > vector[j]){
				intercambiar(vector[i], vector[j]);
			}
		}
	}
}

int main(){
    int n,ind,opc;
    cout<<"Cuantos datos desea ingresar: ";
    cin>>n;
    cout<<"Ingresara enteros (1) o cadenas (2): ";
    cin>>opc;
    if (opc==1){
		int* vector=new int[n];
	    lectura(vector,n);
	    ordIntercambio(vector,n);
	    imprimir(vector,n);
	}
	else{
		string* vector=new string[n];
		cin.ignore();
	    lectura(vector,n);
	    ordIntercambio(vector,n);
	    imprimir(vector,n);
	}
    return 0;
}

//Selection Sort
int minimo(int vector[],int k, int n){
	int min = vector[k];
	int pos = k;
	for(int i = k; i<n; i++){
		if(vector[i]<min){
			min = vector[i];
			pos = i;
		}
	}
	return pos;
}

int minimo(string vector[],int k, int n){
	string min = vector[k];
	int pos = k;
	for(int i = k; i<n; i++){
		if(vector[i]<min){
			min = vector[i];
			pos = i;
		}
	}
	return pos;
}

void ordSeleccion(int vector[], int n){
	for(int i = 0; i<n-1;i++){
		if(vector[i] > vector[minimo(vector, i, n)]){
			intercambiar(vector[i],vector[minimo(vector, i, n)]);
		}
	}
}

void ordSeleccion(string vector[], int n){
	for(int i = 0; i<n-1;i++){
		if(vector[i] > vector[minimo(vector, i, n)]){
			intercambiar(vector[i],vector[minimo(vector, i, n)]);
		}
	}
}

//Insertion Sort
void ordInsercion(int vector[], int n){
	int comp;
	for(int i = 0; i<n-1;i++){
		comp=vector[i+1];
		for(int j = i; j>=0;j--){
			if (vector[j] > comp)
				intercambiar(vector[j],vector[j+1]);
			else
				break;
		}
	}
}

void ordInsercion(string vector[], int n){
	string comp;
	for(int i = 0; i<n-1;i++){
		comp=vector[i+1];
		for(int j = i; j>=0;j--){
			if (vector[j] > comp)
				intercambiar(vector[j],vector[j+1]);
			else
				break;
		}
	}
}

///Burbuja
void ordBurbuja(int vector[], int n){
	bool flag=true;	
	for(int i = 0; i<n-1;i++){
		flag=false;
		for (int j=0 ;j<n-1-i; j++)
			if (vector[j]>vector[j+1]){
				intercambiar(vector[j],vector[j+1]);
				flag=true;
			}
		if (!flag)
			return;
	}	
}

void ordBurbuja(string vector[], int n){
	bool flag=true;	
	for(int i = 0; i<n-1;i++){
		flag=false;
		for (int j=0 ;j<n-1-i; j++)
			if (vector[j]>vector[j+1]){
				intercambiar(vector[j],vector[j+1]);
				flag=true;
			}
		if (!flag)
			return;
	}	
}
