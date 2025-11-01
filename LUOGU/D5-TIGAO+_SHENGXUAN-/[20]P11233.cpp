#include <iostream>
#include <vector>
using namespace std;

int get(int x, int d) {
    return ((x >> d) & 1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, tot = 0, max = 0;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        for (int i = 0; i < (1 << n); i++) {
            tot = 0;
            for (int j = 0; j < n; j++) {
                int c = get(i, j);
                for (int k = j - 1; k >= 0; k--) {
                    if (get(i, k) == c) {
                        if (vec[j] == vec[k]) {
                            tot += vec[j];
                        }
                        break;
                    }
                }
            }
            if (max < tot) max = tot;
        }
        cout << max << endl;
    }
}