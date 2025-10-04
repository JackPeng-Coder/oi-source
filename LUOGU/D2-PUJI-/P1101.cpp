#include <iostream>
#include <string>
using namespace std;

string rect[101];
bool boolrect[101][101];

const string str = "yizhong";

const pair<int, int> map[8] = {
    {-1, -1}, {-1, 0}, {-1, 1}, {0, 1},
    {1, 1}, {1, 0}, {1, -1}, {0, -1}
};

int main()
{
    int n;
    bool found;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> rect[i];
        for (int j = 0; j < n; j++)
        {
            boolrect[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int d = 0; d < 8; d++)
            {
                found = true;
                for (int a = 0; a < 7; a++)
                {
                    if (!(i + map[d].first * a >= 0 && i + map[d].first * a < n && j + map[d].second * a >= 0 && j + map[d].second * a < n))
                    {
                        found = false;
                        break;
                    }
                    if (rect[i + map[d].first * a][j + map[d].second * a] != str[a])
                    {
                        found = false;
                        break;
                    }
                }
                if (found)
                {
                    for (int a = 0; a < 7; a++)
                    {
                        boolrect[i + map[d].first * a][j + map[d].second * a] = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (boolrect[i][j])
            {
                cout << rect[i][j];
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}