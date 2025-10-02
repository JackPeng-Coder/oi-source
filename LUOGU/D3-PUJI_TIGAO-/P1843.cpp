#include <iostream>
#include <algorithm>
using namespace std;
long long n,clo[600005],a,b;

bool check(long long num)
{
	long long t=0;
	for(int i=1;i<=n;i++)
	{
		long long x=clo[i]-num*a;
		if(x>0)
		{
			if(x%b!=0) t+=((x/b)+1);
			else t+=x/b;
		}
	}
	return t<=num;
}

int main()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>clo[i];
	}
	long long l=0,r=1e9,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid))
		{
			r=mid;
		}
		else l=mid+1;
	}
	cout<<l;
	return 0;
}