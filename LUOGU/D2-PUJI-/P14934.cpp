#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, x;
    cin >> n >> m;
    long long min, max;
    cin >> x;
    min = max = x;
    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x < min) min = x;
        if (x > max) max = x;
    }
    cout << (max - min + m - 1) / m << endl;
}