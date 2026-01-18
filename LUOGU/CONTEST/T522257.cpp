#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    if(!(cin >> n >> q)) return 0;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++) cin >> p[i];
    vector<int> pa(n+1, 0);
    vector<int> st;
    st.reserve(n);
    for(int i=1;i<=n;i++){
        int la = 0;
        while(!st.empty() && p[st.back()] < p[i]){
            la = st.back();
            st.pop_back();
        }
        if(!st.empty()){
            pa[i] = st.back();
        }
        if(la != 0){
            pa[la] = i;
        }
        st.push_back(i);
    }
    int root = 1;
    for(int i=1;i<=n;i++) if(pa[i] == 0){ root = i; break; }
    vector<vector<int>> g(n+1);
    for(int i=1;i<=n;i++){
        if(pa[i] != 0) g[pa[i]].push_back(i);
    }
    int LOG = 1;
    while((1<<LOG) <= n) LOG++;
    vector<vector<int>> up(LOG, vector<int>(n+1, 0));
    vector<int> de(n+1, 0);
    stack<int> s;
    s.push(root);
    up[0][root] = 0;
    de[root] = 0;
    while(!s.empty()){
        int u = s.top(); s.pop();
        for(int v : g[u]){
            de[v] = de[u] + 1;
            up[0][v] = u;
            s.push(v);
        }
    }
    for(int j=1;j<LOG;j++){
        for(int i=1;i<=n;i++){
            int mid = up[j-1][i];
            up[j][i] = mid ? up[j-1][mid] : 0;
        }
    }

    auto lca = [&](int a, int b){
        if(a == 0) return b;
        if(b == 0) return a;
        if(de[a] < de[b]) swap(a,b);
        int diff = de[a] - de[b];
        for(int j=0;j<LOG;j++){
            if(diff & (1<<j)) a = up[j][a];
        }
        if(a == b) return a;
        for(int j=LOG-1;j>=0;j--){
            if(up[j][a] != up[j][b]){
                a = up[j][a];
                b = up[j][b];
            }
        }
        return up[0][a];
    };
    for(int _=0;_<q;_++){
        int k; cin >> k;
        int cur = 0;
        for(int i=0;i<k;i++){
            int x; cin >> x;
            if(cur == 0) cur = x;
            else cur = lca(cur, x);
        }
        cout << (de[cur] + 1) << '\n';
    }
}
