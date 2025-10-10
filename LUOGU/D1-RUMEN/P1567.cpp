#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, c = 1, m = 0;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        if (i != 0 && v[i] > v[i - 1])
        {
            c++;
            m = max(c, m);
        }
        else
        {
            c = 0;
        }
    }
    cout << m + 1 << endl;
}