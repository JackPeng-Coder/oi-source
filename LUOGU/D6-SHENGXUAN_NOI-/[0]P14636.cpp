#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int c, t, n, m;
    cin >> c >> t >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> t;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        i *= 2;
        i %= 998244353;
    }
}