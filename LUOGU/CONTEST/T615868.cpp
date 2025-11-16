#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    vector<vector<int>> ch(n + 1);
    vector<long long> L(n + 1), R(n + 1);
    for (int i = 2; i <= n; i++) {
        int p;
        long long l, r;
        cin >> p >> l >> r;
        ch[p].push_back(i);
        L[i] = l;
        R[i] = r;
    }
    vector<char> op(n + 1);
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> op[i] >> a[i];
    }
    while (q--) {
        long long x;
        cin >> x;
        long long ans = 0;
        vector<pair<int, long long>> st;
        st.reserve(n);
        st.emplace_back(1, x);
        while (!st.empty()) {
            auto [u, cur] = st.back();
            st.pop_back();
            long long nxt = (op[u] == '+') ? (cur + a[u]) : (cur - a[u]);
            ans++;
            for (int v : ch[u])
                if (L[v] <= nxt && nxt <= R[v])
            st.emplace_back(v, nxt);
        }
        cout << ans << "\n";
    }
    return 0;
}