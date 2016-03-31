#include<bits/stdc++.h>
using namespace std;
long long int ssearch(long long int arr[],long long  int l, long long int r, long long int x)
{
  while (l <= r)
  {
    long long int m = l + (r-l)/2;

    if ((arr[m] == x&&arr[m-1]<arr[m])||(arr[m] == x&&m==0)) return m;
    if (arr[m] < x) l = m + 1;
    else r = m - 1;  
  }
  return -1;
}
long long int esearch(long long int arr[],long long  int l, long long int r, long long int x)
{
  while (l <= r)
  {
    long long int m = l + (r-l)/2;
	//printf("m=%lld\nl=%lld\nr=%lld\n",m,l,r);
    if ((arr[m] == x&&arr[m+1]>arr[m])||(arr[m] == x&&m==r) )return m;
    if (arr[m] <= x) l = m + 1;
    else r = m - 1;  
	}
	return -1;
}
int main()
{
	long long int x,n,i,strindx,endindx;
	scanf("%lld%lld",&x,&n);
	long long int a[n];
	for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
	strindx=ssearch(a,0,n-1,x);
	endindx=esearch(a,0,n-1,x);
	printf("%lld",endindx-strindx+1);
	return 0;
}

