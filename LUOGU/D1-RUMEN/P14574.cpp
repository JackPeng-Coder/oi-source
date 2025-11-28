#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k, l, r;
    cin >> n >> m >> k >> l >> r;
    
    vector<vector<int>> scores(n + 1, vector<int>(m + 1, 0));
    vector<vector<bool>> informed(n + 1, vector<bool>(m + 1, false));
    
    for (int i = 0; i < k; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        scores[x][y] = v;
        informed[x][y] = true;
    }
    
    for (int i = 1; i <= n; i++) {
        int total = 0;
        for (int j = 1; j <= m; j++) {
            if (informed[i][j]) {
                int v = scores[i][j];
                if (v <= l) {
                    total += 100;
                } else if (v >= r) {
                    total += 0;
                } else {
                    total += v;
                }
            } else {
                total += 0;
            }
        }
        cout << total;
        if (i < n) cout << " ";
    }
    cout << endl;
    
    return 0;
}