/**
 * UNivresidad del valle de Guatemala
 * Laboratorio 3: C++ y Microprocesadores
 * Autor: Josue Hernández
 * Fecha: 06-08-2025
 * Descripción: programa que indica a un estudiante si aprobó o reprobó según su nota final
 */

#include <iostream>
#include <string>
using namespace std;

//estructura para alumno con sus datos
struct Alumno {
    string nombre;
    double zona;
    double examenFinal;
};

//funcion que calcula la nota final con ponderaciones
double calcularNotaFinal(Alumno estudiante) {
    return estudiante.zona * 0.4 + estudiante.examenFinal * 0.6;
}

int main() {
    Alumno alumnoActual;


    cout << "Ingrese datos del alumno:" << endl;
    cout << "Nombre: ";
    getline(cin, alumnoActual.nombre);

    cout << "Zona (0-100): ";
    cin >> alumnoActual.zona;


    cout << "Examen final (0-100): ";
    cin >> alumnoActual.examenFinal;

    //calcular la nota final
    double notaFinal = calcularNotaFinal(alumnoActual);


    cout << "\n------ RESULTADOS ------" << endl;
    cout << "Alumno: " << alumnoActual.nombre << endl;
    cout << "Nota final: " << notaFinal << endl;


    //verificar si aprobo o reprobo
    if (notaFinal >= 60) {
        cout << "ESTADO: Aprobado" << endl;
    } else {
        cout << "ESTADO: Reprobado" << endl;
    }

    return 0;
}