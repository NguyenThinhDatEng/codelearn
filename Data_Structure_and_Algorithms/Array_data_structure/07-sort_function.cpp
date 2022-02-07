#include <iostream>
#include <math.h>
#include <algorithm>

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

    // sort the array
    sort(a, a + n);

    // display result
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            cout << a[i - 1] << " - " << count << "; ";
            count = 1;
        }
        else
            count++;
    }
    cout << a[n - 1] << " - " << count << "; ";

    delete[] a; // return the array memory to the OS
    return 0;
}