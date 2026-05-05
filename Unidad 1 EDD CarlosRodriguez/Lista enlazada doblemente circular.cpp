#include <iostream>
#include <string>

using namespace std;

struct Alumno {
    string nombre;
    Alumno* siguiente;
    Alumno* anterior;
};

// aqui usamos la funcion para insertar en lista doblemente circular
void registrarAsistenciaDobleCircular(Alumno*& inicio, string nombreAlumno) {
    Alumno* nuevo = new Alumno();
    nuevo->nombre = nombreAlumno;

    if (inicio == NULL) {
        inicio = nuevo;
        nuevo->siguiente = inicio; 
        nuevo->anterior = inicio; 
    } 
    else {
        Alumno* aux = inicio;
        
        while (aux->siguiente != inicio) {
            aux = aux->siguiente;
        }
        
        // aqui hacemos las conexciones 
        // conectar el viejo ultimo con el nuevo
        aux->siguiente = nuevo;   
        nuevo->anterior = aux;    
        
        // conectar el nuevo con el inicio para asi cerrar el circulo
        nuevo->siguiente = inicio; 
        inicio->anterior = nuevo;  
    }
    
    cout << "El alumno | " << nombreAlumno << " | registrado en Lista Doble Circular." << endl;
}

int main() {
    Alumno* lista = NULL;
    int opcion;
    string nombreAux;

    do {
        cout << "\n--- REGISTRO DE ASISTENCIA DOBLE CIRCULAR ---" << endl;
        cout << "1. Registrar alumno" << endl;
        cout << "2. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        cin.ignore(); 

        if (opcion == 1) {
            cout << "Nombre del alumno: ";
            getline(cin, nombreAux);
            registrarAsistenciaDobleCircular(lista, nombreAux);
        }

    } while (opcion != 2);
    
    cout<< "Saliendo del codigo...";

    return 0;
}