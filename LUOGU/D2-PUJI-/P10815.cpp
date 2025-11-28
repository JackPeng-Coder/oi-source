#include <iostream>
using namespace std;

int in()
{
    int k = 0, f = 1;
    char c = getchar_unlocked();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar_unlocked();
    }
    while (c >= '0' && c <= '9') k = k * 10 + c - '0', c = getchar_unlocked();
    return k * f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, a, s = 0;
    n = in();
    for (int i = 0; i < n; i++) {
        a = in();
        s += a;
    }
    cout << s << endl;
}