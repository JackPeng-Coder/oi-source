#include <iostream>
#include <string>
using namespace std;

int getMod47(const string &s) {
    int product = 1;
    for (char c : s) {
        int num = c - 'A' + 1;
        product = (product * num) % 47;
    }
    return product;
}

int main() {
    string comet, group;
    cin >> comet >> group;
    
    if (getMod47(comet) == getMod47(group)) {
        cout << "GO" << endl;
    } else {
        cout << "STAY" << endl;
    }
    
    return 0;
}