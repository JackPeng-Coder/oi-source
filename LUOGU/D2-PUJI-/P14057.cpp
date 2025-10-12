#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 1e5 + 10;
int a[MAX_SIZE];

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, m;
        cin >> n >> m;
        
        long long sum = 0;
        int min1 = 0x40000000, min2 = 0x40000000;
        bool isOK = true;
        
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
            
            if (a[i] <= min1) {
                min2 = min1;
                min1 = a[i];
            } else if (a[i] < min2) {
                min2 = a[i];
            }
            
            if (i > 1 && a[i] < a[i - 1]) {
                isOK = false;
            }
        }
        
        if (isOK) {
            cout << sum << '\n';
        } else {
            cout << sum - max(0, min1 + min2 - m) << '\n';
        }
    }
    
    return 0;
}
