//Merge Sort
//Mezclar Listas ordenadas
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

void ordMerge(int vector[],int izq,int der){
	int cen;
	if (izq<der){
		cen=(izq+der)/2;
		ordMerge(vector,izq,cen);
		ordMerge(vector,cen+1,der);
		mezclaLista(vector,izq,cen,der);
	}
	else
		return;
}

void ordHeap(int vector[],int n){
	//Posición del último padre i = (n-1)/2
	//Posición del hijo izquierdo = 2i+1
	//Posición del hijo derecho = 2i+2
	int i,izq,der,hi,hd;
	for (n=n;n>1;n--){
		i=(n-1)/2;
		while(i>=0){
			hi=2*i+1;
			hd=2*i+2;
			if (hd<n){
				if(vector[hd]>vector[i] && vector[hd]>=vector[hi])
					intercambiar(vector[hd],vector[i]);
				else if (vector[hi]>vector[i] && vector[hi]>=vector[hd])
					intercambiar(vector[hi],vector[i]);	
			}
			else if (hi<n)
				if(vector[hi]>vector[i])
					intercambiar(vector[hi],vector[i]);	
			i--;
		}
		intercambiar(vector[0],vector[n-1]);
	}
}
int main(){
	int n,ind,opc,cen;
	cout<<"Cuantos datos desea ingresar: ";
    cin>>n;
	int* vector=new int[n];
    lectura(vector,n);
    ordMerge(vector,0,n-1);
    //cout<<"Ingrese el indice central: ";
    //cin>>cen;
    //mezclaLista(vector,0,cen,n-1);
    imprimir(vector,n);
    return 0;
}
