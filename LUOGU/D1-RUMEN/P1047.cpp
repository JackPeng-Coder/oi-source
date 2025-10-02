#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int l, m, a, b, cnt = 0;
    cin >> l >> m;
    vector<bool> road(l + 1, true);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        for (int j = a; j <= b; j++)
        {
            road[j] = false;
        }
    }
    for (bool x : road)
    {
        if (x) cnt++;
    }
    cout << cnt << endl;
}