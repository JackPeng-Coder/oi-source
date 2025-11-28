#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, max = 0, min = 2e9, max2 = 0; // 次大值
        bool zero = false;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
            if (vec[i] == 0) zero = true;
            if (min > vec[i]) min = vec[i];
            if (max < vec[i]) {
                max2 = max;
                max = vec[i];
            } else if (max2 < vec[i] && vec[i] != max) {
                max2 = vec[i];
            }
        }
        if (zero) cout << max << endl;
        else if (max2 > max - min && n > 1) cout << max2 << endl;
        else cout << max << " " << min << endl;
    }
}