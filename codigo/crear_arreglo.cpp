#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> // Para std::sort, std::reverse, std::swap, std::max
#include <random>    // Para std::mt19937, std::random_device, std::uniform_int_distribution
#include <cstdint>   // Para int32_t, INT32_MIN, INT32_MAX
#include <map>       // Para std::map (usado para contar nombres de archivo duplicados)
#include <iomanip>   // Para std::fixed y std::setprecision

// Generador de números aleatorios Mersenne Twister
std::mt19937 rng(std::random_device{}());

// Función para calcular la cantidad de elementos int32_t para un tamaño de archivo objetivo
size_t calcular_num_elementos(long long tamano_objetivo_bytes) {
    if (tamano_objetivo_bytes <= 0) return 0;
    return static_cast<size_t>(tamano_objetivo_bytes / sizeof(int32_t));
}

// Función para escribir un vector de int32_t en un archivo binario
bool escribir_vector_a_binario(const std::vector<int32_t>& datos, const std::string& nombre_archivo) {
    std::ofstream archivo(nombre_archivo, std::ios::binary | std::ios::trunc);
    if (!archivo) {
        std::cerr << "Error: No se pudo crear/abrir el archivo '" << nombre_archivo << "'" << std::endl;
        return false;
    }
    if (!datos.empty()) {
        archivo.write(reinterpret_cast<const char*>(datos.data()), datos.size() * sizeof(int32_t));
    }
    if (archivo.fail()) {
        std::cerr << "Error: Ocurrió un error al escribir en el archivo '" << nombre_archivo << "'" << std::endl;
        archivo.close();
        return false;
    }
    archivo.close();
    double tamano_mb = (static_cast<double>(datos.size()) * sizeof(int32_t)) / (1024.0 * 1024.0);
    std::cout << "Archivo binario creado: " << nombre_archivo << " (" << std::fixed << std::setprecision(2) << tamano_mb << " MB)" << std::endl;
    return true;
}

// --- Funciones de Generación de Arreglos (sin cambios) ---

// 1. Arreglos completamente desordenados
std::vector<int32_t> generar_arreglo_desordenado(size_t num_elementos) {
    std::vector<int32_t> arr(num_elementos);
    std::uniform_int_distribution<int32_t> distrib(INT32_MIN, INT32_MAX);
    for (size_t i = 0; i < num_elementos; ++i) {
        arr[i] = distrib(rng);
    }
    return arr;
}

// 2. Arreglos ordenados de manera ascendente
std::vector<int32_t> generar_arreglo_ascendente(size_t num_elementos) {
    std::vector<int32_t> arr = generar_arreglo_desordenado(num_elementos);
    std::sort(arr.begin(), arr.end());
    return arr;
}

// 3. Arreglos ordenados de manera descendente
std::vector<int32_t> generar_arreglo_descendente(size_t num_elementos) {
    std::vector<int32_t> arr = generar_arreglo_desordenado(num_elementos);
    std::sort(arr.begin(), arr.end(), std::greater<int32_t>());
    return arr;
}

// 4. Arreglos parcialmente ordenados (prefijo ordenado)
std::vector<int32_t> generar_arreglo_parcialmente_ordenado_prefijo(size_t num_elementos) {
    if (num_elementos == 0) return {};
    std::vector<int32_t> arr(num_elementos);
    size_t cantidad_ordenada = static_cast<size_t>(num_elementos * 0.75);

    std::uniform_int_distribution<int32_t> distrib(INT32_MIN, INT32_MAX);

    for (size_t i = 0; i < cantidad_ordenada; ++i) {
        arr[i] = distrib(rng);
    }
    if (cantidad_ordenada > 0) {
        std::sort(arr.begin(), arr.begin() + cantidad_ordenada);
    }
    
    for (size_t i = cantidad_ordenada; i < num_elementos; ++i) {
        arr[i] = distrib(rng);
    }
    return arr;
}

// 5. Otros posibles casos: "Casi Ordenado" (ordenado con unos pocos intercambios aleatorios)
std::vector<int32_t> generar_arreglo_casi_ordenado_intercambios(size_t num_elementos) {
    if (num_elementos < 2) {
        return generar_arreglo_ascendente(num_elementos);
    }
    std::vector<int32_t> arr = generar_arreglo_ascendente(num_elementos);
    
    size_t num_intercambios = std::max(static_cast<size_t>(1), static_cast<size_t>(num_elementos * 0.01));
    if (num_elementos == 2) num_intercambios = 1;
    
    if (num_intercambios * 2 > num_elementos && num_elementos > 0) {
        num_intercambios = num_elementos / 2;
    }
     if (num_intercambios == 0 && num_elementos > 1) { 
        num_intercambios = 1;
    }

    std::uniform_int_distribution<size_t> distrib_indice(0, num_elementos - 1);

    for (size_t k = 0; k < num_intercambios; ++k) {
        if (num_elementos <= 1) break; 
        size_t i = distrib_indice(rng);
        size_t j = distrib_indice(rng);
        while (i == j) {
            if (num_elementos <= 1) break;
            j = distrib_indice(rng);
        }
        if (i !=j ) {
             std::swap(arr[i], arr[j]);
        }
    }
    return arr;
}

