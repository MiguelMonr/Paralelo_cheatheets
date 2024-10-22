#include <iostream>
using namespace std;
#include <omp.h>

int main(){

    long long int n = 1000000000;

    int* a;
    a = new int[n];

    int* b;
    b = new int[n];
    
    int* c;
    c = new int[n];

    double time1 = omp_get_wtime();
    #pragma omp parallel 
    {
        #pragma omp sections 
        {
            #pragma omp section
            {
                for (long long int k = 0; k< n/2; ++k) 
                {
                    c[k] = a[k] + b[k];
                }
            }
            #pragma omp section
            {
                for (long long int k = n/2; k< n; ++k) 
                {
                    c[k] = a[k] + b[k];
                }
            }
        
        }
        #pragma omp master 
        {
            cout << "termine" << endl;
        }
       
    }
    double time2 = omp_get_wtime();

    double time = time2 - time1;

    cout << "time: " << time << endl;


    delete[] a;
    delete[] b;
    delete[] c;




    return 0;
}