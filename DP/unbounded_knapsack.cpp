#include <bits/stdc++.h>
using namespace std;

int U_knapsackTab(int n, int W, int val[], int wt[])
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
                dp[i][j] = max(itemVal + dp[i][j-itemWt],dp[i-1][j]);
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

    cout << U_knapsackTab(n, W, val, wt);

    return 0;
}