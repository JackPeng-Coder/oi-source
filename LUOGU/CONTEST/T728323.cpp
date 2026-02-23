#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        if (n - 2 >= 2 * m) cout << n + 1 << endl;
        else cout << -1 << endl;
    }
}
