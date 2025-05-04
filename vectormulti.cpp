#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    int A[n][n], B[n], C[n]; // No zero initialization

    cout << "Enter elements of matrix A (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter elements of vector B (" << n << " elements):\n";
    for (int i = 0; i < n; i++)
        cin >> B[i];

    // Matrix-vector multiplication using OpenMP without C[i] = 0;
    #pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        for (int j = 0; j < n; j++)
        {
            temp += A[i][j] * B[j];
        }
        C[i] = temp;
    }

    cout << "Result vector C = A * B:\n";
    for (int i = 0; i < n; i++)
        cout << C[i] << " ";
    cout << endl;

    return 0;
}
