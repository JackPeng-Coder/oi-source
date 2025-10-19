#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        
        long long ans0 = 0;
        int flip_count = 0;
        
        for (int i = 0; i < n; i++) {
            int current = s[i] - '0';
            current = (current + flip_count) % 2;
            
            if (current == 1) {
                ans0 += (i + 1);
                flip_count = (flip_count + 1) % 2;
            }
        }
        
        long long ans1 = 0;
        flip_count = 0;
        
        for (int i = 0; i < n; i++) {
            int current = s[i] - '0';
            current = (current + flip_count) % 2;
            
            if (current == 0) {
                ans1 += (i + 1);
                flip_count = (flip_count + 1) % 2;
            }
        }
        
        cout << min(ans0, ans1) << "\n";
    }
    
    return 0;
}