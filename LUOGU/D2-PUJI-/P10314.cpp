#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double PI = 3.141592653589;

int main()
{
    int T;
    double x;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> x;
        printf("%.6f\n", x-0.5+atan(1/tan(PI*x))/PI);
    }
}