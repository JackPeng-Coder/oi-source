#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

string times(string a, string b)
{
    int length = a.size() + b.size();
    vector<int> av(a.size()), bv(b.size()), resv(length, 0);
    string res;
    for (int i = 0; i < a.size(); i++)
    {
        av[i] = a[a.size() - i - 1] - '0';
    }
    for (int i = 0; i < b.size(); i++)
    {
        bv[i] = b[b.size() - i - 1] - '0';
    }

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            resv[i + j] += av[i] * bv[j];
        }
    }

    for (int i = 1; i < resv.size(); i++)
    {
        resv[i] += resv[i - 1] / 10;
        resv[i - 1] %= 10;
    }

    for (int i = resv.size() - 1; i >= 0; i--)
    {
        res += resv[i] + '0';
    }

    while (res.size() > 0 && res[0] == '0')
    {
        res = res.substr(1, res.size());
    }

    return res;
}

string pow(string a, int b)
{
    string res = "1";
    while (b)
    {
        if (b & 1)
        {
            res = times(res, a);
        }
        a = times(a, a);
        if (a.size() > 500)
        {
            a = a.substr(a.size() - 500, 500);
        }
        if (res.size() > 500)
        {
            res = res.substr(res.size() - 500, 500);
        }
        b >>= 1;
    }
    return res;
}

string minusone(string a)
{
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] != '0')
        {
            a[i] -= 1;      
            if (a.size() > 1 && a[0] == '0')
            {
                a = a.substr(1, a.size());
            }
            return a;
        }
        else
        {
            a[i] = '9';
        }
    }
    return "0";
}

int main()
{
    int p;
    cin >> p;
    string ans = minusone(pow("2", p));
    cout << (int)(p*log10(2)+1) << endl;
    if (ans.size() < 500)
    {
        ans = string(500 - ans.size(), '0') + ans;
    }
    for (int i = ans.size() - 500; i < ans.size(); i += 50)
    {
        cout << ans.substr(i, 50) << endl;
    }
}