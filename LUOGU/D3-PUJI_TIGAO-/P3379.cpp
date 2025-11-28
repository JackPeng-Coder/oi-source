#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000010;
vector<int> head(MAXN, 0), nxt(MAXN*2), to(MAXN*2);
int cnt = 0;
int root;

vector<int> deep(MAXN, -1);
vector<vector<int>> st(MAXN, vector<int>(16));

void add(int from, int to_) {
    cnt++;
    to[cnt] = to_;
    nxt[cnt] = head[from];
    head[from] = cnt;
}

void dfs(int node, int parent) {
    // if (deep[node] != -1) return;
    if (node == root) deep[node] = 1;
    else deep[node] = deep[parent] + 1;
    st[node][0] = parent;
    for (int step = 1; step < 15; step++) {
        st[node][step] = st[st[node][step - 1]][step - 1];
    }
    for (int edge = head[node]; edge != 0; edge = nxt[edge]) {
        int v = to[edge];
        if (v != parent) {
            dfs(v, node);
        }
    }
}

int get(int a, int b) {
    if (deep[a] < deep[b]) {
        swap(a, b);
    }
    for (int step = 14; step >= 0; step--) {
        if (deep[a] - (1 << step) >= deep[b]) {
            a = st[a][step];
        }
    }
    if (a == b) return a;
    for (int step = 14; step >= 0; step--) {
        if (st[a][step] != st[b][step]) {
            a = st[a][step];
            b = st[b][step];
        }
    }
    return st[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M, S, u, v;
    cin >> N >> M >> root;
    for (int i = 1; i < N; i++) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(root, root);
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        cout << get(u, v) << endl;
    }
}
