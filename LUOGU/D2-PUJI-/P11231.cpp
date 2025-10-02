#include <cstdio>
#include <algorithm>
const int N=1e5+6;
int n,x,mp[N],ans;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		ans=std::max(ans,++mp[x]);
	}
	printf("%d\n",ans);
	return 0;
}