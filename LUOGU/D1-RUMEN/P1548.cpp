#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    long long rect = n * (n + 1) / 2 * m * (m + 1) / 2;
    long long square = 0;
    for (int i = 0; i < min(n, m); i++) {
        square += (n - i) * (m - i);
    }
    cout << square << " " << rect - square << endl;
}