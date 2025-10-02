#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int a = 1;
    int sum = 0;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == '-') continue;
        sum += (s[i] - '0') * a;
        sum %= 11;
        a++;
    }
    if ((sum == 10 && s.back() == 'X') || (sum == s.back() - '0'))
    {
        cout << "Right" << endl;
    }
    else
    {
        cout << s.substr(0, s.size() - 1) << (sum == 10 ? 'X' : (char)(sum + '0'));
    }
}