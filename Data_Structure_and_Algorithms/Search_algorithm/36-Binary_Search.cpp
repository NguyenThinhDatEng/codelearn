#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> v, int left, int right, int x)
{
    if (right >= left)
    {
        int mid = (left + right) / 2;
        if (v[mid] == x)
        {
            if (mid == 0)
                return mid;
            if (v[mid - 1] == x)
                return binary_search(v, left, mid - 1, x);
            return mid;
        }
        if (x > v[mid])
            return binary_search(v, mid + 1, right, x);
        return binary_search(v, left, mid - 1, x);
    }
    return -1;
}

int main()
{
    // input
    int n; // number of elements
    cin >> n;
    vector<int> v; // contains n elements
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    int x; // the value is searched
    cin >> x;

    // algo
    cout << binary_search(v, 0, n - 1, x);
    return 0;
}