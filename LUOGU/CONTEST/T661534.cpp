#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int64_t n, m;
        cin >> n >> m;
        int64_t nn = n, mm = m;
        int64_t need = nn * (nn + 1) / 2;
        if (need > mm)
        {
            cout << "-1 -1" << endl;
        }
        else
        {
            int64_t maxDiff = mm - nn * (nn - 1) / 2 - 1;
            int64_t r = mm - need;
            int64_t minDiff = (nn - 1) + (r % nn != 0);
            cout << (long long)maxDiff << " " << (long long)minDiff << endl;
        }
    }
    return 0;
}
