#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t = 0, s;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < v[i].size(); j++) {
            s = 0;
            for (int k = 0; k < n; k++) {
                if (i == k) continue;
                if (v[k].size() < j) continue;
                if (v[i].substr(0, j) == v[k].substr(0, j)) {
                    s++;
                    break;
                }
            }
            for (int k = 0; k < n; k++) {
                if (i == k) continue;
                if (v[k].size() < v[i].size() - j) continue;
                if (v[i].substr(j) == v[k].substr(v[k].size() - (v[i].size() - j))) {
                    s++;
                    break;
                }
            }
            if (s >= 2) {
                t++;
                break;
            }
        }
    }
    cout << t << endl;
}