#include <iostream>
#include <omp.h>
#include <vector>
#include <chrono>

using namespace std;

int main()
{
    long long int size = 100000000;                                       // Tamaño del arreglo
    int *chunk_size = new int[9]{1, 10, 20, 40, 80, 160, 320, 640, 1280}; // Tamaños de bloque (chunks)
    int *pool_size = new int[4]{1, 3, 6, 12};                             // Tamaños del pool de hilos
    int *arreglo_dinamico1 = new int[size];
    int *arreglo_dinamico2 = new int[size];
    int *arreglo_dinamico3 = new int[size];

    // Probar con diferentes números de hilos
    for (size_t i = 0; i < 5; ++i)
    {
        omp_set_num_threads(i); // Establecer el número de hilos

        // Probar con diferentes tamaños de bloques
        for (size_t j = 0; j < 9; ++j)
        {
            int chunk = chunk_size[j];
            auto start = omp_get_wtime(); // Inicia el temporizador

// Paraleliza el bucle `for` para sumar los arreglos con el esquema de `schedule`
#pragma omp for schedule(dynamic, chunk)
            for (size_t j = 0; j < size; ++j)
            {
                arreglo_dinamico1[j] = j;
                arreglo_dinamico2[j] = j;
                arreglo_dinamico3[j] = arreglo_dinamico1[j] + arreglo_dinamico2[j]; // Suma de los arreglos
            }

            auto end = omp_get_wtime(); // Detiene el temporizador
            double elapsed = end - start;
            cout << "Tiempo para sumar los vectores: " << elapsed << " segundos\n"; // Muestra el tiempo de ejecución
        }
    }

    delete[] arreglo_dinamico1;
    delete[] arreglo_dinamico2;
    delete[] arreglo_dinamico3;
    return 0;
}
