#include <iostream>
using namespace std;

int main()
{
    double d = 0, t = 0;
    int c = 0;
    cin >> d;
    double s = 2;
    while (d > t)
    {
        t += s;
        s *= 0.98;
        c++;
    }
    cout << c << endl;
}