#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int charToVal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}

char valToChar(int val) {
    if (val < 10) return val + '0';
    return val - 10 + 'A';
}

int main() {
    int n, m;
    string num;
    cin >> n >> num >> m;

    long long decimal = 0;
    for (char c : num) {
        decimal = decimal * n + charToVal(c);
    }

    if (decimal == 0) {
        cout << "0";
        return 0;
    }

    string result;
    while (decimal > 0) {
        result += valToChar(decimal % m);
        decimal /= m;
    }

    reverse(result.begin(), result.end());
    cout << result;

    return 0;
}
