#include <bits/stdc++.h>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
    ll n, m, min_two = LONG_LONG_MAX, cnt = 0;
    cin >> n >> m;
    vector<pair<ll, ll>> vec(n + 1);
    vector<bool> sign(n + 1, false);
    for (ll i = 1; i <= n; i++) {
        cin >> vec[i].first >> vec[i].second;
        min_two = min(min_two, vec[i].first + vec[i].second);
    }
    for (ll i = 1; i <= n; i++) {
        if (vec[i].first * 2 <= min_two) {
            m -= vec[i].first;
            cnt++;
            sign[i] = true;
        }
    }

    cnt += m / min_two * 2;
    m %= min_two;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for (ll i = 1; i <= n; i++) {
        if (!sign[i] && vec[i].first <= m) {
            // m -= vec[i].first;
            // cnt++;
            pq.push(vec[i].first);
        }
        if (sign[i] && vec[i].second <= m) {
            // m -= vec[i].second;
            // cnt++;
            pq.push(vec[i].second);
        }
    }

    while (!pq.empty() && m - pq.top() >= 0) {
        m -= pq.top();
        pq.pop();
        cnt++;
    }

    cout << cnt << endl;
}