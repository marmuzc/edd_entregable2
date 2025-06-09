#include "insertion_sort.h"
#include "merge_sort.h" // solo usaremos la función merge, no la recursiva

const int MINRUN = 32;  //para el tamaño del run minimo

//del merge sort usaremos la funcion merge 
void merge(std::vector<int32_t>& arr, int izquierda, int medio, int derecha) { //funcion para fusionar dos subarreglos
    int n1 = medio - izquierda + 1; // Tamaño de la mitad izquierda
    int n2 = derecha - medio; // Tamaño de la mitad derecha

    std::vector<int32_t> izquierda_vec(n1);
    std::vector<int32_t> derecha_vec(n2);

    for (int i = 0; i < n1; ++i) // Copiar elementos a los vectores temporales
        izquierda_vec[i] = arr[izquierda + i]; // Copiar elementos de la mitad izquierda
    // Copiar elementos de la mitad derecha
    for (int j = 0; j < n2; ++j)
        derecha_vec[j] = arr[medio + 1 + j];

    int i = 0, j = 0, k = izquierda;
    while (i < n1 && j < n2) {  // Mientras haya elementos en ambas mitades
        // Compara los elementos de ambas mitades y los coloca en el vector original
        if (izquierda_vec[i] <= derecha_vec[j])
            arr[k++] = izquierda_vec[i++];
        else
            arr[k++] = derecha_vec[j++];
    }
 // Copia los elementos restantes de la mitad izquierda y derecha
    while (i < n1)
        arr[k++] = izquierda_vec[i++];
    while (j < n2)
        arr[k++] = derecha_vec[j++];
}

void tim_sort(std::vector<int32_t>& arr) { //implementar el tim sort
    int n = arr.size(); // si el vector esta vacio no hay nada que ordenar

    //1: ordenar por insertion sort cada run de tamaño MINRUN
    for (int i = 0; i < n; i += MINRUN) {
    int derecha = std::min(i + MINRUN - 1, n - 1);
    insertion_sort_2(arr, i, derecha); // Ordena solo ese rango con insertion sort 2 
    }

    // Paso 2: fusionar los runs de tamaño creciente
    for (int size = MINRUN; size < n; size *= 2) { //tamaño de los runs a fusionar
        for (int izquierda = 0; izquierda < n; izquierda += 2 * size) { //
            int medio = std::min(izquierda + size - 1, n - 1);// Punto medio del run
            int derecha = std::min(izquierda + 2 * size - 1, n - 1); //indice del final del run

            if (medio < derecha) //si el run tiene mas de un elemento
                // Llamar a la función merge para fusionar los dos runs
                merge(arr, izquierda, medio, derecha);  // Fusiona los dos subarreglos
        }
    }
}
