#include <iostream>

using namespace std;

int gameGuessNumber(long long l, long long n, int count)
{
    // mid = (l + n) / 2;
    if (l == n)
        return count;
    // mid < n
    return gameGuessNumber((l + n) / 2 + 1, n, ++count);
}

int main()
{
    // input
    long long n;
    cin >> n;
    // algo
    cout << gameGuessNumber(1, n, 1);
    return 0;
}