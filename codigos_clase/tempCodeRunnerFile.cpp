#include <iostream>
#include <omp.h>

int main()
{
    using namespace std;

    omp_set_num_threads(4); // Establece el uso de 4 hilos
    int nthreads = 0;
    int thread_id = -1;

// Inicia una región paralela donde los hilos trabajan simultáneamente
#pragma omp parallel shared(nthreads) private(thread_id)
    {
        thread_id = omp_get_thread_num();         // Obtiene el ID del hilo actual
        cout << "Soy hilo " << thread_id << "\n"; // Imprime el ID del hilo

        // Solo el hilo maestro (thread_id = 0) ejecuta este bloque
        if (thread_id == 0)
        {
            nthreads = omp_get_num_threads(); // Obtiene el número total de hilos
            cout << "Numero de hilos: " << nthreads << "\n";
        }
    }

    return 0;
}
