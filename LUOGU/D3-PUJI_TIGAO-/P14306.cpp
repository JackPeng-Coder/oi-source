#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c, T;
    cin >> c >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long ans = LLONG_MIN;
        long long min_val = LLONG_MAX;
        
        for (int i = 0; i < n; i++) {
            min_val = min(min_val, 1LL * k * i - a[i]);
            long long harmony = 1LL * k * (i + 1) - a[i] - min_val;
            ans = max(ans, harmony);
        }
        cout << ans << "\n";
    }
    return 0;
}