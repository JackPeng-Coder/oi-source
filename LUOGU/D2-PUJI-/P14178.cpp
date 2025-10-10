#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n, s, t;
        cin >> n >> s >> t;
        vector<long long> a(n  + 1);
        for (int i=1; i<=n; i++) {
            cin >> a[i];
        }
        if (s == t) {
            cout << 0 << endl;
        } else {
            long long ans = 2 * (a[s] | a[t]);
            cout << ans << endl;
        }
    }
    return 0;
}