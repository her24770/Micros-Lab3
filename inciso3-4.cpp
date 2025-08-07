/**
 * UNivresidad del valle de Guatemala
 * Laboratorio 3: C++ y Microprocesadores
 * Autor: Josue Hernández
 * Fecha: 06-08-2025
 * Descripción: control de stock de productos
 */


#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

//estructura del producto
struct Producto {
    string nombre;
    int stockInicial;
    int vendidos;
};

int main() {
    vector<Producto> inventario;
    const int numProductos = 10;

    cout << "INGRESO DE INVENTARIO (" << numProductos << " productos)\n\n";

    // Ingresar datos
    for (int i = 0; i < numProductos; i++) {
        Producto temp;
        
        cout << "Producto #" << i+1 << endl;
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, temp.nombre);
        
        cout << "Stock inicial: ";
        cin >> temp.stockInicial;
        
        cout << "Unidades vendidas: ";
        cin >> temp.vendidos;
        
        inventario.push_back(temp);
        cout << endl;
    }

    // Mostrar reporte
    cout << "\nREPORTE DE INVENTARIO\n";
    cout << setw(20) << left << "Producto" 
         << setw(10) << right << "Inicial" 
         << setw(10) << "Vendidos" 
         << setw(10) << "Restante" 
         << setw(10) << "Agotado" << endl;
    cout << string(60, '-') << endl;

    for (const auto &prod : inventario) {
        int restante = prod.stockInicial - prod.vendidos;
        bool agotado = (restante <= 0);
        // Mostrar datos con formato
        cout << setw(20) << left << prod.nombre
             << setw(10) << right << prod.stockInicial
             << setw(10) << prod.vendidos
             << setw(10) << restante
             << setw(10) << (agotado ? "Si" : "No") << endl;//uso de ternario para mostrar agotado
    }

    return 0;
}