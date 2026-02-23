#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, x, g = 0, ans = 0;
        cin >> n >> m;
        unordered_map<int, int> cnt;
        long long tot = 0;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            cnt[x]++;
            tot += x;
        }
        for (auto& p : cnt) {
            g = gcd(g, p.second);
        }
        for (int k = 1; k <= m; ++k) {
            if ((1LL * k * tot) % n != 0) {
                continue;
            }
            int d = gcd(n, k);
            int s = n / d;
            if (g % s == 0) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}