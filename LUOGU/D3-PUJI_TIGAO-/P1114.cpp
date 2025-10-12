#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> v(n + 1);
    v[0] = 0;
    unordered_map<int, int> mp;
    mp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v[i] = v[i - 1] + (x == 0 ? -1 : 1);
        if (mp.count(v[i])) {
            ans = max(ans, i - mp[v[i]]);
        } else {
            mp[v[i]] = i;
        }
    }
    cout << ans << endl;
    return 0;
}
    