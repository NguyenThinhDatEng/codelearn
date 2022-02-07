#include <iostream>

using namespace std;

int main()
{
    int n; // number of elements
    cin >> n;
    int *a = new int[n]; // dynamic array allocation

    // get data for a
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // display result
    for (int i = 0; i < n; i++)
    {
        cout << a[i] * a[i] << " ";
    }

    delete[] a; // return the array memory to the OS
    return 0;
}