#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Manera de declarar una matriz
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}; // Debes declarar sus dimensiones

    // Para iterar una matriz
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Puedes hacer la matriz pero con vectores. La ventaja es que puedes tener de distintos tamaños
    vector<vector<int>> matrix2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // Para iterar una matiz pero de vectores
    for (int i = 0; i < matrix2.size(); i++)
    {
        for (int j = 0; j < matrix2[i].size(); j++)
        {
            cout << matrix2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}