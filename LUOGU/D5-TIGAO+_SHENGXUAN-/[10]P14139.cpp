#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long T;
    cin >> T;
    while (T--)
    {
        long n, sum = 0;
        cin >> n;
        for (long x = 1; x <= n; x++)
        {
            sum += x*x/n + (int)sqrt(n*x);
            sum %= 1000000007;
        }
        cout << sum << endl;
    }
}