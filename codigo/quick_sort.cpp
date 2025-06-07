#include "quick_sort.h"

//quick sort
//particion para colocar el pivote
int partition(std::vector<int32_t>& elementos, int inicio, int fin) {
    int32_t pivote = elementos[fin]; // el pivote es el ultimo elemento del vector
    // Colocamos el pivote al final del vector, y luego lo movemos a su posición correcta
    int i = (inicio - 1); // Índice del elemento más pequeño
    //recorrer vector de inicio al penultimo elemento
    for (int j = inicio; j <= fin - 1; j++) {
        // Si el elemento actual es menor que el pivote
        if (elementos[j] < pivote) {
            i++; 
            std::swap(elementos[i], elementos[j]); //intercambiar actual con elemento mas pequeño
        }
    }
    std::swap(elementos[i + 1], elementos[fin]); //colocar pivote en pos correcta
    return (i + 1); //devolver indice pivote
}

// NUEVA Funcion:ayuda para elegir el pivote usando Mediana de Tres (daba error en la version anterior con muchos datos)
//poner pivote elegido (la mediana de inicio, medio, fin) en elementos[fin]
void elegir_pivote(std::vector<int32_t>& elementos, int inicio, int fin) {
    //verificamos que hayan suficientes elementos para aplicar la mediana de tres
    // Si hay menos de 3 elementos, no es necesario aplicarlo
    if (fin - inicio + 1 < 3) { 
        return;
              
    }

    int medio = inicio + (fin - inicio) / 2; //calculamos el punto medio

    if (elementos[inicio] > elementos[medio]) { // Comparamos inicio y medio
        std::swap(elementos[inicio], elementos[medio]); //si elementos[inicio] es mayor que elementos[medio], los intercambiamos
    }
    if (elementos[inicio] > elementos[fin]) { // Comparamos inicio y fin
        std::swap(elementos[inicio], elementos[fin]); // si elementos[inicio] es mayor que elementos[fin], los intercambiamos
    }
   
    if (elementos[medio] > elementos[fin]) { // Comparamos medio y fin
        std::swap(elementos[medio], elementos[fin]); // si elementos[medio] es mayor que elementos[fin], los intercambiamos
    }

    //ahora, el orden es: elementos[inicio] <= elementos[medio] <= elementos[fin], y la mediana esta en los elementos del medio

    std::swap(elementos[medio], elementos[fin]); //mediana en la posicion final del vector para el pivote
}

// recursiva para Quick Sort
void quicksort_recursiva(std::vector<int32_t>& elementos, int inicio, int fin) {
    if (inicio < fin) {
        //empezamos eligiendo el pivote usando la mediana de tres
        elegir_pivote(elementos, inicio, fin);

        //particionar el vector y conseguir el indice del pivote
        int indiceParticion = partition(elementos, inicio, fin);

        // Llamadas recursivas para ordenar las dos mitades
        quicksort_recursiva(elementos, inicio, indiceParticion - 1);
        quicksort_recursiva(elementos, indiceParticion + 1, fin);
    }
}


void quick_sort(std::vector<int32_t>& elementos) {
    if (elementos.size() < 2) { //si el vector tiwne menso de 2 elementos, no hay nada que ordenar
        return;
    }
    quicksort_recursiva(elementos, 0, elementos.size() - 1);
}
