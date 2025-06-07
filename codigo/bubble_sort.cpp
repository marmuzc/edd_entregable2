#include "bubble_sort.h" 
#include <algorithm> //swap

// Algoritmo Bubble Sort
void bubble_sort(std::vector<int32_t>& elementos) {
    bool hubo_cambio; // para saber si hubo algun intercambio en la pasada
    size_t n = elementos.size(); //tamaño del vector

    do {
        hubo_cambio = false; // reinicia la flag de cambio en cada pasada
        for (size_t i = 1; i < n; ++i) { // recorrer el vector hasta n
            // Si el elemento anterior es mayor que el actual, intercambiar
            if (elementos[i - 1] > elementos[i]) {
                std::swap(elementos[i - 1], elementos[i]); // intercambias los elementos los elementos
                hubo_cambio = true; // marcamos que hubo un cambio
            }
        }
        --n; 
    } while (hubo_cambio); // repetimos mientras haya habido cambios en la pasada
}