#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, minn = 100000000;
    cin >> n >> m;
    vector<int> v(n+1);
    v[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    for (int i = m; i <= n; i++)
    {
        minn = min(v[i] - v[i - m], minn);
    }
    cout << minn << endl;
}