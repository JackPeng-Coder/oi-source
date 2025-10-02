#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> map;

int count(int n)
{
    int tot = 1;
    if (map.count(n))
    {
        return map[n];
    }
    for (int i = 1; i <= n / 2; i++)
        tot += count(i);
    map[n] = tot;
    return tot;
}

int main()
{
    int n;
    cin >> n;
    cout << count(n) << endl;
}