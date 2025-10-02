#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ';')
        {
            if (s[i - 4] == 'a')
            {
                if (s[i - 1] >= '0' && s[i - 1] <= '9') a = s[i - 1] - '0';
                if (s[i - 1] == 'b') a = b;
                if (s[i - 1] == 'c') a = c;
            }
            if (s[i - 4] == 'b')
            {
                if (s[i - 1] >= '0' && s[i - 1] <= '9') b = s[i - 1] - '0';
                if (s[i - 1] == 'a') b = a;
                if (s[i - 1] == 'c') b = c;
            }
            if (s[i - 4] == 'c')
            {
                if (s[i - 1] >= '0' && s[i - 1] <= '9') c = s[i - 1] - '0';
                if (s[i - 1] == 'a') c = a;
                if (s[i - 1] == 'b') c = b;
            }
        }
    }
    cout << a << " " << b << " " << c << endl;
}