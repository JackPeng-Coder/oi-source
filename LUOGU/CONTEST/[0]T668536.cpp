#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, x0, xi;
    cin >> n >> q >> x0;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    while (q--) {
        cin >> xi;
        cout << min(abs(x0 - a[0].first), abs(x0 - a[0].second)) + min(abs(xi - a[0].first), abs(xi - a[0].second)) << endl;
    }
}