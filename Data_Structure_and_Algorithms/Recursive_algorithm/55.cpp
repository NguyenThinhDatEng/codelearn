#include <iostream>

using namespace std;

int fibo(int n)
{
    if (n < 3)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    // input
    int n;
    cin >> n;
    // algo
    cout << fibo(n);
    return 0;
}