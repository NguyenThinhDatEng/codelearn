#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // input
    int n; // number of elements
    cin >> n;

    vector<int> mark;               // mark positive index, negative index, 0
    vector<int> positive, negative; // contains the elements
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp > 0)
        {
            mark.push_back(1);
            positive.push_back(tmp); // init positive
        }
        else if (tmp < 0)
        {
            mark.push_back(-1);
            negative.push_back(tmp); // init negative
        }
        else
            mark.push_back(0);
    }

    // algo
    sort(positive.begin(), positive.end()); // sort positive array in ascending order
    sort(negative.begin(), negative.end(), [](int a, int b)
         { return a > b; }); // sort negative array in descending order

    int i = 0; // is index of positive array
    int j = 0; // is index of negative array
    // assign value for result array
    for (int k = 0; k < n; k++)
    {
        if (mark[k] > 0)
            mark[k] = positive[i++];
        else if (mark[k] < 0)
            mark[k] = negative[j++];
    }

    // display
    for (int i = 0; i < mark.size(); i++)
    {
        cout << mark[i] << " ";
    }
    cout << endl;

    return 0;
}