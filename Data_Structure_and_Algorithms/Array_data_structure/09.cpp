#include <iostream>

using namespace std;

int *inputArr(int &n, int *a)
{
    cin >> n;
    a = new int[n];
    // get data for a
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    return a;
}

int main()
{
    int n, m;
    int *a, *b;
    a = inputArr(n, a);
    b = inputArr(m, b);

    // merge 2 array
    int *c = new int[n + m];
    int i, j, k;
    i = j = k = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            c[k] = a[i];
            i++;
        }
        else
        {
            c[k] = b[j];
            j++;
        }
        k++;
    }

    if (i == n)
        for (int tmp = j; tmp < m; tmp++)
            c[k++] = b[tmp];
    else
        for (int tmp = i; tmp < n; tmp++)
            c[k++] = a[tmp];

    // display result
    int length = m + n;
    for (int i = 0; i < length; i++)
        cout << c[i] << " ";

    delete[] a; // return the array memory to the OS
    delete[] b;
    delete[] c;
    return 0;
}