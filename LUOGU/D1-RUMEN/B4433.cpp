#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, T, x, t;
    cin >> n;
    vector<int> v(n + 1), l(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> l[i];
    }
    cin >> T;
    for (int i = 0; i < T; i++) {
        t = 1;
        cin >> x;
        for (int j = 1; j <= n; j++) {
            if (t + l[j] > x) {
                cout << v[j] << endl;
                break;
            }
            t += l[j];
        }
    }
}