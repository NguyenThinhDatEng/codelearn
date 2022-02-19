#include <iostream>
#include <vector>

using namespace std;

vector<int> v; // contains result
int n, m;      // convolution m of n elements

void TRY(int k)
{
    if (k == m + 1)
    {
        // cout << n << endl;
        for (int i = 1; i <= m; i++)
            cout << v[i];
        cout << " ";
        return;
    }

    /*
      v[k] > v[k - 1]                               (1)
    */

    /*
        Ex: 9C3 => the end of result is 789
            7 = 9 - 3 + 1
            8 = 9 - 3 + 2
            9 = 9 - 3 + 3
        v[1] ≤ n - m + 1
        v[2] <= n - m + 2
        ...
        v[n] <= n - m + n
        => v[k] <= n - m + k; k ∈ [1, n]            (2)
    */

    for (int i = v[k - 1] + 1; i <= n - m + k; i++)
    {
        v[k] = i;
        TRY(k + 1);
    }
}

int main()
{
    // input
    cin >> n >> m;
    v.resize(m + 1);
    // algo
    TRY(1);
    return 0;
}