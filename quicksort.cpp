#include <iostream>
using namespace std;

void lectura(int vector[],int n){
    for (int i=0;i<n;i++){
        cout<<"Ingrese un dato ("<<i<<"): ";
        cin>>vector[i];
    }
}

void imprimir(int vector[],int n){
	for (int i=0;i<n;i++)
		cout<<vector[i]<<endl;
	cout<<endl;
}

void intercambiar(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void mezclaLista(int vector[], int izq, int cen, int der){
	int* temporal= new int[der+1];
	int i,j,k;
	i=k=izq;
	j=cen+1;
	while(i<=cen && j<=der) {
		if (vector[i]<vector[j]){
			temporal[k]=vector[i];
			i++;
			k++;
		}
		else{
			temporal[k]=vector[j];
			j++;
			k++;
		}
	}
	while(i<=cen)
			temporal[k++]=vector[i++];
	while(j<=der)
			temporal[k++]=vector[j++];
	//Copiando el temporal al vector
	for (int k=izq;k<=der;k++)
		vector[k]=temporal[k];
}

int main(){
	int n,ind,opc,cen;
	cout<<"Cuantos datos desea ingresar: ";
    cin>>n;
	int* vector=new int[n];
    lectura(vector,n);
    cout<<"Ingrese el indice central: ";
    cin>>cen;
    mezclaLista(vector,0,cen,n-1);
    imprimir(vector,n);
    return 0;
}
