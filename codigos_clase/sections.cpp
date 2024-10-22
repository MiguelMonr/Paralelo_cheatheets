#include <omp.h>
#include <stdio.h>

#define SIZE 1000000

int main()
{
    long long int vector[SIZE]; // Vector de tamaño grande
    long long int sum1 = 0, sum2 = 0;
    double start = omp_get_wtime(); // Medimos el tiempo de inicio

    // Inicializamos el vector con valores. En este caso, calculamos el cuadrado de i
    for (int i = 0; i < SIZE; i++)
    {
        vector[i] = i ^ 2;
    }

// Iniciamos la región paralela con dos secciones
#pragma omp parallel
    {
#pragma omp sections
        {
// Primera sección: suma de la primera mitad del vector
#pragma omp section
            {
                for (int i = 0; i < SIZE / 2; i++)
                {
                    sum1 += vector[i];
                }
            }

// Segunda sección: suma de la segunda mitad del vector
#pragma omp section
            {
                for (int i = SIZE / 2; i < SIZE; i++)
                {
                    sum2 += vector[i];
                }
            }
        }
    }

    // Imprimimos la suma total
    long long int total_sum = sum1 + sum2;
    printf("Suma total: %lld\n", total_sum);

    double end = omp_get_wtime();                              // Medimos el tiempo al finalizar
    printf("Tiempo de ejecución: %f segundos\n", end - start); // Imprimimos el tiempo total

    return 0;
}
