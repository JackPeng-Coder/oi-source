#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, r, c, x1, y1, x2, y2;
    cin >> n >> m >> r >> c >> x1 >> y1 >> x2 >> y2;
    
    int left_x = x1 / r;
    int right_x = x2 / r;
    int cnt_x = right_x - left_x + 1;
    
    int left_y = y1 / c;
    int right_y = y2 / c;
    int cnt_y = right_y - left_y + 1;
    
    cout << cnt_x * cnt_y << endl;
    return 0;
}