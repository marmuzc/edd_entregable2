#include "merge_sort.h"

// Merge Sort
void merge_sort_rec(std::vector<int32_t>& elementos, int izquierda, int derecha) {
    if (izquierda < derecha) { // Verifica si hay más de un elemento
        int medio = izquierda + (derecha - izquierda) / 2; //el punto medio
//dividir en dos mitades
        // Ordenar mitad izquierda y mitad derecha
        merge_sort_rec(elementos, izquierda, medio); 
        merge_sort_rec(elementos, medio + 1, derecha);

        // Combinar ambas mitades ordenadas
        int n1 = medio - izquierda + 1; // Tamaño de la mitad izquierda
        int n2 = derecha - medio;// Tamaño de la mitad derecha

        std::vector<int32_t> izquierda_vec(n1); // Vector para la mitad izquierda
        std::vector<int32_t> derecha_vec(n2);

        for (int i = 0; i < n1; ++i) // Copiar elementos a los vectores temporales
            izquierda_vec[i] = elementos[izquierda + i]; // Copiar elementos de la mitad izquierda
        // Copiar elementos de la mitad derecha 
        for (int j = 0; j < n2; ++j)
            derecha_vec[j] = elementos[medio + 1 + j];

        int i = 0, j = 0, k = izquierda; //indice para izquierda_vec, j para derecha_vec, k para el vector original

        while (i < n1 && j < n2) { // Mientras haya elementos en ambas mitades
            // Compara los elementos de ambas mitades y los coloca en el vector original
            if (izquierda_vec[i] <= derecha_vec[j]) {
                elementos[k++] = izquierda_vec[i++]; // Coloca el elemento menor en el vector original
            } else {
                elementos[k++] = derecha_vec[j++]; // Coloca el elemento menor en el vector original
            }
        }

        while (i < n1) elementos[k++] = izquierda_vec[i++]; // Copia los elementos restantes de la mitad izquierda
        while (j < n2) elementos[k++] = derecha_vec[j++]; // Copia los elementos restantes de la mitad derecha
    }
}
//funcion principal ms
void merge_sort(std::vector<int32_t>& elementos) {
    if (!elementos.empty()) { //si no esta vacio el vector
        // Llamada a la función recursiva para ordenar el vector
        merge_sort_rec(elementos, 0, elementos.size() - 1);
    }
}