#include <iostream>

using namespace std;

int main()
{
    int n; // number of elements
    cin >> n;
    int *a = new int[n + 1]; // dynamic array allocation

    // get data for a
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int k; // index 0 <= k <= n
    int x; // inserted value
    cin >> k >> x;

    // insert x
    int i = n;
    while (i > k)
    {
        a[i] = a[i - 1];
        i--;
    }
    a[i] = x;

    // display result
    for (int i = 0; i <= n; i++)
    {
        cout << a[i] << " ";
    }

    delete[] a; // return the array memory to the OS
    return 0;
}