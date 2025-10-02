#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int row = ceil((sqrt(8 * N + 1) - 1) / 2);
    int num = N - row * (row - 1) / 2;
    if (row & 1)
    {
        cout << row - num + 1 << "/" << num << endl;
    }
    else
    {
        cout << num << "/" << row - num + 1 << endl;
    }
}