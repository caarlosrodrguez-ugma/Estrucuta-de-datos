/* Carlos Rodriguez ejercicio de pila con un tubo de pelotas de tenis*/

#include <iostream>
#include <string>

using namespace std;


struct Pelota {
    string color;
    Pelota *siguiente;
};

// aqui tenemos la funcion con los 4 pasos
void meterPelota(Pelota *&tubo, string nuevoColor) {
    Pelota *nueva_pelota = new Pelota(); // Paso 1: Crear espacio en la memoria
    nueva_pelota->color = nuevoColor;    // Paso 2: Asignamos un dato en la variable
    nueva_pelota->siguiente = tubo;      // Paso 3: Agregamos un nuevo dato
    tubo = nueva_pelota;                 // Paso 4: Asigar nuevo dato
}

int main() {
    Pelota *tubo = NULL; // Tubo vacio al inicio
    string colorUsuario;
    char respuesta;

    // Preguntarle al usuario
    do {
        cout << "De que color es la pelota que vas a meter al tubo? : ";
        cin >> colorUsuario;

        meterPelota(tubo, colorUsuario); 
        
		cout << "Quieres meter otra pelota? (s/n): ";
        cin >> respuesta;
    } while (respuesta == 's' || respuesta == 'S'); 


	// Aqui mostramos lo que hay dentro del tubo 
    cout << "\n  Pelotas que hay dentro  " << endl;
    
    while (tubo != NULL) {
        Pelota *aux = tubo;
        cout << "Sacaste la pelota color: " << aux->color << endl;
        
        tubo = aux->siguiente;
        delete aux; // Limpiamos la memoria
    }



    return 0;
}