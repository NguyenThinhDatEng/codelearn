#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    // input
    int n; // number of messages
    cin >> n;
    vector<int> v; // contains messages
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    int k; // number of messages that can be displayed
    cin >> k;
    if (k == 0)
        return 0;

    // algorithm
    vector<bool> onScreen;
    onScreen.resize(n + 1);
    fill(onScreen.begin(), onScreen.end(), false);

    queue<int> q; // contains messages that were displayed on screen
    for (int i = 0; i < n; i++)
    {
        if (onScreen[v[i]] == false) // no 2 messages with the same phone number are displayed on the screen together
        {
            if (k == 0)     
            {
                onScreen[v[i]] = true;
                q.push(v[i]);
                onScreen[q.front()] = false;
                q.pop();
            }
            else
            {
                onScreen[v[i]] = true;
                q.push(v[i]);
                k--;
            }
        }
    }

    // display result
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}