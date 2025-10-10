#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, a;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        a += i;
        while (a < 0) a += n;
        a %= n;
        l[a] += 1;
    }

    vector<int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.empty()) m.push_back(i);
        else
        {
            if (l[m[0]] == l[i]) m.push_back(i);
            else if (l[m[0]] < l[i])
            {
                m.clear();
                m.push_back(i);
            }
        }
    }
    for (auto x : m)
    {
        cout << x + 1 << " ";
    }
}