#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int kmax = (int)((sqrt(8.0 * n + 1) - 1) / 2);

        int ans = 0;
        for (int k = kmax; k > 0 && !ans; k--)
        {
            int L = k * (k + 1) / 2;
            if (L > n) continue; 

            vector<int> map(k + 1, 0);
            int bad = 0; 
            
            for (int i = 0; i < L; i++)
            {
                if (a[i] > k) bad++;      
                else map[a[i]]++;
            }
            
            auto good_window = [&]() -> bool {
                if (bad > 0) return false;          
                for (int j = 1; j <= k; j++) {      
                    if (map[j] != j) return false;  
                }
                return true;
            };

            if (good_window()) {
                ans = k;
                break;
            }
            
            for (int i = L; i < n && !ans; i++)
            {
                if (a[i - L] > k) bad--;
                else map[a[i - L]]--;
                
                if (a[i] > k) bad++;
                else map[a[i]]++;

                if (good_window()) {
                    ans = k;
                    break;
                }
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
