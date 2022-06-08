#include <iostream>
#include <cmath>
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

void ordRadix(int vector[], int n){
	int i,max,digMax=0,p=0,dig,j,k;
	int c[10]{}; //Vector que cuenta las columnas en la matriz
	int** matriz=new int*[10]; //Crea la matriz
	for(i=0;i<10;i++)
		matriz[i]=new int[n]{};
	//Hallando el maximo
	max=vector[0];
	for (i=1;i<n;i++)
		if (vector[i]>max)
			max=vector[i];
	//Hallando la cantidad de digitos del maximo
	while(max>0){
		max=max/10;
		digMax++;
	}
	//Algoritmo Heap
	while(p<digMax){
		//Moviendo los numeros del vector a la matriz
		for (i=0;i<n;i++){
			dig=vector[i]/(int)pow(10,p) % 10;
			matriz[dig][c[dig]]=vector[i];
			c[dig]++;
		}
		//Subiendo la matriz al vector
		k=0;
		for (i=0;i<10;i++){
			for (j=0;j<c[i];j++)
				vector[k++]=matriz[i][j];
			c[i]=0;
		}
		p++;
	}
}

int main(){
    int n;
    cout<<"Cuantos datos desea ingresar: ";
    cin>>n;
	int* vector=new int[n];
    lectura(vector,n);
    ordRadix(vector,n);
    imprimir(vector,n);
	return 0;
}
