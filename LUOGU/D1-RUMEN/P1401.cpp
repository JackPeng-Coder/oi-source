#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int xl, xu, yl, yu;
    cin >> xl >> xu >> yl >> yu;
    
    long long p1 = (long long)xl * yl;
    long long p2 = (long long)xl * yu;
    long long p3 = (long long)xu * yl;
    long long p4 = (long long)xu * yu;
    
    long long max_prod = max({p1, p2, p3, p4});
    long long min_prod = min({p1, p2, p3, p4});
    
    if (max_prod > 2147483647 || min_prod < -2147483648) {
        cout << "long long int" << endl;
    } else {
        cout << "int" << endl;
    }
    
    return 0;
}