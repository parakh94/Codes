// C++ program to count of ways to place 1 x 4 tiles
// on n x 4 grid.
#include<iostream>
using namespace std;
 
// Returns count of count of ways to place 1 x 4 tiles
// on n x 4 grid.
int count(int n)
{
    // Create a table to store results of subproblems
    // dp[i] stores count of ways for i x 4 grid.
    int dp[n+1];
    dp[0] = 0;
 
    // Fill the table from d[1] to dp[n]
    for (int i=1; i<=n; i++)
    {
        // Base cases
        if (i >= 1 && i <= 3)
            dp[i] = 1;
        else if (i==4)
            dp[i] = 2 ;
 
        else
            // dp(i-1) : Place first tile horizontally
            // dp(n-4) : Place first tile vertically
            //           which means 3 more tiles have
            //           to be placed vertically.
            dp[i] = dp[i-1] + dp[i-4];
    }
 
    return dp[n];
}
 
// Driver program to test above
int main()
{
    int n = 5;
    cout << "Count of ways is " << count(n);
    return 0;
}
