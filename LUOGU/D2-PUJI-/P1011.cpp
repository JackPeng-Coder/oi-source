#include <iostream>
using namespace std;

int main() {
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    
    if (x == 1) {
        cout << a << endl;
        return 0;
    }
    if (x == 2) {
        cout << a << endl;
        return 0;
    }
    if (n == 3) {
        cout << 2 * a << endl;
        return 0;
    }
    
    int F[21] = {0};
    F[1] = 1;
    F[2] = 1;
    for (int i = 3; i <= n-1; i++) {
        F[i] = F[i-1] + F[i-2];
    }
    
    int k = (m - a * F[n-1]) / (F[n-2] - 1);
    
    int result = a * F[x] + k * (F[x-1] - 1);
    cout << result << endl;
    
    return 0;
}