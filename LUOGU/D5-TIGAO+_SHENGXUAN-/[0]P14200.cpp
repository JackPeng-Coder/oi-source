#include <bits/stdc++.h>
using namespace std;

vector<int> *p;

int g(int l, int r) {
    int res = (*p)[l];
    for (int i = l + 1; i <= r; i++) {
        res &= (*p)[i];
    }
    return res;
}

int f(int r, int x) {
    for (int l = 1; l <= r; l++) {
        if (g(l, r) == x) {
            return l;
        }
    }
    return -1;
}

int a(int i, int n) {
    int res = 0;
    for (int r = i; r <= n; r++) {
        res ^= (i - f(r, g(i, r)) + 1);
    }
    return res;
}

int main() {
    int n, m, res = 0;
    cin >> n >> m;
    vector<int> A(n + 1);
    p = &A;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        res += a(i, n);
        res %= m;
    }
    cout << res;
}