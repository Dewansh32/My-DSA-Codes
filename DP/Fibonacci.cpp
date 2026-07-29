#include<bits/stdc++.h>
using namespace std;

int fib(int n,vector<int> &dp_arr)
{
    if(n == 0 || n == 1)
    {
        return n;
    }

    if(dp_arr[n] != -1)
    {
        return dp_arr[n];
    }

    return dp_arr[n] = fib(n-1,dp_arr) + fib(n-2,dp_arr);
}

int main()
{
    int n=6;

    vector<int> dp_arr(n+1,-1);

    cout<<fib(n,dp_arr);
}