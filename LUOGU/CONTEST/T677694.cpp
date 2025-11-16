#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        int segment = 1;
        int start = 0;
        int end;
        bool valid = true;
        while (start < n) {
            if (vec[start] < segment) {
                valid = false;
                break;
            }
            end = start;
            while (end + 1 < n) {
                if (vec[end + 1] > vec[end] || vec[end + 1] < segment) {
                    break;
                }
                end++;
            }
            start = end + 1;
            segment++;
        }
        if (valid) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}