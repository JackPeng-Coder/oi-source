#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

const long long inf = 2e18;  // 改为 long long 并增大 inf

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    fstream cin;
    cin.open("LUOGU/CONTEST/mexdnc2.in", ios::in);
    fstream cout;
    cout.open("LUOGU/CONTEST/mexdnc2.ans", ios::out);
    
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        unordered_map<long long, long long> umap;  // 改为 long long
        vector<long long> v = {inf};  // 改为 long long
        
        for (int i = 0; i < n; i++) {
            long long a, b;  // 改为 long long
            cin >> a >> b;
            if (umap.find(a) == umap.end()) {
                umap[a] = b;
            } else {
                umap[a] += b;
            }
        }

        for (long long i = 0; umap[i] != 0; i++) {  // 改为 long long
            v.push_back(min(v.back(), umap[i]));
        }

        for (int i = 0; i < q; i++) {
            long long m;  // 改为 long long
            cin >> m;

            vector<long long> vt(v.size(), 0);
            long long mm = min(m, (long long)v.size() - 1);
            vt[mm] = v[mm];
            for (long long i = mm - 1; i >= 1; i--) {
                long long diff = v[i] - v[i + 1];
                vt[i] = diff > 0 ? diff : 0;
            }

            long long r = 0, s = 0;  // 改为 long long
            bool found = false;
            long long j;  // 改为 long long
            
            for (j = mm; j >= 1; j--) {
                // 这里也需要优化，如果 vt[j] 很大可能会超时
                long long max_take = min(vt[j], (m - r) / j);  // 直接计算最大可取值
                if (max_take > 0) {
                    r += max_take * j;
                    s += max_take;
                }
                
                if ((m - r < j - 1 && vt[j - 1] > 0) || (m - r == 0)) {
                    found = true;
                    break;
                }
            }
            
            if (found && s != 0) {
                if (m == r && mm >= (long long)v.size() - 1) 
                    cout << s << endl;
                else 
                    cout << s + 1 << endl;
            }
            else {
                cout << -1 << endl;
            }
        }
    }
}