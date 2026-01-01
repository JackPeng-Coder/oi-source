#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, p, d;
    string s;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while (m--) {
        cin >> p >> d >> s;
        if (s == "Completed") a[p] = d;
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
}