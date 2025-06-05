#include "LEER_ARCHIVO.h"
#include <fstream>
#include <iostream>
#include <algorithm> // Para std::min
using namespace std;

vector<int32_t> leer_archivo(const string& filename) {
    vector<int32_t> datos;
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "No se pudo abrir el archivo: " << filename << endl;
        return datos;
    }

    int32_t num;
    size_t count = 0;
    while (file.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        datos.push_back(num);
        ++count;
    }
    return datos;
}

void print_first_elements(const vector<int32_t>& elementos, size_t count) {
    cout << "Primeros " << min(count, elementos.size()) << " elementos:" << endl;
    for (size_t i = 0; i < elementos.size() && i < count; ++i) {
        cout << elementos[i] << " ";
    }
    cout << endl;
}
