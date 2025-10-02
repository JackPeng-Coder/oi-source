#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> map;

int calc(int n, int k, int s)
{
    int res = 0;
    if (k == 1)
    {
        return 1;
    }
    for (int i = s; i <= n / k; i++)
    {
        res += calc(n - i, k - 1, i);
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << calc(n, k, 1) << endl;
}