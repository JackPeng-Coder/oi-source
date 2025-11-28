#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<long long> vec(n + 2, 0);
        for (int i = 1; i <= n; i++) {
            cin >> vec[i];
        }
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + vec[i];
        }
        
        for (int m = 1; m < n; m++) {
            long long sumL = prefix[m];
            long long sumR = prefix[n] - prefix[m];
            
            if (vec[m] > vec[m + 1]) {
                if (m == n - 1) {
                    sumL += vec[m + 1];
                    sumR -= vec[m + 1];
                } else if (vec[m] + vec[m + 1] > vec[m + 2]) {
                    sumL += vec[m + 1];
                    sumR -= vec[m + 1];
                }
            }
            
            cout << (sumL > sumR ? '1' : '0');
        }
        cout << endl;
    }
    return 0;
}