// Función para obtener un nombre descriptivo para el tipo de arreglo
std::string obtener_nombre_tipo(int indice_tipo) {
    switch (indice_tipo) {
        case 0: return "desordenado";
        case 1: return "ascendente";
        case 2: return "descendente";
        case 3: return "parcial_prefijo_ordenado";
        case 4: return "casi_ordenado_intercambios";
        default: return "tipo_desconocido";
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(2); 

    using GeneradorArreglosFunc = std::vector<int32_t>(*)(size_t);
    std::vector<GeneradorArreglosFunc> generadores = {
        generar_arreglo_desordenado,
        generar_arreglo_ascendente,
        generar_arreglo_descendente,
        generar_arreglo_parcialmente_ordenado_prefijo,
        generar_arreglo_casi_ordenado_intercambios
    };

    // Nuevos tamaños solicitados para todos los tipos de arreglos
    std::vector<long long> nuevos_tamanos_bytes = {
        1LL * 1024 * 1024,    // 1MB
        10LL * 1024 * 1024,   // 10MB
        15LL * 1024 * 1024,   // 15MB
        40LL * 1024 * 1024,   // 40MB
        60LL * 1024 * 1024    // 60MB
    };
    std::vector<std::string> nuevos_nombres_tamanos = { "1MB", "10MB", "15MB", "40MB", "60MB" };


    for (size_t idx_tipo = 0; idx_tipo < generadores.size(); ++idx_tipo) {
        std::string nombre_tipo_str = obtener_nombre_tipo(idx_tipo);
        std::cout << "Generando arreglos tipo: " << nombre_tipo_str << "..." << std::endl;

        // Usar los nuevos tamaños para todos los tipos
        std::vector<long long>& current_target_sizes_bytes = nuevos_tamanos_bytes;
        std::vector<std::string>& current_size_names_base = nuevos_nombres_tamanos;
        
        // El map para contar nombres duplicados ya no es estrictamente necesario 
        // si todos los nombres de tamaño en nuevos_nombres_tamanos son únicos,
        // pero lo mantenemos por si se reintroducen tamaños duplicados en el futuro.
        std::map<std::string, int> name_counts_for_this_type; 

        for (size_t idx_tamano = 0; idx_tamano < current_target_sizes_bytes.size(); ++idx_tamano) {
            long long tamano_actual_objetivo = current_target_sizes_bytes[idx_tamano];
            std::string nombre_base_tamano_actual = current_size_names_base[idx_tamano];
            
            size_t num_elementos = calcular_num_elementos(tamano_actual_objetivo);
            
            name_counts_for_this_type[nombre_base_tamano_actual]++;
            std::string nombre_tamano_para_archivo = nombre_base_tamano_actual;
            if (name_counts_for_this_type[nombre_base_tamano_actual] > 1) {
                nombre_tamano_para_archivo += "_" + std::to_string(name_counts_for_this_type[nombre_base_tamano_actual]);
            }

            if (num_elementos == 0 && tamano_actual_objetivo > 0) {
                 std::cerr << "Advertencia: tamano_objetivo " << nombre_base_tamano_actual
                           << " es demasiado pequeño para contener incluso un int32_t. Omitiendo." << std::endl;
                 continue;
            }
            if (num_elementos == 0 && tamano_actual_objetivo == 0) {
                 std::cout << "  Generando archivo vacío para 0 bytes (nombre base: " << nombre_base_tamano_actual << ")" << std::endl;
            } else {
                 std::cout << "  Generando " << nombre_tipo_str << " de " << nombre_base_tamano_actual
                           << " (" << num_elementos << " elementos)..." << std::endl;
            }
            
            std::vector<int32_t> arreglo_datos = generadores[idx_tipo](num_elementos);
            
            std::string nombre_archivo = nombre_tipo_str + "_" + nombre_tamano_para_archivo + ".bin";
            
            if (!escribir_vector_a_binario(arreglo_datos, nombre_archivo)) {
                std::cerr << "  Fallo al generar archivo: " << nombre_archivo << std::endl;
            }
        }
        std::cout << "-----------------------------------------------------" << std::endl;
    }

    std::cout << "Proceso de generacion de archivos completado." << std::endl;
    return 0;
}