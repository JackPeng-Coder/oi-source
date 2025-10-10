#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    cout << fixed << setprecision(1);
    if (a <= 150)
    {
        cout << 0.4463 * a << endl;
    }
    else if (a <= 400)
    {
        cout << 0.4463 * 150 + 0.4663 * (a - 150) << endl;
    }
    else
    {
        cout << 0.4463 * 150 + 0.4663 * 250 + 0.5663 * (a - 400) << endl;
    }
}