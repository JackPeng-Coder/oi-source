#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;
typedef long long ll;

ll reverse(ll x)
{
    ll res = 0;
    while (x)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

ll quick_pow(ll a, ll b, ll m)
{
    ll res = 1;
    a %= m;
    while (b)
    {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        ll l, r, a, b, c, cnt = 0;
        unordered_set<ll> S;
        cin >> l >> r >> a >> b >> c;
        for (int v = 0; v < b; v++)
        {
            ll pow10 = 1;
            for (int k = 0; k < 15; k++)
            {
                ll y = reverse(v) * pow10 - c;
                ll x = reverse(y);
                pow10 *= 10;
                if (x < l || x > r) continue;
                if (y > 0 && y % 10 != 0 && v == quick_pow(x, a, b)) S.insert(x);
            }
        }
        cout << S.size() << endl;
    } 
}