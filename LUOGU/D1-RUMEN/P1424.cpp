#include <iostream>
using namespace std;

int main()
{
    int w, d, c = 0;
    cin >> w >> d;
    for (int i = w; i < w + d; i++)
    {
        if (i % 7 != 0 && i % 7 != 6) c++;
    }
    cout << c * 250 << endl;
}