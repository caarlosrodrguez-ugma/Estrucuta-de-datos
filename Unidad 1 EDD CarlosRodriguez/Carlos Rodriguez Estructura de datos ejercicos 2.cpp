#include <iostream>
#include <string>
using namespace std; 

int main(){

struct estudiantes{
	string nombre;
	int edad;
	float promedio;	
};

estudiantes alumno1;

 
alumno1.nombre = "Carlos Rodriguez";
alumno1.edad = 29;
alumno1.promedio = 17.3;

cout << "------Datos del estudiante------"<< endl;
cout << "Nombre: " <<alumno1.nombre<<endl;
cout << "Edad: " <<alumno1.edad<<"años"<<endl;
cout << "Promedio: " <<alumno1.promedio<<endl;

return 0;
}


