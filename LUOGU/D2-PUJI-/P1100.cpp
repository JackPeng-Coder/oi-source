#include <iostream>
using namespace std;

int main()
{
    unsigned int a, b, c;
    cin >> a;
    b = a >> 16;
    c = a << 16;
    cout << b + c << endl;
}