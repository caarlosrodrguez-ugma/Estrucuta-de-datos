/*carlos rodriguez
hacer un sistema de geztion de inventario que contenga punteros arreglos estructura y memoria limpieza
que le pinda al usuario ingresar la cantidad de productos
debe incluir; ID (CODIGO), DESCRIPCION, CANTIDAD, PRECIO.
Luego que muestre la cantidad en pantlla por orden alfabetico*/

#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

// Estructura que define el producto
struct Producto {
    int id;
    string descripcion;
    int cantidad;
    float precio;
};

void liberarMemoria(Producto* inventario) {
    delete[] inventario;
    cout << "Memoria liberada correctamente." << endl;
}

bool compararPorNombre(const Producto& a, const Producto& b) {
    return a.descripcion < b.descripcion;
}

int main() {
    int n;

    cout << " Sistema de Gestion de Inventario " << endl;
    cout << "Ingrese la cantidad de productos a registrar: ";
    cin >> n;

    if (n <= 0) {
        cout << "Cantidad no valida." << endl;
        return 1;
    }

    Producto* inventario = new Producto[n];

    for (int i = 0; i < n; i++) {
        cout << "Producto #" << i + 1 << endl;
        cout << "ID (Codigo): ";
        cin >> (inventario + i)->id; 
        cin.ignore(); // Limpiar el buffer para usar getline

        cout << "Descripcion: ";
        getline(cin, (inventario + i)->descripcion);

        cout << "Cantidad: ";
        cin >> (inventario + i)->cantidad;

        cout << "Precio: ";
        cin >> (inventario + i)->precio;
    }

    // Ordenamiento alfabetico
    // Usamos std::sort que es eficiente para arreglos
    sort(inventario, inventario + n, compararPorNombre);

    cout << "Inventario Ordenado Alfabeticamente " << endl;
    cout << "ID\tDESCRIPCION\tCANT\tPRECIO" << endl;
    cout << "--------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        Producto* p = &inventario[i]; 
        cout << p->id << "\t" 
             << p->descripcion << "\t\t" 
             << p->cantidad << "\t$" 
             << p->precio << endl;
    }

    // Limpieza de memoria antes de finalizar
    liberarMemoria(inventario);

    return 0;
}

