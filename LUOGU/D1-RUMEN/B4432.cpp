#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << "x";
    for (int i = 0; i < m / 4; i++) {
        cout << ".xxx";
    }
    cout << endl;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m; j += 2) {
            cout << "x.";
        }
        cout << "x" << endl;
    }
    for (int i = 0; i < m / 4; i++) {
        cout << "xxx.";
    }
    cout << "x" << endl;
}