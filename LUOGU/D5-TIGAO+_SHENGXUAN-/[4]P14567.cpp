#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> c(n + 1), v(n + 1), f(n + 1);
    map<int, int> stat;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        if (stat.find(c[i]) == stat.end()) {
            stat[c[i]] = 0;
        }
        stat[c[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    int start = 1, end = 1;
    map<int, int> tmp_stat;
    vector<pair<int, int>> res_interval;
    int cnt = 0;
    while (end <= n) {
        if (tmp_stat.find(c[end]) == tmp_stat.end()) {
            tmp_stat[c[end]] = 0;
            cnt++;
        }
        tmp_stat[c[end]]++;
        if (tmp_stat[c[end]] == stat[c[end]]) {
            cnt--;
        }
        end++;
        if (cnt == 0 && start != end) {
            res_interval.push_back({start, end - 1});
            start = end;
        }
    }
    int res = 0x3f3f3f3f;
    for (auto p : res_interval) {
        int l = p.first, r = p.second;
        int sum = 0;
        for (int i = l; i <= r; i++) {
            sum += v[i] * f[i - l + 1];
        }
        res = min(res, sum);
    }
    cout << res << endl;

}
