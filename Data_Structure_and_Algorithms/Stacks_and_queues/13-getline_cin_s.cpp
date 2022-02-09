#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // input
    string s;
    getline(cin, s);
    // algorithm
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }

    // display result
    for (int i = 0; i < s.length(); i++)
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}