/**
 * UNivresidad del valle de Guatemala
 * Laboratorio 3: C++ y Microprocesadores
 * Autor: Josue Hernández
 * Fecha: 06-08-2025
 * Descripción: programa para buscar simbolos ASCII
 */



#include <iostream>
using namespace std;

//funcion pa mostrar tabla completa
void mostrarTabla() {
    cout << "\n------ TABLA ASCII COMPLETA:------  \n";
    for (int i = 0; i <= 127; i++) {
        cout << i << " = " << static_cast<char>(i) << "\t";
    }
}

//funcion pa convertir numero a char
void convertirNumero() {
    int num;
    cout << "\nIngrese numero (0-127): ";
    cin >> num;

    if (num < 0 || num > 127) {
        cout << "solo sse puede entre 0 y 127\n";
        return;
    }

    cout << "El caracter ASCII es: " << static_cast<char>(num) << endl;
}

int main() {
    int opcion;
    bool salir = false;

    while (!salir){
    
        cout << "\n----- MENU ASCII -----\n"
             << "1. Ver tabla completa\n"
             << "2. Convertir numero\n"
             << "3. Salir\n"
             << "Opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                mostrarTabla();
                break;
            case 2:
                convertirNumero();
                break;
            case 3:
                cout << "Saliendo...\n";
                salir = true;
                break;
            default:
                cout << "Opcion invalida\n";
        }
    }

    return 0;
}