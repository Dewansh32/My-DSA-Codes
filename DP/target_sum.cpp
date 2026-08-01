#include<bits/stdc++.h>
using namespace std;

bool Target_sum(vector<int> nums,int t_sum,int n)
{
    vector<vector<int>> dp(n+1,vector<int>(t_sum+1,0));


    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<t_sum+1;j++)
        {
            if(nums[i-1] <= j)
            {
                dp[i][j] = max(nums[i-1] + dp[i-1][j-nums[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return t_sum == dp[n][t_sum];

}

int main() {
    vector<int> nums = {4,2,7,1,3};
    int t_sum = 7;

    cout<<Target_sum(nums,t_sum,5);
    return 0;
}