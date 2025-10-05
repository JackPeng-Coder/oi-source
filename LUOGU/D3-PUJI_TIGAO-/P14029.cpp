#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int n;
        long long m;
        cin >> n >> m;
        vector<long long> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<long long> b(n);
        for(int i = 0; i < n; i++) cin >> b[i];
        vector<long long> A_mod(n);
        for(int i = 0; i < n; i++) A_mod[i] = a[i] % m;
        vector<long long> B_mod(n);
        for(int i = 0; i < n; i++) B_mod[i] = b[i] % m;
        long long sumA = 0, sumB = 0;
        for(auto x : A_mod) sumA += x;
        for(auto x : B_mod) sumB += x;
        vector<int> A_pos(n);
        iota(A_pos.begin(), A_pos.end(), 0);
        sort(A_pos.begin(), A_pos.end(), [&](int i, int j){ return A_mod[i] > A_mod[j] || (A_mod[i] == A_mod[j] && i < j); });
        vector<int> B_pos(n);
        iota(B_pos.begin(), B_pos.end(), 0);
        sort(B_pos.begin(), B_pos.end(), [&](int i, int j){ return B_mod[i] < B_mod[j] || (B_mod[i] == B_mod[j] && i < j); });
        vector<long long> b_assigned(n, -1);
        int ptr = 0;
        int good = 0;
        for(int i : A_pos) {
            long long r = m - A_mod[i] - 1;
            if(ptr < n && B_mod[B_pos[ptr]] <= r) {
                b_assigned[i] = b[B_pos[ptr]];
                ptr++;
                good++;
            }
        }
        int K = n - good;
        long long max_sum = sumA + sumB - m * 1LL * K;
        vector<int> unassigned;
        for(int i = 0; i < n; i++) if(b_assigned[i] == -1) unassigned.push_back(i);
        sort(unassigned.begin(), unassigned.end());
        for(size_t k = 0; k < unassigned.size(); k++) {
            int ii = unassigned[k];
            int jj = B_pos[ptr + k];
            b_assigned[ii] = b[jj];
        }
        cout << max_sum << '\n';
        for(int i = 0; i < n; i++) {
            if(i > 0) cout << " ";
            cout << b_assigned[i];
        }
        cout << '\n';
    }
    return 0;
}