#include "bubble_sort.h"
#include <algorithm> // para std::swap

// Algoritmo Bubble Sort
void bubble_sort(std::vector<int32_t>& elementos) {
    bool hubo_cambio;
    size_t n = elementos.size();

    do {
        hubo_cambio = false;
        for (size_t i = 1; i < n; ++i) {
            if (elementos[i - 1] > elementos[i]) {
                std::swap(elementos[i - 1], elementos[i]);
                hubo_cambio = true;
            }
        }
        --n; // optimización: cada pasada deja el mayor al final
    } while (hubo_cambio);
}
