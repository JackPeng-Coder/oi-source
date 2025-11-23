#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, t = 0;
    cin >> n;
    cin >> b;
    for (int i = 1; i < n; i++) {
        a = b;
        cin >> b;
        if (abs(a - b) % 2) t++;
    }
    cout << t << endl;
}