#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (i == 0) {
                    ans.push_back({nums[0], nums[1]});
                    nums.erase(nums.begin());
                    nums.erase(nums.begin());
                    nums.push_back(1);
                    n--;
                    i--;
                }
                else {
                    ans.push_back({nums[i], nums[0]});
                    nums.erase(nums.begin() + i);
                    nums.erase(nums.begin());
                    nums.push_back(1);
                    n--;
                    i--;
                }
            }
        }
        while (n > 1) {
            if (nums[0] != 0 && nums[1] != 0) {
                ans.push_back({nums[0], nums[1]});
                nums.erase(nums.begin());
                nums.erase(nums.begin());
                nums.push_back(0);
                n--;
            } else {
                ans.push_back({nums[0], nums[1]});
                nums.erase(nums.begin());
                nums.erase(nums.begin());
                nums.push_back(0);
                n--;
            }
        }
        if (nums[0] != 0) {
            cout << -1 << endl;
        } else {
            for (auto p : ans) {
                cout << p.first << " " << p.second << endl;
            }
        }
    }
}