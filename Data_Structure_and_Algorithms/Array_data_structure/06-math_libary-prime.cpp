#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

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
        if (isPrime(a[i]))
            cout << a[i] << ' ';
    }

    delete[] a; // return the array memory to the OS
    return 0;
}