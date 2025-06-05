// main.cpp
#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <chrono>    
#include <algorithm> 
#include "leer_archivo.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "sorting_estandar.h"
#include "merge_sort.h"
#include "heap_sort.h"
#include "bubble_sort.h"


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
        print_first_elements(numeros_para_insertion, 30); // Imprime menos elementos para brevedad

        auto start_time = chrono::high_resolution_clock::now();
        insertion_sort(numeros_para_insertion);
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tiempo_insertion = end_time - start_time;

        cout << "Despues de ordenar con Insertion Sort:" << endl;
        print_first_elements(numeros_para_insertion, 30);
        cout << "Tiempo de Insertion Sort: " << tiempo_insertion.count() << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }

    // --- Probar Quick Sort ---
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_quick = numeros_originales; // Copia para Quick Sort
        cout << "\n--- Probando Quick Sort ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_quick, 30);

        auto start_time = chrono::high_resolution_clock::now();
        quick_sort(numeros_para_quick);
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tiempo_quick = end_time - start_time;

        cout << "Despues de ordenar con Quick Sort:" << endl;
        print_first_elements(numeros_para_quick, 30);
        cout << "Tiempo de Quick Sort: " << tiempo_quick.count() << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }

    // --- Probar Biblioteca Sort (std::sort) ---
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_std = numeros_originales; // Copia para std::sort
        cout << "\n--- Probando Biblioteca Sort (std::sort) ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_std, 30);

        auto start_time = chrono::high_resolution_clock::now();
        biblioteca_sort(numeros_para_std);
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tiempo_std = end_time - start_time;

        cout << "Despues de ordenar con Biblioteca Sort:" << endl;
        print_first_elements(numeros_para_std, 30);
        cout << "Tiempo de Biblioteca Sort: " << tiempo_std.count() << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }


     // --- Probar Merge sort (std::sort) ---
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_merge = numeros_originales; // Copia para std::sort
        cout << "\n--- Probando merge Sort (std::sort) ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_merge, 30);

        auto start_time = chrono::high_resolution_clock::now();
        merge_sort(numeros_para_merge);
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tiempo_std = end_time - start_time;

        cout << "Despues de ordenar con merge Sort:" << endl;
        print_first_elements(numeros_para_merge, 30);
        cout << "Tiempo de merge Sort: " << tiempo_std.count() << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }


     // --- Probar heap sort (std::sort) ---
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_heap = numeros_originales; // Copia para std::sort
        cout << "\n--- Probando heap Sort (std::sort) ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_heap, 30);

        auto start_time = chrono::high_resolution_clock::now();
        heap_sort(numeros_para_heap);
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tiempo_std = end_time - start_time;

        cout << "Despues de ordenar con heap Sort:" << endl;
        print_first_elements(numeros_para_heap, 30);
        cout << "Tiempo de heap Sort: " << tiempo_std.count() << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }
    // --- Probar bubble sort (std::sort) ---
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_bubble = numeros_originales; // Copia para std::sort
        cout << "\n--- Probando Bubble Sort (std::sort) ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_bubble, 30);

        auto start_time = chrono::high_resolution_clock::now();
        bubble_sort(numeros_para_bubble);
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tiempo_std = end_time - start_time;

        cout << "Despues de ordenar con heap Sort:" << endl;
        print_first_elements(numeros_para_bubble, 30);
        cout << "Tiempo de bubble Sort: " << tiempo_std.count() << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }
    



    cout << "=============================================" << endl;
    cout << "Todas las pruebas completadas." << endl;
    cout <<"prueba"<< endl;

    return 0;
}
