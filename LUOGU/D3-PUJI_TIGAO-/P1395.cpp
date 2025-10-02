#include <iostream>
#include <vector>
using namespace std;

int n = 200005;
int center = -1;
int sum;

vector<int> g[200005];
vector<int> max_subtree = vector<int>(n+1, 0);
vector<int> subtree_size = vector<int>(n+1, 0);

void dfs(int u, int p)
{
    subtree_size[u] = 1;
    max_subtree[u] = 0;
    for (auto v : g[u])
    {
        if (v == p) continue;
        dfs(v, u);
        subtree_size[u] += subtree_size[v];
        max_subtree[u] = max(max_subtree[u], subtree_size[v]);
    }
    max_subtree[u] = max(max_subtree[u], n - subtree_size[u]);
    if (center == -1 || max_subtree[u] < max_subtree[center] || (max_subtree[u] == max_subtree[center] && u < center))
    {
        center = u;
    }
}

void dfs2(int u, int p, int d)
{
    sum += d;
    for (auto v : g[u])
    {
        if (v == p) continue;
        dfs2(v, u, d + 1);
    }
}

int main()
{
    int a, b;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, -1);
    dfs2(center, -1, 0);
    cout << center << " " << sum << endl;
    return 0;
}