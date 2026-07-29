#include <bits/stdc++.h>
using namespace std;

int max_profit(int n, int W, int val[], int wt[],int pf)
{
    if(n == 0 || W == 0) return pf;

    if(wt[n-1]<=W)
    {
        return max(max_profit(n-1,W-wt[n-1],val,wt,pf + val[n-1]),max_profit(n-1,W,val,wt,pf));
    }

    return max_profit(n-1,W,val,wt,pf);
}

int main() {
    int n = 5;
    int W = 7;
    int pf=0;

    int val[5] = {15,14,10,5,30};
    int wt[5] = {2,5,1,3,4};

    cout << max_profit(n, W, val, wt,pf);

    return 0;
}