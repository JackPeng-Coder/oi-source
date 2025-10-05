#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Union-Find for connectivity check
struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n + 1), rank(n + 1, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }
    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (rank[pu] < rank[pv]) swap(pu, pv);
        parent[pv] = pu;
        if (rank[pu] == rank[pv]) ++rank[pu];
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<int> p(n + 1);
        iota(p.begin() + 1, p.end(), 1);
        ll max_f = LLONG_MIN;
        vector<int> best_p(n + 1);
        do {
            ll sum = 0;
            DSU dsu(n);
            int edges = 0;
            for (int i = 1; i < n; ++i) {
                for (int j = i + 1; j <= n; ++j) {
                    if (p[i] > p[j]) {
                        sum += a[j];
                        if (dsu.unite(i, j)) ++edges;
                    }
                }
            }
            // Check if graph is connected (n-1 edges in a tree)
            if (edges == n - 1 && dsu.find(1) == dsu.find(n) && sum > max_f) {
                max_f = sum;
                copy(p.begin() + 1, p.end(), best_p.begin() + 1);
            }
        } while (next_permutation(p.begin() + 1, p.end()));
        cout << max_f << '\n';
        for (int i = 1; i <= n; ++i)
            cout << best_p[i] << (i < n ? ' ' : '\n');
    }
    return 0;
}