#include <iostream>
#include <map>
using namespace std;

int main()
{
    int N, a;
    cin >> N;
    map<int, int> total;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        if (total.find(a) == total.end())
        {
            total[a] = 1;
        }
        else
        {
            total[a]++;
        }
    }
    for (auto p : total)
    {
        cout << p.first << " " << p.second << endl;
    }
}