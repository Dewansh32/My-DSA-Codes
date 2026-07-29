#include<bits/stdc++.h>
using namespace std;

int cl_st(int n,vector<int> &dp_arr)
{
    if(n == 0 || n == 1)
    {
        return 1;
    }

    if(dp_arr[n] != -1)
    {
        return dp_arr[n];
    }

    return dp_arr[n] = cl_st(n-1,dp_arr) + cl_st(n-2,dp_arr);
}

int main()
{
    int n=100;

    vector<int> dp_arr(n+1,-1);

    cout<<cl_st(n,dp_arr);
}