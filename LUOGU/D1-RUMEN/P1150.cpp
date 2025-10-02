#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int total = n;  // 初始的烟数量
    int butts = n;  // 初始的烟蒂数量
    
    while (butts >= k) {
        int new_cigarettes = butts / k;  // 可以兑换的新烟数量
        total += new_cigarettes;          // 总烟数增加
        butts = butts % k + new_cigarettes; // 剩余烟蒂 = 兑换后剩余的 + 新烟产生的烟蒂
    }
    
    cout << total << endl;
    return 0;
}