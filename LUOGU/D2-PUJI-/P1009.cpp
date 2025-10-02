#include <iostream>
#include <string>
#include <vector>
using namespace std;

string add(string a, string b)
{
    int res, carry = 0;
    string s(max(a.size(), b.size()), '0');
    a = string(max(a.size(), b.size()) - a.size(), '0') + a;
    b = string(max(a.size(), b.size()) - b.size(), '0') + b;
    for (int i = 1; i <= max(a.size(), b.size()); i++)
    {
        res = (a[a.size() - i] + b[b.size() - i] - 2 * '0') + carry;
        carry = res >= 10;
        res %= 10;
        s[s.size() - i] = res + '0';
    }
    if (carry) s = '1' + s;
    return s;
}

string times(string A, string B)
{
    vector<int> a(A.size()), b(B.size()), res(A.size() + B.size(), 0);

    for (int i = 0; i < A.size(); i++)
        a[A.size() - i - 1] = A[i] - '0';
    for (int i = 0; i < B.size(); i++)
        b[B.size() - i - 1] = B[i] - '0';

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            res[i + j] += a[i] * b[j];
        }
    }

    for (int i = 0; i < res.size() - 1; i++)
    {
        res[i + 1] += res[i] / 10;
        res[i] %= 10;
    }

    while (res.size() > 1 && res.back() == 0) res.pop_back();

    string ans;
    for (int i = res.size() - 1; i >= 0; i--)
        ans.push_back(res[i] + '0');
    
    return ans;
}

int main()
{
    int n;
    string S = "0";
    string N = "1";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        N = times(N, to_string(i));
        S = add(S, N);
    }
    cout << S << endl;
}