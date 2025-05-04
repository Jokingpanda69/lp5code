#include <iostream>
#include <omp.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int n=10000;
    vector<double> arr;
    srand(time(0));
    for(int i=0;i<n;i++){
        arr.push_back(rand()%n+1);
    }
    double maximum=arr[0],minimum=arr[0],sum=0,average=0;
    #pragma omp parallel for reduction(max:maximum) reduction(min:minimum) reduction(+:sum)
    for(int i=0;i<n;i++){
        maximum=max(maximum,arr[i]);
        minimum=min(minimum,arr[i]);
        sum += arr[i];
    }
    average=sum/n;

    cout<<"\n Maximum : "<<maximum<<"\n Minimum : "<<minimum<<"\n Addition : "<<sum<<"\n Average : "<<average<<endl;
}