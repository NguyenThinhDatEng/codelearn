#include <iostream>
#include <vector>

using namespace std;

int linear_search(int n, vector<int> v, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
        {
            return i;
        }
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
    cout << linear_search(n, v, x);
    return 0;
}