#include<bits/stdc++.h>
using namespace std;

int mcm(vector<int> &arr,int i,int j)
{
    if(i==j) return 0;

    int min_cost = INT32_MAX;
    for(int k=i;k<j;k++)
    {
        int cost1 = mcm(arr,i,k);
        int cost2 = mcm(arr,k+1,j);

        min_cost = min(min_cost,cost1 + cost2 + (arr[i-1]*arr[k]*arr[j]));
    }

    return min_cost;
}

int mcm_memo(vector<int> &arr,int i,int j,vector<vector<int>> &dp)
{
    if(i==j) return 0;

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int min_cost = INT32_MAX;
    for(int k=i;k<j;k++)
    {
        int cost1 = mcm_memo(arr,i,k,dp);
        int cost2 = mcm_memo(arr,k+1,j,dp);

        min_cost = min(min_cost,cost1 + cost2 + (arr[i-1]*arr[k]*arr[j]));
    }

    return dp[i][j] = min_cost;
}

int mcm_tab(vector<int> &arr,int i,int j)
{
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    for(int i=1;i<n;i++)
    {
        dp[i][i] = 0;
    }

    int min_cost = INT32_MAX;
    for(int len=2;len<n;len++)
    {
        for(int i=1;i<=n-len;i++)
        {
            int j=i+len-1;
            dp[i][j] = INT32_MAX;
            for(int k=i;k<j;k++)
            {
                int cost1 = dp[i][k];
                int cost2 = dp[k+1][j];
                dp[i][j] = min(dp[i][j],cost1 + cost2 + (arr[i-1]*arr[k]*arr[j]));
            }
        }
    }

    return dp[i][j];
}

int main() {
    vector<int> arr = {1,2,3,4,3};
    int n = 5;
    int i = 1;
    int j = 4;

    
    cout<<mcm_tab(arr,i,j);
    return 0;
}