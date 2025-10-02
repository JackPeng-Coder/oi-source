#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool check(int a, int b, int c)
{
    string a_ = to_string(a);
    string b_ = to_string(b);
    string c_ = to_string(c);
    
    if (a_.size() + b_.size() + c_.size() != 9)
    {
        return false;
    }

    string s = a_ + b_ + c_;
    sort(s.begin(), s.end());
    return s == "123456789";
}

int main()
{
    for (int a = 123; a < 330; a++)
    {
        if (check(a, a*2, a*3))
        {
            cout << a << " " << a*2 << " " << a*3 << endl;
        }
    }
}