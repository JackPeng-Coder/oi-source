#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = n; i >= 0; i--) {
        int a;
        cin >> a;
        
        if (a == 0) continue; // 系数为0，跳过
        
        // 处理符号
        if (i < n) { // 非首项
            if (a > 0) {
                cout << "+";
            } else {
                cout << "-";
            }
        } else { // 首项
            if (a < 0) {
                cout << "-";
            }
        }
        
        // 处理系数绝对值
        int abs_a = abs(a);
        if (abs_a != 1 || i == 0) {
            cout << abs_a;
        }
        
        // 处理变量部分
        if (i > 0) {
            cout << "x";
            if (i > 1) {
                cout << "^" << i;
            }
        }
    }
    
    cout << endl;
    return 0;
}