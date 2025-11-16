#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<unsigned long long> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    const unsigned long long MOD = 998244353ULL;
    const unsigned long long MASK = (1ULL << 25) - 1;
    unsigned long long ans = 0;
    for (int l = 1; l <= n; l++) {
        unsigned long long best = a[l];
        ans = (ans + best) % MOD;
        for (int r = l + 1; r <= n; r++) {
        unsigned long long cur = 0;
        for (int i = l; i <= r; i++)
            for (int j = l; j <= r; j++)
            if (i != j) {
                unsigned long long eor = 0;
                for (int k = l; k <= r; k++)
                if (k != i && k != j)
                    eor |= a[k];
                unsigned long long mask = ((~a[j]) & MASK) | eor;
                unsigned long long val = a[i] & mask;
                if (val > cur)
                cur = val;
            }
        ans = (ans + cur) % MOD;
        }
    }
    cout << ans % MOD << "\n";
    return 0;
}