#include <bits/stdc++.h>
using namespace std;

int binary_search(const vector<int>& vec, int x) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] >= x) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, res = 0;
        cin >> n;
        vector<int> array(n + 1);
        vector<int> prefix(n + 1);
        unordered_map<int, vector<int>> map;
        prefix[0] = 0;
        map[0].push_back(0);
        for (int i = 1; i <= n; i++) {
            cin >> array[i];
            prefix[i] = prefix[i - 1] + array[i];
            if (map.find(prefix[i]) == map.end()) {
                map[prefix[i]] = {i};
            }
            else {
                map[prefix[i]].push_back(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            int ans = map[prefix[i - 1]].size() - binary_search(map[prefix[i - 1]], i);
            if (ans > res) {
                res = ans;
            }
        }
        cout << res << endl;
    }
}