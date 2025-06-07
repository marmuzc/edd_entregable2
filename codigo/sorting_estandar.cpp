#include "sorting_estandar.h"

//Sorting estandar de c++
void biblioteca_sort(std::vector<int32_t>& elementos) {
    // std::sort toma dos iteradores:
    // elementos.begin() es un iterador al inicio del vector
    // elementos.end() es un iterador al elemento DESPUÉS del final del vector
    // Esto define el rango [begin, end) que será ordenado.
    std::sort(elementos.begin(), elementos.end()); // Ordena el vector en orden ascendente
    // Si se quisiera ordenar en orden descendente, se podría usar:
    // std::sort(elementos.begin(), elementos.end(), std::greater<int32_t>());

}