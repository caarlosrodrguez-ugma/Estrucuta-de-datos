#include <iostream> // para el uso de cout y cin que son los datos de entrada y salida 
#include <string> //para el uso de caracteres

using namespace std;

// aqui definimos la estructura del codigo 
struct Alumno {
    string nombre;
    Alumno* siguiente;
};
// aqui hacemos la funcion del codigo para registrar alunmos en una lista simple
void registrarAsistencia(Alumno*& inicio, string nombreAlumno) {
    Alumno* nuevo = new Alumno();
    nuevo->nombre = nombreAlumno;
    nuevo->siguiente = NULL;

    if (inicio == NULL) {
        inicio = nuevo;
    } else {
        Alumno* aux = inicio;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
    
    
    cout << ">>> El alumno | " << nombreAlumno << " | registrado exitosamente." << endl;
}
// hacemos un menu para que el usuario ingrese solo elementos en la lista
int main() {
    Alumno* lista = NULL;
    int opcion;
    string nombreAux;

    do {
        cout << "\n--- REGISTRO DE ASISTENCIA ---" << endl;
        cout << "1. Registrar alumno" << endl;
        cout << "2. Salir" << endl;
        cout << "\nOpcion: ";
        cin >> opcion;

        cin.ignore(); 

        if (opcion == 1) {
            cout << "Ingrese el nombre del Alumno: ";
            getline(cin, nombreAux);
            registrarAsistencia(lista, nombreAux);
        }

    } while (opcion != 2);

    cout<<"Saliendo del codigo..." << endl;

    return 0;
}