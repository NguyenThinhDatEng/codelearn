#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int binary_search(vector<int> v, int left, int right, int x)
{
    if (right >= left)
    {
        int mid = (left + right) / 2;
        // cout << "mid = " << mid << endl;
        if (v[mid] == x)
            return mid;
        if (v[mid] < x)
            return binary_search(v, mid + 1, right, x);
        return binary_search(v, 0, mid - 1, x);
    }
    return -1;
}

int main()
{
    // input
    int n;
    cin >> n;
    vector<int> v;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    int s; // the sum
    cin >> s;

    // Special case
    if (v[0] >= s)
    {
        if (v[0] > s)
            cout << -1;
        else
            cout << s;
        return 0;
    }
    // main
    int lastIndex = 0; // number sequence with index from 0 to lastIndex less than s
    int a = -1, b;     // number sequence with index from a to b whose sum is s
    bool assigned_lastIndex = false;
    // generate sub array
    vector<int> totals; // sum of numbers from 0 to i
    int x;              // the last element of totals
    totals.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        totals.push_back(v[i] + totals.back());
        x = totals.back();
        if (x == s)
        {
            a = 0;
            b = i;
            break;
        }
        if (x > s)
        {
            if (assigned_lastIndex == false)
            {
                lastIndex = i - 1;
                assigned_lastIndex = true;
            }
            int index = binary_search(totals, 0, lastIndex, x - s);
            if (index > -1)
            {
                a = index + 1;
                b = i;
                break;
            }
        }
    }

    if (a == -1)
        cout << a;
    else
        for (int i = a; i <= b; i++)
        {
            cout << v[i] << " ";
        }

    return 0;
}