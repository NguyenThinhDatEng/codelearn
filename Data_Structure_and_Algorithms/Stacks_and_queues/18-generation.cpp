#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

const int PRIMES[] = {2, 3, 5, 7};

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    // input
    int n; // number of elements
    cin >> n;
    if (n < 2)
        return 0;

    // initialize for generation
    queue<int> q;
    int i = 0;
    while (PRIMES[i] <= n && i <= 3)
    {
        q.push(PRIMES[i]);
        cout << q.back() << " ";
        i++;
    }

    // if n <= 7 finish program
    if (i < 3)
        return 0;

    // generation
    while (1)
    {
        int tmp;
        int front = q.front();
        for (int i = 1; i <= 9; i += 2) // Units is odd
        {
            tmp = front * 10 + i;
            if (tmp > n) // only consider tmp <= n
                break;

            if (isPrime(tmp))
            {
                q.push(tmp);
                cout << tmp << " ";
            }
        }
        if (tmp >= n) // if tmp >= n, don't generate more
            break;
        q.pop();
    }

    return 0;
}