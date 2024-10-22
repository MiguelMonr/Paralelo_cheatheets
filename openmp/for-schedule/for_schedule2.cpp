#include <omp.h>
#include <iostream>

using namespace std;

int main() {

    long long int n = 1000000000;

    int chunk[9] = {1, 10, 20, 40, 80, 160, 320, 640, 1280};
    int pool_size[4] = {1, 2, 3, 4};

    int* a;
    a = new int[n];

    int* b;
    b = new int[n];
    
    int* c;
    c = new int[n];

    for (int i = 0; i < 9; ++i) {
        // This block is executed sequentially
        for (int j = 0; j < 4; ++j) {
            // This block is executed sequentially
            
            omp_set_num_threads(pool_size[j]);

            double time1 = omp_get_wtime();
            #pragma omp parallel for schedule(static, chunk[i])
            for (long long int k = 0; k< n; ++k) 
            {
                
                c[k] = a[k] + b[k];
                
            }
            double time2 = omp_get_wtime();

            double time = time2 - time1;

            cout << "chunk: " << chunk[i] << " pool_size: " << pool_size[j] << " time: " << time << endl;
            
        
        }
    }

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}