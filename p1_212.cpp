#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void intercambiar(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

void llenar_matriz (int **matriz, int filas, int columnas){
    srand(time(NULL));

    for (int i=0; i < filas; i++){
        for(int j=0; j < columnas; j++){
            matriz[i][j] =  1 + rand()%150;
        }
    }
}

void imprimir_matriz (int **matriz, int filas, int columnas){
	cout << "La matriz A generada:\n";
    for (int i=0; i < filas; i++){
        for(int j=0; j < columnas; j++){
            cout << matriz[i][j] << "\t";
        }
        cout << "\n";
    }
}

void ordIntercambio(int **matriz, int filas, int columnas){
	for(int i=0; i<filas; i++){
	    for(int j=0; j<columnas; j++){
	        for(int x=0; x<filas; x++){
	            for(int y=0; y<columnas; y++){
	                if(matriz[i][j] < matriz[x][y]) intercambiar(matriz[i][j], matriz[x][y]);
	            }
	        }
	    }
	}
}
int main(){
    int m,n;
    cout << "Ingrese el numero de filas: ";
    cin >> m;
    cout << "Ingrese el numero de columnas: ";
    cin >> n;
    int** matriz = new int*[m];
    for(int i = 0; i < m; i++){
        matriz[i] = new int[n]{};
    }
    llenar_matriz(matriz,m,n);
    imprimir_matriz(matriz,m,n);
    ordIntercambio(matriz,m,n);
    imprimir_matriz(matriz,m,n);
    return 0;
}
