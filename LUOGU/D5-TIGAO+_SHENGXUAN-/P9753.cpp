#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
const int N=2e6+5;
int n,dp[N],a[N][26],to[N];
char s[N];
ll ans;
int main()
{
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++)
    {
        to[i]=i;
        int x=a[to[i-1]][s[i]-'a'];
        if(x) to[i]=to[x-1],dp[i]=dp[x-1]+1;
        a[to[i]][s[i]-'a']=i,ans+=dp[i];
    }
    printf("%lld\n",ans);
    return 0;
}