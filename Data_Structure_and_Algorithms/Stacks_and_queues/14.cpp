#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // input
    int n;
    cin >> n;
    
    // algorithm
    stack<int> st;
    while (n > 0)
    {
        st.push(n % 2);
        n /= 2;
    }

    // display result
    int size = st.size();
    for (int i = 1; i <= size; i++)
    {
        cout << st.top();
        st.pop();
    }
    return 0;
}