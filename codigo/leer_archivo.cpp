#include "LEER_ARCHIVO.h"
#include <fstream>
#include <iostream>
#include <algorithm> 
using namespace std;

vector<int32_t> leer_archivo(const string& filename) { //leer un archivo binario y devolver un vector de int32_t
    // Abrir el archivo en modo binario
    vector<int32_t> datos; //vector para almacenar los datos leidos del archivo
    ifstream file(filename, ios::binary);
    if (!file) { //si no se pudo abrir el archivo, devolver un vector vacio
        cerr << "No se pudo abrir el archivo: " << filename << endl;
        return datos;
    }

    int32_t num;
    size_t count = 0;
    while (file.read(reinterpret_cast<char*>(&num), sizeof(num))) { //leer datos del archivo en bloques de int32_t
        datos.push_back(num);
        ++count;
    }
    return datos;
}

void print_first_elements(const vector<int32_t>& elementos, size_t count) { //imprimir los primeros elementos de un vector
    cout << "Primeros " << min(count, elementos.size()) << " elementos:" << endl;
    for (size_t i = 0; i < elementos.size() && i < count; ++i) {
        cout << elementos[i] << " ";
    }
    cout << endl;
}