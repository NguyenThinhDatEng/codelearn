#include <iostream>
#include <vector>

using namespace std;

// based insertion sort
// interval (khoảng)
// O(n (log n)²)
void shell_sort(int n, vector<int> &v)
{
    int interval = n / 2;
    while (interval > 0)
    {
        for (int i = interval; i < n; i++)
        {
            // insert v[i]
            int index = i;
            int value = v[i]; // get old v[i]
            while (index - interval >= 0 && v[index - interval] > value)
            {
                v[index] = v[index - interval];
                index -= interval;
            }

            v[index] = value;
        }
        interval /= 2;
    }
}

int main()
{
    // input
    int n; // number of elements
    cin >> n;
    vector<int> v; // contains the elements
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    shell_sort(n, v);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}