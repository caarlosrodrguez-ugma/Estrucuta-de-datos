/* Carlos Rodriguez ejercicio de pila con un tubo de pelotas de tenis*/

#include <iostream>
#include <string>

using namespace std;

struct Pelota {
    string color;
    Pelota *siguiente;
};


void meterPelota(Pelota *&tubo, string nuevoColor) {
    Pelota *nueva_pelota = new Pelota(); // Paso 1: Crear espacio en la memoria
    nueva_pelota->color = nuevoColor;    // Paso 2: Asignamos un dato en la variable
    nueva_pelota->siguiente = tubo;      // Paso 3: Agregamos un nuevo dato
    tubo = nueva_pelota;                 // Paso 4: Asigar nuevo dato
}


void sacarPelota(Pelota *&tubo, string &n) {
    Pelota *aux = tubo;          // Paso 1: crea una variable *aux de tipo nodo
    n = aux->color;              // Paso 2: igualar n a aux->dato
    tubo = aux->siguiente;       // Paso 3: pasar pila al siguiente nodo
    delete aux;                  // Paso 4: eliminamos aux 
}

int main() {
    Pelota *tubo = NULL; // Tubo vacio al inicio
    string colorUsuario;
    char respuesta;

    // Preguntarle al usuario para meter pelotas
    do {
        cout << "De que color es la pelota que vas a meter al tubo? : ";
        cin >> colorUsuario;

        meterPelota(tubo, colorUsuario); 
        
        cout << "Quieres meter otra pelota? (s/n): ";
        cin >> respuesta;
    } while (respuesta == 's' || respuesta == 'S'); 


    
    cout << "\n  Sacando las pelotas del tubo:  " << endl;
    
    while (tubo != NULL) {
        string colorSacado;
        sacarPelota(tubo, colorSacado); // Usamos la nueva funcion aqui
        cout << "Sacaste la pelota color: " << colorSacado << endl;
    }

    return 0;
}