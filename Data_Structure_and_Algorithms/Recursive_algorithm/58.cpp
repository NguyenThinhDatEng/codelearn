#include <iostream>

using namespace std;

void TRY(int k, string s)
{
    if (k == 0)
    {
        // cout << n << endl;
        cout << s << " ";
        return;
    }
    TRY(k - 1, s + '0');
    TRY(k - 1, s + '1');
}

int main()
{
    // input
    int n; // number of digits
    cin >> n;
    // algo
    TRY(n, "");
    return 0;
}