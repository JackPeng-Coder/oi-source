#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int a, b, c, d;
    char slash;
    cin >> a >> slash >> b;
    cin >> c >> slash >> d;
    int num = a * c;
    int den = b * d;
    int g = gcd(num, den);
    num /= g;
    den /= g;
    cout << num << " " << den << endl;
}