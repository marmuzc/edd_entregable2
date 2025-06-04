#include "quick_sort.h"


//quick sort
// f de particion para Quick Sort
// Coloca el elemento indiceParticionvote en la posicon correcta
// en el array ordenado, y coloca todos los elementos menores que el indiceParticionvote
// a su izquierda y todos los mayores a su derecha.
int partition(vector<int32_t>& elementos, int inicio, int fin) {
    int32_t indiceParticionvot = elementos[fin]; // Elegimos el ultimp elemento como indiceParticionvote
    int i = (inicio - 1); // indice del elemento mas pequeño

    for (int j = inicio; j <= fin - 1; j++) {
        // Si el elemento actual es menor que el indiceParticionvote
        if (elementos[j] < indiceParticionvot) {
            i++; // Incrementamos el indice del elemento mas pequeño
            swap(elementos[i], elementos[j]);
        }
    }
    swap(elementos[i + 1], elementos[fin]);
    return (i + 1); // Retornamos el indice de la partición
}

// Función recursiva de Quick Sort
void quicksort_recursiva(vector<int32_t>& elementos, int inicio, int fin) {
    if (inicio < fin) {
        // indiceParticion es el indice de partición, elementos[indiceParticion] está ahora en el lugar correcto
        int indiceParticion = partition(elementos, inicio, fin);

        // Ordenamos recursivamente los elementos antes y después de la partición
        quicksort_recursiva(elementos, inicio, indiceParticion - 1);
        quicksort_recursiva(elementos, indiceParticion + 1, fin);
    }
}

//Quick sort (función principal que llama a la recursiva)
void quick_sort(vector<int32_t>& elementos) {
    if (elementos.size() < 2) { // No necesita ordenarse si tiene 0 o 1 elemento
        return;
    }
    quicksort_recursiva(elementos, 0, elementos.size() - 1);
}