#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool sign = false;
    if (s[0] == '-')
    {
        sign = true;
        s = s.substr(1, s.size());
    }
    while (s.size() > 1 && s[s.size() - 1] == '0') s = s.substr(0, s.size() - 1);
    if (sign) cout << '-';
    for (int i = s.size() - 1; i >= 0; i--)
        cout << s[i];
    cout << endl;
}