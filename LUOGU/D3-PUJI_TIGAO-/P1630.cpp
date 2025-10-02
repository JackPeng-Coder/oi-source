#include <iostream>
#include <string.h>
using namespace std;

const int m = 10000;

int power(int a, int b)
{
    if (b == 0) return 1 % m;
    int res = 1;
    while (b)
    {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    int N, a, b, sum[m + 1], c, d;
    cin >> N;
    for(; N > 0; N--)
    {
        memset(sum, 0, sizeof(sum));
        cin >> a >> b;
        c = a / m;
        d = a % m;
        for (int i = 1; i <= m; i++)
        {
            sum[i] = (sum[i - 1] + power(i, b)) % m;
        }
        cout << (sum[m] * c + sum[d]) % m << endl;
    }
}