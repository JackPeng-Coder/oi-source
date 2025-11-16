#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    vector<int> primes;
    vector<int> mind(mx + 1, 0);
    for (int i = 2; i <= mx; i++) {
        if (!mind[i]) {
        mind[i] = i;
        primes.push_back(i);
        if (1LL * i * i <= mx)
            for (long long j = 1LL * i * i; j <= mx; j += i)
            if (!mind[j])
                mind[j] = i;
        }
    }
    auto factor = [&](long long x) {
        vector<pair<int, int>> f;
        for (int p : primes) {
        if (1LL * p * p > x)
            break;
        if (x % p == 0) {
            int e = 0;
            while (x % p == 0) {
            x /= p;
            e++;
            }
            f.push_back({p, e});
        }
        }
        if (x > 1)
        f.push_back({(int)x, 1});
        return f;
    };
    const long long MOD = 1000000007LL;
    while (q--) {
        int l, r;
        cin >> l >> r;
        long long ans = 0;
        for (int x = l; x <= r; x++) {
        map<int, int> mp0;
        if (a[x] > 1) {
            for (auto pr : factor(a[x]))
            mp0[pr.first] = max(mp0[pr.first], pr.second);
        }
        ans = (ans + (a[x] % MOD)) % MOD;
        for (int y = x + 1; y <= r; y++) {
            map<int, int> mp = mp0;
            if (a[y] > 1) {
            for (auto pr : factor(a[y]))
                mp[pr.first] = max(mp[pr.first], pr.second);
            }
            vector<int> ones;
            vector<int> fixedv;
            for (int i = x; i <= y; i++) {
            if (a[i] == 1)
                ones.push_back(i);
            else
                fixedv.push_back(a[i]);
            }
            vector<long long> divs = {1};
            for (auto &kv : mp) {
            int p = kv.first, e = kv.second;
            int sz = divs.size();
            long long pw = 1;
            for (int t = 1; t <= e; t++) {
                pw *= p;
                for (int i = 0; i < sz; i++)
                divs.push_back(divs[i] * pw);
            }
            }
            long long cnt = 0;
            int k = ones.size();
            if (k == 0) {
            vector<int> b;
            b.reserve(y - x + 1);
            for (int i = x; i <= y; i++)
                b.push_back(a[i]);
            auto fmp = [&](const vector<int> &seq) {
                map<int, int> mpp;
                for (int v : seq)
                if (v > 1)
                    for (auto pr : factor(v))
                    mpp[pr.first] = max(mpp[pr.first], pr.second);
                return mpp;
            };
            auto mpp = fmp(b);
            if (mpp != mp) {
            } else {
                auto good = [&]() {
                for (long long d : divs) {
                    int c = 0;
                    bool in = false;
                    for (int i = x; i <= y; i++) {
                    bool ok = (b[i - x] % d == 0);
                    if (ok) {
                        if (!in) {
                        in = true;
                        }
                    } else {
                        if (in) {
                        c++;
                        in = false;
                        }
                    }
                    }
                    if (in)
                    c++;
                    if (c > 1)
                    return false;
                }
                return true;
                };
                if (good())
                cnt++;
            }
            } else {
            vector<int> b(y - x + 1);
            for (int i = x; i <= y; i++)
                b[i - x] = (a[i] > 1) ? a[i] : 1;
            vector<int> idx = k ? vector<int>(k) : vector<int>();
            for (int mask = 0; mask < (int)pow((double)divs.size(), k); mask++) {
                int t = mask;
                for (int j = 0; j < k; j++) {
                int pick = t % (int)divs.size();
                t /= (int)divs.size();
                b[ones[j] - x] = (int)divs[pick];
                }
                map<int, int> mpp;
                for (int v : b)
                if (v > 1)
                    for (auto pr : factor(v))
                    mpp[pr.first] = max(mpp[pr.first], pr.second);
                if (mpp != mp)
                continue;
                bool ok = true;
                for (long long d : divs) {
                int c = 0;
                bool in = false;
                for (int i = 0; i < (int)b.size(); i++) {
                    bool s = (b[i] % d == 0);
                    if (s) {
                    if (!in)
                        in = true;
                    } else {
                    if (in) {
                        c++;
                        in = false;
                    }
                    }
                }
                if (in)
                    c++;
                if (c > 1) {
                    ok = false;
                    break;
                }
                }
                if (ok)
                cnt++;
            }
            }
            ans = (ans + cnt) % MOD;
            mp0 = mp;
        }
        }
        cout << ans % MOD << "\n";
    }
    return 0;
}