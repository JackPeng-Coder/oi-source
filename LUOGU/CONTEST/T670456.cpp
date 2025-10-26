#include <iostream>
using namespace std;

const int mod = 998244353;

int main() {
    int n;
    cin >> n;
    long long ans = 1;
    for (long long i = 1; i <= 2 * n - 3; i += 2) {
        ans = ans * i % mod;
    }
    cout << ans << endl;
    return 0;
}