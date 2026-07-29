#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    vector<int> dp_arr(n+1,0);
    dp_arr[0] = 0;
    dp_arr[1] = 1;

    for(int i=2;i<=n;i++)
    {
        dp_arr[i] = dp_arr[i-1] + dp_arr[i-2];
    }
    
    return dp_arr[n];
}

int main()
{
    int n=6;

    

    cout<<fib(n);
}