#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    map<char, char> m, n;
    
    for (int i = 0; i < a.size(); i++) {
        if ((m.count(a[i]) && m[a[i]] != b[i]) || (n.count(b[i]) && n[b[i]] != a[i])) {
            cout << "Failed";
            return 0;
        }
        m[a[i]] = b[i];
        n[b[i]] = a[i];
    }
    
    if (m.size() != 26) {
        cout << "Failed";
        return 0;
    }
    
    for (char ch : c) cout << m[ch];
}