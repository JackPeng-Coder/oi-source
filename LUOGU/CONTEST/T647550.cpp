#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N, A, D;
  cin >> N >> A >> D;
  int n = N;
  int m = n - 1;
  vector<ll> b(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  vector<ll> c(m + 1, 0);
  ll td = 2 * D;
  for (int i = 1; i <= m; i++) {
    if (b[i] > 2) {
      c[i] = (b[i] - 2) / td;
    }
  }
  ll ans = 0;
  int L = max(1, (int)A - 2);
  int R = min(m, (int)A + 2);
  for (int s = L; s <= R; s++) {
    if (c[s] == 0) continue;
    ll fl = 0, rl = 0;
    bool crl = true;
    int lal = s;
    for (int i = s - 1; i >= 1; i--) {
      if (c[i] > 0) {
        if (lal - i > 2) break;
        fl += c[i];
        if (crl) {
          rl += c[i];
          if (c[i] < 2) crl = false;
        }
        lal = i;
      }
    }
    ll fr = 0, rr = 0;
    bool crr = true;
    int lr = s;
    for (int i = s + 1; i <= m; i++) {
      if (c[i] > 0) {
        if (i - lr > 2) break;
        fr += c[i];
        if (crr) {
          rr += c[i];
          if (c[i] < 2) crr = false;
        }
        lr = i;
      }
    }
    ll cs = c[s];
    ll opt = cs;
    ll ol = fl + cs;
    ll or_ = fr + cs;
    opt = max({opt, ol, or_});
    if (cs >= 2) {
      ll b1 = rl + fr + cs;
      ll b2 = rr + fl + cs;
      opt = max({opt, b1, b2});
    }
    if (opt > ans) ans = opt;
  }
  cout << ans << endl;
}