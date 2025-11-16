#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, sum = 0;
        cin >> n;
        vector<int> amounts(n);
        for (int i = 0; i < n; i++) {
            cin >> amounts[i];
            sum += amounts[i];
        }
        int lsum = 0, ksum = sum;
        for (int i = 1; i < n; i++) {
            lsum += amounts[i];
            ksum -= amounts[i];
            if (lsum <= ksum) {
                cout << 0;
            } else {
                cout << 1;
            }
        }
        cout << endl;
    }
}