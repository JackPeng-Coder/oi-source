#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int,int> max_c;
        for (int i = 0; i < n; ++i) {
            int r, c;
            cin >> r >> c;
            if (max_c.count(r)) {
                max_c[r] = max(max_c[r], c);
            } else {
                max_c[r] = c;
            }
        }
        vector<int> tasks;
        for (auto &p : max_c) {
            int cost = 2 * p.first + 2 * p.second;
            tasks.push_back(cost);
        }
        sort(tasks.rbegin(), tasks.rend());
        long long sum1 = 0, sum2 = 0;
        for (int t : tasks) {
            if (sum1 <= sum2) sum1 += t;
            else sum2 += t;
        }
        long long ans = max(sum1, sum2);
        cout << ans << "\n";
    }
    return 0;
}
