#include <iostream>
#include <string>

using namespace std;

struct Alumno {
    string nombre;
    Alumno* siguiente;
};

//usamos la funcion para que el ultimo puntero apunte al inicio de nuevo asi como un circulo 
void registrarAsistenciaCircular(Alumno*& inicio, string nombreAlumno) {
    Alumno* nuevo = new Alumno();
    nuevo->nombre = nombreAlumno;

    if (inicio == NULL) {
        inicio = nuevo;
        nuevo->siguiente = inicio; 
    } 
    else {
        Alumno* aux = inicio;
        
        while (aux->siguiente != inicio) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;   
        nuevo->siguiente = inicio; 
    }
    
    cout << "El alumno | " << nombreAlumno << " | ingresado exitosamente. (Lista Circular)." << endl;
}

int main() {
    Alumno* lista = NULL; 
    int opcion;
    string nombreAux;

    do {
        cout << "\n--- REGISTRO DE ASISTENCIA CIRCULAR ---" << endl;
        cout << "1. Registrar alumno" << endl;
        cout << "2. Salir" << endl;
        cout << "\nOpcion: ";
        cin >> opcion;

        cin.ignore(); 

        if (opcion == 1) {
            cout << "Nombre del Alumno: ";
            getline(cin, nombreAux);
            registrarAsistenciaCircular(lista, nombreAux);
        }

    } while (opcion != 2);
    
    cout<<"Saliendo el codigo...";
    

    return 0;
}