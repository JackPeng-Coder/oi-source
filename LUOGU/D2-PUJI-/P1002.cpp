#include <iostream>
#include <cstring>
using namespace std;

int main() {
    long long MAP[25][25];  // 使用long long防止溢出
    memset(MAP, 0, sizeof(MAP));
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    
    // 先标记所有马的控制点（包括马的位置）
    bool blocked[25][25] = {false};
    blocked[x][y] = true;  // 马的位置
    
    // 马的8个可能控制点
    int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                       {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    for (int i = 0; i < 8; i++) {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];
        // 确保控制点在棋盘范围内
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
            blocked[nx][ny] = true;
        }
    }
    
    // 初始化起点
    MAP[0][0] = blocked[0][0] ? 0 : 1;
    
    // 填充第一行（只能从左边过来）
    for (int j = 1; j <= m; j++) {
        MAP[0][j] = blocked[0][j] ? 0 : MAP[0][j-1];
    }
    
    // 填充第一列（只能从上面过来）
    for (int i = 1; i <= n; i++) {
        MAP[i][0] = blocked[i][0] ? 0 : MAP[i-1][0];
    }
    
    // 填充其余格子
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (blocked[i][j]) {
                MAP[i][j] = 0;  // 被马控制的位置路径数为0
            } else {
                MAP[i][j] = MAP[i-1][j] + MAP[i][j-1];
            }
        }
    }
    
    cout << MAP[n][m] << endl;
    return 0;
}
    