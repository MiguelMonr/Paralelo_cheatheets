#include <iostream>
using namespace std;

int main(){



    int numero = 8;
    int* apuntador;
    apuntador = &numero;
    cout << "el valor de numero es: " << numero << endl;
    cout << "la direccion de memoria de numero es: " << &numero << endl;
    cout << "el valor de apuntador es: " << apuntador << endl;
    cout << "la direccion del apuntador: " << &apuntador << endl;
    cout << "el valor al que apunta apuntador es: " << *apuntador << endl;

    *apuntador = 88;
    cout << "el valor al que apunta apuntador es: " << *apuntador << endl;
    cout << "el valor de numero es: " << numero << endl;
    

    int size = 5;
    int arreglo_estatico[size];

    arreglo_estatico[0] = 11;
    arreglo_estatico[1] = 12;
    arreglo_estatico[2] = 13;
    arreglo_estatico[3] = 14;
    arreglo_estatico[4] = 15;

    for (int elemento: arreglo_estatico) {
        cout << elemento << " ";
    }
    cout << endl;

    for (int i=0; i < sizeof(arreglo_estatico)/sizeof(int); i++) {
        cout << arreglo_estatico[i] << " ";
    }
    cout << endl;



    int* arreglo_dinamico;
    arreglo_dinamico = new int[size]{11,12,13,14,15}; // Reservar memoria

    for (int i=0; i < size; i++) {
        cout << arreglo_dinamico[i] << " ";
    }

    cout << "\n";

    delete[] arreglo_dinamico; // Liberar memoria

    


    int col = 4;
    int ren = 2;

    int** matriz;

    matriz = new int*[ren];

    for (int i=0; i < ren; i++) {
        matriz[i] = new int[col];
    }

    //Inicializacion de la matriz
    for (int i=0; i < ren; i++) {
        for (int j=0; j < col; j++) {
            matriz[i][j] = i*col + j;
        }
    }

    //Impresion de la matriz
    for (int i=0; i < ren; i++) {
        for (int j=0; j < col; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }

    //Liberar memoria
    for (int i=0; i < ren; i++) {
        delete[] matriz[i];
    }

    delete[] matriz;


    return 0;
}