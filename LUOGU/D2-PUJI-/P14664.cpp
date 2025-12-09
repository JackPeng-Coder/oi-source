#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long T;
    unsigned int n;
    cin >> T;
    while (T--) {
        cin >> n;
        unsigned int a = n, b = 0;
        unsigned int n2 = n;
        
        for (int i = 31; i >= 0; --i) {
            unsigned int nw = 1U << i;
            if (nw > n2) continue;
            
            if ((n & nw) == 0) {
                if (a + nw <= n2 && b + nw <= n2) {
                    a += nw;
                    b += nw;
                }
            } else {
                if (abs((int)(a - nw) - (int)(b + nw)) < abs((int)(a - b))) {
                    a -= nw;
                    b += nw;
                }
            }
        }
        
        cout << (a + b) << '\n';
    }
    return 0;
}