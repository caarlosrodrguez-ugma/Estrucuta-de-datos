#include <iostream>
#include <string>

using namespace std;

struct Alumno {
    string nombre;
    Alumno* siguiente;
    Alumno* anterior; // aqui usamos un puntero extra para la lista doblemente enlazada llamado anterior
};
// aqui hacemos la funcion para usar la lista doblemente enlazada usando el puntero nuevo llamado anterior
void registrarAsistenciaDoble(Alumno*& inicio, string nombreAlumno) {
    Alumno* nuevo = new Alumno();
    nuevo->nombre = nombreAlumno;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    if (inicio == NULL) {
        inicio = nuevo;
    } 
    else {
        Alumno* aux = inicio;
    
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
    }
    
    cout << "El alumno | " << nombreAlumno << " | registrado exitosamente en la Lista Doble." << endl;
}

int main() {
    Alumno* lista = NULL;
    int opcion;
    string nombreAux;

    do {
    	cout << "\n--- REGISTRO DE ASISTENCIA DOBLE ---" << endl;
        cout << "1. Registrar alumno" << endl;
        cout << "2. Salir" << endl;
        cout << "\nOpcion: ";
        cin >> opcion;

        cin.ignore(); 

        if (opcion == 1) {
            cout << "Ingrese el nombre del Alumno: ";
            getline(cin, nombreAux);
            registrarAsistenciaDoble(lista, nombreAux);
        }

    } while (opcion != 2);
    
    cout<<"Saliendo del codigo..." << endl;

    return 0;
}