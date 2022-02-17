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
    int k;  // max distance
    cin >> k;

    // algo
    sort(v.begin(), v.end());

    int size = n - 1;
    int count = 1;
    for (int i = 0; i < size; i++)
    {
        if (v[i + 1] - v[i] > k)
        {
            count++;
        }
    }
    // number of people
    cout << count;
    return 0;
}