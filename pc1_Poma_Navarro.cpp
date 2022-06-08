#include <iostream>
using namespace std;

void llenar_datos(string **matriz, int n){
    string dni, nombre;
    for(int i = 0; i< n; i++){
        cout << "DNI " << (i+1) <<": ";
        cin >> dni;


        cout << "Nombre " << (i+1) <<": ";
        cin >> nombre;
        matriz[i][0] = dni;
        matriz[i][1] = nombre;
        cout << "\n";
    }
}

void imprimir(string **matriz, int filas, int columnas){

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            cout << matriz[i][j] << "\t\t";
        }
        cout << "\n";
    }
}

int indice_hash(string dni, int n){
    int suma = 0;
    for (int i=0; i<8; i++){
		suma += (int(dni[i]) - 48);
	}
    return (suma%n);
}

int validar(int indice, int* indices, int n){
    if(indices[indice] == -1) {
        indices[indice] = 0;
        return indice;
    }
    else{
        if(indice == n-1) return validar(0,indices,n);
        else return validar(indice+1,indices,n);
    }
}

void funcion_hash(string **hash, string **matriz, int n){
    int *indices = new int[n];
    for(int i = 0; i < n; i++)
        indices[i] = -1;
    
    int indice;
    for(int i = 0; i < n; i++){
        indice = indice_hash(matriz[i][0],n);
        indice = validar(indice, indices, n);
        hash[indice][0] = indice + 48;
        hash[indice][1] = matriz[i][0];
        hash[indice][2] = matriz[i][1];
    }
}

int validar_dni(string **hash, string dni, int indice, int* indices, int n){
    if(indices[indice] == -1) return -1;
    if(hash[indice][1] == dni) {
        return indice;
    }
    else{
        indices[indice] = -1;
        if(indice == n-1) return validar_dni(hash,dni,0,indices,n);
        else return validar_dni(hash,dni,indice+1,indices,n);
    }
}

int consulta_DNI(string **hash, int n, string dni){
    int *indices = new int[n];
    for(int i = 0; i < n; i++)
        indices[i] = i;

    int indice;
    
	indice = indice_hash(dni,n);
	indice = validar_dni(hash,dni,indice,indices,n);
    return indice;
}

void cambiar_nombre(string **hash, int n, string dni){
    int indice = consulta_DNI(hash, n, dni);
    if(indice == -1) cout << "No se encuentra\n";
    else{
        string nombre;
        cout << "Ingrese el nuevo nombre: ";
        cin >> nombre;
        hash[indice][2] = nombre;
        cout << "Nombre cambiado\n";
    }
}

void eliminar(string **hash, int n, string dni){
    int indice = consulta_DNI(hash, n, dni);
    if(indice == -1) cout << "No se encuentra el dni\n";
    else{
        hash[indice][0] = "";
        hash[indice][1] = "";
        hash[indice][2] = "";
        cout << "Registro eliminado\n";
    }
}

void mostrar_ordenado(string **hash, int n){
    int *indices = new int[n];
    for(int i = 0; i < n; i++)
        indices[i] = i;

    int aux;
    for(int i = 0;i<n-1;i++){
		for(int j = i+1; j<n;j++){
			if(hash[indices[i]][1] > hash[indices[j]][1]){
				aux = indices[i];
                indices[i] = indices[j];
                indices[j] = aux;
			}
		}
	}
    cout << "DNI\t\tNombre\n";
    for(int i = 0; i < n; i++){
        if(hash[indices[i]][1] != "")
            cout << hash[indices[i]][1] <<"\t"<< hash[indices[i]][2] <<"\n";
    }
    cout << "\n";
}

int main(){
    int n;
    do{
        cout << "Ingrese numero de registros: ";
        cin >> n;
    }while(n <= 0);

    string **datos = new string*[n];
    for(int i = 0; i < n; i++)
        datos[i] = new string[2]{};
    
    llenar_datos(datos, n);
    cout << "La base de datos ingresada es: \n";
    cout << "DNI\t\t\tNombre\n";
    imprimir(datos,n,2);

    string **hash = new string*[n];
    for(int i = 0; i < n; i++)
        hash[i] = new string[3]{};

    funcion_hash(hash, datos, n);
    //cout << "Matriz hash:\n";
    //cout << "Indice\t\tDNI\t\t\tNombre\n";
    //imprimir(hash,n,3);

    int opcion, indice;
    string dni;

    do{
		cout << "Menu\n";
		cout << "1. Consultar por DNI\n";
		cout << "2. Cambiar nombre con DNI\n";
		cout << "3. Eliminar por DNI\n";
		cout << "4. Mostrar registros ordenados ascendentemente por DNI\n";
		cout << "5. Salir\n";
        cout << "Ingrese su opcion: ";
		cin >> opcion;

		switch(opcion){
			case 1:
                cout << "Cual DNI desea consultar: ";
	            cin >> dni;
				indice = consulta_DNI(hash,n,dni);
                if(indice == -1) cout << "No se encuentra\n";
                else cout << "Se encuentra en la posicion " << indice << "\n";
				break;

			case 2:
                cout << "Ingrese el dni cuyo nombre quiera cambiar: ";
	            cin >> dni;
				cambiar_nombre(hash,n,dni);
				break;

			case 3:
                cout << "Ingrese el dni que desea eliminar: ";
	            cin >> dni;
				eliminar(hash,n,dni);
				break;

			case 4:
				mostrar_ordenado(hash,n);
				break;
			case 5:
				cout<<"Fin del programa\n";
				break;
                
			default:
				cout<<"Opcion equivocada\n";
		}
        cout << "\n";
	}while(opcion != 5);
    return 0;
}