#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sf scanf
#define pf printf
int main()
{
	ll t;
	sf("%lld",&t);
	while(t--)
	{
		ll n;
		sf("%lld",&n);
		ll arr[n],i,x,temp[5000],j,k,c,z=0,w;
		for(i=1;i<=n;i++)
		{
			j=0,c=0;
			if(i<10)
			{
				arr[z]=i;
				z++;
			}
			else
			{
				w=i;
				while(w)
				{
					x=w%10;
					w=w/10;
					temp[j]=x;
					j++;
				}
				for(k=0;k<j;k++)
				{
					if(abs(temp[k]-temp[k+1])>1&&k!=j-1)
					c=1;
				}
				if(c!=1)
				{
					arr[z]=i;
					z++;
				}
			}
		}
		ll sum=0;
		pf("%lld\n",z+1);
		for(i=0;i<z;i++)
		sum=sum+arr[i];
		pf("%lld\n0 ",sum);
		for(i=0;i<z;i++)
		pf("%lld ",arr[i]);
		pf("\n");
	}
	return 0;
}

