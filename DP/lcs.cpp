#include<bits/stdc++.h>
using namespace std;

int lcs_rec(string s1,string s2)
{
    int n = s1.size();
    int m = s2.size();

    if(n == 0 || m == 0)
    {
        return 0;
    }

    if(s1[n-1] == s2[m-1])
    {
        return 1 + lcs_rec(s1.substr(0,n-1),s2.substr(0,m-1));
    }
    else{
        return max(lcs_rec(s1.substr(0,n-1),s2),lcs_rec(s1,s2.substr(0,m-1)));
    }
}

int lcs_mem(int n1,int n2,vector<vector<int>> &dp,string s1,string s2)
{
    if(n1 == 0 || n2 == 0) return 0;

    if(dp[n1][n2] != 0)
    {
        return dp[n1][n2];
    }

    if(s1[n1-1] == s2[n2-1])
    {
        dp[n1][n2] = 1 + lcs_mem(n1-1,n2-1,dp,s1,s2);
    }
    else{
        dp[n1][n2] = max(lcs_mem(n1-1,n2,dp,s1,s2),lcs_mem(n1,n2-1,dp,s1,s2));
    }

    return dp[n1][n2];    
}

int lcs_tab(int n1,int n2,vector<vector<int>> &dp,string s1,string s2)
{
    for(int i=1;i<n1+1;i++)
    {
        for(int j=1;j<n2+1;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
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

    return dp[n1][n2];
}

int main() {
    string text1 = "abcdge";
    string text2 = "abedg";

    int n1 = text1.length();
    int n2 = text2.length();

    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    int lcs = 0;

    cout<<lcs_rec(text1,text2)<<endl;
    cout<<lcs_mem(n1,n2,dp,text1,text2)<<endl;
    cout<<lcs_tab(n1,n2,dp,text1,text2)<<endl;
    return 0;
}