#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int k, N;
    cin >> k >> N;
    
    long long result = 0;
    int power = 0;
    
    while (N > 0) {
        if (N & 1) {
            result += pow(k, power);
        }
        N >>= 1;
        power++;
    }
    
    cout << result;
    return 0;
}