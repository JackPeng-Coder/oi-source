#include <iostream>
#include <cmath>
using namespace std;

long long isqrt(long long n) {
    long long x = sqrtl(n);
    while (x * x > n) x--;
    while ((x + 1) * (x + 1) <= n) x++;
    return x;
}

int main() {
    long long q, n;
    cin >> q;
    while (q--) {
        cin >> n;
        long long s = isqrt(n);
        long long r = 3 * (s - 1) + 1;
        if (s * s + s <= n) r++;
        if (s * s + 2 * s <= n) r++;
        cout << r << '\n';
    }
    return 0;
}