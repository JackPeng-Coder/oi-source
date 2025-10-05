#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

typedef long long ll;

ll integer_sqrt(ll x) {
    if (x == 0) return 0;
    ll l = 1, r;
    if (x > 1e18) {
        r = 3e9;
    } else {
        r = min((ll)2e9, x);
    }
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (mid <= x / mid) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

ll calculate_min_n(ll m) {
    // 解不等式: n(n-1)/2 >= m
    ll discriminant = 1 + 8 * m;
    ll sqrt_disc = integer_sqrt(discriminant);
    ll n = (1 + sqrt_disc + 1) / 2;
    
    // 确保满足条件
    while (n * (n - 1) < 2 * m) {
        n++;
    }
    return n;
}

ll calculate_max_n(ll m) {
    // 对于 m=1,2 的情况已经在主函数处理
    ll a = m - 1;
    
    // 检查是否可能溢出
    if (a > 0 && (9 * m - 1) > LLONG_MAX / a) {
        // 如果可能溢出，使用近似计算
        double approx_sqrt = sqrt((double)a * (9 * m - 1));
        return (a + (ll)approx_sqrt) / 2;
    }
    
    ll product = a * (9 * m - 1);
    ll sqrt_product = integer_sqrt(product);
    
    return (a + sqrt_product) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        ll m;
        cin >> m;
        
        if (m == 1 || m == 2) {
            cout << "Lose!\n";
            continue;
        }
        
        ll min_n = calculate_min_n(m);
        ll max_n = calculate_max_n(m);
        
        // 额外验证：确保最大n至少为最小n
        if (max_n < min_n) {
            cout << "Lose!\n";
        } else {
            cout << min_n << " " << max_n << "\n";
        }
    }
    return 0;
}