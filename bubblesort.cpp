#include <iostream>
#include <omp.h>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

void bubble_sort(int n, vector <int>&arr)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void parallel_bubble_sort(int n, vector <int>&arr)
{
    for (int i = 0; i < n - 1; i++)
    {
        #pragma omp parallel for
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


int main() {
    srand(time(0)); // Seed for random number generator

    int n;
    cout << "Enter number of random elements to generate: ";
    cin >> n;

    vector<int> arr1(n), arr2(n);

    for (int i = 0; i < n; ++i) {
        int val = rand() % 100 + 1; // Random numbers between 1 and 100
        arr1[i] = val;
        arr2[i] = val;
    }

    cout << "\nRandomly generated array:\n";
    for (int val : arr1) {
        cout << val << " ";
    }
    cout << endl;

    // Sequential Bubble Sort
    double start1 = omp_get_wtime();
    bubble_sort(n, arr1);
    double end1 = omp_get_wtime();
    cout << "\nSequential Bubble Sort Time: " << (end1 - start1) * 1000 << " ms" << endl;

    // Parallel Bubble Sort
    double start2 = omp_get_wtime();
    parallel_bubble_sort(n, arr2);
    double end2 = omp_get_wtime();
    cout << "Parallel Bubble Sort Time: " << (end2 - start2) * 1000 << " ms" << endl;

    return 0;
}
