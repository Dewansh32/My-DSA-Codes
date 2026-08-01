#include <bits/stdc++.h>
using namespace std;

int max_profit(int n, int W, int val[], int wt[])
{
    if (n == 0 || W == 0)
        return 0;

    if (wt[n-1] <= W)
    {
        return max(
            val[n-1] + max_profit(n-1, W-wt[n-1], val, wt),
            max_profit(n-1, W, val, wt)
        );
    }

    return max_profit(n-1, W, val, wt);
}

int knapsackMem(int n, int W, int val[], int wt[],vector<vector<int>> &dp)
{
    if(n == 0 || W == 0) return 0;

    if(dp[n][W] != -1)
    {
        return dp[n][W];
    }

    if(wt[n-1]<=W)
    {
        int ans1 = knapsackMem(n-1,W-wt[n-1],val,wt,dp) + val[n-1];

        int ans2 = knapsackMem(n-1,W,val,wt,dp);

        dp[n][W] = max(ans1,ans2);
    }
    else
    {
        dp[n][W] = knapsackMem(n-1,W,val,wt,dp);
    }

    return dp[n][W];
    
}

int knapsackTab(int n, int W, int val[], int wt[])
{
    vector<vector<int>> dp(n+1,vector<int>(W+1,0));

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            int itemVal = val[i-1];
            int itemWt = wt[i-1];

            if(itemWt<=j)
            {
                dp[i][j] = max(itemVal + dp[i-1][j-itemWt],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n = 5;
    int W = 7;
    int pf=0;

    int val[5] = {15,14,10,45,30};
    int wt[5] = {2,5,1,3,4};

    cout << knapsackTab(n, W, val, wt);

    return 0;
}