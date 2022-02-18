#include <iostream>

using namespace std;

int greatest_common_divisor(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0 || a == b)
        return a;
    if (a > b)
        return greatest_common_divisor(a - b, b);
    return greatest_common_divisor(a, b - a);
}

int main()
{
    // input
    int a, b;
    cin >> a >> b;
    // algo
    cout << greatest_common_divisor(a, b);
    return 0;
}