#include <iostream>
#include <vector>

using namespace std;

// based in-place comparison
/*
    Sequence a[0]->a[k] is sorted, insert a[k + 1] in the appropriate position in that sequence
    (a[k + 1] = a[k])
*/
// compare in turn a[k + 1] to sequence a[k]->a[0]
// O(n²)
void insertion_sort(int n, vector<int> &v)
{
    for (int i = 1; i < n; i++)
    {
        // insert v[i]
        int index = i;
        int value = v[i];                         // get old v[i]
        while (index > 0 && v[index - 1] > value) // browse from the end of seq v[0]->v[n - 1]
        {
            v[index] = v[index - 1];
            index--;
        }
        v[index] = value;
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

    insertion_sort(n, v);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}