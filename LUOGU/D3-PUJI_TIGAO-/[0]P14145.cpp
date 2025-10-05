#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> edges;
    int k = ceil(log2(n)); // 层数
    vector<vector<int>> layers(k);

    // 分配节点到层
    int node = 1;
    for (int i = 0; i < k; i++) {
        int layer_size = (n + k - i - 1) / k; // 平均分配节点
        for (int j = 0; j < layer_size && node <= n; j++) {
            layers[i].push_back(node++);
        }
    }

    // 构造层间全连边
    for (int i = 0; i < k-1; i++) {
        for (int u : layers[i]) {
            for (int v : layers[i+1]) {
                edges.emplace_back(u,v);
            }
        }
    }

    // 输出
    cout << edges.size() << "\n";
    for (auto &e : edges) {
        cout << e.first << " " << e.second << "\n";
    }
    return 0;
}
