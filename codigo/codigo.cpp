#include <iostream>
#include <vector>
#include <fstream>
#include <cstdint>
#include <chrono>
#include <algorithm> //para la funcion sort de c++
using namespace std;

const size_t MAX_ELEMENTS = 50; 

// Lee archivo binario y retorna vector de enteros de 32 bits
vector<int32_t> leer_archivo(const string& filename) {
    vector<int32_t> datos; // Vector para almacenar los numeros leidos
    ifstream file(filename, ios::binary); // Abrir el archivo en modo binario (ios::binary)
    if (!file) {
        cerr << "No se pudo abrir el archivo: " << filename << endl;
        return datos;
    }

    int32_t num;
    size_t count = 0;
    // file.read lee sizeof(num) bytes (4 bytes para int32_t) en la dirección de 'num'
    while (file.read(reinterpret_cast<char*>(&num), sizeof(num)) && count < MAX_ELEMENTS) {
        datos.push_back(num);
        ++count;
    }
    return datos;
}

// Insertion sort
void insertion_sort(vector<int32_t>& elementos) {
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


// Función manual para intercambiar dos números enteros de 32 bits
void swap(int32_t& a, int32_t& b) {
    int32_t temp = a; 
    a = b;          
    b = temp;      
}
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

//Función de sorting implementada en la biblioteca estándar de C++
void biblioteca_sort(vector<int32_t>& elementos) {
    // std::sort toma dos iteradores:
    // elementos.begin() es un iterador al inicio del vector
    // elementos.end() es un iterador al elemento DESPUÉS del final del vector
    // Esto define el rango [begin, end) que será ordenado.
    std::sort(elementos.begin(), elementos.end());
}

void print_first_elements(const vector<int32_t>& elementos, size_t count = 20) {
    cout << "Primeros elementos:" << endl;
    for (size_t i = 0; i < elementos.size() && i < count; ++i) {
        cout << elementos[i] << " ";
    }
    cout << endl;
}



//radix sort como otro algortimo
int32_t radix_getmax(const std::vector<int32_t>& arr) {
    if (arr.empty()) {
        return 0;
    }
    int32_t max_val = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

// Función para realizar el "Counting Sort" para un dígito específico (representado por exp).
// Esta versión está diseñada para números no negativos.
void count_sort_radix_pass(std::vector<int32_t>& arr, int exp) {
    size_t n = arr.size();
    if (n == 0) return;

    std::vector<int32_t> output(n);
    std::vector<int> count(10, 0); // Para los 10 dígitos decimales (0-9)

    // Almacena la cuenta de ocurrencias de cada dígito en la posición 'exp'
    for (size_t i = 0; i < n; ++i) {
        // La lógica (arr[i] / exp) % 10 es para números no negativos.
        count[(arr[i] / exp) % 10]++;
    }

    // Cambia count[i] para que ahora contenga la posición actual
    // de este dígito en el vector de salida (output)
    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    // Construye el vector de salida.
    // Se itera en reversa para mantener la estabilidad del ordenamiento,
    // lo cual es importante para Radix Sort.
    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia el vector de salida (ordenado por el dígito actual) de nuevo a arr[].
    for (size_t i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

// Función principal de Radix Sort para ordenar un std::vector<int32_t>.
// IMPORTANTE: Esta implementación específica de Radix Sort (LSD, base 10)
// está diseñada y SOLO FUNCIONARÁ CORRECTAMENTE para NÚMEROS ENTEROS NO NEGATIVOS.
void radix_sort(std::vector<int32_t>& arr) {
    if (arr.size() < 2) {
        return; // Vector vacío o con un solo elemento ya está "ordenado".
    }

    // Verificación crucial: este Radix Sort no maneja números negativos.
    for (int32_t val : arr) {
        if (val < 0) {
            std::cerr << "Error: La implementación actual de Radix Sort solo funciona con números no negativos." << std::endl;
            std::cerr << "El vector NO será ordenado por radix_sort debido a la presencia de números negativos." << std::endl;
            // Opcionalmente, aquí podrías lanzar una excepción o llamar a otro algoritmo de ordenamiento
            // como std::sort(arr.begin(), arr.end());
            // Por ahora, simplemente no hace nada más.
            return;
        }
    }

    // Encuentra el valor máximo para saber el número de dígitos.
    int32_t max_val = radix_getmax(arr);

    // Realiza counting sort para cada dígito.
    // 'exp' es 10^i donde 'i' es el número del dígito actual (unidades, decenas, centenas...).
    // Se usa 'long long' para 'exp' para prevenir desbordamiento si max_val es muy grande,
    // aunque el 'exp' pasado a count_sort_radix_pass se convertirá a 'int',
    // lo cual es seguro ya que 10^9 (para 10 dígitos) cabe en un 'int'.
    for (long long exp = 1; max_val / exp > 0; exp *= 10) {
        count_sort_radix_pass(arr, static_cast<int>(exp));
    }
}




int main() {
    string archivo;
    cout << "Nombre del archivo binario: ";
    getline(cin, archivo);

    vector<int32_t> numeros_originales = leer_archivo(archivo); 
    if (numeros_originales.empty()) {
        cout << "Archivo vacio o no valido." << endl;
        return 1;
    }

    cout << "Cantidad de numeros leidos: " << numeros_originales.size() << endl;
    cout << "=============================================" << endl;

    // --- Probar Insertion Sort ---
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_insertion = numeros_originales; // Copia para Insertion Sort
        cout << "\n--- Probando Insertion Sort ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_insertion, 50); // Imprime menos elementos para brevedad

        auto start_time = chrono::high_resolution_clock::now();
        insertion_sort(numeros_para_insertion);
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tiempo_insertion = end_time - start_time;

        cout << "Despues de ordenar con Insertion Sort:" << endl;
        print_first_elements(numeros_para_insertion, 50);
        cout << "Tiempo de Insertion Sort: " << tiempo_insertion.count() << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }

    // --- Probar Quick Sort ---
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_quick = numeros_originales; // Copia para Quick Sort
        cout << "\n--- Probando Quick Sort ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_quick, 50);

        auto start_time = chrono::high_resolution_clock::now();
        quick_sort(numeros_para_quick);
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tiempo_quick = end_time - start_time;

        cout << "Despues de ordenar con Quick Sort:" << endl;
        print_first_elements(numeros_para_quick, 50);
        cout << "Tiempo de Quick Sort: " << tiempo_quick.count() << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }

    // --- Probar Biblioteca Sort (std::sort) ---
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_std = numeros_originales; // Copia para std::sort
        cout << "\n--- Probando Biblioteca Sort (std::sort) ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_std, 50);

        auto start_time = chrono::high_resolution_clock::now();
        biblioteca_sort(numeros_para_std);
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tiempo_std = end_time - start_time;

        cout << "Despues de ordenar con Biblioteca Sort:" << endl;
        print_first_elements(numeros_para_std, 50);
        cout << "Tiempo de Biblioteca Sort: " << tiempo_std.count() << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }


        // --- Probar Radix Sort ---
    if (!numeros_originales.empty()) {
        vector<int32_t> numeros_para_radix = numeros_originales; // Copia para std::sort
        cout << "\n--- Probando Radix ---" << endl;
        cout << "Antes de ordenar:" << endl;
        print_first_elements(numeros_para_radix, 50);

        auto start_time = chrono::high_resolution_clock::now();
        radix_sort(numeros_para_radix);
        auto end_time = chrono::high_resolution_clock::now();
        chrono::duration<double, milli> tiempo_std = end_time - start_time;

        cout << "Despues de ordenar con Biblioteca Sort:" << endl;
        print_first_elements(numeros_para_radix, 50);
        cout << "Tiempo de Biblioteca Sort: " << tiempo_std.count() << " ms" << endl;
        cout << "---------------------------------------------" << endl;
    }

    cout << "=============================================" << endl;
    cout << "Todas las pruebas completadas." << endl;

    return 0;
}