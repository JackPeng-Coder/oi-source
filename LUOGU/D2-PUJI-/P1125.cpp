#include <iostream>
#include <cstring>
using namespace std;

bool isPrime(int x)
{
    if (x == 0 || x == 1) return false;
    for (int i = 2; i * i < x; i++)
    {
        if (x % i == 0) return false;
    }
    return true;
}

int map[26];

int getRange()
{
    int minn = 10000000, maxx = 0;
    for (int i = 0; i < 26; i++)
    {
        if (map[i] > 0)
        {
            minn = min(minn, map[i]);
            maxx = max(maxx, map[i]);
        }
    }
    return maxx - minn;
}

int main()
{
    string s;
    cin >> s;
    memset(map, 0, sizeof(map));
    for (int i = 0; i < s.size(); i++)
    {
        map[s[i] - 'a']++;
    }
    int range = getRange();
    if (isPrime(range))
    {
        cout << "Lucky Word" << endl << range << endl;
    }
    else
    {
        cout << "No Answer" << endl << 0 << endl;
    }
}