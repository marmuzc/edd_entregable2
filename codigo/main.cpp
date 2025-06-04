// main.cpp
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <chrono>    // Para la medición de tiempo
#include <algorithm> // Para std::min en mensajes de print_first_elements (si no está ya en file_io.cpp)
#include "leer_archivo.h"

// No incluimos "timer.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "sorting_estandar.h"



const size_t MAX_ELEMENTS = 50; 

int main() {
    string archivo;
    cout << "Nombre del archivo binario: ";
    getline(cin, archivo);

    vector<int32_t> numeros_originales = leer_archivo(archivo); 
    if (numeros_originales.empty()) {
        cout << "Archivo vacio o no valido." << endl;
        return 1;
    }

    cout << "Cantidad de numeros leidos: " << numeros_originales.size() << endl;
    cout << "=============================================" << endl;

    // --- Probar Insertion Sort ---
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_insertion = numeros_originales; // Copia para Insertion Sort
        cout << "\n--- Probando Insertion Sort ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_insertion, 50); // Imprime menos elementos para brevedad

        auto start_time = chrono::high_resolution_clock::now();
        insertion_sort(numeros_para_insertion);
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tiempo_insertion = end_time - start_time;

        cout << "Despues de ordenar con Insertion Sort:" << endl;
        print_first_elements(numeros_para_insertion, 50);
        cout << "Tiempo de Insertion Sort: " << tiempo_insertion.count() << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }

    // --- Probar Quick Sort ---
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_quick = numeros_originales; // Copia para Quick Sort
        cout << "\n--- Probando Quick Sort ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_quick, 50);

        auto start_time = chrono::high_resolution_clock::now();
        quick_sort(numeros_para_quick);
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tiempo_quick = end_time - start_time;

        cout << "Despues de ordenar con Quick Sort:" << endl;
        print_first_elements(numeros_para_quick, 50);
        cout << "Tiempo de Quick Sort: " << tiempo_quick.count() << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }

    // --- Probar Biblioteca Sort (std::sort) ---
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_std = numeros_originales; // Copia para std::sort
        cout << "\n--- Probando Biblioteca Sort (std::sort) ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_std, 50);

        auto start_time = chrono::high_resolution_clock::now();
        biblioteca_sort(numeros_para_std);
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tiempo_std = end_time - start_time;

        cout << "Despues de ordenar con Biblioteca Sort:" << endl;
        print_first_elements(numeros_para_std, 50);
        cout << "Tiempo de Biblioteca Sort: " << tiempo_std.count() << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }


    cout << "=============================================" << endl;
    cout << "Todas las pruebas completadas." << endl;

    return 0;
}