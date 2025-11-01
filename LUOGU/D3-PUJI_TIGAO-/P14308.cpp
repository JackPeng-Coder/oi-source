#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long x, y, l = -1, r = 0, u = 1, d = 0, s = 1;
        cin >> x >> y;
        while (!(x >= l && x <= r && y >= d && y <= u)) {
            if (x >= l && x <= r && y >= d && y <= u) break;
            d -= r - l;
            s = r - l;
            if (x >= l && x <= r && y >= d && y <= u) break;
            r += u - d;
            s = u - d;
            if (x >= l && x <= r && y >= d && y <= u) break;
            u += r - l;
            s = r - l;
            if (x >= l && x <= r && y >= d && y <= u) break;
            l -= u - d;
            s = u - d;
        }
        cout << s << endl;
    }
}
