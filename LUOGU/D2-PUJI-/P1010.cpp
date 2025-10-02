#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string func(int n)
{
    if (n == 0)
    {
        return "0";
    }
    else if (n == 1)
    {
        return "2(0)";
    }
    else if (n == 2)
    {
        return "2";
    }

    vector<int> res;
    string s;
    for (int x = 0; n; x++)
    {
        if (n & 1) res.push_back(x);
        n >>= 1;
    }
    reverse(res.begin(), res.end());
    for (auto i : res)
    {
        if (i != 1)
        {
            s += "+2(" + func(i) + ")";
        }
        else
        {
            s += "+2";
        }
    }
    return s.substr(1, s.size());
}

int main()
{
    int n;
    cin >> n;
    cout << func(n) << endl;
}