#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d, s, t, h, s0, t0, h0;
    cin >> n >> d;
    cin >> s0 >> t0 >> h0;
    for (int i = 1; i <= n; i++) {
        cin >> s >> t >> h;
        if (abs(h - h0) > d) {
            cout << "No" << endl;
            continue;
        }
        if (s - s0 == t - t0) {
            if (s == s0) {
                cout << "Always" << endl;
            } else {
                cout << "No" << endl;
            }
        } else {
            double x = (double)(s0 - s) / ((double)(s0 - s) - (double)(t0 - t));
            if (x < 0 || x > 1) {
                cout << "No" << endl;
            } else {
                cout << x * (t0 - s0) + s0 << endl;
            }
        }
    }
}