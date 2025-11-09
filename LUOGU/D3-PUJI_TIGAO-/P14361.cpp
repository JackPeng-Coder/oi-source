#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<pair<int, int>>> list(n, vector<pair<int, int>>(3));
        vector<vector<pair<int, int>>> list_unsort(n, vector<pair<int, int>>(3));
        vector<priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>> pqs(3);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> list[i][j].first; // 第i个人的第j大满意度的值和部门编号
                list[i][j].second = j;
                list_unsort[i][j] = list[i][j];
            }
            sort(list[i].begin(), list[i].end(), greater<pair<int, int>>());
        }

        for (int i = 0; i < n; i++) {
            pqs[list[i][0].second].push({list[i][0].first - list[i][1].first, i}); // 第j个部门的{损失值, 人编号}
        }

        for (int i = 0; i < 3; i++) {
            while (pqs[i].size() > n / 2) {
                pqs[list[pqs[i].top().second][1].second].push(pqs[i].top());
                pqs[i].pop();
            }
        }
        
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            while (!pqs[i].empty()) {
                sum += list_unsort[pqs[i].top().second][i].first;
                pqs[i].pop();
            }
        }
        cout << sum << endl;
    }
}