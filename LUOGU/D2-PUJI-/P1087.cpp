#include <bits/stdc++.h>
using namespace std;

string post(string s) {
    if (s.size() == 1) {
        if (s == "0") return "B";
        else return "I";
    }
    string a = post(s.substr(0, s.size() / 2));
    string b = post(s.substr(s.size() / 2, s.size() / 2));
    if (a.back() == 'F' || b.back() == 'F' || (a.back() != b.back())) {
        return a + b + "F";
    } else {
        return a + b + a.back();
    }
}

int main() {
    long N;
    cin >> N;
    string s;
    cin >> s;
    cout << post(s) << endl;
}