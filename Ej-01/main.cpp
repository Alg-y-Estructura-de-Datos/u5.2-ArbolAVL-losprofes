#include <iostream>
#include "../ArbolBinario/ArbolBinarioAVL.h"

using namespace std;

void menu() {
    cout << "\n--- Menu de Opciones ---\n";
    cout << "1. Insertar un codigo de producto\n";
    cout << "2. Eliminar un codigo de producto\n";
    cout << "3. Buscar un codigo de producto\n";
    cout << "4. Imprimir el arbol AVL\n";
    cout << "5. Salir\n";
    cout << "Selecciona una opcion: ";
}

int main() {
    ArbolBinarioAVL<int> arbolProductos;
    int opcion, codigo;

    do {
        menu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el codigo del producto a insertar: ";
                cin >> codigo;
                try {
                    arbolProductos.put(codigo);
                    cout << "Producto con codigo " << codigo << " insertado exitosamente.\n";
                } catch (int e) {
                    cout << "Error: el codigo ya existe o es invalido.\n";
                }
                break;
            case 2:
                cout << "Ingrese el codigo del producto a eliminar: ";
                cin >> codigo;
                try {
                    arbolProductos.remove(codigo);
                    cout << "Producto con codigo " << codigo << " eliminado exitosamente.\n";
                } catch (int e) {
                    cout << "Error: no se encontro el codigo a eliminar.\n";
                }
                break;
            case 3:
                cout << "Ingrese el codigo del producto a buscar: ";
                cin >> codigo;
                try {
                    int encontrado = arbolProductos.search(codigo);
                    cout << "Producto con codigo " << codigo << " encontrado.\n";
                } catch (int e) {
                    cout << "Error: producto no encontrado.\n";
                }
                break;
            case 4:
                cout << "Estructura del arbol AVL:\n";
                arbolProductos.print(); // Se muestra la estructura balanceada del árbol
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida, intenta nuevamente.\n";
        }
    } while (opcion != 5);

    return 0;
}
