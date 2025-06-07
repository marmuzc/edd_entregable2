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
#include <vector>   
#include <string>
using namespace std; 


int main() {
    string archivo; // Nombre del archivo a leer
    cout << "=============================================" << endl;
    cout << "Ingrese su archivo: "; 
    getline(cin, archivo); 

    vector<int32_t> numeros_originales = leer_archivo(archivo); //leer el archivo y almacenar datos en el vector
    if (numeros_originales.empty()) {
        cout << "Archivo vacio o no valido." << endl;
        return 1;
    }

    cout << "Cantidad de numeros leidos: " << numeros_originales.size() << endl; //ver la cantidad de numeros leidos segun el tamaño de archivo
    cout << "=============================================" << endl;


    double tiempo_insertion_ms = 0.0; // variable para almacenar el tiempo de ordenamiento de insertion sort 
    double tiempo_qs_ms = 0.0; 
    double tiempo_std_ms = 0.0; 
    double tiempo_ms_ms = 0.0; 
    double tiempo_hs_ms = 0.0; 
    double tiempo_bs_ms = 0.0; 
    
    
    // insertion sort
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_insertion = numeros_originales; //hacemos una copia del vector original para cada prueba
        cout << "\n--- Probando Insertion Sort ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_insertion, 30); // solo pediremos imprimir 30 elementos para no explotar la consola

        auto start_time = chrono::high_resolution_clock::now(); //medir el tiempo de inicio
        insertion_sort(numeros_para_insertion);//llamar a inserion sort
        auto end_time = chrono::high_resolution_clock::now(); //medir el tiempo de fin
        tiempo_insertion_ms = chrono::duration<double, milli>(end_time - start_time).count();

        cout << "Despues de ordenar con Insertion Sort:" << endl;
        print_first_elements(numeros_para_insertion, 30);
        cout << "Tiempo de Insertion Sort: " << tiempo_insertion_ms << " ms" << endl; // mostrar el tiempo de ordenamiento
        cout << "---------------------------------------------" << endl;
    }

    // quick sort
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_quick = numeros_originales; //copia para quick sort
        cout << "\n--- Probando Quick Sort ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_quick, 30);

        auto start_time = chrono::high_resolution_clock::now();
        quick_sort(numeros_para_quick);
        auto end_time = chrono::high_resolution_clock::now();
        tiempo_qs_ms = chrono::duration<double, milli>(end_time - start_time).count();

        cout << "Despues de ordenar con Quick Sort:" << endl;
        print_first_elements(numeros_para_quick, 30);
        cout << "Tiempo de Quick Sort: " << tiempo_qs_ms << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }

    // probar para sort de c++
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_std = numeros_originales; 
        cout << "\n--- Probando Biblioteca Sort (std::sort) ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_std, 30);

        auto start_time = chrono::high_resolution_clock::now();
        biblioteca_sort(numeros_para_std);
        auto end_time = chrono::high_resolution_clock::now();
        tiempo_std_ms = chrono::duration<double, milli>(end_time - start_time).count();

        cout << "Despues de ordenar con Biblioteca Sort:" << endl;
        print_first_elements(numeros_para_std, 30);
        cout << "Tiempo de Biblioteca Sort: " << tiempo_std_ms << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }


     // Merge sort 
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_merge = numeros_originales; // copia para merge sort
        cout << "\n--- Probando Merge Sort  ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_merge, 30);

        auto start_time = chrono::high_resolution_clock::now();
        merge_sort(numeros_para_merge);
        auto end_time = chrono::high_resolution_clock::now();
        tiempo_ms_ms = chrono::duration<double, milli>(end_time - start_time).count();

        cout << "Despues de ordenar con Merge Sort:" << endl;
        print_first_elements(numeros_para_merge, 30);
        cout << "Tiempo de Merge Sort: " << tiempo_ms_ms << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }


     // Heap sort ---
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_heap = numeros_originales; // copia para heap sort
        cout << "\n--- Probando Heap Sort ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_heap, 30);

        auto start_time = chrono::high_resolution_clock::now();
        heap_sort(numeros_para_heap);
        auto end_time = chrono::high_resolution_clock::now();
        tiempo_hs_ms = chrono::duration<double, milli>(end_time - start_time).count();

        cout << "Despues de ordenar con Heap Sort:" << endl;
        print_first_elements(numeros_para_heap, 30);
        cout << "Tiempo de Heap Sort: " << tiempo_hs_ms << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }
    // Bubble sort
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_bubble = numeros_originales; 
        cout << "\n--- Probando Bubble Sort ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_bubble, 30);

        auto start_time = chrono::high_resolution_clock::now();
        bubble_sort(numeros_para_bubble);
        auto end_time = chrono::high_resolution_clock::now();
        tiempo_bs_ms = chrono::duration<double, milli>(end_time - start_time).count();

        cout << "Despues de ordenar con Bubble Sort:" << endl;
        print_first_elements(numeros_para_bubble, 30);
        cout << "Tiempo de Bubble Sort: " << tiempo_bs_ms << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }
    // Resumen de tiempos
    cout << "\n=============================================" << endl;  
    cout << "Resumen de tiempos de ordenamiento:" << endl;
    cout << "Insertion Sort: " << tiempo_insertion_ms << " ms" << endl;
    cout << "Quick Sort: " << tiempo_qs_ms << " ms" << endl;
    cout << "Biblioteca Sort (std::sort): " << tiempo_std_ms << " ms" << endl;
    cout << "Merge Sort: " << tiempo_ms_ms << " ms" << endl;
    cout << "Heap Sort: " << tiempo_hs_ms << " ms" << endl;
    cout << "Bubble Sort: " << tiempo_bs_ms << " ms" << endl;

    cout << "=============================================" << endl;
    cout << "Todos los algoritmos ejecutados." << endl;


    return 0;
}
