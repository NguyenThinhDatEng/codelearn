#include <iostream>

using namespace std;

int main()
{
    int n; // number of elements
    cin >> n;
    int *a = new int[n]; // dynamic array allocation

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    cout << sum;
    delete[] a; // return the array memory to the OS
    return 0;
}