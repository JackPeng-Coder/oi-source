#include <iostream>
using namespace std;

int main()
{
    int n, a, p, c = 0;
    bool up = false;
    cin >> n;
    cin >> a;
    for (int i = 1; i < n; i++)
    {
        p = a;
        cin >> a;
        if (p < a)
        {
            if (!up) c++;
            up = true;
        }
        else if (p > a)
        {
            up = false;
        }
    }
    cout << c - 1 << endl;
}