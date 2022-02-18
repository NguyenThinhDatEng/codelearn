#include <iostream>

using namespace std;

// 20! out of int
long long factorial(int n)
{
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    // input
    int n;
    cin >> n;
    // algo
    cout << factorial(n);
    return 0;
}