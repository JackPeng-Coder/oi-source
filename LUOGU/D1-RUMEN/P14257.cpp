#include <iostream>
using namespace std;

int main() {
    int n, y, s, t;
    cin >> n >> y >> s >> t;
    for (int i = 1; i <= n; ++i) {
        int start = (i - 1) * s;
        int end = i * s;
        bool found = false;
        if (start >= y && (start - y) % t == 0) {
            found = true;
        }
        if (!found && end >= y && (end - y) % t == 0) {
            found = true;
        }
        if (!found) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}