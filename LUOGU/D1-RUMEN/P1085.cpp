#include <iostream>
using namespace std;

int main()
{
    int a, b, max = 0, maxi = 0;
    for (int i = 0; i < 7; i++)
    {
        cin >> a >> b;
        if (a + b > max)
        {
            max = a + b;
            maxi = i;
        }
    }
    if (max <= 8) cout << 0 << endl;
    else cout << maxi + 1 << endl;
}