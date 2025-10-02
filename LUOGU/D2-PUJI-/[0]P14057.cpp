#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        ll m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // stack of blocks: pair(sum, val=min(sum,m))
        vector<pair<ll,ll>> st;
        st.reserve(n);

        for (int i = 0; i < n; ++i) {
            ll s = a[i];
            ll v = min(s, m);
            st.emplace_back(s, v);

            // merge while previous block's val > current block's val
            while (st.size() >= 2) {
                int sz = (int)st.size();
                if (st[sz-2].second > st[sz-1].second) {
                    ll new_sum = st[sz-2].first + st[sz-1].first;
                    ll new_val = min(new_sum, m);
                    st.pop_back();
                    st.pop_back();
                    st.emplace_back(new_sum, new_val);
                } else break;
            }
        }

        ll ans = 0;
        for (auto &p : st) ans += p.second;
        cout << ans << '\n';
    }

    return 0;
}