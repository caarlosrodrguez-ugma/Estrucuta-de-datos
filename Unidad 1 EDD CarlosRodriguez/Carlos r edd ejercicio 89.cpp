#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

// Pototipo de funcion
void pedirDatos();
void ordenarArreglo(int*,int);
void mostrarArreglo(int*,int);

int nElementos, *elemento;

int main(){
	pedirDatos();
	ordenarArreglo (elemento,nElementos);
	mostrarArreglo (elemento,nElementos);
	
	delete[] elemento; //liberar la memoria utilizada para el arreglo dinamico
	
	getch;
	return 0;
	
}

void pedirDatos(){
	cout<<"Coloque el numero de elementos del arreglo: ";
	cin>>nElementos;
	
	elemento = new int [nElementos]; //crear el arreglo
	
	for(int i=0;i<nElementos;i++){
		cout<<"Coloque un numero ["<<i<<"]: ";
		cin>>*(elemento+i); // elemento [i]
	}
}

void ordenarArreglo(int *elemento,int nElementos){
	int aux;
	
	//ordenar el arreglo con el metodo burbuja
	for(int i=0;i<nElementos;i++){
		for(int j=0;j<nElementos-1;j++){
			if(*(elemento+j) > *(elemento+j+1)){ //elemento [j] > elemento [j+1]
				aux = *(elemento+j);
				*(elemento+j) = *(elemento+j+1);
				*(elemento+j+1) = aux;
			}
		}
	}
}

void mostrarArreglo(int *elemento, int nElementos){
	cout<<"\n\nMostrando arreglo ordenado, ";
	for(int i=0;i<nElementos;i++){
		cout<<*(elemento+i)<<" "; //elemento[i]
	}
}