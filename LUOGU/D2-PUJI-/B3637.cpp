#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<int> dp(n);
    vector<int> tail;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(tail.begin(), tail.end(), vec[i]);
        if (it == tail.end()) {
            tail.push_back(vec[i]);
        } else {
            *it = vec[i];
        }
    }
    cout << tail.size() << endl;
}