#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sf scanf
#define pf printf

int main()
{
	ll t,n,count = 0;
	sf("%lld",&t);
	while(t--)
	{
		sf("%lld",&n);
		ll i,max = -1,p,q,arr[n];
		for(i=0;i<n;i++)
		sf("%lld",&arr[i]);
		for(i=0;i<n-3;i++)
		{
			multiset<ll> temp;
			for(int j=i;j<n;j++)
			{
				ll ans=0;
				temp.insert(arr[j]);
				if(temp.size()>=4)
				{
					multiset<ll>::iterator it=temp.begin();
					ans ^= *it;
					it++;
					ans ^= *it;
					it++;
					ans ^= *it;
					it++;
					ans ^= *it;
					if (ans > max)
					{
						p=i;
						q=j;
						max=ans;
					}
					if (q-p<=(j-i)&&ans==max)
					{
						p=i;
						q=j;
					}
				}
			}
		}
		count++;
		pf("Case #%lld:\n",count);
		pf("%lld %lld %lld\n",p+1,q+1,max);
	}
	return 0;
}
