#include <iostream>
#include <string>
using namespace std;

bool check(string s)
{
    int sum = 0;
    int il = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(') sum++;
        else sum--;
        if (sum < 0) il++;
    }
    return (sum == 0 && il <= 1);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        string s;
        cin >> n >> s;
        bool yes = false;

        if (check(s))
        {
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
}