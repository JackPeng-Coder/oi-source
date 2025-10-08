#include <iostream>
#include <cmath>
using namespace std;

const int g = 10;

int main()
{
    double H, S, V, L, K, n;
    cin >> H >> S >> V >> L >> K >> n;
    double t = sqrt(2 * H / g);
    int left = S - V * t;
    if (left < 0) left = 0;

    t = sqrt(2 * (H - K) / g);
    int right = S - V * t + L;
    if (right > n) right = n;

    cout << right - left << endl;
}