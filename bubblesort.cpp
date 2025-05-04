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

int main()
{
    int n = 1000;
    srand(time(0));
    vector<int> arr1,arr2;
    for (int i = 0; i < n; i++)
    {
        int val=rand() % n + 1;
        arr1.push_back(val);
        arr2.push_back(val);
    }

    double start1 = omp_get_wtime();
    bubble_sort(n, arr1);
    double end1 = omp_get_wtime();
    cout << "\nSequential time taken :" << (end1 - start1) * 1000 << "ms" << endl;

    double start2 = omp_get_wtime();
    parallel_bubble_sort(n, arr2);
    double end2 = omp_get_wtime();
    cout << "\nParallel time taken :" << (end2 - start2) * 1000 << "ms" << endl;

    return 0;
}