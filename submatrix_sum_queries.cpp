#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define sf scanf
#define pf printf
long long int binarySearch(long long int arr[],long long  int l, long long int r, long long int x)
{
  while (l <= r)
  {
    long long int m = l + (r-l)/2;

    if (arr[m] == x) return m;  // Check if x is present at mid

    if (arr[m] < x) l = m + 1; // If x greater, ignore left half

    else r = m - 1; // If x is smaller, ignore left half
  }
  return -1; // if we reach here, then element was not present
}
void merge(long long int arr[], long long int l, long long int m, long long int r)
{
    long long int i, j, k;
    long long int n1 = m - l + 1;
    long long int n2 =  r - m;

    /* create temp arrays */
   long long  int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the sub-array
  of arr to be sorted */
void mergeSort(long long int arr[], long long int l, long long int r)
{
    if (l < r)
    {
        long long  int m = l+(r-l)/2;//Same as (l+r)/2, but avoids overflow for large l and h
        mergeSort(arr, l, m);
	    mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
void printArray(long long int A[], long long int size)
{
   long long  int i;
    for (i=0; i < size; i++)
        printf("%lld ", A[i]);
    printf("\n");
}
#define M 4
#define N 5
int preProcess(int mat[M][N], int aux[M][N])
{
   for (int i=0; i<N; i++)
      aux[0][i] = mat[0][i];
   for (int i=1; i<M; i++)
      for (int j=0; j<N; j++)
         aux[i][j] = mat[i][j] + aux[i-1][j];
   for (int i=0; i<M; i++)
      for (int j=1; j<N; j++)
         aux[i][j] += aux[i][j-1];
}
int sumQuery(int aux[M][N], int tli, int tlj, int rbi,int rbj)
{
    int res = aux[rbi][rbj];
    if (tli > 0)
       res = res - aux[tli-1][rbj];
    if (tlj > 0)
       res = res - aux[rbi][tlj-1];
    if (tli > 0 && tlj > 0)
       res = res + aux[tli-1][tlj-1];
 
    return res;
}
int main()
{
   int aux[M][N],i,j,mat[M][N];
   for (i=0;i<M;i++)
   {
   	for(j=0;j<N;j++)
   	cin>>mat[i][j];
   }
   
   preProcess(mat, aux);
   /*for (i=0;i<M;i++)
   {
   	for(j=0;j<N;j++)
   	cout<<aux[i][j]<<" ";
   	cout<<"\n";
   }*/
   int tli,tlj,rbi,rbj;
   cin>>tli>>tlj>>rbi>>rbj;	
   cout <<sumQuery(aux, tli, tlj, rbi, rbj);
 
   return 0;
}
