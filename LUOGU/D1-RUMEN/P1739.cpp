#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int cnt = 0;
    cin >> s;
    for (auto c : s) {
        if (c == '(') cnt++;
        else if (c == ')') cnt--;
        if (cnt < 0) break;
    }
    if (cnt == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}