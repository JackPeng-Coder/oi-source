#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int g = gcd(n, m);
    int res = 0;
    
    for (int d = 0; d < g; ++d) {
        int ar = 0, ap = 0, as = 0;
        for (int i = d; i < n; i += g) {
            if (a[i] == 'R') ar++;
            else if (a[i] == 'P') ap++;
            else as++;
        }
        int br = 0, bp = 0, bs = 0;
        for (int j = d; j < m; j += g) {
            if (b[j] == 'R') br++;
            else if (b[j] == 'P') bp++;
            else bs++;
        }
        int lenA = ar + ap + as;
        int lenB = br + bp + bs;
        int minc = 1e9;
        
        minc = min(minc, (lenA - ar) + (lenB - bp)); 
        minc = min(minc, (lenA - ar) + (lenB - bs)); 
        minc = min(minc, (lenA - ap) + (lenB - br)); 
        minc = min(minc, (lenA - ap) + (lenB - bs)); 
        minc = min(minc, (lenA - as) + (lenB - br)); 
        minc = min(minc, (lenA - as) + (lenB - bp)); 
        
        minc = min(minc, (lenA - ar) + (lenB - (bp + bs))); 
        minc = min(minc, (lenA - ap) + (lenB - (br + bs))); 
        minc = min(minc, (lenA - as) + (lenB - (br + bp))); 
        
        minc = min(minc, (lenA - (ar + ap)) + (lenB - bs)); 
        minc = min(minc, (lenA - (ar + as)) + (lenB - bp)); 
        minc = min(minc, (lenA - (ap + as)) + (lenB - br)); 
        
        res += minc;
    }
    cout << res << endl;
    return 0;
}
    