#include <iostream>
#include <vector>

using namespace std;

/*
    divide and conquer
*/
// O(n log n)
void merge(vector<int> &v, int l, int r, int mid)
{
    vector<int> tmp;
    int i = l, j = mid + 1; // the beginning index
    // merge
    while (i <= mid && j <= r)
    {
        if (v[i] > v[j])
        {
            tmp.push_back(v[j]);
            j++;
        }
        else
        {
            tmp.push_back(v[i]);
            i++;
        }
    }

    while (i > mid && j <= r)
    {
        tmp.push_back(v[j++]);
    }

    while (j > r && i <= mid)
    {
        tmp.push_back(v[i++]);
    }

    // assign v

    for (int k = l; k <= r; k++)
    {
        v[k] = tmp[k - l];
    }
}
void merge_sort(vector<int> &v, int l, int r)
{
    if (r == l)
        return;
    int mid = (r + l) / 2;
    merge_sort(v, l, mid);
    merge_sort(v, mid + 1, r);
    merge(v, l, r, mid);
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

    merge_sort(v, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}