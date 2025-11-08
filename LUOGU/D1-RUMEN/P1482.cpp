#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int a, b, c, d;
    scanf("%d/%d", &a, &b);
    scanf("%d/%d", &c, &d);
    a *= c;
    b *= d;
    int g = gcd(a, b);
    a /= g;
    b /= g;
    cout << b << " " << a << endl;
}