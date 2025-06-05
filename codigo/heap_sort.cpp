#include "heap_sort.h"
#include <algorithm> // para std::swap

// Heapify: mantener la propiedad del heap
void heapify(vector<int32_t>& arr, int n, int i) {
    int mayor = i; // raíz
    int izquierda = 2 * i + 1;
    int derecha = 2 * i + 2;

    if (izquierda < n && arr[izquierda] > arr[mayor])
        mayor = izquierda;

    if (derecha < n && arr[derecha] > arr[mayor])
        mayor = derecha;

    if (mayor != i) {
        swap(arr[i], arr[mayor]); // intercambiamos
        heapify(arr, n, mayor);   // aplicamos recursivamente
    }
}

// Heap Sort
void heap_sort(vector<int32_t>& arr) {
    int n = arr.size();

    // Construir heap (reorganizar el vector)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);      // Mover raíz al final
        heapify(arr, i, 0);        // Reaplicar heapify al heap reducido
    }
}

