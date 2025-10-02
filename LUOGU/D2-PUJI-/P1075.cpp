#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, p;
    cin >> n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            n /= i;
            p = i;
        }
    }
    if (n != 1) cout << n << endl;
    else cout << p << endl;
}