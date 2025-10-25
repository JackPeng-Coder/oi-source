#include <iostream>
#include <string>
#include <vector>
using namespace std;

const vector<int> comb = {1, 26, 325, 2600, 14950, 65780, 230230};

int main() {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        cnt += comb[s.size() - i - 1];
    }
    for (int i = 0; i < s.size(); i++) {
        cnt += (s[i] - 'a') * comb[s.size() - i - 1];
    }
    cout << cnt << endl;
}
