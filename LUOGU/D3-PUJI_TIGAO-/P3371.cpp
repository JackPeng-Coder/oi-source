#include <iostream>
#include <utility>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;
const ll inf = 2147483647;

int main() {
    ll n, m, s, u, v, w;
    cin >> n >> m >> s;
    vector<vector<pair<ll, ll>>> graph(n + 1, vector<pair<ll, ll>>());
    queue<ll> q;
    q.push(s);
    vector<bool> sign(n + 1, false); // in queue
    vector<ll> dist(n + 1, inf);
    for (ll i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    dist[s] = 0;
    sign[s] = true;
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        sign[u] = false;
        // if (sign[u]) continue;
        // sign[u] = true;
        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!sign[v]) {
                    q.push(v);
                    sign[v] = true;
                }
            }
        }
    }
    
    for (int i = 1; i < dist.size(); i++) {
        cout << dist[i] << " ";
    }
}
