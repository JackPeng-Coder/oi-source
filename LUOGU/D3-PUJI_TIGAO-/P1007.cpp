#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int L, N, mint = 0, maxt = 0;
    cin >> L >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for (auto x : a)
    {
        mint = max(mint, min(x, L + 1 - x));
        maxt = max(maxt, max(x, L + 1 - x));
    }
    cout << mint << " " << maxt << endl;
}