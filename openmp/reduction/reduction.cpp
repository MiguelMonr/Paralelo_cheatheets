#include <iostream>
using namespace std;
#include <omp.h>

int main(){
    long long int n = 100000000;
    int* c;
    c = new int[n];
    int min = c[0];

    #pragma omp parallel
    {
        #pragma omp for reduction(min: var)
        {
            
            for (int i = 1; i < n; i++) {
                if (i < min) {
                    min = c[i];
                }
            }
        }

    }

    delete[] c;
}