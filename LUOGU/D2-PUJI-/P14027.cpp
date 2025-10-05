#include <iostream>
using namespace std;

int main()
{
    int a, b, k, d = 0;
    cin >> a >> b >> k;
    while (a * k < a + k && a < b)
    {
        a += k;
        d++;
    }
    while(a < b)
    {
        a *= k;
        d++;
    }
    cout << d << endl;
}