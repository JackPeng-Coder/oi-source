#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int e = a * 60 + b;
    int f = c * 60 + d;
    int g = f - e;
    cout << g / 60 << " " << g % 60 << endl;
}