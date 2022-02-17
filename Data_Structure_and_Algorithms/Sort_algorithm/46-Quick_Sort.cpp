#include <iostream>
#include <vector>

using namespace std;

// based divide and conquer
// pivot (phần tử chốt)
/*
    1. divide the array into 2 parts by comparing each element of the array with pivot
    first array consists of elements ≤ pivot
    second array consists of the elements ≥ pivot

    2. 4 ways to select pivot
    - Always pick first and last element as pivot.
    - Always pick middle element as pivot. (implemented below)
    - Pick a random element as pivot.
    - Pick median as pivot.
*/
// O(n log n)

pair<int, int> partition(vector<int> &v, int l, int r)
{
    int mid = (l + r) / 2;
    int pivot = v[mid]; // determine a pivot
    int i = l, j = r;
    while (i < j)
    {
        // shift left pointer to find a value greater than pivot
        while (v[i] < pivot)
            i++;
        // shift right pointer to find a value less than pivot
        while (v[j] > pivot)
            j--;

        // if mid is swapped, that will lead to case i > mid or j < mid so i can be greater than j
        if (i <= j)
        {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }
    return {i, j};
}

void quick_sort(vector<int> &v, int l, int r) // Select middle element as pivot
{
    if (l >= r)
        return;
    pair<int, int> index = partition(v, l, r);
    quick_sort(v, index.first, r);
    quick_sort(v, l, index.second);
}

int main()
{
    // input
    int n; // number of elements
    cin >> n;
    vector<int> v; // contains the elements
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    quick_sort(v, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}