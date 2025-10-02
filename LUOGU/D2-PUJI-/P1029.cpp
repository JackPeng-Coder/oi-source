#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int t;
    while (b)
    {
        t = a;
        a = b;
        b = t % b;
    }
    return a;
}

int main()
{
    int x, y;
    cin >> x >> y;
    int cnt = 0;
    for (int i = x; i <= y; i += x)
    {
        if (x * y % i == 0 && gcd(i, x * y / i) == x) cnt++;
    }
    cout << cnt << endl;
}