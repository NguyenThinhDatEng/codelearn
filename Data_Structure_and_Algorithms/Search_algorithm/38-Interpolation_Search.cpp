// find the sum s of the consecutive sequence
#include <iostream>
#include <vector>
using namespace std;

int interpolation_search(vector<int> v, int left, int right, int x)
{
    // if x < v[left], mid can be less than 0
    // if x > v[right], mid can be greater than n - 1
    if (v[right] > v[left] && x >= v[left] && x <= v[right])
    {
        // mid = l + (r-l) * (x-a[l]) / (a[r]-a[l])
        int mid = left + (right - left) * (x - v[left]) / (v[right] - v[left]);
        if (v[mid] == x)
            return mid;
        if (v[mid] < x)
            return interpolation_search(v, mid + 1, right, x);
        return interpolation_search(v, 0, mid - 1, x);
    }
    return -1;
}

int main()
{
    // input
    int n;
    cin >> n;
    vector<int> v;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    int x; // the value is be searched
    cin >> x;

    cout << interpolation_search(v, 0, n - 1, x);

    return 0;
}