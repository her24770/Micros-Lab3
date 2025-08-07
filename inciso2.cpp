/**
 * UNivresidad del valle de Guatemala
 * Laboratorio 3: C++ y Microprocesadores
 * Autor: Josue Hernández
 * Fecha: 06-08-2025
 * Descripción: Programa que calcula instrucciones de 8 bits segun instrucciones del laboratorio
 */

#include <iostream>
#include <iomanip>
using namespace std;

// Función para calcular el promedio de temperaturas
double calcularProm(double temps[], int size) {

    double suma = 0.0;
 
    for (int i = 0; i < size; i++) {
        suma += temps[i];
    }
    return suma / size;
}

// Función para encontrar el máximo 
double encontrarMax(double listatemps[], int cant) {
    double maximo = listatemps[0];

    for (int i = 1; i < cant; i++) {
        if (listatemps[i] > maximo) {
            maximo = listatemps[i];
        }
    }

    return maximo;
}

//funcione para encontra el minimo
double encontrarMin(double listatemps[], int cant) {
    double minimo = listatemps[0];
    for (int i = 1; i < cant; i++) {
        if (listatemps[i] < minimo) {
            minimo = listatemps[i];
        }
    }
    return minimo;
}

int main() {
    double temperaturas[5];

    //pedir al suuari temperaturas
    cout << "Ingrese las 5 temperaturas:" << endl;
    for (int x = 0; x < 5; x++) {
        cout << "Dia " << x + 1 << ": ";
        
        cin >> temperaturas[x];
    }

    //llamar funciones
    double prom = calcularProm(temperaturas, 5);
    double temp_max = encontrarMax(temperaturas, 5);
    double temp_min = encontrarMin(temperaturas, 5);

    cout << fixed << setprecision(2);//casteo para no mostrar decimales de mas
    cout << "\n------ RESULTADOS ------" << endl;
    cout << "Temperatura promedio: " << prom << endl;
    cout << "Temperatura mas alta: " << temp_max << endl;
    cout << "Temperatura mas baja: " << temp_min << endl;

    return 0;
}