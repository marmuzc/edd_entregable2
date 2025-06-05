#include "quick_sort.h"

//quick sort
// f de particion para Quick Sort
// Coloca el elemento indiceParticionvote en la posicon correcta
// en el array ordenado, y coloca todos los elementos menores que el indiceParticionvote
// a su izquierda y todos los mayores a su derecha.
int partition(vector<int32_t>& elementos, int inicio, int fin) {
    int32_t pivote = elementos[fin]; // El pivote es el elemento en la posición 'fin'
                                     // (después de que elegir_pivote lo haya colocado allí)
    int i = (inicio - 1); // Índice del elemento más pequeño

    for (int j = inicio; j <= fin - 1; j++) {
        // Si el elemento actual es menor que el pivote
        if (elementos[j] < pivote) {
            i++; // Incrementamos el índice del elemento más pequeño
            swap(elementos[i], elementos[j]);
        }
    }
    swap(elementos[i + 1], elementos[fin]);
    return (i + 1); // Retornamos el índice de la partición
}

// NUEVA FUNCIÓN: Ayudante para elegir el pivote usando Mediana de Tres
// Coloca el pivote elegido (la mediana de inicio, medio, fin) en elementos[fin]
void elegir_pivote(vector<int32_t>& elementos, int inicio, int fin) {
    // Solo aplicar si hay al menos 3 elementos para elegir la mediana
    if (fin - inicio + 1 < 3) {
        return; // Para menos de 3 elementos, la estrategia por defecto (último elemento) es suficiente
                // o la partición se vuelve trivial.
    }

    int medio = inicio + (fin - inicio) / 2;

    // Ordenar elementos[inicio], elementos[medio], elementos[fin]
    // para encontrar la mediana.
    if (elementos[inicio] > elementos[medio]) {
        swap(elementos[inicio], elementos[medio]);
    }
    if (elementos[inicio] > elementos[fin]) {
        swap(elementos[inicio], elementos[fin]);
    }
    // Después de esto, elementos[inicio] es el más pequeño de los tres.
    // Ahora comparamos elementos[medio] y elementos[fin].
    if (elementos[medio] > elementos[fin]) {
        swap(elementos[medio], elementos[fin]);
    }
    // Ahora, el orden es: elementos[inicio] <= elementos[medio] <= elementos[fin]
    // (refiriéndose a los valores que estaban originalmente en esas posiciones).
    // El valor que está en elementos[medio] es la mediana de los tres.

    // Movemos la mediana (que está en elementos[medio]) a la posición 'fin',
    // ya que tu función 'partition' espera el pivote en elementos[fin].
    swap(elementos[medio], elementos[fin]);
}

// MODIFICADA: Función recursiva de Quick Sort
void quicksort_recursiva(vector<int32_t>& elementos, int inicio, int fin) {
    if (inicio < fin) {
        // Elegir y colocar el pivote usando Mediana de Tres ANTES de particionar
        elegir_pivote(elementos, inicio, fin);

        // indiceParticion es el índice de partición, elementos[indiceParticion] está ahora en el lugar correcto
        int indiceParticion = partition(elementos, inicio, fin);

        // Ordenamos recursivamente los elementos antes y después de la partición
        quicksort_recursiva(elementos, inicio, indiceParticion - 1);
        quicksort_recursiva(elementos, indiceParticion + 1, fin);
    }
}

// Tu función principal Quick Sort (interfaz) - SIN CAMBIOS
void quick_sort(vector<int32_t>& elementos) {
    if (elementos.size() < 2) { // No necesita ordenarse si tiene 0 o 1 elemento
        return;
    }
    quicksort_recursiva(elementos, 0, elementos.size() - 1);
}
