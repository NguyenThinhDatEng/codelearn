#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int linear_search(int n, vector<int> v, int x, int firstIndex)
{
    if (firstIndex == 0) // browse v following 0 to n
        for (int i = 0; i < n; i++)
        {
            if (v[i] == x)
            {
                return i;
            }
        }
    else
        for (int i = n - 1; i >= 0; i--) // if firstIndex != 0, browse v following 0 to n
        {
            if (v[i] == x)
            {
                return i;
            }
        }
    return 1;
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

    // algo
    vector<int> v2 = v;
    sort(v2.begin(), v2.end());
    int i = linear_search(n, v, v2[0], 0);
    int j = linear_search(n, v, v2[n - 1], 1);
    swap(v[i], v[j]); // highlight

    // display
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}