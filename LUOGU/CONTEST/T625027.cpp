#include <bits/stdc++.h>
using namespace std;

int main() {
    long long T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        n = sqrt(n);
        cout << n / 3 << endl;
    }
}