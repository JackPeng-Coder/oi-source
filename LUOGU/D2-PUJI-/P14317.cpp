#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        unordered_set<char> set0;
        unordered_set<char> set1;
        unordered_set<char> set2;
        for (int i = 0; i < s.size(); i++) {
            set0.insert(s[i]);
        }
        for (int i = 0; i < s.size() - 1; i++) {
            set1.insert(s[i]);
        }
        for (int i = 1; i < s.size(); i++) {
            set2.insert(s[i]);
        }
        if (set0.size() == 26 && (set1.size() == 26 || set2.size() == 26)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
            if (set0.size() != 26 && (set1.size() != 26 && set2.size() != 26)) {
                cout << "1 2" << endl;
            } else if (set0.size() != 26) {
                cout << "1" << endl;
            } else {
                cout << "2" << endl;
            }
        }
    }
    return 0;
}