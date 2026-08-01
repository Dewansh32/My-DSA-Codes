#include<bits/stdc++.h>
using namespace std;

int lcsubstr_tab(int n1,int n2,vector<vector<int>> &dp,string s1,string s2)
{
    int ans = 0;
    for(int i=1;i<n1+1;i++)
    {
        for(int j=1;j<n2+1;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans,dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    for(int i=0;i<n1+1;i++)
    {
        for(int j=0;j<n2+1;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return ans;
}

int main() {
    string text1 = "abcde";
    string text2 = "abgce";

    int n1 = text1.length();
    int n2 = text2.length();

    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

    cout<<lcsubstr_tab(n1,n2,dp,text1,text2)<<endl;
    return 0;
}