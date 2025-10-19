#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, l, r, total = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        total += v[i];
    }
    cin >> l >> r;
    
    if (total < n * l || total > n * r)
    {
        cout << -1 << endl;
        return 0;
    }
    
    int need_add = 0, need_sub = 0;
    for (auto x : v)
    {
        if (x < l) need_add += l - x;
        else if (x > r) need_sub += x - r;
    }
    
    cout << max(need_add, need_sub) << endl;
    return 0;
}