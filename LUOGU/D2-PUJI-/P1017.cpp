#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string base = "0123456789ABCDEFGHIJKL";

int main()
{
    int n, R, a, b;
    cin >> n >> R;
    cout << n << "=";
    vector<int> num;
    while (n != 0)
    {
        a = n / R;
        b = n % R;
        if (b < 0)
        {
            a++;
            b -= R;
        }
        num.push_back(b);
        n = a;
    }
    for (int i = num.size() - 1; i >= 0; i--)
    {
        cout << base[num[i]];
    }
    cout << "(base" << R << ")" << endl;
}