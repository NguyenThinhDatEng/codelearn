#include <iostream>

using namespace std;

int count = 0;
void solve(int n, int k)
{
    if (k == 0)
    {
        // cout << n << endl;
        count++;
        return;
    }

    solve(n * 2, k - 1);

    if ((n - 1) % 3 == 0)
    {
        int preN = (n - 1) / 3; // preN is odd
        if (preN % 2)
            solve((n - 1) / 3, k - 1);
    }
}

int main()
{
    // input
    int n; // the value
    int k; // number of transformations
    cin >> n >> k;
    // algo
    solve(n, k);
    cout << count;
    return 0;
}