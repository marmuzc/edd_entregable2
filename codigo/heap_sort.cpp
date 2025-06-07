#include "heap_sort.h"
#include <algorithm> // para std::swap

// Heapify para mantener la propiedad del heap
void heapify(std::vector<int32_t>& arr, int n, int i) { // n es el tamaño del heap, i es el índice del nodo a heapificar
    int mayor = i; //padre inicial o raiz
    int izquierda = 2 * i + 1; // hijo izquierdo
    int derecha = 2 * i + 2; // hijo derecho

    if (izquierda < n && arr[izquierda] > arr[mayor]) // si el hijo izquierdo es mayor que la raiz
        mayor = izquierda; // actualizamos el mayor

    if (derecha < n && arr[derecha] > arr[mayor]) // si el hijo derecho es mayor que el mayor actual
        mayor = derecha; // actualizamos el mayor
    // Si el mayor no es el padre, intercambiamos y aplicamos heapify recursivamente

    if (mayor != i) {
        std::swap(arr[i], arr[mayor]); // intercambiamos
        heapify(arr, n, mayor);   // aplicamos recursivamente
    }
}

// Heap Sort
void heap_sort(std::vector<int32_t>& arr) {
    int n = arr.size();

    // Construir heap (reorganizar el vector)
    for (int i = n / 2 - 1; i >= 0; i--) // Construir el heap desde el ultimo nodo padre
        heapify(arr, n, i); // heapify el subarbol

    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);      // mover raiz al final
        heapify(arr, i, 0);        // reaplicar heapify al heap reducido
    }
}
