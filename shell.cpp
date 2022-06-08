//Ordenacion Shell
#include <iostream>
using namespace std;
void intercambiar(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void ordShell(int vector[], int n) {
	bool cambio;
	int s = n/2,rec=0;
	cout<<"Recorrido \t Salto \t Intercambios \t\t Lista\n";
	while (s>=1) {
		cambio = true; //Hubo cambios
		while (cambio){
			cambio=false;
			for (int i = 0; i < n - s; i++) 
				if (vector[i] > vector[i + s]) {
					intercambiar(vector[i], vector[i + s]);
					cambio = true;
				}
		}	
		s /= 2;
	}
}

void ordQuick(int vector[], int inicio, int fin) {
	int i,j,central; //indices
	int pivote;
	central=(inicio+fin)/2;
	pivote=vector[central];
	i=inicio;
	j=fin;
	while(i<=j)
	{
		while(vector[i]<pivote) i++;
		while(vector[j]>pivote) j--;
		if (i<=j){
			intercambiar(vector[i],vector[j]);
			i++;
			j--;
		}
	}
	if (inicio<j)
		ordQuick(vector,inicio,j);
	if (i<fin)
		ordQuick(vector,i,fin);
}

