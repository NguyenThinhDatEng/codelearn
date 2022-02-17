#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s = "-18,66,-51,-28,41,77,60,-2,30,-19,-9,-53,65,-26,-13,-12,-32,3,84,4,-18,-14,15,-46,45,-5,-11,27,-49,-7";
    int count = 0;
    for_each(s.begin(), s.end(), [&count](char c)
             {
        if (c == ',')
            count++; });
    cout << count + 1 << endl;
    replace(s.begin(), s.end(), ',', ' ');
    cout << s;
    return 0;
}