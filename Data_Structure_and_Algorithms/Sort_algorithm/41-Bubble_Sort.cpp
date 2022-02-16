#include <iostream>
#include <vector>

using namespace std;

// The smallest number is moved to the beginning of the sequence
// compare in turn (a[0] with a[1]), (a[1] with a[2]), ..., (a[n - 2] with a[n - 1])
// O(n²) slowest among the basic sorting algorithms
void bubble_sort(int n, vector<int> &v)
{
    int size = n - 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (v[j] < v[j - 1])
            {
                swap(v[j], v[j - 1]); // iostream libary
            }
        }
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

    bubble_sort(n, v);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}