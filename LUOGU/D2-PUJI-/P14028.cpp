#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n, m, min = 1e9, max = -1e9;
        cin >> n >> m;
        int *a = new int[n];
        int *c = new int[n+1] {0};
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        int l, r;
        for (int j = 0; j < m; j++)
        {
            cin >> l >> r;
            c[l-1]++;
            c[r]--;
        }
        for (int j = 1; j < n; j++)
        {
            c[j] += c[j-1];
        }
        for (int j = 0; j < n; j++)
        {
            if (a[j] - c[j] > max) max = a[j] - c[j];
            if (a[j] + c[j] < min) min = a[j] + c[j];

        }
        if (max - min < 0)
            cout << 0 << endl;
        else
            cout << max - min << endl; 
    }
}