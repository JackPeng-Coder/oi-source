#include <iostream>
using namespace std;

int main() {
    int budget;
    int current = 0;
    int saved = 0;
    
    for (int month = 1; month <= 12; month++) {
        cin >> budget;
        current += 300;
        
        if (current < budget) {
            cout << "-" << month;
            return 0;
        }
        
        current -= budget;
        
        if (current >= 100) {
            int saveAmount = (current / 100) * 100;
            saved += saveAmount;
            current -= saveAmount;
        }
    }
    
    int total = current + saved * 1.2;
    cout << total;
    
    return 0;
}