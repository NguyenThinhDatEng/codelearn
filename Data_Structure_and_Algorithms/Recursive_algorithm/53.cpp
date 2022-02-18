#include <iostream>

using namespace std;

long long pow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    return a * pow(a, b - 1);
}

int main()
{
    // input
    int a, b;
    cin >> a >> b;
    // algo
    cout << pow(a, b);
    return 0;
}