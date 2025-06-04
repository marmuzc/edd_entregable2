#include "sorting_estandar.h"


//Función de sorting implementada en la biblioteca estándar de C++
void biblioteca_sort(vector<int32_t>& elementos) {
    // std::sort toma dos iteradores:
    // elementos.begin() es un iterador al inicio del vector
    // elementos.end() es un iterador al elemento DESPUÉS del final del vector
    // Esto define el rango [begin, end) que será ordenado.
    std::sort(elementos.begin(), elementos.end());
}