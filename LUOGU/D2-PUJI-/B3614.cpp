#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        vector<unsigned long long> stack;
        int n;
        cin >> n;
        while (n--) {
            string op;
            cin >> op;
            if (op == "push") {
                unsigned long long a;
                cin >> a;
                stack.push_back(a);
            }
            else if (op == "pop") {
                if (stack.empty()) cout << "Empty" << endl;
                else stack.pop_back();
            }
            else if (op == "query") {
                if (stack.empty()) cout << "Anguei!" << endl;
                else cout << stack.back() << endl;
            }
            else if (op == "size") {
                cout << stack.size() << endl;
            }
        }
    }
}