#include <iostream>
#include <vector>
using namespace std;

const int inf = 1e9;

int main() {
    int n, m, u, v, w;
    cin >> n >> m;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, inf));
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        if (w < graph[u][v])
        {
            graph[u][v] = w;
            graph[v][u] = w;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    for (int u = 1; u <= n; u++) {
        for(int v = 1; v <= n; v++) {
            cout << graph[u][v] << " ";
        }
        cout << endl;
    }
}