#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int N, a;
    cin >> N;
    for (int i = 0; s.size() < N * N; i++)
    {
        cin >> a;
        if (i % 2 == 1) {
            s += string(a, '1');
        }
        else {
            s += string(a, '0');
        }
    }
    for (int i = 0; i <= N; i++)
    {
        cout << s.substr(i * N, N) << endl;
    }
}