//Ordenamiento burbuja mejorado
#include <iostream>
#include <string>
using namespace std;

void lectura(int vector[],int n){
    for (int i=0;i<n;i++){
        cout<<"Ingrese un dato ("<<i<<"): ";
        cin>>vector[i];
    }
}

void imprimir(int vector[],int n){
	for (int i=0;i<n;i++)
		cout<<vector[i]<<" ";
	cout<<endl;
}

void intercambiar(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}
///Burbuja
void ordBurbuja(int vector[], int n){
	bool cambio;	
	for(int i = 0; i<n-1;i++){
		cambio=false; // Asume que esta ordenado
		for (int j=0 ;j<n-1-i; j++)
			if (vector[j]>vector[j+1]){
				intercambiar(vector[j],vector[j+1]);
				cambio=true;
			}
		if (!cambio)
			return;
	}
}

int main(){
    int n;
    cout<<"Cuantos datos desea ingresar: ";
    cin>>n;
	int* vector=new int[n];
    lectura(vector,n);
    ordBurbuja(vector,n);
    imprimir(vector,n);
	return 0;
}
//////////////////////////////////////////////////////
//Ordenamiento burbuja Bidireccional
///Burbuja Bidireccional
void ordBurbuja(int vector[], int n){
	bool cambio;	
	int inicio=0;
	int final=n-1;
	while(inicio<final){
		cambio=false; // Asume que esta ordenado
		//Bucle de izquierda a derecha aplicando Burbuja
		for (int j=inicio ;j<final; j++)
			if (vector[j]>vector[j+1]){
				intercambiar(vector[j],vector[j+1]);
				cambio=true;
			}
		if (!cambio) //Sin cambio entonces termina
			return;
		//Bucle de derecha a izquierda aplicando Burbuja
		for (int j=final-1 ;j>inicio; j--)
			if (vector[j-1]>vector[j]){
				intercambiar(vector[j-1],vector[j]);
				cambio=true;
			}
		if (!cambio) //Sin cambio entonces termina
			return;
		final--;
		inicio++;
	}	
}
