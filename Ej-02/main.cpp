#include <iostream>
#include "../ArbolBinario/ArbolBinarioAVL.h"

using namespace std;

int main() {
    ArbolBinarioAVL<int> inventario;
    int opcion, codigoProducto;

    do {
        cout << "Sistema de Gestión de Inventario\n";
        cout << "1. Agregar producto\n";
        cout << "2. Eliminar producto\n";
        cout << "3. Buscar producto\n";
        cout << "4. Mostrar inventario\n";
        cout << "5. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingrese el codigo del producto a agregar: ";
                cin >> codigoProducto;
                try {
                    inventario.put(codigoProducto);
                    cout << "Producto agregado exitosamente.\n";
                } catch (int e) {
                    if (e == 200) {
                        cout << "Error: El producto ya existe en el inventario.\n";
                    }
                }
                break;

            case 2:
                cout << "Ingrese el codigo del producto a eliminar: ";
                cin >> codigoProducto;
                try {
                    inventario.remove(codigoProducto);
                    cout << "Producto eliminado exitosamente.\n";
                } catch (int e) {
                    if (e == 404) {
                        cout << "Error: Producto no encontrado.\n";
                    }
                }
                break;

            case 3:
                cout << "Ingrese el codigo del producto a buscar: ";
                cin >> codigoProducto;
                try {
                    int encontrado = inventario.search(codigoProducto);
                    cout << "Producto " << encontrado << " encontrado en el inventario.\n";
                } catch (int e) {
                    if (e == 404) {
                        cout << "Producto no encontrado.\n";
                    }
                }
                break;

            case 4:
                cout << "Inventario actual (estructura del arbol AVL):\n";
                inventario.print();
                break;

            case 5:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opcion invalida. Intente nuevamente.\n";
                break;
        }

        cout << endl;
    } while (opcion != 5);

    return 0;
}
