#include<bits/stdc++.h>
using namespace std;

int minCoins(vector<int> coins,int val)
{
    int n = coins.size();
    int count = 0;
    for(int i=n-1;i>=0 && val>0;i--)
    {
        if(val>=coins[i])
        {
            count += val/coins[i];
            val = val%coins[i];
        }
    }

    return count;
}


int main() {
    vector<int> coins = {1,2,5,10,20,50,100,500,2000};
    int val = 590;

    cout<<"Min number of coins change: "<<minCoins(coins,val);

    return 0;
}