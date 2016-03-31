#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sf scanf
#define pf printf
int main()
{
	long long int  n,i,ans=1,c=0,ans1=1;
	scanf("%lld",&n);
	long long int a[n];
	for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
	if(a[0]<a[1])
	{
		c=0;
		ans=2;
	}
	if(a[0]>a[1])
	{
		c=1;
		ans=2;
	}
	for(i=1;i<n;i++)
	{
		if(a[i]>a[i+1]&&c==0&&i!=n-1)
		{
			ans++;
			c=1;
		}
		if(a[i]<a[i+1]&&c==1&&i!=n-1)
		{
			ans++;
			c=0;
		}
	}
	for(i=1;i<n;i++)
	{
		if(a[i]>a[i+1]&&i!=n-1&&c==0)
		{
			ans1++;
			c=1;
		}
		if(a[i]<a[i+1]&&i!=n-1&&c==1)
		{
			ans1++;
			c=0;
		}
	}
	if(ans1>ans)
	printf("%lld",ans1);
	else
	printf("%lld",ans);
	return 0;
}

