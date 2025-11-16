// T658339 猜数游戏 guess
// 解法：
// - 预处理 gcd(a)。若 gcd != 1，则无法将区间缩到 1，答案为 -1。
// - 计算 dpDist[d]：使用步长集合 {±a_i}，到达净位移 d 的最小代价（Dijkstra 在 0..Amax 范围）。
// - 预计算 costQuery[s]：一次询问覆盖 s 个位置的最小代价，等于 min_i{ dpDist[a_i - s] + b_i }（需要 a_i >= s）。
// - 双端 DP：F[L], G[L]（左端/右端），
//   F[L] = min_{1<=s<=min(L-1, Amax)} { costQuery[s] + max(G[s], F[L-s]) }
//   G[L] = min_{1<=s<=min(L-1, Amax)} { costQuery[s] + max(F[s], G[L-s]) }
//   基础 F[1]=G[1]=0。
// 复杂度：O(n * Amax + Amax * m)，其中 Amax = max(a_i) ≤ 1000。

// 兼容 Clang/非 GNU 环境：不使用 <bits/stdc++.h> 与 C++17 特性
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstdint>
using namespace std;

static const long long INF = (1LL<<60);

static inline int gcd_int(int a, int b) {
    while (b) { int t = a % b; a = b; b = t; }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, T;
    if (!(cin >> c >> T)) {
        return 0;
    }
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        vector<long long> b(m);
        for (int i = 0; i < m; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];

        // gcd check
        int g = 0;
        for (int i = 0; i < m; ++i) g = gcd_int(g, a[i]);
        if (g != 1) {
            cout << -1 << '\n';
            continue;
        }

        int Amax = 0;
        for (int x : a) Amax = max(Amax, x);

        // Dijkstra on states 0..Amax to compute minimal cost for net displacement d
        vector<long long> dist(Amax + 1, INF);
        dist[0] = 0;
        typedef pair<long long,int> P;
        priority_queue<P, vector<P>, greater<P> > pq;
        pq.push(P(0LL, 0));
        while (!pq.empty()) {
            P tp = pq.top(); pq.pop();
            long long du = tp.first; int u = tp.second;
            if (du != dist[u]) continue;
            for (int i = 0; i < m; ++i) {
                int len = a[i];
                long long cost = b[i];
                // move +len
                int v = u + len;
                if (v <= Amax && dist[v] > du + cost) {
                    dist[v] = du + cost;
                    pq.push(P(dist[v], v));
                }
                // move -len
                v = u - len;
                if (v >= 0 && dist[v] > du + cost) {
                    dist[v] = du + cost;
                    pq.push(P(dist[v], v));
                }
            }
        }

        // costQuery[s]
        int Smax = min(Amax, n - 1);
        vector<long long> costQuery(Smax + 1, INF);
        for (int s = 1; s <= Smax; ++s) {
            long long best = INF;
            for (int i = 0; i < m; ++i) {
                if (a[i] >= s) {
                    int d = a[i] - s; // outside offset needed
                    if (dist[d] < INF) {
                        best = min(best, dist[d] + b[i]);
                    }
                }
            }
            costQuery[s] = best;
        }

        // DP F, G
        vector<long long> F(n + 1, INF), G(n + 1, INF);
        F[1] = 0; G[1] = 0;
        for (int L = 2; L <= n; ++L) {
            long long bestF = INF, bestG = INF;
            int up = min(Smax, L - 1);
            for (int s = 1; s <= up; ++s) {
                long long cq = costQuery[s];
                if (cq >= INF) continue;
                // Left anchored -> split s
                long long candF = cq + max(G[s], F[L - s]);
                if (candF < bestF) bestF = candF;
                // Right anchored -> split s
                long long candG = cq + max(F[s], G[L - s]);
                if (candG < bestG) bestG = candG;
            }
            F[L] = bestF;
            G[L] = bestG;
        }

        long long ans = F[n];
        if (ans >= INF/2) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}