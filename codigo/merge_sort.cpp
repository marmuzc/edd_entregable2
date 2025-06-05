#include "merge_sort.h"

// Merge Sort
void merge_sort_rec(vector<int32_t>& elementos, int izquierda, int derecha) {
    if (izquierda < derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        // Ordenar mitad izquierda y mitad derecha
        merge_sort_rec(elementos, izquierda, medio);
        merge_sort_rec(elementos, medio + 1, derecha);

        // Combinar ambas mitades ordenadas
        int n1 = medio - izquierda + 1;
        int n2 = derecha - medio;

        vector<int32_t> izquierda_vec(n1);
        vector<int32_t> derecha_vec(n2);

        for (int i = 0; i < n1; ++i)
            izquierda_vec[i] = elementos[izquierda + i];
        for (int j = 0; j < n2; ++j)
            derecha_vec[j] = elementos[medio + 1 + j];

        int i = 0, j = 0, k = izquierda;

        while (i < n1 && j < n2) {
            if (izquierda_vec[i] <= derecha_vec[j]) {
                elementos[k++] = izquierda_vec[i++];
            } else {
                elementos[k++] = derecha_vec[j++];
            }
        }

        while (i < n1) elementos[k++] = izquierda_vec[i++];
        while (j < n2) elementos[k++] = derecha_vec[j++];
    }
}

void merge_sort(vector<int32_t>& elementos) {
    if (!elementos.empty()) {
        merge_sort_rec(elementos, 0, elementos.size() - 1);
    }
}