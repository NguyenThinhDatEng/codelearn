#include <iostream>
#include <vector>

using namespace std;

/*
    Sequence a[0]->a[k] is sorted, select minimum value a[i] of sequence a[k + 1]->a[n - 1]
    (swap a[i] with a[k + 1])
*/
// O(n²)
void selection_sort(int n, vector<int> &v)
{
    for (int i = 0; i < n; i++)
    {
        // select min value
        int indexOfMin = i;
        for (int j = i; j < n; j++)
        {
            if (v[j] < v[indexOfMin])
                indexOfMin = j;
        }
        if (indexOfMin > i)
        {
            swap(v[indexOfMin], v[i]);
        }
    }
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

    selection_sort(n, v);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}