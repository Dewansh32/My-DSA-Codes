#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2)
{
    return (double)p1.first / p1.second > (double)p2.first / p2.second;
}

double maxProfit(vector<int> val,vector<int> weight,int k)
{
vector <pair<int,int>> knapsack;
    for(int i=0;i<3;i++)
    {
        knapsack.push_back({val[i],weight[i]});
    }

    sort(knapsack.begin(),knapsack.end(),compare);

    double profit = 0.0;
    for(int i=0;i<3;i++)
    {
        if(k==0) break;
        if(knapsack[i].second<=k)
        {
            profit += knapsack[i].first;
            k -= knapsack[i].second;
        }
        else
        {
            profit += ((double)k / knapsack[i].second) * knapsack[i].first;

            k=0;
        }
    }

    return profit;
}

int main() {
    vector<int> val = {60,100,120};
    vector<int> weight = {10,20,30};
    int k = 50;

    cout<<"profit: "<<maxProfit(val,weight,k)<<endl;
    return 0;
}