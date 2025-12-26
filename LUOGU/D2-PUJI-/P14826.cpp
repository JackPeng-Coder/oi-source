#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll n, k;
        cin >> n >> k;
        if (k == 0) {
            cout << 0 << endl;
            continue;
        }
        ll maxg = 0, sqrtn = static_cast<ll>(sqrtl(n));
        for (ll a = 1; a <= sqrtn + 1; a++) {
            if (a > n) break;
            ll b = n / a;
            ll cg = k * a * b - a - b;
            maxg = max(maxg, cg);
        }
        cout << k * n - maxg << endl;
    }
}