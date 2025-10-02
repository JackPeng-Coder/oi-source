#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //freopen("color.in", "r", stdin);
    //freopen("color.out", "w", stdout);

    int T, n, j, f, min, sum, *A;
    vector<pair<int, int>> vec;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n;
        vec.clear();
        A = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
            for (j = i - 1; j >= 0 && A[j] != A[i]; j--);
            if (j == -1) continue;
            f = 0;
            for (int k = 0; k < vec.size(); k++)
            {
                if (vec[k].first < j && j < vec[k].second && ++f > 1) break;
            }
            vec.push_back(make_pair(j, i));
            
            while (f > 1)
            {
                min = 0;
                for (int k = 0; k < vec.size(); k++)
                {
                    if (A[vec[min].first] > A[vec[k].first]) min = k;
                }
                vec.erase(vec.begin() + min);
                f--;
            }
        }
        sum = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            sum += A[vec[i].first];
        }
        cout << sum << endl;

    }
    return 0;
}