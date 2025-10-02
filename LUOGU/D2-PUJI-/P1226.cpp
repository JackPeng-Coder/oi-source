#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, p;
    cin >> a >> b >> p;
    cout << a << "^" << b << " mod " << p << "=";

    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    cout << res << endl;
}