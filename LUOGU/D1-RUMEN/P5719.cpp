#include <iostream>
using namespace std;

int main() {
    int n, k, a_sum = 0, b_sum = 0, a_cnt = 0, b_cnt = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        if (i % k == 0) {
            a_cnt++;
            a_sum += i;
        }
        else {
            b_cnt++;
            b_sum += i;
        }
    }
    printf("%.1f %.1f", (double)a_sum / a_cnt, (double)b_sum / b_cnt);
}   