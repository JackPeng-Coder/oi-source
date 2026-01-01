#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int r, q, n, m;
        cin >> r >> q >> n >> m;
        
        int lim = (m + 2) / 3;
        
        if (r <= m) {
            cout << "Yes" << endl;
        } else {
            int maxb = min(q * n, r - 1) - min(q, (min(q * n, r - 1) + n - 1) / n) * lim;
            maxb = max(0, maxb);
            
            if (r - maxb <= m) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    
    return 0;
}