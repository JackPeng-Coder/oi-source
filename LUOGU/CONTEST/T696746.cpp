#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, r, t, p;
    cin >> N;
    map<pair<int, int>, int> MAP;
    for (int i = 0; i < N; i++) {
        cin >> r >> t >> p;
        if (MAP.find({t, p}) == MAP.end()) {
            MAP[{t, p}] = r;
        } else if (MAP[{t, p}] > r) {
            MAP[{t, p}] = r;
        }
    }
    int max = 0;
    for (auto r : MAP) {
        if (r.second > max) max = r.second;
    }
    cout << max << endl;
}