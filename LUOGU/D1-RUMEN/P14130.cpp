#include <iostream>
using namespace std;

int main()
{
    int n, a, s = 0;
    cin >> n;
    while (n--)
    {
        cin >> a;
        if (a == 0) s++;
    }
    cout << s << endl;
}