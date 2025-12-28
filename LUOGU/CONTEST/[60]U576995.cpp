#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, d, x, last, top, cnt = 0;
    cin >> n >> k >> d;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);
    }
    while (!pq.empty()) {
        last = pq.top();
        pq.pop();
        for (int i = 1; i < k; i++) {
            if (pq.empty()) break;
            top = pq.top();
            if (top - last <= d) {
                last = top;
                pq.pop();
            } else {
                last += d;
                cnt++;
            }
        }
    }
    if ((cnt + n) % k != 0) cnt += k - (cnt + n) % k;
    cout << cnt << endl;
}