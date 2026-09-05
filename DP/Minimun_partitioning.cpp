#include<bits/stdc++.h>
using namespace std;

int getMinDiff(vector<int> nums,int n,int h_sum,int t_sum)
{
    vector<vector<int>> dp(n+1,vector<int>(h_sum+1,0));

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<h_sum+1;j++)
        {
            if(nums[i-1]<=j)
            {
                dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int grp1 = dp[n][h_sum];
    int grp2 = t_sum - grp1;
    return abs(grp1 - grp2);
}

int main() {
    vector<int> nums = {1,6,11,5};
    int n=4;
    int t_sum = 0;
    for(int i=0;i<n;i++)
    {
        t_sum += nums[i];
    }

    int h_sum = t_sum/2;
    
    cout<<getMinDiff(nums,n,h_sum,t_sum);
    return 0;
}