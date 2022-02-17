#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

bool isPerfectSquare(int n)
{
    if (n < 0)
        return false;
    int sqrtN = sqrt(n);
    return sqrtN * sqrtN == n;
}

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

    bool exist = false;
    int preVi = -1; // restore previous perfect square of v[i]
    for (int i = 0; i < n; i++)
    {
        if (isPerfectSquare(v[i]) && v[i] > preVi)
        {
            exist = true;
            preVi = v[i];
            cout << v[i] << " ";
        }
    }
    if (!exist)
        cout << "NULL";
    return 0;
}