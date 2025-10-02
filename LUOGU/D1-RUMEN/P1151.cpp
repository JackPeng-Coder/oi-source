#include <iostream>
using namespace std;

int main()
{
    int K;
    cin >> K;
    bool no = true;
    for (int i = 10000; i <= 30000; i++)
    {
        if (
            i / 100 % K == 0 &&
            i / 10 % 1000 % K == 0 &&
            i % 1000 % K == 0
        )
        {
            cout << i << endl;
            no = false;
        }
    }
    if (no) cout << "No" << endl;
}