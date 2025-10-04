#include <iostream>
using namespace std;

int main()
{
    int n, k, min = 1e9, max = -1e9, a;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a < min) min = a;
        if (a > max) max = a;
    }
    if (k <= 1) cout << 0 << endl;
    else cout << (long long)(max - min) * (max - min) << endl;
}