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
    bool isNULL = true;
    for (int i = 0; i < n; i += 2)
    {
        if (v[i] % 2)
        {
            cout << v[i] << " ";
            isNULL = false;
        }
    }
    if (isNULL)
        cout << "NULL";
    return 0;
}