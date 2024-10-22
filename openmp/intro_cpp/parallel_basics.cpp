#include <omp.h>
#include <iostream>

int main() {


    omp_set_num_threads(4);
    int nthreads = 0;
    int thread_id = 0;

    #pragma omp parallel shared(nthreads) private(thread_id)
    {
        thread_id = omp_get_thread_num();
        std::cout << "Soy hilo " << thread_id << std::endl;
        
        if (thread_id == 0) {
            nthreads = omp_get_num_threads();
            std::cout << "Número de hilos: " << nthreads << std::endl;
        }
        

    }

    return 0;
}