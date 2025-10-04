#include <iostream>
#include <cstring>
using namespace std;

int n;
int res[40][40];

int count(int step, int amount)
{
    int sum = 0;
    if (step == 2 * n)
    {
        if (amount == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    if (res[step][amount] != -1)
    {
        return res[step][amount];
    }

    if (amount > 0)
    {
        sum += count(step + 1, amount - 1);
    }
    if (amount <= n)
    {
        sum += count(step + 1, amount + 1);
    }
    res[step][amount] = sum;
    return sum;
}

int main()
{
    memset(res, -1, sizeof(res));
    cin >> n;
    cout << count(0, 0) << endl;
}