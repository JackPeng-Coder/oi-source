#include <iostream>
#include <cstring>
using namespace std;

int fa[200005];
int h[200005];

int find(int x) {
    if (x == fa[x]) return x;
    else return fa[x] = find(fa[x]);
}

int main() {
    int n, m, z, x, y;
    cin >> n >> m;
    for (int i = 0; i < n; i++) fa[i] = i;
    memset(h, 0, n * 4);
    for (int i = 0; i < m; i++) {
        cin >> z >> x >> y;
        if (z == 2) {
            if (find(x) == find(y)) cout << "Y" << endl;
            else cout << "N" << endl;
        } else {
            x = find(x), y = find(y);
            if (h[x] < h[y]) fa[x] = y;
            else if (h[x] > h[y]) fa[y] = x;
            else {
                fa[x] = y;
                h[y]++;
            }
        }
    }
}