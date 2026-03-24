#include <iostream>

using namespace std;

int main() {
    int numero;
    int *ptrNumero = &numero; // El puntero guarda la dirección de 'numero'
    bool esPrimo = true;

    cout << "Introduce un numero entero: ";
    cin >> *ptrNumero; // Guardamos el valor directamente en la dirección apuntada

    // Un número menor o igual a 1 no es primo
    if (*ptrNumero <= 1) {
        esPrimo = false;
    } else {
        // Lógica para verificar si es primo usando el puntero
        for (int i = 2; i <= *ptrNumero / 2; i++) {
            if (*ptrNumero % i == 0) {
                esPrimo = false;
                break;
            }
        }
    }

    // Resultados
    cout << "\n--- Resultados ---" << endl;
    if (esPrimo) {
        cout << "El numero " << *ptrNumero << " es primo." << endl;
    } else {
        cout << "El numero " << *ptrNumero << " no es primo." << endl;
    }

    // Mostrar la posición de memoria
    cout << "El numero se guardo en la posicion de memoria: " << ptrNumero << endl;

    return 0;
}