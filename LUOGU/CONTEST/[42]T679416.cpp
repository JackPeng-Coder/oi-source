#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    ll sum, res = -2e18;
    cin >> n >> m;
    vector<vector<ll>> matrix(n + 1, vector<ll>(m + 1, 0));
    vector<vector<ll>> prefix(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + matrix[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                for (int l = k; l <= m; l++) {
                    sum = prefix[j][l] - prefix[i - 1][l] - prefix[j][k - 1] + prefix[i - 1][k - 1];
                    res = max(res, sum * min(j - i + 1, l - k + 1));
                }
            }
        }
    }
    cout << res << endl;
}