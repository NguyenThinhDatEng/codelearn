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

    int k; // index 0 <= k <= n
    cin >> k;

    // delete the element at index k
    int i = k;
    while (i < n - 1)
    {
        a[i] = a[i + 1];
        i++;
    }

    // display result
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << " ";
    }

    delete[] a; // return the array memory to the OS
    return 0;
}