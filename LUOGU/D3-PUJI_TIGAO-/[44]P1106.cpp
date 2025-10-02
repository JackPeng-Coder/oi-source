#include <iostream>
#include <string>
using namespace std;

string change(string s)
{
    char max = '0' - 1;
    char maxi = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (max < s[i])
        {
            max = s[i];
            maxi = i;
        }
    }
    return s.substr(0, maxi) + s.substr(maxi + 1, s.size());
}

int main()
{
    string s;
    int k;
    cin >> s >> k;
    for (; k > 0; k--)
    {
        s = change(s);
    }
    cout << s << endl;
}