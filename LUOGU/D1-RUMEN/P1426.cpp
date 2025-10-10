#include <iostream>
#include <cmath>
using namespace std;

const double EPS = 1e-8;

int main() {
    double s, x;
    cin >> s >> x;
    double left = s - x;
    double right = s + x;
    double total = 0.0;
    double speed = 7.0;
    
    while (total < left - EPS) {
        total += speed;
        speed *= 0.98;
    }
    
    if (total > right + EPS) {
        cout << "n";
    } else {
        if (total + speed > right + EPS) {
            cout << "n";
        } else {
            cout << "y";
        }
    }
    
    return 0;
}