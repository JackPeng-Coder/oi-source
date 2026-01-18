#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull; 
vector<int> gab(int mask, int len) {
    vector<int> res;
    for (int i = 0; i < len; ++i) {
        if (mask & (1 << i)) {
            res.push_back(i);
        }
    }
    return res;
}
ull pu(ull a, int k) {
    ull res = 1;
    for (int i = 0; i < k; ++i) {
        res *= a;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> c(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> c[i][j];
            }
        }
        vector<vector<vector<vector<int>>>> val(n, vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(m, 0))));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) { 
                for (int u = 0; u < m; ++u) {
                    for (int v = u + 1; v < m; ++v) { 
                        int A = c[i][u]; 
                        int B = c[i][v]; 
                        int C = c[j][u]; 
                        int D = c[j][v]; 
                        if (A == D && C == B && A != B) {
                            val[i][j][u][v] = 1;
                        } else {
                            val[i][j][u][v] = 0;
                        }
                    }
                }
            }
        }
        int mmc = 1 << m;
        vector<vector<vector<int>>> cc(n, vector<vector<int>>(n, vector<int>(mmc, 0)));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) { 
                for (int mc = 0; mc < mmc; ++mc) {
                    vector<int> cols = gab(mc, m);
                    int cnt = 0;
                    for (int x = 0; x < cols.size(); ++x) {
                        for (int y = x + 1; y < cols.size(); ++y) {
                            int u = cols[x];
                            int v = cols[y];
                            cnt += val[i][j][u][v];
                        }
                    }
                    cc[i][j][mc] = cnt;
                }
            }
        }

        
        int mmr = 1 << n;
        vector<vector<int>> rs(mmr, vector<int>(mmc, 0));
        for (int mr = 0; mr < mmr; ++mr) {
            vector<int> rows = gab(mr, n);
            for (int x = 0; x < rows.size(); ++x) {
                for (int y = x + 1; y < rows.size(); ++y) {
                    int i = rows[x];
                    int j = rows[y];
                    
                    for (int mc = 0; mc < mmc; ++mc) {
                        rs[mr][mc] += cc[i][j][mc];
                    }
                }
            }
        }
        vector<ull> cnt(10000, 0); 
        int mg = 0;
        for (int mr = 0; mr < mmr; ++mr) {
            for (int mc = 0; mc < mmc; ++mc) {
                int g = rs[mr][mc];
                cnt[g]++;
                mg = max(mg, g);
            }
        }
        ull ans = 0;
        for (int i = 0; i <= mg; ++i) {
            if (cnt[i] == 0) continue;
            ans += pu(cnt[i], k);
        }
        cout << ans << '\n';
    }
}