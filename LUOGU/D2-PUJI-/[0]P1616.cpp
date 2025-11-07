#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T, M;
    cin >> T >> M;
    vector<pair<int, int>> vec(M);
    vector<int> dp(T + 1);
    for (int i = 0; i < M; i++) {
        cin >> vec[i].first >> vec[i].second;
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j <= T - vec[i].first; j++) {
            dp[j] = max(dp[j], dp[j - vec[i].first] + vec[i].second);
        }
    }
    cout << dp[T] << endl;
}