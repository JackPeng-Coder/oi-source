#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> G(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({w, v});
        G[v].push_back({w, u});
    }
    vector<bool> vis(N + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vis[1] = true;
    for (auto [w, v] : G[1]) {
        pq.push({w, v});
    }
    int ans = 0;
    int cnt = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        ans += w;
        cnt++;
        for (auto [w, v] : G[u]) {
            if (!vis[v]) {
                pq.push({w, v});
            }
        }
    }
    if (cnt != N - 1) {
        cout << "orz" << endl;
    } else {
        cout << ans << endl;
    }
}