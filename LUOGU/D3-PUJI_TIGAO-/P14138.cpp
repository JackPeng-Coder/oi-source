#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;
long long gcdll(long long a,long long b){while(b){long long t=a%b;a=b;b=t;}return a;}
string tostr(i128 x){if(x==0) return "0";string s;while(x){s.push_back('0'+x%10);x/=10;}reverse(s.begin(),s.end());return s;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--){
        long long p,q;cin>>p>>q;
        i128 prod=(i128)180*q;
        long long g=gcdll(p,(long long)(prod%p));
        if(prod%p==0) g=p;
        i128 m=prod/g;
        cout<<tostr(m-1)<<'\n';
    }
}
