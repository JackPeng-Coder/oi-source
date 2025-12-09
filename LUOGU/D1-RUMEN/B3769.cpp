#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    int q, l1, r1, l2, r2;
    cin >> q;
    while (q--) {
        cin >> l1 >> r1 >> l2 >> r2;
        if (s.substr(l1 - 1, r1 - l1 + 1) < t.substr(l2 - 1, r2 - l2 + 1)) {
            cout << "yifusuyi" << endl;
        }
        else if (s.substr(l1 - 1, r1 - l1 + 1) == t.substr(l2 - 1, r2 - l2 + 1)) {
            cout << "ovo" << endl;
        }
        else {
            cout << "erfusuer" << endl;
        }
    }
}