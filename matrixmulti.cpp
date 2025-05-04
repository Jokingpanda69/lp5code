#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    int A[n][n], B[n][n], C[n][n] = {0};

    cout << "Enter elements of matrix A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter elements of matrix B (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    // Matrix multiplication C = A * B using OpenMP
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant Matrix C = A * B:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << C[i][j] << "  ";
        }
        cout << endl;
    }

    return 0;
}
