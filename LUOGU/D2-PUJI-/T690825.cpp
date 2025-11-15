#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    vector<char> vec;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') vec.push_back(s[i]);
    }
    sort(vec.begin(), vec.end(), greater<char>());
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
    }
    cout << endl;
}