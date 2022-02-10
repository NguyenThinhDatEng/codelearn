#include <iostream>

using namespace std;

int main()
{
    int m, n; // number of rows and columns
    cin >> m >> n;

    // allocate dynamic 2 dimensional arrays
    int **a = new int *[m];
    for (int i = 0; i < m; i++)
        a[i] = new int[n];

    // get data for a
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    // display result
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            sum += a[i][j];
    }

    cout << sum;

    delete[] a; // return the array memory to the OS
    return 0;
}