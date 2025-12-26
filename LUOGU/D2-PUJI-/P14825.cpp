#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n + 1);
    vector<bool> cpm(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        if (a[i + 1] >= a[i]) cpm[i] = true;
        if (cpm[i - 1] && cpm[i]) cnt++;
    }
    cout << n - cnt << endl;
}