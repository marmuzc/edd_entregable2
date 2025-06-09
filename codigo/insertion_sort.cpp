#include "insertion_sort.h"

// Insertion sort
void insertion_sort(std::vector<int32_t>& elementos) {
    for (size_t i = 1; i < elementos.size(); ++i) {
        //recorrer desde el segundo elemento del vector hasta el final
        int32_t valor_actual = elementos[i]; //guardar el valor actual que queremos insertar en la parte ordenada
        
        int j = i - 1; //indice del elemento anterior al actual
        //mientras estemos en el primer elemento y ese sea mayor al valor actual
        while (j >= 0 && elementos[j] > valor_actual) {
            elementos[j + 1] = elementos[j]; //movemos el elemento anterior a la derecha
            --j; //avanzamos a la izquierda, si nos salimos del vector termina el while
        }
        elementos[j + 1] = valor_actual; //insertamos valor actual en la posicion correcta, despues del elemento menor o igual
    }
}

void insertion_sort_2(std::vector<int32_t>& elementos, int izquierda, int derecha) { //para usar en tim_sort
    for (int i = izquierda + 1; i <= derecha; ++i) {
        int32_t valor_actual = elementos[i];
        int j = i - 1;

        while (j >= izquierda && elementos[j] > valor_actual) {
            elementos[j + 1] = elementos[j];
            --j;
        }
        elementos[j + 1] = valor_actual;
    }
}

