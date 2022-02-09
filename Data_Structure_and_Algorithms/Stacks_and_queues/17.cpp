#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // input
    int n; // number of elements
    cin >> n;
    queue<int> q;

    // get data to q
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        q.push(tmp);
    }

    // input
    int k; // number of teleportation spells
    cin >> k;

    // execute
    while (k-- > 0)
    {
        q.push(q.front());
        q.pop();
    }

    // display result
    for (int i = 0; i < n; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}