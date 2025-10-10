#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s, t;
    cin >> s;
    int N = s.size(), c = 0;
    bool judge0 = true;
    cout << N << " ";
    for (int i = 1; i < N; i++)
    {
        cin >> t;
        s += t;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (judge0)
        {
            if (s[i] == '0')
            {
                c++;
            }
            else
            {
                cout << c << " ";
                c = 0;
                judge0 = !judge0;
                i--;
            }
        }
        else
        {
            if (s[i] == '1')
            {
                c++;
            }
            else
            {
                cout << c << " ";
                c = 0;
                judge0 = !judge0;
                i--;
            }
        }
    }
    if (c != 0) cout << c;
}