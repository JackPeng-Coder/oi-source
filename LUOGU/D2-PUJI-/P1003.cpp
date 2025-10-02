#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

typedef tuple<int, int, int, int> rect;

int main()
{
    int n, a, b, g, k, x, y;
    bool exist = false;
    cin >> n;
    vector<rect> data(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> g >> k;
        data[i] = {a, b, g, k};
    }
    cin >> x >> y;
    for (int i = n; i > 0; i--)
    {
        if ((get<0>(data[i]) <= x) && (get<0>(data[i]) + get<2>(data[i]) >= x) && (get<1>(data[i]) <= y) && (get<1>(data[i]) + get<3>(data[i]) >= y))
        {
            cout << i << endl;
            exist = true;
            break;
        }
    }
    if (!exist)
    {
        cout << -1 << endl;
    }
}