#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        double n, m;
        cin >> n >> m;
        cout << min(n - 1, n - ceil(m / (n - 1))) << " ";
        if (m <= floor(n / 4 * n)) cout << ceil(n / 2) << endl;
        else cout << n - floor((1 + sqrt(1 + 8 * m)) / 2) << endl;
    }
}