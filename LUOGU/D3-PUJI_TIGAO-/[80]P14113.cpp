#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> findmax_windows(const string &s, const vector<int> &prefStart, int maxLen, int &bestCount) {
    bestCount = 0;
    vector<pair<int,int>> res;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        int len = min(maxLen, n - i);
        if (len <= 0) continue;
        int cnt = 0;
        if (len >= 4) {
            int upper = i + len - 4;
            cnt = prefStart[upper + 1] - prefStart[i];
        }
        if (cnt > bestCount) { bestCount = cnt; res.clear(); res.emplace_back(i,len); }
        else if (cnt == bestCount) res.emplace_back(i,len);
    }
    return res;
}

int check_cross_optimized(const vector<pair<int,int>> &sv, const vector<pair<int,int>> &tv, const string &s, const string &t) {
    set<string> sEnds, tStarts;
    for (auto &ps : sv) {
        int si = ps.first, slen = ps.second;
        int sendLen = min(3, slen);
        int sendStart = si + slen - sendLen;
        sEnds.insert(s.substr(sendStart, sendLen));
    }
    for (auto &pt : tv) {
        int ti = pt.first, tlen = pt.second;
        int tstartLen = min(3, tlen);
        tStarts.insert(t.substr(ti, tstartLen));
    }
    for (auto &send : sEnds) {
        for (auto &tstart : tStarts) {
            if ((send + tstart).find("CDNL") != string::npos) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, k;
        string s, t;
        cin >> n >> m >> k;
        cin >> s >> t;
        if (m > (int)s.size()) m = s.size();
        if (k > (int)t.size()) k = t.size();

        vector<int> occS(n, 0), occT(n, 0);
        for (int i = 0; i + 4 <= n; ++i) if (s.substr(i,4) == "CDNL") occS[i] = 1;
        for (int i = 0; i + 4 <= n; ++i) if (t.substr(i,4) == "CDNL") occT[i] = 1;

        vector<int> prefS(n+1, 0), prefT(n+1, 0);
        for (int i = 0; i < n; ++i) {
            prefS[i+1] = prefS[i] + occS[i];
            prefT[i+1] = prefT[i] + occT[i];
        }

        int svl = 0, tvl = 0;
        vector<pair<int,int>> sv = findmax_windows(s, prefS, m, svl);
        vector<pair<int,int>> tv = findmax_windows(t, prefT, k, tvl);

        int cross = check_cross_optimized(sv, tv, s, t);
        cout << svl + tvl + cross << '\n';
    }
}