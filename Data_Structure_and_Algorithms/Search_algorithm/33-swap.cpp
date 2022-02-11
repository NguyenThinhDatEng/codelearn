#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // input
    int n; // number of elements
    cin >> n;
    vector<int> v; // contains n elements
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    // algo
    int maxIndex = n - 1, minIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[n - i - 1] > v[maxIndex]) // browse v following n - 2 to 0
            maxIndex = n - i - 1;
        if (v[i] < v[minIndex]) // browse v following 1 to n - 1
            minIndex = i;
    }
    // highlight
    swap(v[minIndex], v[maxIndex]);

    // display
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}