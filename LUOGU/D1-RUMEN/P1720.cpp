#include <iostream>
using namespace std;

int main()
{
    long long a = 0, b = 1, n, t;
    cin >> n;
    while (n--)
    {
        t = a;
        a = b;
        b += t;
    }
    cout << a << ".00" << endl;
}