/**
 * UNivresidad del valle de Guatemala
 * Laboratorio 3: C++ y Microprocesadores
 * Autor: Josue Hernández
 * Fecha: 06-08-2025
 * Descripción: calcula el porcentaje de grasa corporal de una persona
 */


#include <iostream>
#include <iomanip>
using namespace std;

// dato de la persona
struct Persona {
    string nombre;
    char sexo;     // M o F
    double peso;    // en kg
    double altura;  // en metros
    int edad;
};

// caoclar el porcentaje de grasa corporal
double calcularGrasa(Persona p) {
    double grasa;
    
    switch(p.sexo) {
        case 'M':
            // Formula para hombres
            grasa = 1.20 * p.peso / (p.altura * p.altura) + 0.23 * p.edad - 16.2;
            break;
        case 'F':
            // Formula para mujeres
            grasa = 1.20 * p.peso / (p.altura * p.altura) + 0.23 * p.edad - 5.4;
            break;
        default:
            cout << "Sexo no valido! Usando formula generica\n";
            return 0; // sexo invalido
    }
    
    return grasa;
}

int main() {
    Persona usuario;
    
    cout << "------ GRASA CORPORAL-------\n\n";
    
    cout << "Nombre: ";
    getline(cin, usuario.nombre);
    
    cout << "Sexo (M/F): ";
    cin >> usuario.sexo;
    
    cout << "Peso (kg): ";
    cin >> usuario.peso;
    
    cout << "Altura (m): ";
    cin >> usuario.altura;
    
    cout << "Edad: ";
    cin >> usuario.edad;
    
    // Calcular y mostrar resultado
    double porcentaje = calcularGrasa(usuario);
    
    cout << fixed << setprecision(2);//limpiar a dos decimales
    cout << "\nRESULTADO PARA " << usuario.nombre << ":\n";
    cout << "Porcentaje de grasa: " << porcentaje << "%\n";
    
    // mensajes
    if (porcentaje < 10) {
        cout << "Muy bajo\n";
    } else if (porcentaje < 20) {
        cout << "Estable\n";
    } else {
        cout << "Muy alto\n";
    }
    
    return 0;
}