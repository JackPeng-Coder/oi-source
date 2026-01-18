#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    vector<ll> pf(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pf[i + 1] = pf[i] + a[i];
    }
    
    vector<int> res;
    for (int k = 3; k <= n; ++k) {
        bool ip = false;
        for (int i = k - 1; i < n; ++i) {
            ll sp = pf[i] - pf[i - k + 1];
            if (sp > a[i]) {
                ip = true;
                break;
            }
        }
        if (ip) {
            res.push_back(k);
        }
    }
    
    for (int i = 0; i < res.size(); ++i) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << endl;
}