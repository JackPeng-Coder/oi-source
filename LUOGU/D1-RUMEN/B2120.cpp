#include <iostream>
#include <string>
using namespace std;

int main() {
    int sum = 0;
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            if (sum != 0) cout << sum << ',';
            sum = 0;
        } else {
            sum++;
        }
    }
    if (sum != 0) cout << sum;
}