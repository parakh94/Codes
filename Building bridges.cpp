
#include<bits/stdc++.h>
using namespace std;

struct pairs
{
	int x;
	int y;  
};

bool myf(struct pairs p1,struct pairs p2)
{
	return p1.x<p2.x;   
}
int CeilIndex(int A[], int l, int r, int key)
{
    while (r - l > 1)
    {
        int m = l + (r - l)/2;
        if (A[m]>=key)
            r = m;
        else
            l = m;
    }
    return r;
}
 
int calculate_channels(struct pairs a[],int n){
	sort(a,a+n,myf);
    int *tailTable   = new int[n];
    int len; 
	memset(tailTable, 0, sizeof(tailTable[0])*n);
 	tailTable[0] = a[0].y;
    len = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i].y < tailTable[0])
            tailTable[0] = a[i].y;
 
        else if (a[i].y > tailTable[len-1])
            tailTable[len++] = a[i].y;
 
        else
            tailTable[CeilIndex(tailTable, -1, len-1, a[i].y)] = a[i].y;
    }
	delete[] tailTable;
    return len;
}
 
int main()
{
	int t;
	scanf("%d",&t);
    while(t--)
    {
		struct pairs arr[100];
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
		    cin>>arr[i].x;    
	   	}
	   	for(int i=0;i<n;i++)
		{
		    cin>>arr[i].y;    
	   	}
	   	int max=calculate_channels(arr,n);
		cout<<max<<"\n";
	}
    return 0;
}
