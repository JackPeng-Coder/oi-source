#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MAX_N = 2000000;

int main() {
    int n;
    cin >> n;
    vector<int> lights(MAX_N + 1, 0); // 索引从1到MAX_N

    for (int i = 0; i < n; i++) {
        double a;
        int t;
        cin >> a >> t;
        for (int k = 1; k <= t; k++) {
            int id = (int)(k * a);
            if (id <= MAX_N) {
                lights[id] ^= 1;
            }
        }
    }

    for (int i = 1; i <= MAX_N; i++) {
        if (lights[i] == 1) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}