#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    s += ' ';
    double A = 0, B = 0, num = 0, sign = 1, left = 1;
    char x;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            num = num * 10 + (s[i] - '0') * sign;
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '=' || s[i] == ' ')
        {
            sign = (s[i] == '+' || s[i] == '=') ? 1 : -1;
            if (i > 0 && s[i - 1] >= 'a' && s[i - 1] <= 'z')
            {
                if (i == 1)
                {
                    A += 1;
                }
                else if (i > 1 && (s[i - 2] == '+' || s[i - 2] == '='))
                {
                    A += 1;
                }
                else if (i > 1 && s[i - 2] == '-')
                {
                    A -= 1;
                }
                else
                {
                    A += num * left;
                }
                x = s[i - 1];
            }
            else
            {
                B += num * left;
            }
            if (s[i] == '=')
            {
                left = -1;
            }
            num = 0;
        }
    }
    cout << x;
    if (B == 0)
        cout << "=0.000";
    else
        printf("=%.3f\n", -B / A);
}