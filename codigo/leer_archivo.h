#ifndef LEER_ARCHIVO
#define LEER_ARCHIVO

#include <vector>
#include <string>
#include <cstdint>
#include <cstddef> 
using namespace std;

std::vector<int32_t> leer_archivo(const string& filename);
void print_first_elements(const vector<int32_t>& elementos, size_t count);



#endif 