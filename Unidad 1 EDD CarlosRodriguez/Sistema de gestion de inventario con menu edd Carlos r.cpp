/* Un sistema de gestion que le permita al usuario mediante un menu las opciones: agregar, editar, eliminar 
y ver los productos agregados anteriormente
Carlos Rodriguez 26479840*/

#include <iostream>
#include <string>

using namespace std;

struct Producto {
    int id;
    string descripcion;
    int cantidad;
    float precio;
};

int main() {
    Producto inventario[100];
    int totalProductos = 0; 
    int opcion;

    do {
        cout << "\n    MENU DE INVENTARIO   " << endl;
        cout << "1. Agregar Producto" << endl;
        cout << "2. Ver Inventario Completo" << endl;
        cout << "3. Editar Producto" << endl;
        cout << "4. Eliminar Producto" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione: ";
        cin >> opcion;

        if (opcion == 1) { // Opcion de agregar
            if (totalProductos < 100) {
                cout << "\n    Registrar Nuevo Producto   " << endl;
                cout << "ID: "; cin >> inventario[totalProductos].id;
                cin.ignore();
                cout << "Descripcion: "; getline(cin, inventario[totalProductos].descripcion);
                cout << "Cantidad: "; cin >> inventario[totalProductos].cantidad;
                cout << "Precio: "; cin >> inventario[totalProductos].precio;
                
                totalProductos++; 
                cout << ">> Producto guardado exitosamente." << endl;
            } else {
                cout << "Error: Inventario lleno (limite 100)." << endl;
            }
        } 
        else if (opcion == 2) { // Opcion de Ver Inventario
            if (totalProductos == 0) {
                cout << "\nEl inventario esta vacio." << endl;
            } else {
                cout << "\nID\tDESCRIPCION\tCANT\tPRECIO" << endl;
                cout << "--------------------------------------------" << endl;
                for (int i = 0; i < totalProductos; i++) {
                    cout << inventario[i].id << "\t" 
                         << inventario[i].descripcion << "\t\t" 
                         << inventario[i].cantidad << "\t$" 
                         << inventario[i].precio << endl;
                }
                cout << "--------------------------------------------" << endl;
                cout << "Total de articulos: " << totalProductos << endl;
            }
        }
        else if (opcion == 3) { // Opcion de editar productos
            int idBuscar;
            bool encontrado = false;
            cout << "Ingrese el ID del producto a editar: "; cin >> idBuscar;
            
            for (int i = 0; i < totalProductos; i++) {
                if (inventario[i].id == idBuscar) {
                    cout << "Editando: " << inventario[i].descripcion << endl;
                    cout << "Nueva Cantidad: "; cin >> inventario[i].cantidad;
                    cout << "Nuevo Precio: "; cin >> inventario[i].precio;
                    cout << ">> Producto actualizado." << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) cout << "Producto no encontrado." << endl;
        }
        else if (opcion == 4) { // Opcion de eliminar por id
            int idBuscar;
            bool eliminado = false;
            cout << "ID a eliminar: "; cin >> idBuscar;
            
            for (int i = 0; i < totalProductos; i++) {
                if (inventario[i].id == idBuscar) {
                    
                    for (int j = i; j < totalProductos - 1; j++) {
                        inventario[j] = inventario[j + 1];
                    }
                    totalProductos--; 
                    cout << ">> Producto eliminado." << endl;
                    eliminado = true;
                    break;
                }
            }
            if (!eliminado) cout << "No se encontro el ID." << endl;
        }

    } while (opcion != 5);

    return 0;
}