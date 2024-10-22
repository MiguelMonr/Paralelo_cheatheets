#include <omp.h>
#include <iostream>
#include <time.h>

// Cantidad de clientes en la cartera con score crediticio con más de 50.

using namespace std;

long long serial(int* scores_crediticios, long long int numero_clientes) {
    long long contador = 0;
    for (long long int i = 0; i < numero_clientes; i++) {
        if (scores_crediticios[i] > 50) {
            contador++;
        }
    }
    return contador;
}


long long paralelo(int* scores_crediticios, long long int numero_clientes) {
    long long contador = 0;
    omp_set_num_threads(2);  // Configurar número de hilos

    #pragma omp parallel
    {
        #pragma omp for reduction(+: contador)
        for (long long int i = 0; i < numero_clientes; i++) {
            if (scores_crediticios[i] > 50) {
                contador++;
            }
        }
    }

    return contador;
}


int main() {
    // Indica el tamaño de la cartera de clientes
    long long int numero_clientes = 200000000;

    // Crea la cartera de clientes
    int* scores_crediticios{new int[numero_clientes]{}};

    double promedio_serial = 0;
    for (int i = 0; i < 3; i++) {

        // Cambia la semilla del generador de números aleatorios
        srand(time(NULL));

        // Crea aleatoriamente los scores crediticios de los clientes
        for (long long int j = 0; j < numero_clientes; j++) {
            scores_crediticios[j] = rand() % 100 + 1;
        }


        double start = omp_get_wtime();
        long long buenos = serial(scores_crediticios, numero_clientes);
        double end = omp_get_wtime();
        double time = end - start;
        long long malos = numero_clientes - buenos;
        promedio_serial = promedio_serial + time;
        cout << "Serial " << i << ": " << buenos << " clientes buenos, " << malos << " clientes malos. Tiempo de ejecución: " << time << endl;
    }

    promedio_serial = promedio_serial/3;
    cout << "Promedio serial: " << promedio_serial << endl;

    for (int i = 0; i < 3; i++) {

        // Cambia la semilla del generador de números aleatorios
        srand(time(NULL));

        // Crea aleatoriamente los scores crediticios de los clientes
        for (long long int j = 0; j < numero_clientes; j++) {
            scores_crediticios[j] = rand() % 100 + 1;
        }


        double start = omp_get_wtime();
        long long buenos = paralelo(scores_crediticios, numero_clientes);
        double end = omp_get_wtime();
        float time = end - start;
        float speed_ups = promedio_serial / time;
        long long malos = numero_clientes - buenos;
        cout << "Serial " << i << ": " << buenos << " clientes buenos, " << malos << " clientes malos, tiempo de ejecución: " << time << ", speed ups: " << speed_ups << endl;
    }

    delete[] scores_crediticios;
}