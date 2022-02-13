#include <iostream>
#include <vector>

using namespace std;

int res = -1;

void binary_search_variant(vector<int> v, int left, int right, int x)
{
    if (right >= left)
    {
        int mid = (left + right) / 2;
        // cout << "mid = " << mid << endl;
        if (v[mid] >= x)
        {
            if (v[mid] == x)
                res = mid;
            return binary_search_variant(v, left, mid - 1, x);
        }
        return binary_search_variant(v, mid + 1, right, x);
    }
    return;
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
    binary_search_variant(v, 0, n - 1, x);
    cout << res;
    return 0;
}