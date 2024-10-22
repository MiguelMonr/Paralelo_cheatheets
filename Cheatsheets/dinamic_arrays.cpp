#include <iostream>
using namespace std;

int main()
{
    int size; // Statically
    int *point;

    cout << "Entra el tamanio del arreglo: ";
    cin >> size;

    // Creando el array
    point = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Entra el valor del elemento " << i << ": ";
        cin >> point[i];
    }

    // Imprimiendo el array pero usando la notacion de pointers
    for (int i = 0; i < size; i++)
    {
        cout << *(point + i) << " " << endl;
    }
    // liberando arrays usas la siguiente notacion:
    delete[] point;

    return 0;
}