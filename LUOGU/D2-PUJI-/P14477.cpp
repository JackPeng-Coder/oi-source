#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    cout << a + (n - a - b) / (a + 1) * a + (n - a - b - (n - a - b) / (a + 1) * (a + 1)) << endl;
}