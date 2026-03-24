/* Nombre: Carlos Rodriguez 26479.840
Ejercicio 2 bloque 8: Hacer una estructura llamada alumno, en la cual se tendran los siguientes
Campos: Nombre, edad, promedio, pedir datos al usuario para 3 alumnos, comprobar
cual de los 3 tiene el mejor promedio y posteriormente imprimir los datos del alumno. */

#include <iostream>
#include <string>

using namespace std; 

//deficinion de estructura para alumno
struct Alumno{
	string nombre;
	int edad;
	float promedio;
	};

int main(){
	int n;
	int mejorIndice = 0;
	float mayorPromedio = 0;
	
	cout<< "Cantidad de alumnos: ";
	cin>> n ;
	
	//aqui usamos el arreglo dinamico
	Alumno* alumnos = new Alumno [n];
	

	// Aqui comenzamos a pedir datos al usuario
	for(int i = 0; i < n; i++){
		cout<<"  Ingrese los datos del alumno  "<<i+1<<endl;
		cout<<"Nombre: ";
		getline(cin>>ws, alumnos[i].nombre);
		cout<<"Edad: "; 
		cin>>alumnos[i].edad;
		cout<<"Promedio: ";
		cin>>alumnos[i].promedio;
		//Aqui se comprueba quien tiene el mejor promedio mientras colocamos los datos del alumno 
		if (alumnos[i].promedio > mayorPromedio){
			mayorPromedio = alumnos[i].promedio;
			mejorIndice = i;
		}
		cout<<endl;
	}
	cout << "      ALUMNO CON MEJOR PROMEDIO     " << endl;
    cout << "Nombre: " << alumnos[mejorIndice].nombre << endl;
    cout << "Edad: " << alumnos[mejorIndice].edad << "edad" << endl;
    cout << "Promedio: " << alumnos[mejorIndice].promedio << endl;
	
	delete[] alumnos;
	
	return 0;
}