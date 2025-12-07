#include <bits/stdc++.h>
using namespace std;

int main() {
    long long T, n, r, l = -1, i;
    cin >> T;
    while (T--) {
        cin >> n;
        r = n;
        for (i = 0; (1 << i) <= n; i++) {
            if ((n >> i & 1) == 0) {
                r += (1 << (i + 1));
                l = i;
            }
        }
        if (i - l == 2) {
            // r -= (1 << (l + 1));
            cout << n << endl;
        } else {
            cout << r << endl;
        }
    }
}