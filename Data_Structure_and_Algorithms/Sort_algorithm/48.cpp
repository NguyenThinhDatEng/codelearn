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

    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i] != v[i - 1])
        {
            cout << v[i - 1] << " " << count << "; ";
            count = 1;
        }
        else
            count++;
    }
    cout << v[n - 1] << " " << count << "; ";
    return 0;
}