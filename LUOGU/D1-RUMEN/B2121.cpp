#include <iostream>
#include <string>
using namespace std;

int main() {
    int sum = 0, max = -1e9, min = 1e9;
    string s, maxs, mins;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ' || s[i] == ',' || s[i] == '.') {
            if (max < sum) {
                max = sum;
                maxs = s.substr(i - sum, sum);
            }
            if (min > sum) {
                min = sum;
                mins = s.substr(i - sum, sum);
            }
            sum = 0;
        } else {
            sum++;
        }
    }
    cout << maxs << endl << mins << endl;
}