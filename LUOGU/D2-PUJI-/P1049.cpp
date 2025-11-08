#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int V, n;
    cin >> V >> n;
    vector<int> vec(n);
    vector<int> dp(V + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = V; j >= vec[i]; j--) {
            dp[j] = max(dp[j], dp[j - vec[i]] + vec[i]);
        }
    }
    cout << V - dp[V] << endl;
    return 0;
}