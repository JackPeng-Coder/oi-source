#include <iostream>
using namespace std;
typedef long long ll;

ll arr[100005], seg[400020], lzy[400020];

void build(int u, int l, int r) {
    if (l == r) {
        seg[u] = arr[l];
        return;
    }
    int m = (l + r) / 2;
    build(u * 2, l, m);
    build(u * 2 + 1, m + 1, r);
    seg[u] = seg[u * 2] + seg[u * 2 + 1];
}

void maketag(int u, int len, ll x) {
    lzy[u] += x;
    seg[u] += len * x;
}

void pushdown(int u, int L, int R) {
    int M = (L + R) / 2;
    maketag(u * 2, M - L + 1, lzy[u]);
    maketag(u * 2 + 1, R - M, lzy[u]);
    lzy[u] = 0;
}

// L, R是递归查询用的
ll query(int u, int L, int R, const int l, const int r) {
    if (L >= l && R <= r) return seg[u];
    else if (L > r || R < l) return 0;
    else {
        int M = (L + R) / 2;
        pushdown(u, L, R);
        return query(u * 2, L, M, l, r) + query(u * 2 + 1, M + 1, R, l, r);
    }
}

void update(int u, int L, int R, int l, int r, ll x) {
    if (L >= l && R <= r) {
        maketag(u, R - L + 1, x);
    } else if (!(L > r || R < l)) {
        int M = (L + R) / 2;
        pushdown(u, L, R);
        update(u * 2, L, M, l, r, x);
        update(u * 2 + 1, M + 1, R, l, r, x);
        seg[u] = seg[u * 2] + seg[u * 2 + 1];
    }
}

int main() {
    int n, m, op, l, r;
    ll x;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    build(1, 0, n - 1);

    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == 2) {
            cin >> l >> r;
            cout << query(1, 0, n - 1, l - 1, r - 1) << endl;
        } else {
            cin >> l >> r >> x;
            update(1, 0, n - 1, l - 1, r - 1, x);
        }
    }
}