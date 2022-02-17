#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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

    // algo
    sort(v.begin(), v.end());
    // base case
    if (v[0] != 0)
    {
        cout << 0;
        return 0;
    }
    // execute
    for (int i = 1; i < n; i++)
    {
        if (v[i] - v[i - 1] > 1) // v[i] - v[i - 1] equal 0 or 1
        {
            cout << v[i] - 1;
            return 0;
        }
    }
    cout << v[n - 1] + 1;

    return 0;
}