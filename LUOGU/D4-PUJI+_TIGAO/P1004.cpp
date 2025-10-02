#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using namespace std;

int dp[10][10][10][10];
int f[10][10];

int mymax(int a, int b, int c, int d)
{
    return max(max(a, b), max(c, d));
}

int main()
{

    memset(dp, 0, sizeof(dp));
    memset(f, 0, sizeof(f));
    
    int N, x, y, n;
    cin >> N;

    while (true)
    {
        cin >> x >> y >> n;
        if (x == 0 && y == 0 && n == 0) break;

        f[x][y] = n;
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int k = 1; k <= N; k++)
            {
                for (int l = 1; l <= N; l++)
                {
                    if ((i == k) && (j == l))
                    {
                        dp[i][j][k][l] = mymax(
                            dp[i-1][j][k-1][l],
                            dp[i-1][j][k][l-1],
                            dp[i][j-1][k-1][l],
                            dp[i][j-1][k][l-1]
                        ) + f[i][j];
                    }
                    else
                    {
                        dp[i][j][k][l] = mymax(
                            dp[i-1][j][k-1][l],
                            dp[i-1][j][k][l-1],
                            dp[i][j-1][k-1][l],
                            dp[i][j-1][k][l-1]
                        ) + f[i][j] + f[k][l];    
                    }
                }
                
            }
        }
    }

    cout << dp[N][N][N][N] << endl;
}