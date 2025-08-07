/**
 * UNivresidad del valle de Guatemala
 * Laboratorio 3: C++ y Microprocesadores
 * Autor: Josue Hernández
 * Fecha: 06-08-2025
 * Descripción: Programa que calcula instrucciones de 8 bits segun instrucciones del laboratorio
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Función para mostrar un número en binario directamente
void mostrarBinario(int numero, int bits) {

    for (int i = bits - 1; i >= 0; i--) {
        if (numero & (1 << i)) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
}

// Función para manejar la paridad
bool manejarParidad(int instruccion) {
    // Extraer bit de paridad (bit 7)
    int bitParidad = (instruccion >> 7) & 1;
    
    // Contar bits 1 en los bits 0-6 directamente
    int conteo1s = 0;
    for (int i = 0; i <= 6; i++) {
        if ((instruccion >> i) & 1) {
            conteo1s++;
        }
    }
    
    cout << "=== PARIDAD ===" << endl;
    
    // Mostrar tipo de paridad requerida
    if (bitParidad == 0) {
        cout << "Tipo: PAR -> ";
    } else {
        cout << "Tipo: IMPAR -> ";
    }
    
    // Validar y mostrar resultado
    bool paridadCorrecta = false;
    if (bitParidad == 0) {
        // Paridad par requerida
        if (conteo1s % 2 == 0) {
            cout << "CUMPLE" << endl;
            paridadCorrecta = true;
        } else {
            cout << "NO CUMPLE" << endl;
        }
    } else {
        // Paridad impar requerida
        if (conteo1s % 2 == 1) {
            cout << "CUMPLE" << endl;
            paridadCorrecta = true;
        } else {
            cout << "NO CUMPLE" << endl;
        }
    }
    
    if (!paridadCorrecta) {
        cout << "INSTRUCCIÓN RECHAZADA por por no cumplir paridad." << endl;
    }
    
    return paridadCorrecta;
}

// Función para manejar toda la lógica de OPCODE
int manejarOpcode(int instruccion, int opA, int opB) {

    // Extraer OPCODE (bits 6-5)
    int opcode = (instruccion >> 5) & 3;
    
    cout << "\n=== OPCODE ===" << endl;
    cout << "OPCODE: ";
    mostrarBinario(opcode, 2);
    cout << " -> ";
    
    int resultado;

    string nombrOp;
    
    switch (opcode) {
        case 0: // SUMA


            resultado = opA + opB;
            nombrOp = "SUMA";
            cout << "SUMA" << endl;
            break;
        case 1: // AND
            resultado = opA & opB;
            nombrOp = "AND";
            cout << "AND" << endl;
            break;

        case 2: // OR
            resultado = opA | opB;
            nombrOp = "OR";
            cout << "OR" << endl;
            break;
        case 3: // XOR
            resultado = opA ^ opB;
            nombrOp = "XOR";
            cout << "XOR" << endl;
            break;
        default:
            cout << "ERROR: OPCODE inválido" << endl;
            return 0;
    }


    cout << "Operacion " << nombrOp << ": " << opA << " "    << nombrOp << " " << opB << " = " << resultado << endl;

    return resultado;
}

// Función para manejar toda la lógica de MOD
void manejarMod(int instruccion, int& opA, int& opB, int& resultado) {
    // Extraer MOD (bits 4-3)
    int mod = (instruccion >> 3) & 3;
    
    cout << "\n=== MOD ===" << endl;
    cout << "MOD: ";
    mostrarBinario(mod, 2);
    cout << " -> ";
    
    switch (mod) {
        case 0: // Directo
            cout << "Directo (sin modificación)" << endl;
            break;
        case 1: // Negar resultado
            cout << "Negar resultado (~)" << endl;
            resultado = ~resultado;
            break;
        case 2: // Doble operando A
            cout << "Doble operando A (A * 2)" << endl;
            opA = opA * 2;
            break;
        case 3: // Intercambio de operandos
            cout << "Intercambio de operandos" << endl;
            int temp = opA;
            opA = opB;
            opB = temp;
            break;
    }
}

// Función para manejar toda la lógica de BANDERA
void manejarBandera(int instruccion, int& opA, int& opB) {
    // Extraer BANDERA (bit 2)
    int bandera = (instruccion >> 2) & 1;
    
    cout << "\n=== BANDERA ===" << endl;
    cout << "BANDERA: " << bandera << " -> ";
    
    if (bandera == 0) {
        cout << "Operar sin modificar operandos" << endl;
    } else {
        cout << "Invertir bits de entrada antes de operar" << endl;
        // Invertir bits de operandos (8 bits)
        opA = (~opA) & 0xFF;
        opB = (~opB) & 0xFF;
        cout << "OpA después de invertir: " << opA << endl;
        cout << "OpB después de invertir: " << opB << endl;
    }
}

// Función para manejar toda la lógica de OPERANDOS
void manejarOperandos(int instruccion, int& opA, int& opB) {
    // Extraer OPERANDOS (bits 1-0)
    int operandos = instruccion & 3;
    
    cout << "\n=== OPERANDOS ===" << endl;
    cout << "OPERANDOS: ";
    mostrarBinario(operandos, 2);
    cout << " -> ";
    
    // Obtener valor del operando según la tabla
    int valor;
    switch (operandos) {
        case 0: valor = 1; break;
        case 1: valor = 2; break;
        case 2: valor = 3; break;
        case 3: valor = 4; break;
        default: valor = 1; break;
    }
    
    cout << "Valor: " << valor << endl;
    
    opA = valor;
    opB = valor;
    cout << "OpA = " << opA << ", OpB = " << opB << endl;
}

// Validar instruccion de 8bits
void procesarInstruccion(string cadenaDeBits) {
    
    cout << "\n------------------------------------------" << endl;
    
    // Validar longitud de cadena
    if (cadenaDeBits.length() != 8) {
        cout << "ERROR: La instruccion debe tener 8 bits." << endl;
        return;
    }
    int instruccion = stoi(cadenaDeBits, 0, 2);
    
    // 1. MANEJAR PARIDAD
    if (!manejarParidad(instruccion)) {
        return; 
    }
    
    // 2. MANEJAR OPERANDOS 
    int op1, op2;
    manejarOperandos(instruccion, op1, op2);
    
    // 3. MANEJAR BANDERA
    manejarBandera(instruccion, op1, op2);
    
    // 4. MANEJAR MOD 
    int mod = (instruccion >> 3) & 3;
    if (mod == 2 || mod == 3) {
        int resultado = 0; 
        manejarMod(instruccion, op1, op2, resultado);
    }
    
    // 5. MANEJAR OPCODE
    int resultado = manejarOpcode(instruccion, op1, op2);
    
    // 6. MANEJAR MOD 
    if (mod == 1) {
        manejarMod(instruccion, op1, op2, resultado);
    }
    
    // 7. MOSTRAR RESULTADO FINAL
    cout << "\n------ RESULTADO ------" << endl;
    mostrarBinario(resultado & 0xFF, 8);
    cout << endl;
}

int main() {
    string entradaUser;


    cout << "----- LAB 3 -----" << endl;
    cout << "Ingrese instruccione: ";
    getline(cin, entradaUser);
    
    // dividir strucciones por cadenas de 8bit
    stringstream ss(entradaUser);
    string instruccion;
    
    while (ss >> instruccion) {
        procesarInstruccion(instruccion);
    }
    
    return 0;
}