#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    vector<int> nums(4);
    
    while (T--) {
        for (int i = 0; i < 4; ++i) {
            cin >> nums[i];
        }
        sort(nums.begin(), nums.end());
        bool p = (nums[0] == nums[1] && nums[2] == nums[3]) || 
                        (nums[0] == nums[3] && nums[1] == nums[2]);
        
        p ? cout << "Yes" << endl : cout << "No" << endl;
    }
}