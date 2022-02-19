#include <iostream>
#include <vector>

using namespace std;

vector<int> v; // contains result
vector<bool> visited;
int n;

void TRY(int k)
{
    if (k == n)
    {
        // cout << n << endl;
        for (int i = 0; i < n; i++)
            cout << v[i];
        cout << " ";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            v[k] = i;
            TRY(k + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    // input
    cin >> n;
    v.resize(n);
    visited.resize(n + 1);
    fill(visited.begin(), visited.end(), false);
    // algo
    TRY(0);
    return 0;
}