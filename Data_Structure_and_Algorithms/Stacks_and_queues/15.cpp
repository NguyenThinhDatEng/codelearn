#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main()
{
    // input
    string s;
    getline(cin, s);

    // algorithm
    string rs = "";
    int length = s.length();
    int lastIndex = 0;
    for (int i = 0; i < length; i++)
    {
        if (s[i] != s[i + 1])
        {
            rs += s[i] + to_string(i + 1 - lastIndex);
            lastIndex = i + 1;
        }
    }

    // display result
    cout << rs;

    return 0;
}