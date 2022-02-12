#include <iostream>
#include <vector>

using namespace std;

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
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == x)
            cnt++;
    }
    cout << cnt;
    return 0;
}