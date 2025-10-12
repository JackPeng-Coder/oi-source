#include <bits/stdc++.h>
using namespace std;

string change(string s)
{
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i + 1] < s[i])
        {
            return s.substr(0, i) + s.substr(i + 1, s.size());
        }
    }
    return s.substr(0, s.size() - 1);
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    while (n--) {
        s = change(s);
    }
    while (s.size() > 1 && s[0] == '0') s = s.substr(1, s.size());
    cout << s << endl;
}