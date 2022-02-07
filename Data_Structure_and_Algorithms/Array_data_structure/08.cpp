#include <iostream>

using namespace std;

bool isMonotonousSeq(int n, int *a)
{
    if (n == 1)
        return true;
    if (a[0] < a[1])
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] >= a[i])
                return false;
        }
    else
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] <= a[i])
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
    if (isMonotonousSeq(n, a))
        cout << "YES";
    else
        cout << "NO";

    delete[] a; // return the array memory to the OS
    return 0;
}